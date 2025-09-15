// src/editor/text_editor.h
#pragma once

#include <QPlainTextEdit>
#include <QTimer>

class TextEditor : public QPlainTextEdit {
    Q_OBJECT
public:
    explicit TextEditor(QWidget *parent = nullptr);
    void setLanguageMode(const QString& language);

private slots:
    void autoSave();

private:
    QTimer m_autoSaveTimer;
};
