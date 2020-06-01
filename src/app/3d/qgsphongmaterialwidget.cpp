/***************************************************************************
  qgsphongmaterialwidget.cpp
  --------------------------------------
  Date                 : July 2017
  Copyright            : (C) 2017 by Martin Dobias
  Email                : wonder dot sk at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "qgsphongmaterialwidget.h"

#include "qgsmaterialsettings.h"


QgsPhongMaterialWidget::QgsPhongMaterialWidget( QWidget *parent )
  : QWidget( parent )
{
  setupUi( this );
  cbxMaterialType->addItem("Flat colors");
  cbxMaterialType->addItem("Diffuse texture");

  setMaterial( QgsMaterialSettings() );

  connect( btnDiffuse, &QgsColorButton::colorChanged, this, &QgsPhongMaterialWidget::changed );
  connect( btnAmbient, &QgsColorButton::colorChanged, this, &QgsPhongMaterialWidget::changed );
  connect( btnSpecular, &QgsColorButton::colorChanged, this, &QgsPhongMaterialWidget::changed );
  connect( spinShininess, static_cast<void ( QDoubleSpinBox::* )( double )>( &QDoubleSpinBox::valueChanged ), this, &QgsPhongMaterialWidget::changed );
  connect( textureFile, &QgsFileWidget::fileChanged, this, &QgsPhongMaterialWidget::changed );
  connect( cbxMaterialType, &QComboBox::currentTextChanged, this, &QgsPhongMaterialWidget::changed );
}

void QgsPhongMaterialWidget::setDiffuseVisible( bool visible )
{
  lblDiffuse->setVisible( visible );
  btnDiffuse->setVisible( visible );
}

bool QgsPhongMaterialWidget::isDiffuseVisible() const
{
  return btnDiffuse->isVisible();
}

void QgsPhongMaterialWidget::setMaterial( const QgsMaterialSettings &material )
{
  btnDiffuse->setColor( material.diffuse() );
  btnAmbient->setColor( material.ambient() );
  btnSpecular->setColor( material.specular() );
  spinShininess->setValue( material.shininess() );
  textureFile->setFilePath( material.texturePath() );
  switch (material.materialType()) {
  case QgsMaterialSettings::FLAT_COLORS:
    cbxMaterialType->setCurrentIndex(0);
    break;
  case QgsMaterialSettings::DIFFUSE_TEXTURE:
    cbxMaterialType->setCurrentIndex(1);
    break;
  default:
    cbxMaterialType->setCurrentIndex(0);
    break;
  }
}

QgsMaterialSettings QgsPhongMaterialWidget::material() const
{
  QgsMaterialSettings m;
  if (cbxMaterialType->currentIndex() == 0) m.setMaterialType(QgsMaterialSettings::FLAT_COLORS);
  else if (cbxMaterialType->currentIndex() == 1) m.setMaterialType(QgsMaterialSettings::DIFFUSE_TEXTURE);
  m.setDiffuse( btnDiffuse->color() );
  m.setAmbient( btnAmbient->color() );
  m.setSpecular( btnSpecular->color() );
  m.setShininess( spinShininess->value() );
  m.setTexturePath( textureFile->filePath() );
  return m;
}
