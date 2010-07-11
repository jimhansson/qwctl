// -*- mode:c++; indent-tabs-mode:nil; -*-

#include "client.h"

#include "qwctl_adaptor.h"

#include <QtGui>
#include <QtCore/QVariantMap>
#include <QtCore/QDebug>

int
main(int ac, char** av)
{
  QApplication application(ac, av);

  // Create a new adaptor, which takes the current qapplication as
  // argument. The adaptor always takes a QObject and treat it as its parents.
  QWCtlAdaptor* adaptor = new QWCtlAdaptor(&application);
  // Setup the DBus connection framework. First we need a connection to the bus.
  QDBusConnection connection = QDBusConnection::sessionBus();
  // Register a suitable service on the connection.
  connection.registerService("se.liu.lysator.qwctl");
  // Register the object which shall respond to messages.
  connection.registerObject("/client1", adaptor);

  ClientUi* ui = new ClientUi;
  ui->show();

  const int rval = application.exec();
  delete adaptor;
  return rval;
}
