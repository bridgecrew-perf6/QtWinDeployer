#include "XString.h"

QString XString::toString(std::string message) {
	return QString::fromStdString(message);
}

std::string XString::toString(QString message) {
	return message.toStdString();
}
