// -*- mode:c++; indent-tabs-mode:nil; -*-

#ifndef QWCTLAPP_H
#define QWCTLAPP_H

#include "ui_qwctlapp.h"

#include <QtCore/QDebug>

class QWCtl;

class QWCtlAppUi : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT;
  
 public:
  QWCtlAppUi(QWidget* /*parent*/ = NULL)
      : _qwctlproxy(NULL)
  {
    setupUi(this);
  }

  ~QWCtlAppUi()
  {
  }

  void setProxyObject(QWCtl*);
      
 private Q_SLOTS:
  // Private slot for "talking" with the gui, these will be automatically
  // connected to the buttons named.
  void on_buttonSetSize_clicked();
  void on_buttonSetPosition_clicked();
  
 private:
  QWCtl* _qwctlproxy;
};

#endif
