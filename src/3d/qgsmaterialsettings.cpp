/***************************************************************************
  qgsphongmaterialsettings.cpp
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

#include "qgsmaterialsettings.h"

#include "qgssymbollayerutils.h"


void QgsMaterialSettings::readXml( const QDomElement &elem )
{
  mAmbient = QgsSymbolLayerUtils::decodeColor( elem.attribute( QStringLiteral( "ambient" ) ) );
  mDiffuse = QgsSymbolLayerUtils::decodeColor( elem.attribute( QStringLiteral( "diffuse" ) ) );
  mSpecular = QgsSymbolLayerUtils::decodeColor( elem.attribute( QStringLiteral( "specular" ) ) );
  mShininess = elem.attribute( QStringLiteral( "shininess" ) ).toFloat();
  mMaterialType = stringToMaterialType( elem.attribute( QStringLiteral( "material_type" ), "FLAT_COLORS" ) );
  mTexturePath = elem.attribute( QStringLiteral( "texture_path" ), "" );
}

void QgsMaterialSettings::writeXml( QDomElement &elem ) const
{
  elem.setAttribute( QStringLiteral( "ambient" ), QgsSymbolLayerUtils::encodeColor( mAmbient ) );
  elem.setAttribute( QStringLiteral( "diffuse" ), QgsSymbolLayerUtils::encodeColor( mDiffuse ) );
  elem.setAttribute( QStringLiteral( "specular" ), QgsSymbolLayerUtils::encodeColor( mSpecular ) );
  elem.setAttribute( QStringLiteral( "shininess" ), mShininess );
  elem.setAttribute( QStringLiteral( "material_type"), materialTypeToString( mMaterialType ) );
}
