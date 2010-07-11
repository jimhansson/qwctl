// -*- mode:c++; indent-tabs-mode:nil; -*-

#ifndef CLIENTUI_H
#define CLIENTUI_H

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

  void setDBusAdaptor(QObject* adaptor)
  {
    connect(adaptor,SIGNAL(setSize(int,int)), this,SLOT(setSize(int,int)));
    connect(adaptor,SIGNAL(setPosition(int,int)), this,SLOT(setPosition(int,int)));
  }

 public Q_SLOTS:
  void setSize(int x, int y)
  {
    _appendToTextBrowser(x,y);
  }

  void setPosition(int x, int y)
  {
    _appendToTextBrowser(x,y);
  }

 private Q_SLOTS:
  // Private slot for "talking" with the gui, these will be automatically
  // connected to the buttons named.
  void on_buttonFoo_clicked() { qDebug() << __func__; }
  void on_buttonBar_clicked() { qDebug() << __func__; }
  
 private:
  void _appendToTextBrowser(int x, int y)
  {
    QString text = QString("%1(%2,%3)").arg(__func__).arg(x).arg(y);
    textBrowser->append(text);
  }

};

#endif
