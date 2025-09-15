#pragma once

#include "../syntax_highlighter.h"
#include <QRegularExpression>

class CppHighlighter : public SyntaxHighlighter {
public:
    CppHighlighter(QTextDocument* parent);
    void highlightBlock(const QString& text) override;

private:
    // Struct to hold highlighting rules
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;
};
