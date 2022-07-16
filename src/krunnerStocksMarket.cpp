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
#include "krunnerStocksMarket.h"

KrunnerStocksMarket::KrunnerStocksMarket(QObject *parent, const KPluginMetaData &pluginMetaData, const QVariantList &args)
: Plasma::AbstractRunner(parent, pluginMetaData, args) {}

KrunnerStocksMarket::~KrunnerStocksMarket() {}

void KrunnerStocksMarket::match(Plasma::RunnerContext& context)
{
    QString query = context.query();

    if (query.length() < 2) {
        return;
    }

    if (query.contains(QStringLiteral("*"))) {
        query.remove(query.length() - 1, query.length());
        query.append(QStringLiteral(".SA"));
    }

    smPrice.setRegion(defaultRegion);
    smPrice.setQuoteSearch(query);

    const QString jsonStringData = QString::fromUtf8(smCon.readData(smPrice.getUrl()));

    if (jsonStringData.isEmpty()) {
        return;
    }

    const QJsonObject jsonObjectData = QJsonDocument::fromJson(jsonStringData.toUtf8()).object();
    const QJsonArray quoteResponse = jsonObjectData.value(QString::fromUtf8("quoteResponse")).toObject().value(QString::fromUtf8("result")).toArray();
    const QJsonObject quoteRespondeObj = quoteResponse[0].toObject();
    const QString marketState = (quoteRespondeObj.value(QString::fromUtf8("marketState")).toVariant().toString())
          .compare(QStringLiteral("REGULAR")) == 0 ? QStringLiteral("O") : QStringLiteral("C");
    const QString longName = quoteRespondeObj.value(QString::fromUtf8("longName")).toVariant().toString();
    const QString regularMarketPrice = quoteRespondeObj.value(QString::fromUtf8("regularMarketPrice")).toVariant().toString();

    if (regularMarketPrice.isEmpty()) {
        return;
    }

    QList<Plasma::QueryMatch> matches;
    Plasma::QueryMatch match(this);

    match.setText(i18n("%1 | $ %2 %3", longName, regularMarketPrice, marketState));
    match.setData(longName);
    match.setId(longName);
    match.setIconName(QStringLiteral("homebank"));
    match.setRelevance(1.0);
    match.setType(Plasma::QueryMatch::ExactMatch);

    matches.append(match);
    context.addMatches(matches);
}

//void KrunnerStocksMarket::run(const Plasma::RunnerContext& context, const Plasma::QueryMatch& match) {}

//void KrunnerStocksMarket::createRunOptions(QWidget* widget) {}

//void KrunnerStocksMarket::reloadConfiguration() {}

//void KrunnerStocksMarket::init() {}

//void KrunnerStocksMarket::prepareForMatchSession() {}

//void KrunnerStocksMarket::matchSessionFinished() {}

K_EXPORT_PLASMA_RUNNER_WITH_JSON(KrunnerStocksMarket, "plasma-runner-krunnerstocksmarket.json");
#include "krunnerStocksMarket.moc"
