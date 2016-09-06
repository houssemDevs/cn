#include "note.h"

Note::Note()
{

}

QString Note::getNote() const
{
    return note;
}

void Note::setNote(const QString &value)
{
    note = value;
}

int Note::getId() const
{
    return id;
}

void Note::setId(const int &value)
{
    id = value;
}
