// -*- mode:c++; indent-tabs-mode:nil; -*-

#include "client.h"

#include "qwctl_adaptor.h"

#include <QtGui>
#include <QtCore>

int
main(int ac, char** av)
{
  QApplication application(ac, av);

  QString registrationObjectName;
  if (ac > 1) {
    // This is for debugging only, i.e using a different name to be able to
    // have multiple clients at the same time.
    registrationObjectName = "/" + QString(av[1]);
  } else {
    registrationObjectName = "/qwctl";
  }

  // Create a new adaptor, which takes the current qapplication as
  // argument. The adaptor always takes a QObject and treat it as its parents.
  // This whole part should go into a class which is instantiated as a static
  // object.
  QWCtlAdaptor* adaptor = new QWCtlAdaptor(&application);
  // Setup the DBus connection framework. First we need a connection to the bus.
  QDBusConnection connection = QDBusConnection::sessionBus();
  // Register a suitable service on the connection.
  connection.registerService("se.liu.lysator.qwctl");
  // Register the object which shall respond to messages.
  connection.registerObject(registrationObjectName, &application);

  ClientUi* ui = new ClientUi;
  ui->show();

  const int rval = application.exec();
  delete adaptor;
  return rval;
}
