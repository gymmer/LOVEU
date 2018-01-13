#ifndef XORENCRYPTDECRYPT_H
#define XORENCRYPTDECRYPT_H
#include <QTextCodec>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

void XorEncrypt(const QString &fileName, const QString &str, const char &key);
QString XorDecrypt(const QString &fileName, const char &key);

QString getXorEncryptDecrypt(const QString &, const char &);
QString byteToQString(const QByteArray &byte);
QByteArray qstringToByte(const QString &strInfo);

#endif // XORENCRYPTDECRYPT_H
