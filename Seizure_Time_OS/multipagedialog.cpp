#include "multipagedialog.h"

MultiPageDialog::MultiPageDialog(QWidget *parent,QStringList pages) :
    QDialog(parent)
{
    setFixedSize(200,200);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);

    pageLibrary.clear();
    pageLibrary = pages;

    doneButton = new QPushButton(this);
    leftButton = new QPushButton(this);
    rightButton = new QPushButton(this);

    doneButton->setText("Done");
    leftButton->setText("<-");
    rightButton->setText("->");

    doneButton->setGeometry(width()/2-75/2,169,75,23);
    leftButton->setGeometry(width()/4-8,8,16,16);
    rightButton->setGeometry(3*width()/4-8,8,16,16);

    helpDisplay = new QTextEdit(this);

    helpDisplay->setGeometry(8,32,184,126);
    helpDisplay->setText(pageLibrary.at(0));
    pageIndex = 0;

    pageLabel = new QLabel(this);
    QString currentCommandNum,totalCommandsNum;
    currentCommandNum.setNum(1);
    totalCommandsNum.setNum(pageLibrary.size());
    pageLabel->setText(currentCommandNum+"/"+totalCommandsNum);
    pageLabel->adjustSize();
    pageLabel->setGeometry(width()/2-pageLabel->width()/2,8,pageLabel->width(),pageLabel->height());

    connect(doneButton,SIGNAL(clicked()),this,SLOT(doneClicked()));
    connect(leftButton,SIGNAL(clicked()),this,SLOT(leftClicked()));
    connect(rightButton,SIGNAL(clicked()),this,SLOT(rightClicked()));

    show();
}

MultiPageDialog::~MultiPageDialog()
{
    delete doneButton;
    delete leftButton;
    delete rightButton;

}

void MultiPageDialog::doneClicked()
{
    close();
}

void MultiPageDialog::leftClicked()
{
    pageIndex -= 1;
    if(pageIndex < 0)
    {
        pageIndex = pageLibrary.size() - 1;
    }
    helpDisplay->setText(pageLibrary.at(pageIndex));

    QString currentCommandNum,totalCommandsNum;
    currentCommandNum.setNum(pageIndex+1);
    totalCommandsNum.setNum(pageLibrary.size());
    pageLabel->setText(currentCommandNum+"/"+totalCommandsNum);
    pageLabel->adjustSize();
    pageLabel->setGeometry(width()/2-pageLabel->width()/2,8,pageLabel->width(),pageLabel->height());
}

void MultiPageDialog::rightClicked()
{
    pageIndex += 1;
    if(pageIndex >= pageLibrary.size())
    {
        pageIndex = 0;
    }
    helpDisplay->setText(pageLibrary.at(pageIndex));

    QString currentCommandNum,totalCommandsNum;
    currentCommandNum.setNum(pageIndex+1);
    totalCommandsNum.setNum(pageLibrary.size());
    pageLabel->setText(currentCommandNum+"/"+totalCommandsNum);
    pageLabel->adjustSize();
    pageLabel->setGeometry(width()/2-pageLabel->width()/2,8,pageLabel->width(),pageLabel->height());
}
