/********************************************************************************
** Form generated from reading UI file 'cellularAutomaton.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLULARAUTOMATON_H
#define UI_CELLULARAUTOMATON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cellularAutomatonClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnGenerate;
    QPushButton *pushButton;
    QPushButton *btnSave;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QPushButton *btnStep;
    QPushButton *btnAuto;
    QLabel *label_3;
    QSlider *speedSlider;
    QSpacerItem *verticalSpacer_4;
    QLabel *labelStat;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *cellularAutomatonClass)
    {
        if (cellularAutomatonClass->objectName().isEmpty())
            cellularAutomatonClass->setObjectName(QStringLiteral("cellularAutomatonClass"));
        cellularAutomatonClass->resize(629, 585);
        centralWidget = new QWidget(cellularAutomatonClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(19, 9, 601, 511));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(500, 500));
        label->setMaximumSize(QSize(500, 500));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btnGenerate = new QPushButton(horizontalLayoutWidget);
        btnGenerate->setObjectName(QStringLiteral("btnGenerate"));

        verticalLayout->addWidget(btnGenerate);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        btnSave = new QPushButton(horizontalLayoutWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));
        btnSave->setEnabled(false);

        verticalLayout->addWidget(btnSave);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        btnStep = new QPushButton(horizontalLayoutWidget);
        btnStep->setObjectName(QStringLiteral("btnStep"));
        btnStep->setEnabled(false);

        verticalLayout->addWidget(btnStep);

        btnAuto = new QPushButton(horizontalLayoutWidget);
        btnAuto->setObjectName(QStringLiteral("btnAuto"));
        btnAuto->setEnabled(false);

        verticalLayout->addWidget(btnAuto);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        speedSlider = new QSlider(horizontalLayoutWidget);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));
        speedSlider->setEnabled(false);
        speedSlider->setMinimum(100);
        speedSlider->setMaximum(2000);
        speedSlider->setSingleStep(100);
        speedSlider->setPageStep(200);
        speedSlider->setValue(500);
        speedSlider->setOrientation(Qt::Horizontal);
        speedSlider->setInvertedAppearance(true);
        speedSlider->setInvertedControls(false);

        verticalLayout->addWidget(speedSlider);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        labelStat = new QLabel(horizontalLayoutWidget);
        labelStat->setObjectName(QStringLiteral("labelStat"));
        labelStat->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelStat);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);

        cellularAutomatonClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(cellularAutomatonClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 21));
        cellularAutomatonClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(cellularAutomatonClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        cellularAutomatonClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(cellularAutomatonClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        cellularAutomatonClass->setStatusBar(statusBar);

        retranslateUi(cellularAutomatonClass);
        QObject::connect(btnGenerate, SIGNAL(clicked()), cellularAutomatonClass, SLOT(generate()));
        QObject::connect(btnStep, SIGNAL(clicked()), cellularAutomatonClass, SLOT(step()));
        QObject::connect(btnAuto, SIGNAL(clicked()), cellularAutomatonClass, SLOT(autoMode()));
        QObject::connect(pushButton, SIGNAL(clicked()), cellularAutomatonClass, SLOT(loadImage()));
        QObject::connect(btnSave, SIGNAL(clicked()), cellularAutomatonClass, SLOT(saveImage()));

        QMetaObject::connectSlotsByName(cellularAutomatonClass);
    } // setupUi

    void retranslateUi(QMainWindow *cellularAutomatonClass)
    {
        cellularAutomatonClass->setWindowTitle(QApplication::translate("cellularAutomatonClass", "cellularAutomaton", 0));
        label->setText(QString());
        btnGenerate->setText(QApplication::translate("cellularAutomatonClass", "Generate", 0));
        pushButton->setText(QApplication::translate("cellularAutomatonClass", "Load Image...", 0));
        btnSave->setText(QApplication::translate("cellularAutomatonClass", "Save Image...", 0));
        label_2->setText(QApplication::translate("cellularAutomatonClass", "Generation 0", 0));
        btnStep->setText(QApplication::translate("cellularAutomatonClass", "Step", 0));
        btnAuto->setText(QApplication::translate("cellularAutomatonClass", "Auto", 0));
        label_3->setText(QApplication::translate("cellularAutomatonClass", "Speed:", 0));
        labelStat->setText(QApplication::translate("cellularAutomatonClass", "Stat:", 0));
    } // retranslateUi

};

namespace Ui {
    class cellularAutomatonClass: public Ui_cellularAutomatonClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLULARAUTOMATON_H
