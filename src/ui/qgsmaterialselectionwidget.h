#ifndef QGSMATERIALSELECTIONWIDGET_H
#define QGSMATERIALSELECTIONWIDGET_H

#include <QWidget>

namespace Ui {
class QgsMaterialSelectionWidget;
}

class QgsMaterialSelectionWidget : public QWidget
{
  Q_OBJECT

public:
  explicit QgsMaterialSelectionWidget(QWidget *parent = nullptr);
  ~QgsMaterialSelectionWidget();

private:
  Ui::QgsMaterialSelectionWidget *ui;
};

#endif // QGSMATERIALSELECTIONWIDGET_H
