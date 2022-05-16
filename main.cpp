#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>
#include <QObject>
#include <QScopedPointer>
#include <QTimer>
#include <QQmlContext>

#include "XFileManagement.h"
#include "XObjectManagement.h"
#include "XTestFunction.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
	QGuiApplication app(argc, argv);

	QQuickView m_view;
	const QUrl url(QStringLiteral("qrc:/main.qml"));
	QObject::connect(m_view.engine(), &QQmlEngine::quit, &m_view, &QWindow::close);

	app.setWindowIcon(QIcon(":/resource/icon/windeploy.ico"));
	m_view.setTitle("QtWinDeployer Version 1");
	m_view.setResizeMode(QQuickView::SizeRootObjectToView);
	m_view.setMaximumHeight(800);
	m_view.setMaximumWidth(600);
	m_view.setMinimumHeight(800);
	m_view.setMinimumWidth(600);
	m_view.setSource(url);
	m_view.show();

	_obj.setQuickView(&m_view);
	_file.init();

	XTestFunction x_function;
	m_view.rootContext()->setContextProperty("x_function", &x_function);

	return app.exec();
}
