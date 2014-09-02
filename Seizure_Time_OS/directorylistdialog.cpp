#include "directorylistdialog.h"

DirectoryListDialog::DirectoryListDialog(QWidget *parent, QString dirName) :
    QDialog(parent)
{
    if(dirName == "")
    {
        //Create error message
    }
    setFixedSize(150,200);
    show();
}

DirectoryListDialog::~DirectoryListDialog()
{

}
