#include "XTestFunction.h"

XTestFunction::XTestFunction(QObject *parent)
	: QObject{parent}
{

}

bool isRunning(const QString &process) {
  QProcess tasklist;
  tasklist.start(
		"tasklist",
		QStringList() << "/NH"
					  << "/FO" << "CSV"
					  << "/FI" << QString("IMAGENAME eq %1").arg(process));
  tasklist.waitForFinished();
  QString output = tasklist.readAllStandardOutput();
  return output.startsWith(QString("\"%1").arg(process));
}

void XTestFunction::test() {
	_obj.set("obj_lbl_status", "text", QString("<font color=\"%1\"><b>Initializing...</b></font>").arg("#ff6a00"));

	QString qmlDir = _obj.get("obj_txt_qml", "text").toString();
	QString exeFilename = _obj.get("obj_txt_exe", "text").toString();
	QString exportDir = _obj.get("obj_txt_export", "text").toString();

	// TODO: copy and paste QML Files...
	{
		QVector<QString> m_files1 = _file.get_dirFiles(qmlDir, "*.QML");
		foreach(QString filename, m_files1)
		{
			if(!_file.exists(exportDir + "/" + filename))
				QFile::copy(QString("%1/%2").arg(qmlDir).arg(filename), QString("%1/%2").arg(exportDir).arg(filename));
			else
			{
				// TODO: if found file in export directory we should remove it
				QFile::remove(QString("%1/%2").arg(exportDir).arg(filename));

				// TODO: we should here copy of file and paste last outpot file in export directory
				QFile::copy(QString("%1/%2").arg(qmlDir).arg(filename), QString("%1/%2").arg(exportDir).arg(filename));
			}
		}
	}


	{
		QString filename = exeFilename.split("/").at(exeFilename.split("/").size() - 1);

		// TODO: copy and paste exe Files...
		if(!_file.exists(exportDir + "/" + filename))
			QFile::copy(QString("%1").arg(exeFilename), QString("%1/%2").arg(exportDir).arg(filename));
		else
		{
			// TODO: if found file in export directory we should remove it
			QFile::remove(QString("%1/%2").arg(exportDir).arg(filename));

			// TODO: we should here copy of file and paste last outpot file in export directory
			QFile::copy(QString("%1").arg(exeFilename), QString("%1/%2").arg(exportDir).arg(filename));
		}
	}

	// TODO: run process
	{
		QString filename = exeFilename.split("/").at(exeFilename.split("/").size() - 1);

		QString cmd;
		cmd = _obj.get("obj_txt_command", "text").toString();

		if(_file.exists(QString("%1/compile.bat").arg(exportDir)))
			QFile::remove(QString("%1/compile.bat").arg(exportDir));
		else
		{
			QFile m_file(QString("%1/compile.bat").arg(exportDir));
			m_file.open(QFile::WriteOnly);
			m_file.write(QString("start %1").arg(cmd).toUtf8());
			m_file.close();
		}

//		QScopedPointer<QProcess> process { new QProcess };
		process.reset(new QProcess);
		process->setProgram(QString("%1/compile.bat").arg(exportDir));
		process->start();
		process->waitForFinished();

		pTimer.reset(new QTimer);
		pTimer->setSingleShot(false);
		pTimer->start(1000);
		QObject::connect(pTimer.data(), &QTimer::timeout, [&]()
		{
			static int index = 0;

			if(isRunning("windeployqt.exe") == true) {
				// still running
				_obj.set("obj_lbl_status", "text", QString("<font color=\"%1\">Application <b>Deploying...</b></font>").arg("#ff0000"));
				_obj.set("obj_lbl_second", "text", QString("<font color=\"%1\">[%2 Second]</font>").arg("#ff0000").arg(index));
			}
			else {
				// on finished
				_obj.set("obj_lbl_status", "text", QString("<font color=\"#59ff00\"><b>Ready.</b></font>"));
				_obj.set("obj_lbl_second", "text", QString(""));

				QFile::remove(QString("%1/compile.bat").arg(exportDir));

				process->close();
				pTimer->stop();
			}
			index++;
		});
	}
}
