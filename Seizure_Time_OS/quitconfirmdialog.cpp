#include "quitconfirmdialog.h"

QuitConfirmDialog::QuitConfirmDialog(QWidget *parent) :
    QDialog(parent)
{
    setFixedSize(200,100);
    setModal(true);
    //setWindowFlags(Qt::WindowTitleHint);
    yesButton = new QPushButton(this);
    noButton = new QPushButton(this);
    confirmLabel = new QLabel(this);

    confirmLabel->setText("Are you sure you want to quit?");
    confirmLabel->adjustSize();
    confirmLabel->setGeometry(width()/2 - confirmLabel->width()/2,32,confirmLabel->width(),confirmLabel->height());

    yesButton->setGeometry(17,69,75,23);
    yesButton->setText("Yes");

    noButton->setGeometry(108,69,75,23);
    noButton->setText("No");

    connect(yesButton,SIGNAL(clicked()),parent,SLOT(close()));
    connect(noButton,SIGNAL(clicked()),this,SLOT(close()));
    show();
}

QuitConfirmDialog::~QuitConfirmDialog()
{
    delete yesButton;
    delete noButton;
    delete confirmLabel;
}

void QuitConfirmDialog::noClicked()
{
    close();
}
