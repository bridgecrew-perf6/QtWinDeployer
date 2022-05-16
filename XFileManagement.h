#ifndef XFILEMANAGEMENT_H
#define XFILEMANAGEMENT_H

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

#include "XObjectManagement.h"
#include "XString.h"

class XFileManagement : public QObject, public QDir
{
	Q_OBJECT
public:
	XFileManagement();
	~XFileManagement();

	void init();
	void updateSetting();

	QString get_dir(QString filename = "");
	QVector<QString> get_dirFiles(QString dir, QString format);

public slots:
	void useX64(bool value);
	void slot_updateSetting();
	void slot_textFilter(QString objectName, QString text);
};

extern XFileManagement _file;

#endif // XFILEMANAGEMENT_H
