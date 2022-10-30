#include "ReadFile.h"

ReadFile::ReadFile() {}

QList<QList<QString>> ReadFile::readCSV() {

    QStringList line = readLine();
    int lineSize = line.size();

    QVector<QList<QString>> transactions;
    QStringList::iterator lineIterator;

    if (lineSize < 3) {line = readLine();}

    while(!currentFile->atEnd())
    {
        QList<QString> lineItem;
        for (lineIterator = line.begin(); lineIterator < line.end(); lineIterator++)
        {
//            int columnNumber = lineIterator - line.begin();
            lineIterator->replace("\"", "");
            lineIterator->replace("$", "");
            lineIterator->replace(",", "");
            lineItem.append(*lineIterator);
        }

        transactions.append(lineItem);
        line = readLine();
    }
    return transactions;
}


QStringList ReadFile::readLine() {
    QStringList values;
    if ( !currentFile->atEnd() ) {
        QByteArray line = currentFile->readLine();
        // The intent is to only generate strings in the list from CSV delimiters and allow commas otherwise
        auto strList = QString(line).split( QRegularExpression("(\\\"\\,\\\")") );
        // Get the line, retrieved in ByteArray form
//        QList<QByteArray> valuesInBytes = line.split(',');
        // Split the line by commas, since its a CSV
        for (auto fileIterator = strList.begin(); fileIterator < strList.end(); fileIterator++) {
            if ( fileIterator->contains('\n') ) {
                   fileIterator->erase(std::remove(fileIterator->begin(), fileIterator->end(), '\n'), fileIterator->end());
            }
            values.append(*fileIterator);
        }
    }
    return values;
}

