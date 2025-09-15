#pragma once

#include <QPlainTextEdit>
#include <QTimer>
#include "language_support/syntax_highlighter.h"

class TextEditor : public QPlainTextEdit {
    Q_OBJECT
public:
    explicit TextEditor(QWidget *parent = nullptr);
    void openFile(const QString& filePath);

private slots:
    void autoSave();

private:
    QTimer m_autoSaveTimer;
    SyntaxHighlighter* m_highlighter; // Base class for all highlighters
};
