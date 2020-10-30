/*
 * Copyright 2020 Han Young <hanyoung@protonmail.com>
 * Copyright 2020 Devin Lin <espidev@gmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */
#include "locationquery.h"
namespace KWeatherCore
{
LocationQueryResult::LocationQueryResult(double latitude, double longitude, QString toponymName, QString name, QString countryCode, QString countryName, QString geonameId)
    : m_latitude(latitude)
    , m_longitude(longitude)
    , m_toponymName(std::move(toponymName))
    , m_name(std::move(name))
    , m_countryCode(std::move(countryCode))
    , m_countryName(std::move(countryName))
    , m_geonameId(std::move(geonameId)) {};

double LocationQueryResult::latitude() const
{
    return m_latitude;
}
double LocationQueryResult::longitude() const
{
    return m_longitude;
}
const QString &LocationQueryResult::toponymName() const
{
    return m_toponymName;
}
const QString &LocationQueryResult::name() const
{
    return m_name;
}
const QString &LocationQueryResult::countryName() const
{
    return m_countryName;
}
const QString &LocationQueryResult::countryCode() const
{
    return m_countryCode;
}
const QString &LocationQueryResult::geonameId() const
{
    return m_geonameId;
}
}
