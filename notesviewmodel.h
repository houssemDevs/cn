#ifndef NOTESVIEWMODEL_H
#define NOTESVIEWMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QVector>

#include "notesmodel.h"
#include "note.h"

enum NotesModelRoles {
    NoteIdRole = Qt::UserRole + 1,
    NoteRole
};

class NotesViewModel: public QAbstractListModel
{
    Q_OBJECT

    NotesModel *nmodel;

public:
    NotesViewModel();
    int rowCount(const QModelIndex &parent) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    NotesModel *getNmodel() const;
    void setNmodel(NotesModel *value);

    Q_INVOKABLE void addNewNote(QString n);
    Q_INVOKABLE void modifyNote(QString n, int index, int id);
    Q_INVOKABLE void removeNode(int index, int id);
    Q_INVOKABLE void changeProjectId(int pId);

};

#endif // NOTESVIEWMODEL_H
