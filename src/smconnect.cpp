/*
 * This file is part of the krunnerStocksMarket project
 * Copyright (C) 2022  Jackson Lopes <jacksonlopes@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "smconnect.h"

// credits: https://karanbalkar.com/posts/sending-http-request-using-qt5
QByteArray SMConnect::readData(const QString& urlAPI)
{
    QEventLoop qEvLoop;
    QNetworkAccessManager qNam;
    QByteArray qByteReturn;

    if (urlAPI.contains(QStringLiteral("*"))) {
        return qByteReturn;
    }

    QObject::connect(&qNam, SIGNAL(finished(QNetworkReply*)), &qEvLoop, SLOT(quit()));

    url.setUrl(urlAPI);

    QNetworkRequest qNrequest(url);
    QNetworkReply *qNreply = qNam.get(qNrequest);
    qEvLoop.exec();

    if (qNreply->error() == QNetworkReply::NoError) {
        qByteReturn = qNreply->readAll();

        delete qNreply;

        return qByteReturn;
    }

    delete qNreply;

    return qByteReturn;
}
