#include "directorylistdialog.h"

DirectoryListDialog::DirectoryListDialog(QWidget *parent, QString dirName) :
    QDialog(parent)
{
    if(dirName == "")
    {
        //Create error message
    }
    setFixedSize(150,200);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);

    listEdit = new QTextEdit(this);
    okButton = new QPushButton(this);
    dir = new QDir(dirName);

    okButton->setText("Ok");
    okButton->setGeometry(width()/2-75/2,height()-32,75,23);

    listEdit->setGeometry(8,8,134,160);
    readDirectory();
    listEdit->setReadOnly(true);

    connect(okButton,SIGNAL(clicked()),this,SLOT(okClicked()));

    show();
}

DirectoryListDialog::~DirectoryListDialog()
{
    delete dir;
    delete okButton;
    delete listEdit;
}

void DirectoryListDialog::readDirectory()
{
    QStringList fileList;
    fileList.clear();
    QString displayString = "";
    fileList = dir->entryList();
    for(int i = 2;i < fileList.size();i++)
    {
        displayString += fileList.at(i);
        displayString += "\r\n";
    }

    listEdit->setText(displayString);
}

void DirectoryListDialog::okClicked()
{
    close();
}
