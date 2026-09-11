#ifndef INPUT_DATE_H
#define INPUT_DATE_H

#include <QWidget>
#include <QDate>
#include <QDateEdit>

class InputDate : public QWidget
{
    Q_OBJECT

public:
    InputDate(QWidget *parent = nullptr);

signals:
    void inputDate(const QDate& date);

private slots:
    void onButtonClicked();

private:
    QDateEdit* dateEdit;
};


#endif
