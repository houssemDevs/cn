#ifndef FILE_H
#define FILE_H

#include <QString>

class File
{
public:
    File();

    QString getUri() const;
    void setUri(const QString &value);

    QString getThumbnail() const;
    void setThumbnail(const QString &value);

    QString getComment() const;
    void setComment(const QString &value);

    bool getIsPicture() const;
    void setIsPicture(bool value);

    int getId() const;
    void setId(int value);

private:
    QString uri;
    QString thumbnail;
    QString comment;
    bool isPicture;
    int id;
};

#endif // FILE_H
