#include "filesviewmodel.h"

FilesModel *FilesViewModel::getFmodel() const
{
    return fmodel;
}

void FilesViewModel::setFmodel(FilesModel *value)
{
    beginResetModel();
    fmodel = value;
    endResetModel();
}

int FilesViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return fmodel->filesCount();
}

Qt::ItemFlags FilesViewModel::flags(const QModelIndex &index) const
{
    Q_UNUSED(index)
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

QHash<int, QByteArray> FilesViewModel::roleNames() const
{
    auto roles = QAbstractListModel::roleNames();
    roles.insert(FileModelRoles::FileCommentRole, "fileComment");
    roles.insert(FileModelRoles::FileIdRole, "fileId");
    roles.insert(FileModelRoles::FileThumbnailRole, "fileThumbnail");
    roles.insert(FileModelRoles::FileUriRole, "fileUri");
    return roles;
}

QVariant FilesViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    switch (role) {
    case FileModelRoles::FileCommentRole:
        return QVariant(fmodel->getFile(index.row()).getComment());
    case FileModelRoles::FileIdRole:
        return QVariant(fmodel->getFile(index.row()).getId());
    case FileModelRoles::FileThumbnailRole:
        return QVariant(fmodel->getFile(index.row()).getThumbnail());
    case FileModelRoles::FileUriRole:
        return QVariant(fmodel->getFile(index.row()).getUri());
    default:
        return QVariant(fmodel->getFile(index.row()).getUri());
    }
}

void FilesViewModel::addNewFile(QString uri, QString comment)
{
    File f;
    f.setComment(comment);
    f.setUri(uri);
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex()));
    fmodel->addFile(f);
    endInsertRows();
}

void FilesViewModel::updateFile(QString uri, QString comment, int index, int id)
{
    File f;
    f.setId(id);
    f.setComment(comment);
    f.setUri(uri);
    fmodel->updateFile(f);
    dataChanged(this->index(index,0,QModelIndex()), this->index(index,0,QModelIndex()),
                QVector<int>{
                    FileModelRoles::FileCommentRole,
                    FileModelRoles::FileIdRole,
                    FileModelRoles::FileThumbnailRole,
                    FileModelRoles::FileUriRole
                });
}

void FilesViewModel::removeFile(int index, int id)
{
    File f; f.setId(id);
    beginRemoveRows(QModelIndex(),index,index);
    fmodel->removeFile(f);
    endRemoveRows();
}

void FilesViewModel::changeProjectId(int id)
{
    beginResetModel();
    fmodel->setProjectId(id);
    endResetModel();
}

FilesViewModel::FilesViewModel()
{

}
