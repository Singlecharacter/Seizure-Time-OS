#ifndef DIRECTORYLISTDIALOG_H
#define DIRECTORYLISTDIALOG_H

#include <QDialog>
#include <QString>
#include <QDir>
#include <QTextEdit>

class DirectoryListDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DirectoryListDialog(QWidget *parent = 0, QString dirName = "");
    ~DirectoryListDialog();

signals:

public slots:

};

#endif // DIRECTORYLISTDIALOG_H
