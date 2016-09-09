#include "projectsviewmodel.h"

ProjectsModel *ProjectsViewModel::getPmodel() const
{
    return pmodel;
}

void ProjectsViewModel::setPmodel(ProjectsModel *value)
{
    beginResetModel();
    pmodel = value;
    endResetModel();
}

int ProjectsViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return pmodel->projectCount();
}

Qt::ItemFlags ProjectsViewModel::flags(const QModelIndex &index) const
{
    Q_UNUSED(index)
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QHash<int, QByteArray> ProjectsViewModel::roleNames() const
{
    auto roles = QAbstractListModel::roleNames();
    roles.insert(ProjectModelRoles::ProjectIdRole, "projectId");
    roles.insert(ProjectModelRoles::ProjectDateRole, "projectDate");
    roles.insert(ProjectModelRoles::ProjectDescriptionRole, "projectDescription");
    roles.insert(ProjectModelRoles::ProjectLocationRole, "projectLocation");
    roles.insert(ProjectModelRoles::ProjectTitleRole, "projectTitle");
    return roles;
}

QVariant ProjectsViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    switch (role) {
    case ProjectModelRoles::ProjectIdRole:
        return QVariant(pmodel->getProject(index.row()).getId());
    case ProjectModelRoles::ProjectDateRole:
        return QVariant(pmodel->getProject(index.row()).getDate());
    case ProjectModelRoles::ProjectTitleRole:
        return QVariant(pmodel->getProject(index.row()).getProject());
    case ProjectModelRoles::ProjectDescriptionRole:
        return QVariant(pmodel->getProject(index.row()).getDescription());
    case ProjectModelRoles::ProjectLocationRole:
        return QVariant(pmodel->getProject(index.row()).getLocation());
    default:
        return QVariant(pmodel->getProject(index.row()).getProject());
    }
}

void ProjectsViewModel::addNewProject(QString title, QString location, QString date, QString description)
{
    Project p;
    p.setDate(date);
    p.setDescription(description);
    p.setLocation(location);
    p.setProject(title);
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex()));
    pmodel->addProject(p);
    endInsertRows();
}

void ProjectsViewModel::modifyProject(QString title, QString location, QString date, QString description, int id, int index)
{
    Project p;
    p.setId(id);
    p.setDate(date);
    p.setDescription(description);
    p.setLocation(location);
    p.setProject(title);
    pmodel->updateProject(p);
    qDebug() << "modify project";
    dataChanged(this->index(index,0,QModelIndex()),this->index(index,0,QModelIndex()),
                QVector<int>{
                    ProjectModelRoles::ProjectDateRole,
                    ProjectModelRoles::ProjectDescriptionRole,
                    ProjectModelRoles::ProjectIdRole,
                    ProjectModelRoles::ProjectLocationRole,
                    ProjectModelRoles::ProjectTitleRole
                });
}

void ProjectsViewModel::removeProject(int id, int index)
{
    Project p;
    p.setId(id);
    beginRemoveRows(QModelIndex(), index, index);
    pmodel->removeProject(p);
    endRemoveRows();
}

ProjectsViewModel::ProjectsViewModel()
{

}
