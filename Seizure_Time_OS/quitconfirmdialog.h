#ifndef QUITCONFIRMDIALOG_H
#define QUITCONFIRMDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

class QuitConfirmDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QuitConfirmDialog(QWidget *parent = 0);
    ~QuitConfirmDialog();

signals:

private slots:

    void noClicked();

private:

    QLabel *confirmLabel;

    QPushButton *yesButton;
    QPushButton *noButton;
};

#endif // QUITCONFIRMDIALOG_H
