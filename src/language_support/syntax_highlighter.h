#pragma once

#include <QSyntaxHighlighter>

class SyntaxHighlighter : public QSyntaxHighlighter {
public:
    SyntaxHighlighter(QTextDocument* parent) : QSyntaxHighlighter(parent) {}

protected:
    virtual void highlightBlock(const QString& text) = 0;
};
