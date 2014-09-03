#include "datedialog.h"

DateDialog::DateDialog(QWidget *parent) :
    QDialog(parent)
{
    setFixedSize(200,300);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);

    okButton = new QPushButton(this);
    setButton = new QPushButton(this);
    dateEdit = new QDateEdit(this);
    dateLabel = new QLabel(this);

    QDate date = QDate().currentDate();
    int day,month,year;
    date.getDate(&year,&month,&day);
    dateEdit->setDate(date);
    QString dayString = "";

    show();
}

DateDialog::~DateDialog()
{

}

void DateDialog::okClicked()
{
    close();
}

void DateDialog::setClicked()
{

}
