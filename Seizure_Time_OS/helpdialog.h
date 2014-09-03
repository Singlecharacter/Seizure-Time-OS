#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

class HelpDialog : public QDialog
{
    Q_OBJECT

public:

    explicit HelpDialog(QWidget *parent = 0);
    ~HelpDialog();

signals:



private slots:

    void doneClicked();
    void leftClicked();
    void rightClicked();

private:

    QStringList commandLibrary;

    int commandIndex;

    QPushButton *doneButton;
    QPushButton *leftButton;
    QPushButton *rightButton;

    QTextEdit *helpDisplay;

    QLabel *pageLabel;


};

#endif // HELPDIALOG_H
