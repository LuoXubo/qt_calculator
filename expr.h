#ifndef EXPR_H
#define EXPR_H

#include <QDialog>
#include <QStack>
#include <QTimer>


namespace Ui {
class expr;
}

class expr : public QDialog
{
    Q_OBJECT

public:
    explicit expr(QWidget *parent = 0);
    ~expr();

    void calculate();
    int  process(char a,char b);

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_BackSpace_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_00_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_plus_clicked();

    void on_pushButton_minus_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_Exit_clicked();


private:
    QString Process;
    Ui::expr *ui;
    float  result;
    QString S;
    QString Sresult;
    float sum;
    int choose, stat, dot;


};

#endif // EXPR_H

