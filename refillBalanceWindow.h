#ifndef REFILLBLNCWINDOW_H_
#define REFILLBLNCWINDOW_H_

#include "currentAccount.h"
#include "database.h"
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <string>

class BalanceWindow : public QDialog
{
  public:
    BalanceWindow(CurrentAccount* user,QWidget *parent = nullptr);
    ~BalanceWindow();
    void onConfirm();
    bool isCorrect()
    {
        return correct;
    }
    int getValue()
    {
        return this->value;
    }

  private:
    int value;
    bool correct;
    QGridLayout *grLay = nullptr;
    QPushButton *confirmBtn = nullptr;
    QLineEdit *valueField = nullptr;
    QLineEdit *passwordField = nullptr;
    QLabel *valueTitle = nullptr;
    QLabel *passwordTitle = nullptr;
    QVBoxLayout *vboxlay = nullptr;
    QHBoxLayout *hboxBtnLay = nullptr;
    CurrentAccount *userAcc = nullptr;
};

#endif