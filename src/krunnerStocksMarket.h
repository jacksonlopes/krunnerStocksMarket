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
#ifndef KRUNNERSTOCKSMARKET_H
#define KRUNNERSTOCKSMARKET_H

#include <QtCore>
#include <QString>
#include <QtGlobal>
#include <QJsonArray>
#include <QJsonDocument>
#include <KLocalizedString>
#include <KRunner/AbstractRunner>
#include "smconnect.h"
#include "smprice.h"

class KrunnerStocksMarket : public Plasma::AbstractRunner
{
  Q_OBJECT

  public:
     KrunnerStocksMarket(QObject *parent, const KPluginMetaData &pluginMetaData, const QVariantList &args);
     ~KrunnerStocksMarket() override;
     void match(Plasma::RunnerContext &context) override;
     //void run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match) override;
     //void createRunOptions(QWidget *widget) override;
     //void reloadConfiguration() override;
  protected Q_SLOTS:
      //void init() override;
      //void prepareForMatchSession();
      //void matchSessionFinished();
  private:
      SMConnect smCon;
      SMPrice smPrice;
      QString defaultRegion = QStringLiteral("BR");
};

#endif
