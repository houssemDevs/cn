#ifndef FILESMODEL_H
#define FILESMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

#include "file.h"

class FilesModel : public QObject
{
    Q_OBJECT
public:
    explicit FilesModel(QObject *parent = 0) = delete;
    FilesModel(QSqlDatabase db, int projectId);

    int getProjectId() const;
    void setProjectId(int value);

signals:

public slots:
    int filesCount();
    File getFile(int offset);
    void addFile(File f);
    void updateFile(File f);
    void removeFile(File f);

private:
    int projectId;
    QSqlDatabase db;
};

#endif // FILESMODEL_H
