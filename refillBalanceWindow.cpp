#include "refillBalanceWindow.h"

BalanceWindow::BalanceWindow(CurrentAccount *user, QWidget *parent)
{
    userAcc = user;
    this->setWindowTitle("Refill Balance");
    this->setFixedHeight(100);
    this->setMaximumWidth(250);
    grLay = new QGridLayout;
    confirmBtn = new QPushButton;
    valueField = new QLineEdit;
    passwordField = new QLineEdit;
    valueTitle = new QLabel;
    passwordTitle = new QLabel;
    vboxlay = new QVBoxLayout;
    hboxBtnLay = new QHBoxLayout;

    confirmBtn->setText("Confirm");
    valueTitle->setText("Input amount: ");
    passwordTitle->setText("Input password: ");

    grLay->addWidget(valueField, 1, 2, 1, 1);
    grLay->addWidget(passwordField, 2, 2, 1, 1);
    grLay->addWidget(valueTitle, 1, 1, 1, 1);
    grLay->addWidget(passwordTitle, 2, 1, 1, 1);

    hboxBtnLay->addWidget(confirmBtn, Qt::AlignHCenter);

    vboxlay->addLayout(grLay);
    vboxlay->addLayout(hboxBtnLay);

    this->setLayout(vboxlay);

    connect(confirmBtn, &QPushButton::pressed, this, onConfirm);
}

BalanceWindow::~BalanceWindow()
{
}

void BalanceWindow::onConfirm()
{
	if(userAcc!=nullptr)
	{
        std::string actualPassword = userAcc->getPassword();
        std::string password = passwordField->text().toStdString();
		
		if(password != actualPassword)
		{
            QMessageBox::critical(this, "Fail!", "Wrong password");
            correct = false;
            return;
        }
        
		value = valueField->text().toInt();

		if(value>100000)
		{
            QMessageBox::critical(this, "Fail!", "the value is too big!");
            correct = false;
            return;
        }
		if(value <= 0)
		{
            QMessageBox::critical(this, "Fail!", "the value is too small!");
            correct = false;
            return;
        }
        correct = true;
        userAcc->setBalance(userAcc->getBalance() + value);
        Database *db = new Database;
        db->writeBalance(userAcc->getBalance(), userAcc->getUsername());
        delete db;
        close();
    }
}
