/*
 * SPDX-FileCopyrightText: 2020-2021 Han Young <hanyoung@protonmail.com>
 * SPDX-FileCopyrightText: 2020 Devin Lin <espidev@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "sunrise.h"
#include <QDateTime>
#include <QObject>
#include <kweathercore/kweathercore_export.h>
class QNetworkAccessManager;
class QNetworkReply;
namespace KWeatherCore
{
/**
 * @short The SunriseSource class can obtain the sunrise data of one location
 * for several days
 *
 * @see Sunrise
 *
 * @author Han Young <hanyoung@protonmail.com>
 */
class KWEATHERCORE_EXPORT SunriseSource : public QObject
{
    Q_OBJECT
public:
    /**
     * SunriseSource
     * @param offset from UTC, in seconds
     * @param sunrise for caching purpose
     */
    SunriseSource(double latitude,
                  double longitude,
                  int offset,
                  const std::vector<Sunrise> &sunrise = std::vector<Sunrise>(),
                  QObject *parent = nullptr);
    /**
     * start downloading data
     */
    void requestData();
    /**
     * change the offset in case of daylight time changing and something
     */
    void setOffset(int offset);
    /**
     * get the value
     * @return
     */
    const std::vector<Sunrise> &value() const
    {
        return m_sunriseVec;
    };
Q_SIGNALS:
    /**
     * network error
     */
    void networkError();
    /**
     * query finished
     */
    void finished();
private Q_SLOTS:
    void parseResults(QNetworkReply *reply);

private:
    double m_latitude, m_longitude;
    int m_offset;
    std::vector<Sunrise> m_sunriseVec;
    QNetworkAccessManager *m_manager = nullptr;

    void popDay();
};
}
