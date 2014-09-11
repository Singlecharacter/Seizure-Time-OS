#ifndef TEXTDIALOG_H
#define TEXTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class TextDialog : public QDialog
{
    Q_OBJECT

public:

    explicit TextDialog(QWidget *parent = 0, QString text = "");
    ~TextDialog();

private:

    QLabel *label;
    QPushButton *okButton;

private slots:

    void okClicked();

};

#endif // TEXTDIALOG_H
