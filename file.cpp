#include "file.h"

File::File()
{

}

QString File::getUri() const
{
    return uri;
}

void File::setUri(const QString &value)
{
    uri = value;
}

QString File::getThumbnail() const
{
    return thumbnail;
}

void File::setThumbnail(const QString &value)
{
    thumbnail = value;
}

QString File::getComment() const
{
    return comment;
}

void File::setComment(const QString &value)
{
    comment = value;
}

bool File::getIsPicture() const
{
    return isPicture;
}

void File::setIsPicture(bool value)
{
    isPicture = value;
}

int File::getId() const
{
    return id;
}

void File::setId(int value)
{
    id = value;
}
