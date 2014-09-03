#include "helpdialog.h"

HelpDialog::HelpDialog(QWidget *parent) :
    QDialog(parent)
{
    setFixedSize(200,200);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);

    commandLibrary.clear();
    commandLibrary.push_back("Command: File List\r\n\r\nThe File List button opens a dialog window containing a scrollable text area that contains a list of all files and directories in the operating system's base directory, which by default is (User directory)/Seizure_Time_OS. Files are listed with extensions, while directories appear without any extensions.");
    commandLibrary.push_back("Command: Date\r\n\r\nThe Date button opens a dialog window containing a text display of the operating system's current date and a field for editing that date.");
    commandLibrary.push_back("Command: Quit\r\n\r\nThe Quit button opens a dialog window that asks if you're sure you want to quit and waits for your response.");

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
    helpDisplay->setText(commandLibrary.at(0));
    commandIndex = 0;

    pageLabel = new QLabel(this);
    QString currentCommandNum,totalCommandsNum;
    currentCommandNum.setNum(1);
    totalCommandsNum.setNum(commandLibrary.size());
    pageLabel->setText(currentCommandNum+"/"+totalCommandsNum);
    pageLabel->adjustSize();
    pageLabel->setGeometry(width()/2-pageLabel->width()/2,8,pageLabel->width(),pageLabel->height());

    connect(doneButton,SIGNAL(clicked()),this,SLOT(doneClicked()));
    connect(leftButton,SIGNAL(clicked()),this,SLOT(leftClicked()));
    connect(rightButton,SIGNAL(clicked()),this,SLOT(rightClicked()));

    show();
}

HelpDialog::~HelpDialog()
{
    delete doneButton;
    delete leftButton;
    delete rightButton;

}

void HelpDialog::doneClicked()
{
    close();
}

void HelpDialog::leftClicked()
{
    commandIndex -= 1;
    if(commandIndex < 0)
    {
        commandIndex = commandLibrary.size() - 1;
    }
    helpDisplay->setText(commandLibrary.at(commandIndex));

    QString currentCommandNum,totalCommandsNum;
    currentCommandNum.setNum(commandIndex+1);
    totalCommandsNum.setNum(commandLibrary.size());
    pageLabel->setText(currentCommandNum+"/"+totalCommandsNum);
    pageLabel->adjustSize();
    pageLabel->setGeometry(width()/2-pageLabel->width()/2,8,pageLabel->width(),pageLabel->height());
}

void HelpDialog::rightClicked()
{
    commandIndex += 1;
    if(commandIndex >= commandLibrary.size())
    {
        commandIndex = 0;
    }
    helpDisplay->setText(commandLibrary.at(commandIndex));

    QString currentCommandNum,totalCommandsNum;
    currentCommandNum.setNum(commandIndex+1);
    totalCommandsNum.setNum(commandLibrary.size());
    pageLabel->setText(currentCommandNum+"/"+totalCommandsNum);
    pageLabel->adjustSize();
    pageLabel->setGeometry(width()/2-pageLabel->width()/2,8,pageLabel->width(),pageLabel->height());
}
