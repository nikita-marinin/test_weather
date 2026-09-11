#include "InputDate.h"
#include <QPushButton>
#include <QDate>
#include <QDateEdit>
#include <QHBoxLayout>

InputDate::InputDate(QWidget *parent) : QWidget(parent)
{
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    dateEdit->setDisplayFormat("dd.MM.yyyy");
    QPushButton* button = new QPushButton("Применить", this);
    QHBoxLayout* inputLayout = new QHBoxLayout(this);
    inputLayout->addWidget(dateEdit);
    inputLayout->addWidget(button);
    connect(button, &QPushButton::clicked, this, &InputDate::onButtonClicked);
}

void InputDate::onButtonClicked()
{
    emit inputDate(dateEdit->date());
}
