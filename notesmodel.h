#ifndef NOTESMODEL_H
#define NOTESMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

#include "note.h"

class NotesModel : public QObject
{
    Q_OBJECT
public:
    explicit NotesModel(QObject *parent = 0);
    NotesModel(int projectId, QSqlDatabase db);

    int getProjectId() const;
    void setProjectId(int value);

signals:

public slots:
    int notesCount();
    Note getNote(int offset);
    void addNode(Note n);
    void updateNote(Note n);
    void removeNote(Note n);

private:
    int projectId;
    QSqlDatabase db;
};

#endif // NOTESMODEL_H
