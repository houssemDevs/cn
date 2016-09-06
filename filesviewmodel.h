#ifndef FILESVIEWMODEL_H
#define FILESVIEWMODEL_H

#include <QAbstractListModel>

#include "filesmodel.h"

enum FileModelRoles {
    FileIdRole = Qt::UserRole + 1,
    FileUriRole,
    FileThumbnailRole,
    FileCommentRole
};

class FilesViewModel: public QAbstractListModel
{

    FilesModel *fmodel;

public:
    FilesViewModel();
    FilesModel *getFmodel() const;
    void setFmodel(FilesModel *value);

    int rowCount(const QModelIndex& parent) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QHash<int,QByteArray> roleNames() const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void addNewFile(QString uri, QString comment);
    Q_INVOKABLE void updateFile(QString uri, QString comment, int index, int id);
    Q_INVOKABLE void removeFile(int index, int id);
    Q_INVOKABLE void changeProjectId(int id);

};

#endif // FILESVIEWMODEL_H
