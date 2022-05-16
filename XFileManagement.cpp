#include "XFileManagement.h"

XFileManagement _file;

XFileManagement::XFileManagement() {

}

XFileManagement::~XFileManagement() {

}

QString XFileManagement::get_dir(QString filename) {
	QString directory;
	if(filename.isEmpty() == true)
		directory = QDir::currentPath();

	if(filename.isEmpty() == false)
		directory = QString("%1/%2").arg(QDir::currentPath()).arg(filename);

	return directory;
}

QVector<QString> XFileManagement::get_dirFiles(QString dir, QString format) {
	QDir directory(dir);
	QStringList list = directory.entryList({format}, QDir::Files);
	QVector<QString> m_list;
	foreach(QString filename, list)
		m_list.append(filename);
	return m_list;
}

void XFileManagement::init()
{
	// TODO: signal & slot connections
	QObject::connect(_obj.object()->rootObject(), SIGNAL(updateSettingQML()), this, SLOT(slot_updateSetting()));
	QObject::connect(_obj.object()->rootObject(), SIGNAL(textFilterQML(QString, QString)), this, SLOT(slot_textFilter(QString, QString)));

	// TODO: if file json is not existed in application directory
	QFile m_file;
	m_file.setFileName(this->get_dir("setting.json"));

	if(exists(this->get_dir("setting.json")) == false)
	{
		m_file.open(QFile::WriteOnly | QFile::Text);

		QJsonObject m_json;

		QJsonObject windeployerObject;
		windeployerObject.insert("X64", "null");
		windeployerObject.insert("X32", "null");

		QJsonObject directoryObject;
		directoryObject.insert("exe", "null");
		directoryObject.insert("qml", "null");
		directoryObject.insert("export", "null");

		QJsonObject appObject;
		appObject.insert("useX64", true);

		m_json.insert("windeployer", windeployerObject);
		m_json.insert("directorys", directoryObject);
		m_json.insert("app", appObject);

		// TODO: create data json
		QJsonDocument m_jsonDocument(m_json);

		// TODO: write json data in file
		m_file.write(m_jsonDocument.toJson());
	}

	// TODO: if find file in directory
	if(exists(this->get_dir("setting.json")) == true)
	{
		m_file.open(QFile::ReadOnly | QFile::Text);

		QJsonDocument m_jsonDocument = QJsonDocument::fromJson(m_file.readAll());
		QJsonObject jsonObject = m_jsonDocument.object();

		_obj.set("obj_txt_deploy64",	"text",	jsonObject.value("windeployer").toObject().value("X64").toString());
		_obj.set("obj_txt_deploy32",	"text",	jsonObject.value("windeployer").toObject().value("X32").toString());
		_obj.set("obj_txt_exe",			"text",	jsonObject.value("directorys").toObject().value("exe").toString());
		_obj.set("obj_txt_qml",			"text",	jsonObject.value("directorys").toObject().value("qml").toString());
		_obj.set("obj_txt_export",		"text",	jsonObject.value("directorys").toObject().value("export").toString());
		_obj.set("obj_switch_platform", "isActive", jsonObject.value("app").toObject().value("useX64").toBool());
	}

	// TODO: close file
	m_file.close();
}

void XFileManagement::updateSetting() {
	QFile m_file(this->get_dir("setting.json"));
	// TODO: check file is currently open
	if(!m_file.open(QFile::WriteOnly | QFile::Text)) {
		qDebug() << "file cant open.";
		return;
	}

	QJsonObject m_json;

	QJsonObject windeployerObject;
	windeployerObject.insert("X64", _obj.get("obj_txt_deploy64", "text").toString());
	windeployerObject.insert("X32", _obj.get("obj_txt_deploy32", "text").toString());

	QJsonObject directoryObject;
	directoryObject.insert("exe", _obj.get("obj_txt_exe", "text").toString());
	directoryObject.insert("qml", _obj.get("obj_txt_qml", "text").toString());
	directoryObject.insert("export", _obj.get("obj_txt_export", "text").toString());

	QJsonObject appObject;
	appObject.insert("useX64", _obj.get("obj_switch_platform", "isActive").toBool());

	m_json.insert("windeployer", windeployerObject);
	m_json.insert("directorys", directoryObject);
	m_json.insert("app", appObject);

	// TODO: create data json
	QJsonDocument m_jsonDocument(m_json);

	// TODO: write json data in file
	m_file.write(m_jsonDocument.toJson());
	m_file.close();

	QString exeFileDir = _obj.get("obj_txt_exe", "text").toString();
	QString exeFilename = exeFileDir.split("/").at(exeFileDir.split("/").size() - 1);

	QString cmd;
	// ./././windeployqt.exe --qmldir <qml_dir> <exe_dir> -verbose=2
	if(_obj.get("obj_switch_platform", "isActive").toBool() == true)
		cmd = QString("%1 --qmldir %2/ %3/%4 -verbose=2").arg(
						  _obj.get("obj_txt_deploy64", "text").toString()).arg(
						  _obj.get("obj_txt_export", "text").toString()).arg(
						  _obj.get("obj_txt_export", "text").toString()).arg(
						exeFilename);
	else
		cmd = QString("%1 --qmldir %2/ %3/%4 -verbose=2").arg(
						  _obj.get("obj_txt_deploy32", "text").toString()).arg(
						  _obj.get("obj_txt_export", "text").toString()).arg(
						  _obj.get("obj_txt_export", "text").toString()).arg(
						exeFilename);

	_obj.set("obj_txt_command", "text", cmd);
}

void XFileManagement::useX64(bool value) {
	QFile m_file(this->get_dir("setting.json"));

	// TODO: check file is currently open
	if(!m_file.open(QFile::WriteOnly | QFile::Text)) {
		qDebug() << "file cant open.";
		return;
	}

	QJsonObject m_json;

	QJsonObject windeployerObject;
	windeployerObject.insert("X64", _obj.get("obj_txt_deploy64", "text").toString());
	windeployerObject.insert("X32", _obj.get("obj_txt_deploy32", "text").toString());

	QJsonObject directoryObject;
	directoryObject.insert("exe", _obj.get("obj_txt_exe", "text").toString());
	directoryObject.insert("qml", _obj.get("obj_txt_qml", "text").toString());
	directoryObject.insert("export", _obj.get("obj_txt_export", "text").toString());

	QJsonObject appObject;
	appObject.insert("useX64", _obj.get("obj_switch_platform", "isActive").toBool());

	m_json.insert("windeployer", windeployerObject);
	m_json.insert("directorys", directoryObject);
	m_json.insert("app", appObject);

	// TODO: create data json
	QJsonDocument m_jsonDocument(m_json);

	// TODO: write json data in file
	m_file.write(m_jsonDocument.toJson());
	m_file.close();


	//============================================================
	m_file.open(QFile::ReadOnly | QFile::Text);
	QJsonDocument m_document = QJsonDocument::fromJson(m_file.readAll());
	m_file.close();
}

//======================================================================
// TODO: signals and slots

void XFileManagement::slot_updateSetting() {
	this->updateSetting();
}

void XFileManagement::slot_textFilter(QString objectName, QString text) {

	// TODO: if not found file:///
	if(XString::toString(text).find("file:///") == std::string::npos) {
		_obj.set(objectName, "text", text);
		return;
	}

	// TODO: if find file:///
	if(XString::toString(text).find("file:///") != std::string::npos) {
		text = text.mid(QString("file:///").length(), QString(text).length());
		_obj.set(objectName, "text", text);
		return;
	}
}















