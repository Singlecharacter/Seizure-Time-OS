#include "quitconfirmdialog.h"

QuitConfirmDialog::QuitConfirmDialog(QWidget *parent) :
    QDialog(parent)
{
    setFixedSize(200,100);
    yesButton = new QPushButton(this);
    noButton = new QPushButton(this);

    yesButton->setGeometry(17,69,75,23);
    yesButton->setText("Yes");

    noButton->setGeometry(108,69,75,23);
    noButton->setText("No");

    connect(yesButton,SIGNAL(clicked()),parent,SLOT(close()));
    connect(noButton,SIGNAL(clicked()),this,SLOT(close()));
}

void QuitConfirmDialog::noClicked()
{
    close();
}
