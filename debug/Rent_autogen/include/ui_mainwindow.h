/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *balanceDisplay;
    QPushButton *refillBalanceBtn;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QVBoxLayout *base;
    QVBoxLayout *rentContainer;
    QVBoxLayout *verticalLayout;
    QLabel *rentLabel;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *drmBtn;
    QSpinBox *drumsAmount;
    QPushButton *pianoBtn;
    QSpinBox *pianoAmount;
    QPushButton *gtrBtn;
    QSpinBox *guitarAmount;
    QPushButton *purchaseBtn;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName("MainWindowClass");
        MainWindowClass->resize(583, 275);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowClass->sizePolicy().hasHeightForWidth());
        MainWindowClass->setSizePolicy(sizePolicy);
        MainWindowClass->setMinimumSize(QSize(583, 275));
        MainWindowClass->setMaximumSize(QSize(583, 275));
        MainWindowClass->setAutoFillBackground(false);
        MainWindowClass->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setBold(true);
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        balanceDisplay = new QLabel(centralWidget);
        balanceDisplay->setObjectName("balanceDisplay");

        horizontalLayout_2->addWidget(balanceDisplay);

        refillBalanceBtn = new QPushButton(centralWidget);
        refillBalanceBtn->setObjectName("refillBalanceBtn");

        horizontalLayout_2->addWidget(refillBalanceBtn);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName("pushButton_3");
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{color: black;}\n"
"QPushButton:hover\n"
"{\n"
"	color: blue;\n"
"}"));
        pushButton_3->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"padding: 2px 0;\n"
"background-color: yellow;\n"
"border-radius: 7px;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(6, 2);

        verticalLayout_2->addLayout(horizontalLayout_2);

        base = new QVBoxLayout();
        base->setSpacing(6);
        base->setObjectName("base");
        rentContainer = new QVBoxLayout();
        rentContainer->setSpacing(6);
        rentContainer->setObjectName("rentContainer");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        rentLabel = new QLabel(centralWidget);
        rentLabel->setObjectName("rentLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(rentLabel->sizePolicy().hasHeightForWidth());
        rentLabel->setSizePolicy(sizePolicy2);
        rentLabel->setMinimumSize(QSize(0, 55));
        rentLabel->setMaximumSize(QSize(16777215, 70));
        QFont font2;
        font2.setPointSize(40);
        font2.setBold(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        rentLabel->setFont(font2);
        rentLabel->setStyleSheet(QString::fromUtf8(""));
        rentLabel->setScaledContents(false);
        rentLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(rentLabel);

        label = new QLabel(centralWidget);
        label->setObjectName("label");
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(0, 55));
        label->setMaximumSize(QSize(16777215, 55));
        QFont font3;
        font3.setPointSize(30);
        font3.setItalic(false);
        label->setFont(font3);
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        label->setMargin(0);
        label->setIndent(-1);
        label->setOpenExternalLinks(false);

        verticalLayout->addWidget(label);


        rentContainer->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        drmBtn = new QPushButton(centralWidget);
        drmBtn->setObjectName("drmBtn");
        drmBtn->setMaximumSize(QSize(400, 40));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        drmBtn->setFont(font4);

        horizontalLayout->addWidget(drmBtn);

        drumsAmount = new QSpinBox(centralWidget);
        drumsAmount->setObjectName("drumsAmount");
        drumsAmount->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(drumsAmount);

        pianoBtn = new QPushButton(centralWidget);
        pianoBtn->setObjectName("pianoBtn");
        pianoBtn->setMaximumSize(QSize(400, 40));
        pianoBtn->setFont(font4);

        horizontalLayout->addWidget(pianoBtn);

        pianoAmount = new QSpinBox(centralWidget);
        pianoAmount->setObjectName("pianoAmount");
        pianoAmount->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(pianoAmount);

        gtrBtn = new QPushButton(centralWidget);
        gtrBtn->setObjectName("gtrBtn");
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(gtrBtn->sizePolicy().hasHeightForWidth());
        gtrBtn->setSizePolicy(sizePolicy3);
        gtrBtn->setMaximumSize(QSize(400, 40));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setKerning(true);
        gtrBtn->setFont(font5);
        gtrBtn->setLayoutDirection(Qt::LeftToRight);
        gtrBtn->setStyleSheet(QString::fromUtf8(""));
        gtrBtn->setCheckable(false);
        gtrBtn->setAutoDefault(false);
        gtrBtn->setFlat(false);

        horizontalLayout->addWidget(gtrBtn);

        guitarAmount = new QSpinBox(centralWidget);
        guitarAmount->setObjectName("guitarAmount");
        guitarAmount->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(guitarAmount);


        rentContainer->addLayout(horizontalLayout);

        rentContainer->setStretch(1, 1);

        base->addLayout(rentContainer);

        purchaseBtn = new QPushButton(centralWidget);
        purchaseBtn->setObjectName("purchaseBtn");

        base->addWidget(purchaseBtn);


        verticalLayout_2->addLayout(base);

        verticalLayout_2->setStretch(1, 2);
        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        pushButton_3->setDefault(false);
        gtrBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "Music store", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowClass", "username", nullptr));
        balanceDisplay->setText(QCoreApplication::translate("MainWindowClass", "Your balance:", nullptr));
        refillBalanceBtn->setText(QCoreApplication::translate("MainWindowClass", "Refill Balance", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindowClass", "Log out", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindowClass", "Sign In", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindowClass", "Log In", nullptr));
        rentLabel->setText(QCoreApplication::translate("MainWindowClass", "Buy an instrument", nullptr));
        label->setText(QCoreApplication::translate("MainWindowClass", "Buy something", nullptr));
        drmBtn->setText(QCoreApplication::translate("MainWindowClass", "drums ($1000)", nullptr));
        pianoBtn->setText(QCoreApplication::translate("MainWindowClass", "piano ($198)", nullptr));
        gtrBtn->setText(QCoreApplication::translate("MainWindowClass", "guitar ($700)", nullptr));
        purchaseBtn->setText(QCoreApplication::translate("MainWindowClass", "Purchase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
