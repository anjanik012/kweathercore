/*
 * Copyright 2020 Han Young <hanyoung@protonmail.com>
 * Copyright 2020 Devin Lin <espidev@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */
#pragma once
#include "dailyforecast.h"
#include "sunrise.h"
#include <QSharedData>
#include <kweathercore/kweathercore_export.h>
namespace KWeatherCore
{
/**
 * @short The WeatherForecast class contains the weather information of one location for days
 *
 * @see WeatherForecastSource
 *
 * @author Han Young <hanyoung@protonmail.com>
 */
class KWEATHERCORE_EXPORT WeatherForecast : public QSharedData
{
public:
    /**
     * @brief construct an empty object
     */
    WeatherForecast();
    /**
     * @brief convert to QJsonObject
     */
    QJsonObject toJson() const;
    /**
     * @brief construct from json
     */
    static QExplicitlySharedDataPointer<WeatherForecast> fromJson(QJsonObject obj);
    /**
     * @return daily weather forecast
     */
    const std::vector<DailyWeatherForecast> &dailyWeatherForecast() const;
    double latitude() const;
    double longitude() const;
    /**
     * @return the time this forecast object was created, this value won't change once constructed
     */
    const QDateTime &createdTime() const;
    /**
     * @brief internal std::vector
     * @return
     */
    std::vector<DailyWeatherForecast> &dailyWeatherForecast();
    /**
     * @brief IANA Time Zone ID
     * @return
     */
    const QString &timezone() const;
    /**
     * @brief setCoordinate
     */
    void setCoordinate(double latitude, double longitude);
    /**
     * @brief setTimezone
     * @param timezone
     */
    void setTimezone(const QString &timezone);
    /**
     * @brief setTimezone
     * @param timezone valid IANA Time Zone ID
     */
    void setTimezone(QString &&timezone);
    void setDailyWeatherForecast(const std::vector<DailyWeatherForecast> &forecast);
    void setDailyWeatherForecast(std::vector<DailyWeatherForecast> &&forecast);
    /**
     * @brief the vector should be sorted
     */
    void setSunriseForecast(const std::vector<Sunrise> &sunrise);
    /**
     * @brief overloaded version
     */
    void setSunriseForecast(std::vector<Sunrise> &&sunrise);

    /**
     * @brief merge DailyWeatherForecast
     */
    WeatherForecast &operator+=(const DailyWeatherForecast &forecast);
    /**
     * @brief overloaded version
     */
    WeatherForecast &operator+=(DailyWeatherForecast &&forecast);
    /**
     * @brief merge HourlyWeatherForecast, new day is created when required
     */
    WeatherForecast &operator+=(const HourlyWeatherForecast &forecast);
    /**
     * @brief overloaded version
     */
    WeatherForecast &operator+=(HourlyWeatherForecast &&forecast);

private:
    std::vector<DailyWeatherForecast> m_dailyWeatherForecast;
    // std::vector<Sunrise> m_sunriseForecast;
    QString m_timezone;
    double m_latitude, m_longitude;
    QDateTime m_createdTime;
};
}
