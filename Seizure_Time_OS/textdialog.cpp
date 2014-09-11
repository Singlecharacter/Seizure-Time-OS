#include "textdialog.h"

TextDialog::TextDialog(QWidget *parent, QString text) :
    QDialog(parent)
{
    label = new QLabel(this);
    okButton = new QPushButton(this);
    setFixedSize(200,100);
    okButton->setText("OK");
    label->setText(text);
    label->adjustSize();
    okButton->setGeometry(width()/2 - 75/2,69,75,23);
    label->setGeometry(width()/2-label->width()/2,32,label->width(),label->height());

    setWindowFlags(Qt::Window);
    setModal(true);

    connect(okButton,SIGNAL(clicked()),this,SLOT(okClicked()));

    show();
}

TextDialog::~TextDialog()
{

}

void TextDialog::okClicked()
{
    close();
}
