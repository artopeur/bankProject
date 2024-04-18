#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

    QByteArray token;
public slots:
    void fetchBalance(int atmId, QByteArray token);
private slots:
    void twentyHandler();
    void fiftyHandler();
    void hundredHandler();
    void twoHundredHandler();
    void fiveHundredHandler();
    void saveBillsToAtm();
    void atmManagerFinished(QNetworkReply*);
    void getBalance(QNetworkReply *reply);
    void clickHandler();
    void selectedLineEdit();

private:
    Ui::admin *ui;
    QNetworkAccessManager *atmManager;
    QNetworkReply *reply;
    QByteArray myToken;
    int balance;
    int twenty = 0;
    int dataTwenty;
    int fifty = 0;
    int dataFifty;
    int hundred = 0;
    int dataHundred;
    int twoHundred = 0;
    int dataTwoHundred;
    int fiveHundred = 0;
    int dataFiveHundred;
    int atmId = 1;
    int state = 0;
    QString num = 0;
};

#endif // ADMIN_H
