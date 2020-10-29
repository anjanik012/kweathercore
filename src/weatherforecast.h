#pragma once
#include "dailyforecast.h"
#include "sunrise.h"
#include <QSharedData>
namespace KWeatherCore
{
class WeatherForecast : public QSharedData
{
public:
    WeatherForecast();
    WeatherForecast(QVector<DailyWeatherForecast> daily, QVector<HourlyWeatherForecast> hourly);
    const QVector<DailyWeatherForecast> &dailyWeatherForecast() const;
    QVector<DailyWeatherForecast> &dailyWeatherForecast();
    const QVector<Sunrise> &sunriseForecast() const;
    const QString &timezone() const;
    void setTimezone(const QString &timezone);
    void setTimezone(QString &&timezone);
    void setDailyWeatherForecast(const QVector<DailyWeatherForecast> &forecast);
    void setDailyWeatherForecast(QVector<DailyWeatherForecast> &&forecast);
    void setSunriseForecast(const QVector<Sunrise> &sunrise);
    void setSunriseForecast(QVector<Sunrise> &&sunrise);

    WeatherForecast &operator+=(const DailyWeatherForecast &forecast);
    WeatherForecast &operator+=(DailyWeatherForecast &&forecast);
    WeatherForecast &operator+=(const HourlyWeatherForecast &forecast);
    WeatherForecast &operator+=(HourlyWeatherForecast &&forecast);

private:
    QVector<DailyWeatherForecast> m_dailyWeatherForecast;
    QVector<Sunrise> m_sunriseForecast;
    QString m_timezone;
};
}
