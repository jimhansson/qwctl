// -*- mode:c++; indent-tabs-mode:nil; -*-

#include "qwctlapp.h"
#include "ui_qwctlapp.h"
#include "clients_model.h"

#include "qwctl_proxy.h"

#include <iostream>
#include <unistd.h>
#include <assert.h>

#include <QtCore/QRegExp>

#include <QtGui/QApplication>

#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnectionInterface>

// Misc functions.
// ---------------------------------------------------------------------------
inline bool
parseTwoCommaSeparatedNumbers(const QString& text, int& a, int& b)
{
  static QRegExp rx("^(\\d{1,4}),(\\d{1,4})$");
  if (rx.exactMatch(text)) {
    a = rx.cap(1).toInt();
    b = rx.cap(2).toInt();
    return true;
  } else {
    return false;
  }
}

// In-file definitions of the ui-methods, we want to talk to the proxy.
// ---------------------------------------------------------------------------
QWCtlAppUi::QWCtlAppUi(QWidget* /*parent*/ = NULL)
  : _qwctlproxy(NULL), ui(new Ui::MainWindow),
  clients_model(new DBusClientsModel())
{
  ui->setupUi(this);
  ui->clientTreeView->setModel(clients_model.data());
}

QWCtlAppUi::~QWCtlAppUi()
{
}

void
QWCtlAppUi::setProxyObject(QWCtl* proxy)
{
  _qwctlproxy = proxy;
}

void
QWCtlAppUi::on_buttonSetSize_clicked()
{
  if (_qwctlproxy) {
    int w, h;
    if (parseTwoCommaSeparatedNumbers(ui->lineEditSize->text(),w,h)) {
      qDebug() << "Size: " << w << "," << h;
      _qwctlproxy->setSize(w,h);
    } else {
      qDebug() << __func__ << ": Incorrect format for size";
    }
  } else {
    qDebug() << "_qwctlproxy not set, operation ignored";
  }
}

void
QWCtlAppUi::on_buttonSetPosition_clicked()
{
  if (_qwctlproxy) {
    int x, y;
    if (parseTwoCommaSeparatedNumbers(ui->lineEditPosition->text(),x,y)) {
      qDebug() << "Pos: " << x << "," << y;
      _qwctlproxy->setPosition(x,y);
    } else {
      qDebug() << __func__ << ": Incorrect format for position";
    }
  } else {
    qDebug() << "_qwctlproxy not set, operation ignored";
  }
}

void
QWCtlAppUi::on_actionQuit_triggered(bool /*checked_or_not*/)
{
  qDebug() << __func__ << ": Quiting via actionQuit";
  QMainWindow::close();
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
