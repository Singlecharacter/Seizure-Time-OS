#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>

class MultiPageDialog : public QDialog
{
    Q_OBJECT

public:

    explicit MultiPageDialog(QWidget *parent = 0,QStringList pages = QStringList());
    ~MultiPageDialog();

signals:



private slots:

    void doneClicked();
    void leftClicked();
    void rightClicked();

private:

    QStringList pageLibrary;

    int pageIndex;

    QPushButton *doneButton;
    QPushButton *leftButton;
    QPushButton *rightButton;

    QTextEdit *helpDisplay;

    QLabel *pageLabel;

};

#endif // HELPDIALOG_H
