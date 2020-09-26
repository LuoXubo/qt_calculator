#include "expr.h"
#include "ui_expr.h"
#include "floatnumber.h"
#include <QPushButton>
#include <QTextEdit>
#include <QString>
#include <QDialog>
#include <QDebug>

typedef struct node _tNode;
#define NUM_OF_NUMBER 20
#define KIND_NUMBER  0
#define KIND_OPERATOR 1

expr::expr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::expr)
{
    ui->setupUi(this);
    setFixedSize(532,591);
    ui->textEdit_show->setText("Plese press the button");
    Process = "";
    result = 0;
    S = "";
    stat = 0;
    choose = 0;
    sum = 0;
    dot = 0;

}

expr::~expr()
{
    delete ui;
}





void expr::on_pushButton_1_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "1";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "1";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_2_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "2";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "2";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_3_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "3";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "3";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_4_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "4";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "4";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_5_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "5";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "5";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_6_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "6";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "6";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_7_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "7";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "7";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_8_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "8";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "8";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_9_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "9";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "9";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_BackSpace_clicked()
{
    if(choose==0)
    {
        S.chop(1);
        ui->textEdit_show->setText(S);
    }
    else{
        Process.chop(1);
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_0_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "0";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "0";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_00_clicked()
{
    if(stat == -1){
        result = sum;
        on_pushButton_clear_clicked();
    }
    if(choose == 0){
        S += "00";
        ui->textEdit_show->setText(S);
    }
    else if(choose!=0){
        Process += "00";
        ui->textEdit_show->setText(Process);
    }
}

void expr::on_pushButton_dot_clicked()
{
    if(dot==0)
    {
        if(choose==0)
        {
            S += ".";
            ui->textEdit_show->setText(S);
        }
        else if(choose!=0)
        {
            Process += ".";
            ui->textEdit_show->setText(S);
        }
    }
    stat = 1;
    dot = 1;
}

void expr::on_pushButton_equal_clicked()
{
    switch (choose) {
    case 1:
        result += S.toFloat() + Process.toFloat();
        sum = result;
        Sresult = QString("%1").arg(result);
        ui->textEdit_show->setText(Sresult);
        break;
    case 2:
        result += S.toFloat() - Process.toFloat();
        sum = result;
        Sresult = QString("%1").arg(result);
        ui->textEdit_show->setText(Sresult);
        break;
    case 3:
        if(sum==0)
            result = 1;
        else
            result = sum;
        if(S.toFloat() * Process.toFloat()!=0){
            result*=S.toFloat()*Process.toFloat();
            qDebug() << result << "" << sum;
        }
        else{
            result *= (S.toFloat() * Process.toFloat());
            qDebug() << result << "" << sum;
        }
        sum = result;
        Sresult = QString("%1").arg(result);
        ui->textEdit_show->setText(Sresult);
        break;
    case 4:
        if(Process.toFloat()==0){
            ui->textEdit_show->setText("System error");
            QTimer::singleShot(1000,this,SLOT(on_pushButton_clear_clicked()));
            break;
        }
        if(sum==0)
            result = 1;
        else
            result = sum;
        if(S.toFloat()/Process.toFloat()!=0)
        {
            result = S.toFloat() / Process.toFloat();
            qDebug() << result << "" << sum;
        }
        else
        {
            result /= (S.toFloat() + Process.toFloat());
            qDebug() << result <<  "" << sum;
        }
        sum = result;
        Sresult = QString("%1").arg(result);
        ui->textEdit_show->setText(Sresult);
        break;
    }
    sum = result;
    stat = -1;
    choose = 0;
    S = "";
    Process = "";
}

void expr::on_pushButton_clear_clicked()
{
    result = 0;
    S="";
    Process="";
    stat = 0;
    choose = 0;
    ui->textEdit_show->setText("Please press the button");
    dot = 0;
}

void expr::on_pushButton_plus_clicked()
{
    if(stat==0 || stat==-1)
        ui->textEdit_show->append("+");
    sum = result;
    stat = 1;
    choose = 1;
    dot = 0;
}

void expr::on_pushButton_minus_clicked()
{
    if(stat==0 || stat==-1)
        ui->textEdit_show->append("-");
    sum = result;
    stat = 1;
    choose = 2;
    dot = 0;
}

void expr::on_pushButton_multiply_clicked()
{
    if(stat==0 || stat==-1){
        ui->textEdit_show->append("*");
    }
    sum = result;
    stat = 1;
    choose = 3;
    dot = 0;
}

void expr::on_pushButton_divide_clicked()
{
    if(stat==0 || stat==-1){
        ui->textEdit_show->append("/");
    }
    sum = result;
    stat = 1;
    choose = 4;
    dot = 0;
}

void expr::on_pushButton_Exit_clicked()
{
    close();
}

