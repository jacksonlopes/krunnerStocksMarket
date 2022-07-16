
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
#ifndef KPRICE_H
#define KPRICE_H

#include <QtCore>
#include <QObject>
#include <QtNetwork/QNetworkReply>

class SMPrice
{
  public:
      SMPrice() {};
      ~SMPrice() {};
      void setRegion(const QString& _region);
      void setQuoteSearch(const QString& _quoteSearch);
      QString getUrl() const;
  private:
      const QString urlFirst = QStringLiteral("https://query1.finance.yahoo.com/v7/finance/quote?lang=en-US&region=");
      const QString urlLast = QStringLiteral("&corsDomain=finance.yahoo.com&fields=marketState,longName,regularMarketPrice&symbols=");
      QString quoteSearch;
      QString region;
      QString createUrl() const;
};

#endif
