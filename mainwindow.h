#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTableWidget;
class QLineEdit;
class QSpinBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddClicked();

private:
    QTableWidget* table;
    QLineEdit* nameInput;
    QLineEdit* secondNameInput;
    QSpinBox* ageInput;
};

#endif // MAINWINDOW_H
