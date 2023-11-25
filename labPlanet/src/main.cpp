// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include <iostream>
#include <QQmlContext>
#include <QtQml>
#include <QObject>
#include "app_environment.h"
#include "import_qml_components_plugins.h"
#include "import_qml_plugins.h"
#include "model/main_model.h"

/*float current_u = 220 * sqrt(2);
float M_engine = 0;
float M_aft_e = 0;
float M_load = 0;
float L = 0.33;
float R = 2.2;
float J_d = 1.2e-5;
float K = 1 / R;
float T = L / R;
float u_nom = 220 * sqrt(2);
float k_v = 0.05;
float k_e = 1e-2;
float k_m = 1415e-5;
float i = 10;
float c = 3e4;
float eta = 0.5;
float J_load = 1;
float delta = 0.005;
const float DT = 0.00005;
*/


int main(int argc, char *argv[])
{
    set_qt_environment();

    // Create a QGuiApplication object
    QGuiApplication app(argc, argv);
    qmlRegisterType<ElectromechanicalSystem>("com.example", 1, 0, "ElectromechanicalSystem");

    // Create a QQmlApplicationEngine object
    QQmlApplicationEngine engine;

    // Load the QML file
    const QUrl url(u"qrc:content/App.qml"_qs);
    engine.load(url);




    // Check if the QML file was loaded successfully
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
