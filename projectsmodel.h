#ifndef PROJECTSMODEL_H
#define PROJECTSMODEL_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QObject>
#include <QList>
#include <QVariant>

#include "project.h"

class ProjectsModel: QObject
{
    Q_OBJECT
public:
    ProjectsModel() = delete;
    ProjectsModel(QSqlDatabase db);

private:
    QSqlDatabase db;

public slots:
    int projectCount();
    Project getProject(int offset);
    int addProject(Project p);
    void updateProject(Project p);
    void removeProject(Project p);
};

#endif // PROJECTSMODEL_H
