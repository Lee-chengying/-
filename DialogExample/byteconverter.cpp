#include "byteconverter.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

ByteConverter::ByteConverter(QWidget *parent)
    : QDialog(parent)
{
    // 建立排版管理器
    QVBoxLayout* mainLayout   = new QVBoxLayout(this);
    QGridLayout* editLayout   = new QGridLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // 建立標籤與輸入框
    QLabel* decLabel = new QLabel(tr("Decimal"));
    QLabel* hexLabel = new QLabel(tr("Hex"));
    QLabel* binLabel = new QLabel(tr("Binary"));

    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    // 加入網格排版
    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit,  0, 1);
    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit,  1, 1);
    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit,  2, 1);

    // 建立 Exit 按鈕並加入水平排版
    QPushButton* exitButton = new QPushButton(tr("Exit"));
    buttonLayout->addStretch();
    buttonLayout->addWidget(exitButton);

    // 連接 Exit 按鈕點擊信號到 QDialog::accept
    connect(exitButton, SIGNAL(clicked()), this, SLOT(accept()));

    // 連接三個輸入框的文字改變信號
    connect(decEdit, SIGNAL(textChanged(const QString&)),
            this, SLOT(decChanged(const QString&)));
    connect(hexEdit, SIGNAL(textChanged(const QString&)),
            this, SLOT(hexChanged(const QString&)));
    connect(binEdit, SIGNAL(textChanged(const QString&)),
            this, SLOT(binChanged(const QString&)));
}

ByteConverter::~ByteConverter()
{
}

// 十進制轉換
void ByteConverter::decChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok);
    if (ok)
    {
        hexEdit->setText(QString::number(num, 16));
        binEdit->setText(QString::number(num, 2));
    }
    else
    {
        hexEdit->setText("");
        binEdit->setText("");
    }
}

// 十六進制轉換
void ByteConverter::hexChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok, 16);
    if (ok)
    {
        decEdit->setText(QString::number(num, 10));
        binEdit->setText(QString::number(num, 2));
    }
    else
    {
        decEdit->setText("");
        binEdit->setText("");
    }
}

// 二進制轉換
void ByteConverter::binChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok, 2);
    if (ok)
    {
        hexEdit->setText(QString::number(num, 16));
        decEdit->setText(QString::number(num, 10));
    }
    else
    {
        hexEdit->setText("");
        decEdit->setText("");
    }
}