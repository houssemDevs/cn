#include "project.h"

Project::Project()
{

}

QString Project::getProject() const
{
    return project;
}

void Project::setProject(const QString &value)
{
    project = value;
}

QString Project::getLocation() const
{
    return location;
}

void Project::setLocation(const QString &value)
{
    location = value;
}

QString Project::getDescription() const
{
    return description;
}

void Project::setDescription(const QString &value)
{
    description = value;
}

QString Project::getDate() const
{
    return date;
}

void Project::setDate(const QString &value)
{
    date = value;
}

int Project::getId() const
{
    return id;
}

void Project::setId(int value)
{
    id = value;
}
