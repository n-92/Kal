#include "calculator.h"
#include "ui_calculator.h"
#include <QMessageBox>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)

{
    ui->setupUi(this);
    lastOperation='0';  //no operation on startup

    QObject::connect(ui->zeroButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->oneButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->twoButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->threeButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->fourButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->fiveButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->sixButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->sevenButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->eightButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->nineButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));
    QObject::connect(ui->decimalButton,SIGNAL(clicked()), this,SLOT(slot_numberButtonClicked()));

    QObject::connect(ui->plusButton,SIGNAL(clicked()), this,SLOT(slot_plusClicked()));
    QObject::connect(ui->minusButton,SIGNAL(clicked()), this,SLOT(slot_minusClicked()));
    QObject::connect(ui->divideButton,SIGNAL(clicked()), this,SLOT(slot_divideClicked()));
    QObject::connect(ui->multiplyButton,SIGNAL(clicked()), this,SLOT(slot_multiplyClicked()));


}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::slot_plusClicked()
{
    lastOperation  ='+';
    result = ui->lcdNumber->value();
    numberString = "";
    ui->lcdNumber->display(result);
}

void Calculator::slot_minusClicked()
{
    lastOperation  ='-';
    result = ui->lcdNumber->value();
    numberString = "";
    ui->lcdNumber->display(result);
}

void Calculator::slot_divideClicked()
{
    lastOperation  ='/';
    result = ui->lcdNumber->value();
    numberString = "";
    ui->lcdNumber->display(result);
}

void Calculator::slot_multiplyClicked()
{
    lastOperation  ='*';
    result = ui->lcdNumber->value();
    numberString = "";
    ui->lcdNumber->display(result);
}


void Calculator::slot_numberButtonClicked()
{

    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text(); // retrive the text from the button clicked
    numberString.append(buttonText);
    ui->lcdNumber->display(numberString);

}

void Calculator::on_clearButton_clicked()
{
    ui->lcdNumber->display(0);
    numberString="";
    result = 0;
}


void Calculator::on_equalButton_clicked()
{
    switch(lastOperation){
        case '+':
            result = result + numberString.toDouble();
            numberString = "";
            ui->lcdNumber->display(result);
            lastOperation = '0';
        break;
    case '-':
        result = result - numberString.toDouble();
        numberString = "";
        ui->lcdNumber->display(result);
        lastOperation = '0';
    break;
    case '*':
        result = result * numberString.toDouble();
        numberString = "";
        ui->lcdNumber->display(result);
        lastOperation = '0';
    break;
    case '/':
        result = result / numberString.toDouble();
        numberString = "";
        ui->lcdNumber->display(result);
        lastOperation = '0';
    break;

    }
}

void Calculator::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Created by o92");
    msgBox.exec();
}
