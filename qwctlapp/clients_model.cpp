
#include "clients_model.h"
#include <stdexcept>

DBusClientsModel::DBusClientsModel(QObject* parent, 
                                   QDBusConnection::BusType use_bus) : 
                                   QAbstractItemModel(parent), 
                                   bus(QDBusConnection::sessionBus()) {
  switch(use_bus) {
  case QDBusConnection::SessionBus:
    bus = QDBusConnection::sessionBus(); break;
  case QDBusConnection::SystemBus:
    bus = QDBusConnection::systemBus(); break;
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
  return createIndex(row,column,(void*)NULL);
}

int DBusClientsModel::rowCount(const QModelIndex& parent) const {
  return 0;
}

int DBusClientsModel::columnCount(const QModelIndex& parent) const {
  return 0;
}

QModelIndex DBusClientsModel::parent(const QModelIndex& child) const {
  return QModelIndex();
}

QVariant DBusClientsModel::data(const QModelIndex& index, 
                                int role) const {
  return QVariant();
}

QVariant DBusClientsModel::headerData(int section, 
                                      Qt::Orientation orientation, 
                                      int role) const {
  return QVariant();
}
