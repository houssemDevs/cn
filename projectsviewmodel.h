#ifndef PROJECTSVIEWMODEL_H
#define PROJECTSVIEWMODEL_H

#include <QAbstractListModel>

#include "projectsmodel.h"

enum ProjectModelRoles {
    ProjectIdRole = Qt::UserRole + 1,
    ProjectTitleRole,
    ProjectLocationRole,
    ProjectDescriptionRole,
    ProjectDateRole
};

class ProjectsViewModel: public QAbstractListModel
{

    ProjectsModel *pmodel;

public:
    ProjectsViewModel();
    ProjectsModel *getPmodel() const;
    void setPmodel(ProjectsModel *value);
    int rowCount(const QModelIndex &parent) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QHash<int,QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void addNewProject(QString title, QString location, QString date, QString description);
    Q_INVOKABLE void modifyProject(QString title, QString location, QString date, QString description, int id, int index);
    Q_INVOKABLE void removeProject(int id, int index);

};

#endif // PROJECTSVIEWMODEL_H
