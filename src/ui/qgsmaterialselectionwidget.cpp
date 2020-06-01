#include "qgsmaterialselectionwidget.h"
#include "ui_qgsmaterialselectionwidget.h"

QgsMaterialSelectionWidget::QgsMaterialSelectionWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QgsMaterialSelectionWidget)
{
  ui->setupUi(this);
}

QgsMaterialSelectionWidget::~QgsMaterialSelectionWidget()
{
  delete ui;
}
