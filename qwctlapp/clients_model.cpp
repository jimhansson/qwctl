
#include "clients_model.h"
#include <stdexcept>

DBusClientsModel::DBusClientsModel(QObject* parent, 
                                   QDBusConnection::BusType use_bus) : 
                                   QAbstractItemModel(parent) {
  switch(use_bus) {
  case QDBusConnection::SessionBus:
    bus = new QDBusConnection(QDBusConnection::sessionBus()); break;
  case QDBusConnection::SystemBus:
    bus = new QDBusConnection(QDBusConnection::systemBus()); break;
  default:
    // I hate throwing exception in constructors, but it's the only way.
    throw std::invalid_argument("Can not connect to requested bus");
  }
}

DBusClientsModel::~DBusClientsModel() {
}

QModelIndex DBusClientsModel::index(int row, int column,
                                    const QModelIndex& parent) const {
  if(row < 0 || column < 0)
    return QModelIndex();
  return createIndex(row,column,(qint32) 5);
}

int DBusClientsModel::rowCount(const QModelIndex& parent) const {
  if(parent.internalId() != 5)
    return 1;
  return 0;
}

int DBusClientsModel::columnCount(const QModelIndex& parent) const {
  if(parent.internalId() != 5)
    return 2;
  return 0;
}

QModelIndex DBusClientsModel::parent(const QModelIndex& child) const {
  return QModelIndex();
}

QVariant DBusClientsModel::data(const QModelIndex& index, 
                                int role) const {
  if(role == Qt::DisplayRole)
    return QVariant(QString("something"));
  return QVariant();
}

QVariant DBusClientsModel::headerData(int section, 
                                      Qt::Orientation orientation, 
                                      int role) const {
  switch(role) {
  case Qt::DisplayRole:
    if(section == 0)
      return QVariant(QString("Name"));
  }
  return QVariant();
}
//darion    4348 11.4 91.2 7101112 5574556 pts/0 Dl   16:22   0:10 qwctlapp/qwctlapp
