#include "notesviewmodel.h"

NotesModel *NotesViewModel::getNmodel() const
{
    return nmodel;
}

void NotesViewModel::setNmodel(NotesModel *value)
{
    beginResetModel();
    nmodel = value;
    endResetModel();
}

void NotesViewModel::addNewNote(QString n)
{
    Note nn;
    nn.setNote(n);
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex()));
    nmodel->addNode(nn);
    endInsertRows();
}

void NotesViewModel::changeProjectId(int pId)
{
    beginResetModel();
    nmodel->setProjectId(pId);
    endResetModel();
}

void NotesViewModel::modifyNote(QString n, int index, int id)
{
    Note nn; nn.setId(id); nn.setNote(n);
    nmodel->updateNote(nn);
    auto in = this->index(index,0,QModelIndex());
    dataChanged(in,in,QVector<int>{NotesModelRoles::NoteRole});
}

void NotesViewModel::removeNode(int index, int id)
{
    Note n; n.setId(id);
    beginRemoveRows(QModelIndex(), index, index);
    nmodel->removeNote(n);
    endRemoveRows();
}

NotesViewModel::NotesViewModel()
{

}

int NotesViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return nmodel->notesCount();
}

Qt::ItemFlags NotesViewModel::flags(const QModelIndex &index) const
{
    Q_UNUSED(index)
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant NotesViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();
    switch(role){
    case NotesModelRoles::NoteIdRole:
        return QVariant(nmodel->getNote(index.row()).getId());
    case NotesModelRoles::NoteRole:
        return QVariant(nmodel->getNote(index.row()).getNote());
    case Qt::DisplayRole:{
        auto n = nmodel->getNote(index.row());
        QString d = QString("Note %1: %2").arg(n.getId()).arg(n.getNote());
        return QVariant(d);
    }
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> NotesViewModel::roleNames() const
{
    auto roles = QAbstractListModel::roleNames();
    roles.insert(NotesModelRoles::NoteIdRole, "noteId");
    roles.insert(NotesModelRoles::NoteRole, "note");
    return roles;
}
