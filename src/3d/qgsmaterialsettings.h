#ifndef QGSMATERIALSETTINGS_H
#define QGSMATERIALSETTINGS_H

#include "qgis_3d.h"

#include <QColor>

class QDomElement;

/**
 * \ingroup 3d
 * Basic shading material used for rendering based on the Phong shading model
 * with three color components: ambient, diffuse and specular.
 *
 * \warning This is not considered stable API, and may change in future QGIS releases. It is
 * exposed to the Python bindings as a tech preview only.
 *
 * \since QGIS 3.0
 */
class _3D_EXPORT QgsMaterialSettings
{
  public:
  enum QgsMaterialType {
    FLAT_COLORS,
    DIFFUSE_TEXTURE
  };
  public:
    QgsMaterialSettings()
      : mMaterialType( QgsMaterialType::FLAT_COLORS )
      , mAmbient( QColor::fromRgbF( 0.1f, 0.1f, 0.1f, 1.0f ) )
      , mDiffuse( QColor::fromRgbF( 0.7f, 0.7f, 0.7f, 1.0f ) )
      , mSpecular( QColor::fromRgbF( 1.0f, 1.0f, 1.0f, 1.0f ) )
      , mTexturePath("")
    {
    }

    //! Returns the material type
    QgsMaterialType materialType() const { return mMaterialType; }
    //! Returns ambient color component
    QColor ambient() const { return mAmbient; }
    //! Returns diffuse color component
    QColor diffuse() const { return mDiffuse; }
    //! Returns specular color component
    QColor specular() const { return mSpecular; }
    //! Returns shininess of the surface
    float shininess() const { return mShininess; }
    //! Returns shininess of the surface
    QString texturePath() const { return mTexturePath; }

    //! Sets the material type
    void setMaterialType(QgsMaterialType type) { mMaterialType = type; }
    //! Sets ambient color component
    void setAmbient( const QColor &ambient ) { mAmbient = ambient; }
    //! Sets diffuse color component
    void setDiffuse( const QColor &diffuse ) { mDiffuse = diffuse; }
    //! Sets specular color component
    void setSpecular( const QColor &specular ) { mSpecular = specular; }
    //! Sets shininess of the surface
    void setShininess( float shininess ) { mShininess = shininess; }
    //! Sets the path of the texture
    void setTexturePath( QString texturePath ) { mTexturePath = texturePath; }

    //! Reads settings from a DOM element
    void readXml( const QDomElement &elem );
    //! Writes settings to a DOM element
    void writeXml( QDomElement &elem ) const;

    bool operator==( const QgsMaterialSettings &other ) const
    {
      return mAmbient == other.mAmbient &&
             mDiffuse == other.mDiffuse &&
             mSpecular == other.mSpecular &&
             mShininess == other.mShininess &&
             mMaterialType == other.mMaterialType &&
             mTexturePath == other.mTexturePath;
    }
  private:
    QString materialTypeToString(QgsMaterialType materialType) const {
        QString materialTypeStr;
        switch (materialType) {
        case QgsMaterialSettings::FLAT_COLORS:
            materialTypeStr = "FLAT_COLORS";
            break;
        case QgsMaterialSettings::DIFFUSE_TEXTURE:
            materialTypeStr = "DIFFUSE_TEXTURE";
            break;
        default:
            Q_ASSERT(false);
        }
        return materialTypeStr;
    }
    QgsMaterialType stringToMaterialType(const QString& materialTypeStr) const {
        QgsMaterialType materialType;
        if (materialTypeStr == "FLAT_COLORS") materialType = QgsMaterialType::FLAT_COLORS;
        else if (materialTypeStr == "DIFFUSE_TEXTURE") materialType = QgsMaterialType::DIFFUSE_TEXTURE;
        else Q_ASSERT(false);
        return materialType;
    }
  private:
    QColor mAmbient;
    QColor mDiffuse;
    QColor mSpecular;
    float mShininess = 0.0f;
    QString mTexturePath;
    QgsMaterialType mMaterialType;
};

#endif // QGSMATERIALSETTINGS_H
