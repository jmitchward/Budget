#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegExp>


class ReadFile
{
public:
    ReadFile();
    QStringList readLine();
    QList<QList<QString>> readCSV();
    inline void setFile(QFile* file) {
        currentFile = file;
    }

private:
    QDir currentDir;
    QFile *currentFile;
};

#endif // READFILE_H
