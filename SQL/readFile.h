#ifndef READFILE_H
#define READFILE_H

#include <iostream>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegExp>


class readFile
{
public:
    readFile(QFile*);
    QStringList readLine();
    QList<QList<QString>> readCSV();

private:
    QDir currentDir;
    QFile *currentFile;
};

#endif // READFILE_H
