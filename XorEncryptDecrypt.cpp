#include "XorEncryptDecrypt.h"

void XorEncrypt(const QString &fileName, const QString &str, const char &key)
{
    QString strToEncrypt = getXorEncryptDecrypt(str, key);
    QByteArray dataArray = qstringToByte(strToEncrypt);
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(0, "错误", QObject::tr("指定的加密文件%1有误！").arg(fileName), QMessageBox::Yes);
    }
    file.write(dataArray);
    file.close();
}

QString XorDecrypt(const QString &fileName, const char &key)
{
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(0, "错误", QObject::tr("指定的解密文件%1有误！").arg(fileName), QMessageBox::Yes);
    }
    QByteArray dataArray = file.readAll();
    QString strToDecrypt = byteToQString(dataArray);
    file.close();

    QString dataAlreadyDecrypt = getXorEncryptDecrypt(strToDecrypt, key);
    return dataAlreadyDecrypt;
}

QString getXorEncryptDecrypt(const QString &str, const char &key)
{
  QString result;
  QByteArray bs = qstringToByte(str);

  for(int i=0; i<bs.size(); i++){
    bs[i] = bs[i] ^ key;
  }

  result = byteToQString(bs);
  return result;
}

QString byteToQString(const QByteArray &byte)
{
  QString result;
  if(byte.size() > 0){
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    result = codec->toUnicode(byte);
  }

  return result;
}

QByteArray qstringToByte(const QString &strInfo)
{
  QByteArray result;
  if(strInfo.length() > 0){
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    result = codec->fromUnicode(strInfo);
  }

  return result;
}
