#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QDebug>
#include <QFile>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QQuickStyle>

#include "file.h"
#include "filesmodel.h"
#include "filesviewmodel.h"
#include "note.h"
#include "notesmodel.h"
#include "notesviewmodel.h"
#include "project.h"
#include "projectsmodel.h"
#include "projectsviewmodel.h"

void OnStartup() {
  QString dbname("database.db");
  if (!QFile::exists(dbname)) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbname);
    if (db.open()) {
      QSqlQuery query(db);

      // Projects table
      query.exec("CREATE TABLE IF NOT EXISTS Projects"
                 "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "project TEXT NOT NULL DEFAULT 'Projet unconnu',"
                 "location TEXT NOT NULL,"
                 "date TEXT NOT NULL,"
                 "description TEXT);");
      if (!query.isValid())
        qDebug() << query.lastError().text();

      // Notes table
      query.exec("CREATE TABLE IF NOT EXISTS Notes"
                 "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "note TEXT NOT NULL,"
                 "project_id INT NOT NULL,"
                 "CONSTRAINT projects_notes_FK FOREIGN KEY (project_id) "
                 "REFERENCES Projects (id)"
                 "ON DELETE CASCADE "
                 "ON UPDATE CASCADE);");
      if (!query.isValid())
        qDebug() << query.lastError().text();

      // Files table
      query.exec("CREATE TABLE IF NOT EXISTS Files"
                 "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                 "is_picture BOOL NOT NULL DEFAULT 'false',"
                 "uri TEXT NOT NULL,"
                 "thumbnail TEXT,"
                 "comment TEXT,"
                 "project_id INT NOT NULL,"
                 "CONSTRAINT projects_files_FK FOREIGN KEY (project_id) "
                 "REFERENCES Projects (id)"
                 "ON DELETE CASCADE "
                 "ON UPDATE CASCADE);");
      if (!query.isValid())
        qDebug() << query.lastError().text();
      db.close();
    }
  }
}

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  OnStartup();
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("database.db");
  db.open();

  auto nModel = new NotesModel(1, db);
  auto nvModel = new NotesViewModel();
  nvModel->setNmodel(nModel);

  auto fModel = new FilesModel(db, 1);
  auto fvModel = new FilesViewModel();
  fvModel->setFmodel (fModel);

  auto pModel = new ProjectsModel(db);
  auto pvModel = new ProjectsViewModel();
  pvModel->setPmodel(pModel);


  QQmlApplicationEngine engine;
  engine.load(QUrl(QLatin1String("qrc:/main.qml")));

  engine.rootContext ()->setContextProperty("notesModel", nvModel);
  engine.rootContext ()->setContextProperty("projectsModel", pvModel);
  engine.rootContext ()->setContextProperty ("filesModel", fvModel);

  return app.exec();
}
