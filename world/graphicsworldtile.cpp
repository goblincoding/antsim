/* Copyright (c) 2013 by William Hallatt.
 *
 * This file forms part of "AntSim".
 *
 * The official website for this project is <http://www.goblincoding.com> and,
 * although not compulsory, it would be appreciated if all works of whatever
 * nature using this source code (in whole or in part) include a reference to
 * this site.
 *
 * Should you wish to contact me for whatever reason, please do so via:
 *
 *                 <http://www.goblincoding.com/contact>
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program (GNUGPL.txt).  If not, see
 *
 *                    <http://www.gnu.org/licenses/>
 */

#include "graphicsworldtile.h"
#include "graphicspheromoneitem.h"

#include <QBrush>
#include <QPen>
#include <QDomDocument>

/*--------------------------------------------------------------------------------------*/

GraphicsWorldTile::GraphicsWorldTile( const AntPosition& position, TileType type, QGraphicsItem* parent )
: AntWorldTile     (),
  QGraphicsRectItem( parent )
{
  setCentre( position );
  setTileType( type );
}

/*--------------------------------------------------------------------------------------*/

QDomElement GraphicsWorldTile::serialise()
{
  QDomDocument doc;
  QDomElement element = doc.createElement( "GraphicsWorldTile" );
  element.setAttribute( "x", rect().x() );
  element.setAttribute( "y", rect().y() );
  element.setAttribute( "width", rect().width() );
  element.setAttribute( "height", rect().height() );
  element.setAttribute( "type", static_cast< int >( tileType() ) );
  return element.cloneNode().toElement();
}

/*--------------------------------------------------------------------------------------*/

void GraphicsWorldTile::updateGraphics( AntWorldTile::TileType type )
{
  switch( type )
  {
    case Path:
      setBrush( Qt::white );
      setToolTip( "This is a \"path\" tile." );
      break;
    case Wall:
      setBrush( Qt::darkBlue );
      setToolTip( "This is a \"wall\" tile." );
      break;
    case Hazard:
      setBrush( Qt::darkRed );
      setToolTip( "This is a \"hazard\" tile." );
      break;
    case Food:
      setBrush( Qt::darkGreen );
      setToolTip( "This is a \"food\" tile." );
      break;
    case Spawn:
      setBrush( Qt::darkMagenta );
      setToolTip( "This is a spawn point." );
      break;
    default:
      return;   // if type is NONE, do no nothing
  }
}

/*--------------------------------------------------------------------------------------*/