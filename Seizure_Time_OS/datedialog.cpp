#include "datedialog.h"

DateDialog::DateDialog(QWidget *parent, QDate date) :
    QDialog(parent)
{
    setFixedSize(200,100);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);

    okButton = new QPushButton(this);
    setButton = new QPushButton(this);
    dateEdit = new QDateEdit(this);
    dateLabel = new QLabel(this);

    dateEdit->setDate(date);
    dateEdit->setGeometry(width()/2-dateEdit->width()/2,32,dateEdit->width(),16);

    changeDate(date);

    okButton->setGeometry(3*width()/4-75/2,69,75,23);
    setButton->setGeometry(width()/4-75/2,69,75,23);
    okButton->setText("Ok");
    setButton->setText("Set date");

    connect(okButton,SIGNAL(clicked()),this,SLOT(okClicked()));
    connect(setButton,SIGNAL(clicked()),this,SLOT(setClicked()));

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
    changeDate(dateEdit->date());
}

void DateDialog::changeDate(QDate newDate)
{
    int day,month,year;
    newDate.getDate(&year,&month,&day);
    QString dayString = "";
    dayString.setNum(day);
    QString monthString = "";
    monthString.setNum(month);
    QString yearString = "";
    yearString.setNum(year);
    dateLabel->setText("The date is: " + monthString + "/" + dayString + "/" + yearString);
    dateLabel->adjustSize();
    dateLabel->setGeometry(width()/2-dateLabel->width()/2,16,dateLabel->width(),dateLabel->height());
}
