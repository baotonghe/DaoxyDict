#include "DaoxyDictHttpService.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

DaoxyDictHttpService::DaoxyDictHttpService(QObject *parent)
    : QObject(parent)
{
    m_pNetworkManager = new QNetworkAccessManager(this);
    connect(m_pNetworkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleNetworkData(QNetworkReply*)));
}

DaoxyDictHttpService::~DaoxyDictHttpService()
{
    m_pNetworkManager->deleteLater();
}

void DaoxyDictHttpService::doRequestURL(const QString &url)
{
    m_pNetworkManager->get(QNetworkRequest(QUrl(url)));
}

void DaoxyDictHttpService::handleNetworkData(QNetworkReply *networkReply)
{
    if (!networkReply->error())
    {
        QByteArray oResponse = networkReply->readAll();
        static_cast<void>(oResponse);
    }

    networkReply->deleteLater();
}
