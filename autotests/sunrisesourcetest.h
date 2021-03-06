/*
 * SPDX-FileCopyrightText: 2020-2021 Han Young <hanyoung@protonmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include <QSignalSpy>
#include <QTest>
#include <kweathercore/sunrisesource.h>
using namespace KWeatherCore;
class SunriseSourceTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase();
    void testFetch();

private:
    SunriseSource *d;
    QSignalSpy *finished_spy;
    QSignalSpy *networkError_spy;
};
