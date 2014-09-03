#ifndef DATEDIALOG_H
#define DATEDIALOG_H

#include <QDialog>
#include <QDateEdit>
#include <QPushButton>
#include <QLabel>
#include <QDate>

class DateDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DateDialog(QWidget *parent = 0);
    ~DateDialog();

signals:

private slots:

    void setClicked();
    void okClicked();

private:

    QPushButton *setButton;
    QPushButton *okButton;
    QDateEdit *dateEdit;
    QLabel *dateLabel;
};

#endif // DATEDIALOG_H
