#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

public slots:
    void slot_plusClicked();
    void slot_minusClicked();
    void slot_divideClicked();
    void slot_multiplyClicked();
    void slot_numberButtonClicked();



private slots:
    void on_clearButton_clicked();
    void on_equalButton_clicked();

    void on_actionAbout_triggered();

private:
    Ui::Calculator *ui;
    QString numberString;
    char lastOperation;
    double result;

};
#endif // CALCULATOR_H
