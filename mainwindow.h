#pragma once

#include "ui_mainwindow.h"

#include "currentAccount.h"
#include "database.h"
#include "logWindow.h"
#include "products.h"
#include "refillBalanceWindow.h"
#include "regWindow.h"

#include <QPushButton>
#include <QString>
#include <ctime>
#include <fstream>

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    void onGtrPressed()
    {
        ui.guitarAmount->setValue(ui.guitarAmount->value() + 1);
    }
    void onPianoPressed()
    {
        ui.pianoAmount->setValue(ui.pianoAmount->value() + 1);
    }
    void onDrmsPressed()
    {
        ui.drumsAmount->setValue(ui.drumsAmount->value() + 1);
    }

    void onSignPressed();
    void onLogPressed();
    void onLogOutPressed();
    void onPurchasePressed();
    void onRefillBalancePressed();
    void logIn(std::string username, std::string password, std::string id, int balance);
    bool generateReceipt(std::string username, const int cost);
    std::string getTime();

  private:
    void refillBalance(int value)
    {
        user->setBalance(value);
    }
    void showBalance()
    {
        ui.balanceDisplay->setText(
            QString::fromStdString(("Your balance: " + std::to_string(this->user->getBalance()))));
    }
    struct Products
    {
        Guitar guitar1;
        Piano piano1;
        Drums drums1;
    } products;
    bool isLogged = false;
    CurrentAccount *user = nullptr;
    Database *db = nullptr;
    Ui::MainWindowClass ui;
};
