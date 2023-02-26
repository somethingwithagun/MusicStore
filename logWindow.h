#ifndef LOGWINDOW_H_
#define LOGWINDOW_H_

#include "database.h"
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>


class LoginWindow : public QDialog
{
    Q_OBJECT

  public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    bool isLogged()
    {
        return this->logged;
    }
    Database *getDB()
    {
        if (db != nullptr)
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
    bool logged = false;
    bool failed = false;
    void loginFail()
    {
        this->loginTitle->setStyleSheet("QLabel{color: red;}");
        this->passwordTitle->setStyleSheet("QLabel{color: red;}");
    }
    void normalizeLogin()
    {
        this->loginTitle->setStyleSheet("QLabel{color: black;}");
        this->passwordTitle->setStyleSheet("QLabel{color: black;}");
    }
    bool onConfirm();
};

#endif