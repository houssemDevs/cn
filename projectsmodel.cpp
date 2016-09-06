#include "projectsmodel.h"

ProjectsModel::ProjectsModel(QSqlDatabase db): db {db}
{

}

int ProjectsModel::projectCount()
{
    QSqlQuery query(db);
    query.exec(QString("SELECT count(id) FROM Projects;"));
    query.first();
    return query.value(0).toInt();
}

Project ProjectsModel::getProject(int offset)
{
    QSqlQuery query(db);
    query.exec (QString("SELECT * FROM Projects LIMIT 1 OFFSET %1;").arg (offset));
    query.first ();
    Project p;
    p.setId (query.value ("id").toInt ());
    p.setProject (query.value ("project").toString());
    p.setLocation (query.value ("location").toString ());
    p.setDescription (query.value ("description").toString ());
    //TODO: Add Date field support.
    return p;
}

int ProjectsModel::addProject(Project p)
{
    QSqlQuery query(db);
    query.exec (QString("INSERT INTO Projects(project,location,description) VALUES ('%1','%2','%3');")
                .arg (p.getProject ())
                .arg (p.getLocation ())
                .arg (p.getDescription ()));
    //TODO: Add Date field support in insertion too.
    query.exec ("SELECT last_insert_rowid() FROM Projects;");
    query.first ();
    return query.value (0).toInt ();
}

void ProjectsModel::updateProject(Project p)
{
    QSqlQuery query(db);
    query.exec (QString("UPDATE OR IGNORE Projects SET project = %1, location = %2, description = %3"
                        "WHERE id = %4;")
                .arg (p.getProject ())
                .arg (p.getLocation ())
                .arg (p.getDescription ())
                .arg (p.getId ()));
}

void ProjectsModel::removeProject(Project p)
{
    QSqlQuery query(db);
    query.exec (QString("DELETE FROM Projects WHERE id = %1;").arg (p.getId ()));
}