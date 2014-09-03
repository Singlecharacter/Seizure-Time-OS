#ifndef DIRECTORYLISTDIALOG_H
#define DIRECTORYLISTDIALOG_H

#include <QDialog>
#include <QString>
#include <QDir>
#include <QTextEdit>
#include <QPushButton>
#include <QStringList>

class DirectoryListDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DirectoryListDialog(QWidget *parent = 0, QString dirName = "");
    ~DirectoryListDialog();

signals:

private slots:

    void okClicked();

private:

    void readDirectory();

    QDir *dir;
    QPushButton *okButton;
    QTextEdit *listEdit;
};

#endif // DIRECTORYLISTDIALOG_H
