#ifndef BYTECONVERTER_H
#define BYTECONVERTER_H

#include <QDialog>

class QLineEdit;

class ByteConverter : public QDialog
{
    Q_OBJECT

public:
    ByteConverter(QWidget *parent = 0);
    ~ByteConverter();

private:
    QLineEdit* decEdit;
    QLineEdit* hexEdit;
    QLineEdit* binEdit;

private slots:
    void decChanged(const QString&);
    void hexChanged(const QString&);
    void binChanged(const QString&);
};

#endif // BYTECONVERTER_H