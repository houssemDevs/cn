#ifndef PROJECT_H
#define PROJECT_H

#include <QString>
#include <QVector>

#include "note.h"
#include "file.h"

class Project
{
public:
    Project();

    QString getProject() const;
    void setProject(const QString &value);

    QString getLocation() const;
    void setLocation(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString getDate() const;
    void setDate(const QString &value);

    int getId() const;
    void setId(int value);

private:
    QString project;
    QString location;
    QString description;
    QString date;
    int id;
};

#endif // PROJECT_H
