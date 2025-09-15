#pragma once

#include <QString>

class FileIO {
public:
    static QString loadFile(const QString& filePath);
    static bool saveFile(const QString& filePath, const QString& content);
};
