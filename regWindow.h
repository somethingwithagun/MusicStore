#ifndef REGWINDOW_H_
#define REGWINDOW_H_

#include "database.h"
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>

#include <regex>

class RegistrationWindow : public QDialog
{
    Q_OBJECT

  public:
    RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();
    bool isRegistered()
    {
        return this->signedIn;
    }
    Database *getDB()
    {
        if(db != nullptr)
        {
            return db;
        }
        return nullptr;
    }

  private:
    QGridLayout *grLay = nullptr;
    QPushButton *confirmBtn = nullptr;
    QLineEdit *loginField = nullptr;
    QLineEdit *passwordField = nullptr;
    QLabel *loginTitle = nullptr;
    QLabel *passwordTitle = nullptr;
    QVBoxLayout *vboxlay = nullptr;
    QHBoxLayout *hboxBtnLay = nullptr;
    Database *db = nullptr;

  private:
    enum ValidatingRes // Validating results
    {
        OK = 1,
        F_USERNAME = 2,
        F_PASSWORD = 3
    };
    bool signedIn = false;
    bool failed = false;
    int validateField(std::string field, std::regex forbidden, bool isUsrname);
    void failUsername()
    {
        this->loginTitle->setStyleSheet("QLabel{color: red;}");
    }
    void failPassword()
    {
        this->passwordTitle->setStyleSheet("QLabel{color: red;}");
    }
    void normalizeUsername()
    {
        this->loginTitle->setStyleSheet("QLabel{color: black;}");
    }
    void normalizePassword()
    {
        this->passwordTitle->setStyleSheet("QLabel{color: black;}");
    }
    bool onConfirm();
};

#endif