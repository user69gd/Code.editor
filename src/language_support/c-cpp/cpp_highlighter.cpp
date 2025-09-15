// src/language_support/cpp_highlighter.cpp
#include "cpp_highlighter.h"

CppHighlighter::CppHighlighter(QTextDocument* parent) : SyntaxHighlighter(parent) {
    HighlightingRule rule;

    // Keywords
    QTextCharFormat keywordFormat;
    keywordFormat.setForeground(QColor("#569CD6")); // A common blue for keywords
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns = {
        "\\b(alignas|alignof|and|and_eq|asm|atomic_cancel|atomic_commit|atomic_noexcept|auto|bitand|bitor|break|case|catch|class|co_await|co_return|co_yield|compl|concept|const|constexpr|const_cast|continue|decltype|default|delete|do|double|dynamic_cast|else|enum|explicit|export|extern|false|float|for|friend|goto|if|inline|int|long|mutable|namespace|new|noexcept|not|not_eq|nullptr|operator|or|or_eq|private|protected|public|reflexpr|register|reinterpret_cast|requires|return|short|signed|sizeof|static|static_assert|static_cast|struct|switch|synchronized|template|this|thread_local|throw|true|try|typedef|typeid|typename|union|unsigned|using|virtual|void|volatile|wchar_t|while|xor|xor_eq|override|final)\\b"
    };
    for (const QString &pattern : keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    
    // Multi-line comments
    QTextCharFormat multiLineCommentFormat;
    multiLineCommentFormat.setForeground(QColor("#6A9955")); // A common green for comments
    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");

    // Single-line comments
    QTextCharFormat singleLineCommentFormat;
    singleLineCommentFormat.setForeground(QColor("#6A9955"));
    rule.pattern = QRegularExpression("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // Strings
    QTextCharFormat stringFormat;
    stringFormat.setForeground(QColor("#D69D85")); // Common orange for strings
    rule.pattern = QRegularExpression("\"[^\"\\\\]*(\\\\.[^\"\\\\]*)*\"");
    rule.format = stringFormat;
    highlightingRules.append(rule);
}

void CppHighlighter::highlightBlock(const QString &text) {
    for (const HighlightingRule &rule : highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    // Handle multi-line comments
    setCurrentBlockState(0);
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);
    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
