#ifndef NOTE_H
#define NOTE_H

#include <QString>

class Note
{
public:
    Note();

    QString getNote() const;
    void setNote(const QString &value);

    int getId() const;
    void setId(const int &value);

private:
    QString note;
    int id;
};

#endif // NOTE_H
