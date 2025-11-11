#include "mainwindow.h"
#include "QHBoxLayout"
#include "QTableWidget"
#include "QLabel"
#include "QLineEdit"
#include "QSpinBox"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget;
    setCentralWidget(centralWidget);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    centralWidget->setLayout(mainLayout);

    table = new QTableWidget;
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels(QStringList() << "Name" << "Second Name" <<"Age");
    mainLayout->addWidget(table);

    QVBoxLayout* VerticalLayout = new QVBoxLayout;
    mainLayout->addLayout(VerticalLayout);

    VerticalLayout->addWidget(new QLabel("Name:"));
    nameInput = new QLineEdit;
        VerticalLayout->addWidget(nameInput);

        VerticalLayout->addWidget(new QLabel("Second name:"));
        secondNameInput = new QLineEdit;
        VerticalLayout->addWidget(secondNameInput);

        VerticalLayout->addWidget(new QLabel("Age:"));
        ageInput = new QSpinBox;
        VerticalLayout->addWidget(ageInput);

        QPushButton* addButton = new QPushButton("Add");
        connect(addButton, &QPushButton::clicked,this,&MainWindow::onAddClicked);
        VerticalLayout->addWidget(addButton);

         VerticalLayout->addStretch();
}


MainWindow::~MainWindow()
{

}

void MainWindow::onAddClicked()
{
    const QString name = nameInput->text();
    const QString secondName = secondNameInput->text();
    const int age = ageInput->value();
    const int rowCount = table->rowCount();

    table->setRowCount(rowCount + 1);
    table->setItem(rowCount, 0,new QTableWidgetItem(name));
    table->setItem(rowCount, 1,new QTableWidgetItem(secondName));
    table->setItem(rowCount, 2,new QTableWidgetItem(QString::number(age)));


    // Очистка полей ввода после добавления
    nameInput->clear();
    secondNameInput->clear();
    ageInput->setValue(0);

}
















