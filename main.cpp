#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QFile>
#include <QDebug>

#include "projectsmodel.h"
#include "notesmodel.h"
#include "notesviewmodel.h"
#include "note.h"
#include "project.h"

void OnStartup() {
    QString dbname("database.db");
    if(!QFile::exists (dbname)){
        QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE");
        db.setDatabaseName (dbname);
        if(db.open ()){
            QSqlQuery query(db);

            // Projects table
            query.exec ("CREATE TABLE IF NOT EXISTS Projects"
                        "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                        "project TEXT NOT NULL DEFAULT 'Projet unconnu',"
                        "location TEXT NOT NULL,"
                        "date TEXT NOT NULL,"
                        "description TEXT);"
                        );
            if (!query.isValid ()) qDebug() << query.lastError ().text();

            // Notes table
            query.exec ("CREATE TABLE IF NOT EXISTS Notes"
                        "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                        "note TEXT NOT NULL,"
                        "project_id INT NOT NULL,"
                        "CONSTRAINT projects_notes_FK FOREIGN KEY (project_id) REFERENCES Projects (id)"
                        "ON DELETE CASCADE "
                        "ON UPDATE CASCADE);");
            if (!query.isValid ()) qDebug() << query.lastError ().text();

            // Files table
            query.exec ("CREATE TABLE IF NOT EXISTS Files"
                        "(id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                        "is_picture BOOL NOT NULL DEFAULT 'false',"
                        "uri TEXT NOT NULL,"
                        "thumbnail TEXT,"
                        "comment TEXT,"
                        "project_id INT NOT NULL,"
                        "CONSTRAINT projects_files_FK FOREIGN KEY (project_id) REFERENCES Projects (id)"
                        "ON DELETE CASCADE "
                        "ON UPDATE CASCADE);");
            if (!query.isValid ()) qDebug() << query.lastError ().text();
            db.close ();
        }
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    OnStartup ();
    QSqlDatabase db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName ("database.db");
    db.open ();

    auto nModel = new NotesModel(1, db);
    auto nvModel = new NotesViewModel();
    nvModel->setNmodel(nModel);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    engine.rootContext()->setContextProperty("notesModel", nvModel);

    return app.exec();
}
