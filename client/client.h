// -*- mode:c++; indent-tabs-mode:nil; -*-

#ifndef CLIENT_H
#define CLIENT_H

#include "ui_client.h"

#include <QtCore/QDebug>

class ClientUi : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT;
  
 public:
  ClientUi(QWidget* /*parent*/ = NULL)
  {
    setupUi(this);
  }

  ~ClientUi()
  {
  }

 private Q_SLOTS:
  // Private slot for "talking" with the gui, these will be automatically
  // connected to the buttons named.
  void on_buttonFoo_clicked()
  {
    qDebug() << __func__;
    _appendToTextBrowser(__func__);
  }
  void on_buttonBar_clicked()
  {
    qDebug() << __func__;
    _appendToTextBrowser(__func__);
  }
  
 private:
  // Appends text to the client ui's textBrowser. Debugging only.
  void _appendToTextBrowser(QString text)
  {
    QString append_text = QString("%1(%2)").arg(__func__).arg(text);
    textBrowser->append(append_text);
  }
  
};

#endif
