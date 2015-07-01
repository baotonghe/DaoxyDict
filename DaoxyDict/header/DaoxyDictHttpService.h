#ifndef DAOXYDICTHTTPSERVICE_H
#define DAOXYDICTHTTPSERVICE_H

#include <QObject>

class QNetworkReply;
class QNetworkAccessManager;

class DaoxyDictHttpService : public QObject
{
    Q_OBJECT
public:
    DaoxyDictHttpService(QObject *parent = 0);
    ~DaoxyDictHttpService();

    void doRequestURL(const QString &url);

private slots:
    void handleNetworkData(QNetworkReply *networkReply);

private:
    QNetworkAccessManager *m_pNetworkManager;
};

#endif // DAOXYDICTHTTPSERVICE_H
