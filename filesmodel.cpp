#include "filesmodel.h"

FilesModel::FilesModel(QSqlDatabase db, int projectId): projectId{projectId}, db{db}
{

}

File FilesModel::getFile(int offset)
{
    QSqlQuery query(db);
    query.exec(QString("SELECT * FROM Files WHERE project_id = %1 LIMIT 1 OFFSET %2;")
               .arg(projectId)
               .arg(offset));
    query.first();
    File f;
    f.setId(query.value("id").toInt());
    f.setUri(query.value("uri").toString());
    f.setThumbnail(query.value("thumbnail").toString());
    f.setIsPicture(query.value("isPicture").toBool());
    f.setComment(query.value("comment").toString());
    return f;
}

void FilesModel::addFile(File f)
{
    QSqlQuery query(db);
    query.exec(QString("INSERT INTO Files (uri,thumbnail,isPicture,comment) VALUES ('%1','%2','%3','%4');")
               .arg(f.getUri())
               .arg(f.getThumbnail())
               .arg(QVariant(f.getIsPicture()).toString())
               .arg(f.getComment()));
}

void FilesModel::updateFile(File f)
{
    QSqlQuery query(db);
    query.exec(QString("UPDATE OR IGNORE Files SET uri = '%1', thumbnail = '%2', isPicture = '%3', comment = '%4' WHERE id = %5;")
               .arg(f.getUri())
               .arg(f.getThumbnail())
               .arg(QVariant(f.getIsPicture()).toString())
               .arg(f.getComment())
               .arg(f.getId()));
}

void FilesModel::removeFile(File f)
{
    QSqlQuery query(db);
    query.exec(QString("DELETE OR IGNORE FROM Files WHERE id = %1;").arg(f.getId()));
}

int FilesModel::getProjectId() const
{
    return projectId;
}

void FilesModel::setProjectId(int value)
{
    projectId = value;
}

int FilesModel::filesCount()
{
    QSqlQuery query(db);
    query.exec(QString("SELECT count(id) FROM Files WHERE project_id = %1;")
               .arg(projectId));
    query.first();
    return query.value(0).toInt();
}
