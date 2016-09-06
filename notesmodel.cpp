#include "notesmodel.h"

NotesModel::NotesModel(QObject *parent)
{
    Q_UNUSED(parent)
}

NotesModel::NotesModel(int projectId, QSqlDatabase db): projectId {projectId}, db {db}
{

}

int NotesModel::notesCount()
{
    QSqlQuery query(db);
    query.exec (QString("SELECT count(id) FROM Notes WHERE project_id = %1;").arg (projectId));
    query.first ();
    if (!query.lastError().text().isEmpty()) qDebug() << query.lastError().text();
    return query.value (0).toInt();
}

Note NotesModel::getNote(int offset)
{
    QSqlQuery query(db);
    query.exec (QString("SELECT id,note FROM Notes WHERE project_id = %1 LIMIT 1 OFFSET %2;")
                .arg (projectId)
                .arg (offset));
    query.first ();
    if (!query.lastError().text().isEmpty()) qDebug() << query.lastError().text();
    Note n;
    n.setId(query.value("id").toInt());
    n.setNote (query.value ("note").toString ());
    return n;
}

void NotesModel::addNode(Note n)
{
    QSqlQuery query(db);
    query.exec (QString("INSERT INTO Notes (note,project_id) VALUES ('%1',%2);")
                .arg (n.getNote ())
                .arg (projectId));
    if (!query.lastError().text().isEmpty()) qDebug() << query.lastError().text();
}

void NotesModel::updateNote(Note n)
{
    QSqlQuery query(db);
    query.exec(QString("UPDATE OR IGNORE Notes SET note = '%1', project_id = %2 WHERE id = %3;")
               .arg(n.getNote())
               .arg(projectId)
               .arg(n.getId()));
    if (!query.lastError().text().isEmpty()) qDebug() << query.lastError().text();
}

void NotesModel::removeNote(Note n)
{
    QSqlQuery query(db);
    query.exec(QString("DELETE OR IGNORE FROM Notes WHERE id = %1;").arg(n.getId()));
    if (!query.lastError().text().isEmpty()) qDebug() << query.lastError().text();
}

int NotesModel::getProjectId() const
{
    return projectId;
}

void NotesModel::setProjectId(int value)
{
    projectId = value;
}
