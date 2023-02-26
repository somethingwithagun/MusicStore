#include "logWindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Log in");
    this->setFixedHeight(100);
    this->setMaximumWidth(250);
    grLay = new QGridLayout;
    confirmBtn = new QPushButton;
    loginField = new QLineEdit;
    passwordField = new QLineEdit;
    loginTitle = new QLabel;
    passwordTitle = new QLabel;
    vboxlay = new QVBoxLayout;
    hboxBtnLay = new QHBoxLayout;

    confirmBtn->setText("Confirm");
    loginTitle->setText("Input username: ");
    passwordTitle->setText("Input password: ");

    grLay->addWidget(loginField, 1, 2, 1, 1);
    grLay->addWidget(passwordField, 2, 2, 1, 1);
    grLay->addWidget(loginTitle, 1, 1, 1, 1);
    grLay->addWidget(passwordTitle, 2, 1, 1, 1);

    hboxBtnLay->addWidget(confirmBtn, Qt::AlignHCenter);

    vboxlay->addLayout(grLay);
    vboxlay->addLayout(hboxBtnLay);

    this->setLayout(vboxlay);

    connect(confirmBtn, &QPushButton::pressed, this, onConfirm);
}

LoginWindow::~LoginWindow()
{
    if (db != nullptr)
    {
        delete db;
    }
}
bool LoginWindow::onConfirm()
{
    std::string username = loginField->text().toStdString();
    std::string password = passwordField->text().toStdString();

    // if it's all ok, but the fail flag lasts
    if (failed)
    {
        failed = false;
        normalizeLogin();
    }

    if (db == nullptr)
        db = new Database;

    if (db->readUserData(username))
    {
		if(db->getPassword() == password && db->getUsername() == username)
		{
			logged = true;
            failed = false;
            QMessageBox::information(this, "Congratulations!", "You have succesfully logged!");
            normalizeLogin();
			this->close();
            return true;
		}
		else
		{
            delete db;
            db = nullptr;
            logged = false;
            failed = true;
            QMessageBox::critical(this, "Fail", "Wrong username or password");
            loginFail();
            return false;
        }
    }
    else
    {
        delete db;
        db = nullptr;
        logged = false;
        failed = true;
		QMessageBox::critical(this, "Fail", "Wrong username or password");
        loginFail();
        return false;
    }
}
