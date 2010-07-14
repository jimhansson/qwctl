// -*- mode:c++; indent-tabs-mode:nil; -*-

#include "qwctlapp.h"

#include "qwctl_proxy.h"

#include <iostream>
#include <unistd.h>
#include <assert.h>

#include <QtGui/QApplication>


// In-file definitions of the ui-methods, we want to talk to the proxy.
// ---------------------------------------------------------------------------
void
QWCtlAppUi::setProxyObject(QWCtl* proxy)
{
  _qwctlproxy = proxy;
}

void
QWCtlAppUi::on_buttonSetSize_clicked()
{

  if (_qwctlproxy) {
    qDebug() << __func__;
    _qwctlproxy->setSize(700,500);
  } else {
    qDebug() << "_qwctlproxy not set, operation ignored";
  }
}

void
QWCtlAppUi::on_buttonSetPosition_clicked()
{
  if (_qwctlproxy) {
    qDebug() << __func__;
    _qwctlproxy->setPosition(200,200);
  } else {
    qDebug() << "_qwctlproxy not set, operation ignored";
  }
}


int
main(int ac, char** av)
{
  QApplication application(ac, av);

  // Create the controller proxy, the accessor to the adaptor used by the
  // clients controlled by this app. (The adaptor attaches itself to the
  // clients main window, if any, and adjusts the size and position).
  QWCtl* qwctlproxy = new QWCtl("se.liu.lysator.qwctl", "/qwctl",
                                QDBusConnection::sessionBus(), NULL);

  // If the client is running, set the size to "nothing" from start and see
  // what happens. The client ui should be resized to its minimal geometry.
  qwctlproxy->setSize(0,0);

  // Start controller ui and set the proxy object. It is controller from
  // within the ui-slots.
  QWCtlAppUi* ui = new QWCtlAppUi;
  ui->setProxyObject(qwctlproxy);
  ui->show();

  return application.exec();
}
