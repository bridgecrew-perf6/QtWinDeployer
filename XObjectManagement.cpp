#include "XObjectManagement.h"

XObjectManagement _obj;

XObjectManagement::XObjectManagement(QQuickView* view)
{
	if(view != nullptr) {
		this->m_view = view;
		this->IsViewInit = true;
	}
}

QQuickView* XObjectManagement::object() {
	return m_view;
}

void XObjectManagement::setQuickView(QQuickView *view) {
	if(!this->IsViewInit){
		this->m_view = view;
		this->IsViewInit = true;
		return;
	}
	qDebug() << QString("setQuickView its not nullptr [XObjectManagement]");
}

void XObjectManagement::set(QString objectName, const char *propertyName, QVariant value) {
	this->m_view->findChild<QObject*>(objectName)->setProperty(propertyName, value);
}

QVariant XObjectManagement::get(QString objectName, const char* propertyName) {
	return this->m_view->findChild<QObject*>(objectName)->property(propertyName);
}
