#ifndef XOBJECTMANAGEMENT_H
#define XOBJECTMANAGEMENT_H

#include <QObject>
#include <QString>
#include <QQuickView>
#include <QQuickItem>
#include <QVariant>

class XObjectManagement
{
public:
	XObjectManagement(QQuickView * view = nullptr);

public:
	void setQuickView(QQuickView* view);
	void set(QString objectName, const char* propertyName, QVariant value);
	QVariant get(QString objectName, const char* propertyName);

	QQuickView* object();

private:
	QQuickView * m_view;
	bool IsViewInit;
};

extern XObjectManagement _obj;

#endif // XOBJECTMANAGEMENT_H
