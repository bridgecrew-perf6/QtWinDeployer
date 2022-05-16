#ifndef XTESTFUNCTION_H
#define XTESTFUNCTION_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QDir>
#include <QTimer>
#include <QProcess>

#include "XString.h"
#include "XObjectManagement.h"
#include "XFileManagement.h"

#include "json.h"

using namespace nlohmann;

class XTestFunction : public QObject
{
	Q_OBJECT
public:
	explicit XTestFunction(QObject *parent = nullptr);

	Q_INVOKABLE void test();

private:
	QScopedPointer<QTimer> pTimer;
	QScopedPointer<QProcess> process;
};

#endif // XTESTFUNCTION_H
