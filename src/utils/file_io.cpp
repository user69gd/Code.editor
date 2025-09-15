#include "file_io.h"
#include <QFile>
#include <QTextStream>

QString FileIO::loadFile(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QString(); // Return an empty string on error
    }
    QTextStream in(&file);
    return in.readAll();
}

bool FileIO::saveFile(const QString& filePath, const QString& content) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream out(&file);
    out << content;
    return true;
}
