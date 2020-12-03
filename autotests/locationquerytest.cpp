/*
 * Copyright 2020 Han Young <hanyoung@protonmail.com>
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */
#include "locationquerytest.h"

void LocationQueryTest::initTestCase()
{
    d = new LocationQuery();
}

void LocationQueryTest::testLocate()
{
    finished_spy = new QSignalSpy(d, &LocationQuery::located);
    d->locate();

    auto ret = finished_spy->wait(30000);

    // if failed to located, test fails here
    QVERIFY(ret);

    LocationQueryResult location = finished_spy->takeFirst().at(0).value<LocationQueryResult>();

    QVERIFY(!location.name().isEmpty());
}

void LocationQueryTest::testQuery()
{
    d->query(QStringLiteral("London"));

    finished_spy = new QSignalSpy(d, &LocationQuery::queryFinished);
    networkError_spy = new QSignalSpy(d, &LocationQuery::queryError);

    auto ret = finished_spy->wait(30000);

    if (ret) {
        QVERIFY(finished_spy->takeFirst().at(0).value<QVector<LocationQueryResult>>().size() > 0);
    } else {
        QVERIFY(networkError_spy->count() > 0);
    }
}
QTEST_MAIN(LocationQueryTest)
