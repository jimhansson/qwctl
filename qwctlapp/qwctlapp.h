// -*- mode:c++; indent-tabs-mode:nil; -*-

#ifndef QWCTLAPP_H
#define QWCTLAPP_H

#include <QtCore/QDebug>
#include <QtCore/QScopedPointer>
#include <QtGui/QMainWindow>
class QWCtl;

namespace Ui {
  class MainWindow;
}

class QWCtlAppUi : public QMainWindow
{
  Q_OBJECT;

 public:
  QWCtlAppUi(QWidget* parent);
  ~QWCtlAppUi();
  void setProxyObject(QWCtl*);

 private Q_SLOTS:
  // Private slot for "talking" with the gui, these will be automatically
  // connected to the buttons named.
  void on_buttonSetSize_clicked();
  void on_buttonSetPosition_clicked();
  void on_actionQuit_triggered(bool);

  //void on_lineEditSize_textChanged(const QString&);
  //void on_lineEditPosition_textChanged(const QString&);

 private:
  QWCtl* _qwctlproxy;
  QScopedPointer<Ui::MainWindow> ui;
  Q_DISABLE_COPY(QWCtlAppUi)
};

#endif
