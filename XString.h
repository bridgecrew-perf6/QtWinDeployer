#ifndef XSTRING_H
#define XSTRING_H

#include <QString>
#include <QDebug>
#include <iostream>
#include <string>

using namespace std;

class XString
{
public:
	static QString toString(std::string message);
	static std::string toString(QString message);
};


#endif // XSTRING_H
