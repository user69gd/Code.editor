// src/lsp_client.h
#pragma once

#include <QObject>
#include <QProcess>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTextStream>
#include <QDebug>

class LspClient : public QObject {
    Q_OBJECT
public:
    LspClient(const QString& serverPath, QObject* parent = nullptr);
    void initialize();
    void didOpen(const QString& fileUri, const QString& languageId, const QString& text);
    void didChange(const QString& fileUri, const QString& text);
    void requestCompletion(const QString& fileUri, int line, int character);
    
signals:
    void completionReady(const QJsonObject& completionData);

private slots:
    void readStdout();
    void readStderr();
    void processStarted();
    void processFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QProcess* m_serverProcess;
    QTextStream* m_streamIn;
    QTextStream* m_streamOut;
    // ... other internal state for JSON-RPC messages
};
