#include "readfile.h"

readFile::readFile(QFile *inputFile) :
    currentFile(inputFile)
{
//    std::cout << "Inside readFile." << std::endl;
}

QList<QList<QString>> readFile::readCSV()
{
//    std::cout << "Beginning to read CSV." << std::endl;
//    std::cout << "Read attempt." << std::endl;
    QStringList line = readLine();
    int lineSize = line.size();
//    std::cout << "Read success." << std::endl;
//    std::cout << "This line contains: " << line.size() << " items." << std::endl;

    QVector<QList<QString>> transactions;
    QStringList::iterator lineIterator;

    if (lineSize < 3) {line=readLine();}

    while(!currentFile->atEnd())
    {
        QList<QString> lineItem;
        for (lineIterator = line.begin(); lineIterator < line.end(); lineIterator++)
        {
//            int columnNumber = lineIterator - line.begin();
//            std::cout << "Column number: " << columnNumber << std::endl;
//            std::cout << "Column value: " << lineIterator->toStdString() << std::endl;
            lineItem.append(*lineIterator);
//            std::cout << "Line Item size: " << lineItem.size() << std::endl;
        }
        transactions.append(lineItem);
        line = readLine();
    }
    return transactions;
}


QStringList readFile::readLine()
{
//    std::cout << "Beginning to read line." << std::endl;
    QStringList values;
    if (!currentFile->atEnd())
    {
        QByteArray line = currentFile->readLine();
        // Get the line, retrieved in ByteArray form
        QList<QByteArray> valuesInBytes = line.split(',');
        // Split the line by commas, since its a CSV
        QList<QByteArray>::const_iterator fileIterator;
        for (fileIterator = valuesInBytes.cbegin(); fileIterator < valuesInBytes.cend(); fileIterator++)
        {
//            if (fileIterator->toStdString().empty() || fileIterator->isEmpty())
//            {
//                continue;
//            }
//            else
//            {
//                std::cout << "Value: " << fileIterator->toStdString() << std::endl;
            values.append(*fileIterator);
//                std::cout << "Values size: " << values.size() << std::endl;
                 // For each value in the line, append them to a QList
//            }

        }
    }
    return values;
}

