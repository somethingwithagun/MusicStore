#include "regWindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Sign in");
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

RegistrationWindow::~RegistrationWindow()
{
    if(db!=nullptr)
    {
        delete db;
    }
}
int RegistrationWindow::validateField(std::string field, std::regex forbidden, bool isUsrname)
{
    int result = std::regex_search(field, forbidden);

    if (result && isUsrname)
    {
        return ValidatingRes::F_USERNAME;
    }
    else if (result && !isUsrname)
    {
        return ValidatingRes::F_PASSWORD;
    }
    return ValidatingRes::OK;
}
bool RegistrationWindow::onConfirm()
{
    std::regex forbiddenUsr("[.,'+&=_<> ]");
    std::regex forbiddenPassw("[/ ]");
    std::string username = loginField->text().toStdString();
    std::string password = passwordField->text().toStdString();

    int validateUsrnameResult = validateField(username, forbiddenUsr, true);
    int validatePasswordResult = validateField(password, forbiddenPassw, false);

    if (validatePasswordResult + validateUsrnameResult == 5 || username == "" && password == "") // if they are together failed
    {
        failPassword();
        failUsername();
        failed = true;
        QMessageBox::critical(this, "Fail!", "Inappropriate username and password! Avoid .,'+&=_<>");
        return false;
    }
    else if (validateUsrnameResult == ValidatingRes::F_USERNAME || username == "")
    {
        failUsername();
        failed = true;
        QMessageBox::critical(this, "Fail!", "Inappropriate username! Avoid .,'+&=_<>");
        return false;
    }
    else if (validatePasswordResult == ValidatingRes::F_PASSWORD || password == "")
    {
        failPassword();
        failed = true;
        QMessageBox::critical(this, "Fail!", "Inappropriate password!");
        return false;
    }

    // if it's all ok, but the fail flag lasts
    if (failed)
    {
        failed = false;
        normalizePassword();
        normalizeUsername();
    }

    if(db==nullptr)
        db = new Database;

    if (db->addUser(username, password))
    {
        signedIn = true;
        QMessageBox::information(this, "Congratulations!", "You have succesfully registered!");
        this->close();
        return true;
    }
    else
    {
        delete db;
        db = nullptr;
        failUsername();
        signedIn = false;
        QMessageBox::information(this, "Fail!", QString::fromStdString( username + " has already exists"));
        failed = true;
        return false;
    }
}
