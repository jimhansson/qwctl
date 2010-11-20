
#include <QtCore/QAbstractItemModel>
//this should be forward declared instead.
#include <QtDBus/QDBusConnection>
#include <QtCore/QScopedPointer>
class DBusClientsModel : public QAbstractItemModel {
 public:
  DBusClientsModel(QObject* parent = 0, 
                   QDBusConnection::BusType usebus = QDBusConnection::SessionBus);
  ~DBusClientsModel();

  QModelIndex index(int row, int column,
                    const QModelIndex& parent) const;
  QModelIndex parent(const QModelIndex& child) const;

  int rowCount(const QModelIndex& parent) const;
  int columnCount(const QModelIndex& parent) const;
  QVariant data(const QModelIndex& index, int role) const;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role) const;

 private:
  QDBusConnection* bus;
  Q_DISABLE_COPY(DBusClientsModel);
};
