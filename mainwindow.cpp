#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.pushButton_3->hide();
    ui.label_2->hide();
    ui.balanceDisplay->hide();
    ui.refillBalanceBtn->hide();

    connect(ui.pushButton_3, &QPushButton::pressed, this, onLogOutPressed);
    connect(ui.pushButton_2, &QPushButton::pressed, this, onSignPressed);
    connect(ui.pushButton, &QPushButton::pressed, this, onLogPressed);
    connect(ui.refillBalanceBtn, &QPushButton::pressed, this, onRefillBalancePressed);
    connect(ui.purchaseBtn, &QPushButton::pressed, this, onPurchasePressed);

    connect(ui.pianoBtn, &QPushButton::pressed, this, onPianoPressed);
    connect(ui.drmBtn, &QPushButton::pressed, this, onDrmsPressed);
    connect(ui.gtrBtn, &QPushButton::pressed, this, onGtrPressed);
}

void MainWindow::onPurchasePressed()
{
    const int guitarAmount = ui.guitarAmount->value();
    const int pianoAmount = ui.pianoAmount->value();
    const int drumsAmount = ui.drumsAmount->value();

    products.drums1.amount = drumsAmount;
    products.piano1.amount = pianoAmount;
    products.guitar1.amount = guitarAmount;

    const int purchaseCost =
        guitarAmount * products.guitar1.cost + pianoAmount * products.piano1.cost + drumsAmount * products.drums1.cost;

    if (user != nullptr)
    {
        if (purchaseCost < 1)
        {
            QMessageBox::critical(this, "Fail", "You have to buy something");
            return;
        }
        if (user->getBalance() >= purchaseCost)
        {
            if (!generateReceipt(this->user->getUsername(), purchaseCost))
            {
                QMessageBox::critical(this, "Fail", "Purchase failed!");
                return;
            }

            user->setBalance(user->getBalance() - purchaseCost);

            showBalance();

            db = new Database;
            db->writeBalance(user->getBalance(), user->getUsername());
            delete db;

            ui.drumsAmount->setValue(0);
            ui.pianoAmount->setValue(0);
            ui.guitarAmount->setValue(0);
        }
        else
            QMessageBox::critical(this, "cannot buy!", "You havent got enough money!");
    }
    else
        QMessageBox::critical(this, "cannot buy!", "Login into account");
}

void MainWindow::onSignPressed()
{
    RegistrationWindow *regWnd = new RegistrationWindow;
    this->setDisabled(true);
    regWnd->exec();
    if (regWnd->isRegistered())
        this->db = regWnd->getDB();
    else
        this->db = nullptr;
    if (this->db != nullptr) // if user logged
    {
        logIn(db->getUsername(), db->getPassword(), db->getId(), db->getBalance());
    }

    this->setDisabled(false);
    delete regWnd;
}

void MainWindow::logIn(std::string username, std::string password, std::string id, int balance)
{
    this->user = new CurrentAccount;

    this->user->setUsername(username);
    this->user->setId(id);
    this->user->setPassword(password);
    this->user->setBalance(balance);

    this->isLogged = true;

    ui.label_2->setText(QString::fromStdString(user->getUsername()));

    ui.balanceDisplay->show();
    ui.refillBalanceBtn->show();
    ui.label_2->show();
    ui.pushButton_3->show();

    ui.pushButton->hide();
    ui.pushButton_2->hide();

    showBalance();
}

bool MainWindow::generateReceipt(std::string username, const int cost)
{
    std::string time = getTime();
    std::ofstream receipt(time + ".txt");
    if (!receipt.is_open())
    {
        QMessageBox::critical(this, "Failed", "Unable to generate receipt!");
        return false;
    }

    receipt << username << ' ' << time << '\n';
    receipt << "*******************************************\n";

    if (products.guitar1.amount > 0)
        receipt << 'X' << products.guitar1.amount << ' ' << products.guitar1.name << "\t\t\t"
                << products.guitar1.cost * products.guitar1.amount << '\n';
    if (products.piano1.amount > 0)
        receipt << 'X' << products.piano1.amount << ' ' << products.piano1.name << "\t\t\t"
                << products.piano1.cost * products.piano1.amount << '\n';
    if (products.drums1.amount > 0)
        receipt << 'X' << products.drums1.amount << ' ' << products.drums1.name << "\t\t\t"
                << products.drums1.cost * products.drums1.amount << '\n';

    receipt << "\t\tSummary: " << cost << '\n';
    receipt << "*******************************************\n";
    receipt << "Thank you for purchase!\n";

    receipt.close();
    ui.label->setText("Thank you for purchase!");
    return true;
}

std::string MainWindow::getTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string result = "";
    result += std::to_string(ltm->tm_hour);
    result += "_";
    result += std::to_string(ltm->tm_min);
    result += "_";
    result += std::to_string(ltm->tm_sec);

    return result;
}

void MainWindow::onLogPressed()
{
    LoginWindow *logWnd = new LoginWindow;
    this->setDisabled(true);
    logWnd->exec();
    if (logWnd->isLogged())
        this->db = logWnd->getDB();
    else
        this->db = nullptr;
    if (this->db != nullptr) // if user logged
    {
        logIn(db->getUsername(), db->getPassword(), db->getId(), db->getBalance());
    }

    this->setDisabled(false);
    delete logWnd;
}

void MainWindow::onLogOutPressed()
{
    if (this->user != nullptr)
    {
        delete this->user;
        // this->user = nullptr;
    }
    this->isLogged = false;
    ui.pushButton_3->hide();
    ui.label_2->hide();
    ui.balanceDisplay->hide();
    ui.refillBalanceBtn->hide();

    ui.pushButton->show();
    ui.pushButton_2->show();
}

void MainWindow::onRefillBalancePressed()
{
    BalanceWindow *blncWnd = new BalanceWindow(user);
    blncWnd->exec();
    showBalance();
    delete blncWnd;
}

MainWindow::~MainWindow()
{
}
