#include "DaoxyQSSUtils.h"

#include <QString>
#include <QFile>

QString DaoxyQSSUtils::getStyleSheet(const QString &sheetName)
{
    QFile file(":/qss/" + sheetName + ".qss");

    if (!file.open(QFile::ReadOnly))
    {
        return QString();
    }

    QString styleSheet = QString::fromLatin1(file.readAll());
    return styleSheet;
}
