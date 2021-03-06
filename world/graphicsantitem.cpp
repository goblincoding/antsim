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

#include "graphicsantitem.h"
#include "graphicsworldtile.h"
#include "antworldscene.h"
#include "utils/antconfig.h"

/*--------------------------------------------------------------------------------------*/

GraphicsAntItem::GraphicsAntItem( const GraphicsAntWorldScene* scene, const AntPosition& position, const QPixmap& pixmap )
: AntBot             ( position ),
  QGraphicsPixmapItem( pixmap ),
  m_scene            ( scene )
{
  setZValue( 1.0 );           // always draw on top
  AntBot::updatePosition( position );
}

/*--------------------------------------------------------------------------------------*/

std::vector< const AntWorldTile* > GraphicsAntItem::queryTerrain( const AntPosition& position )
{
  std::vector< const AntWorldTile* > tiles;

  if( m_scene )
  {
    tiles = m_scene->neighbours( position );
  }

  return tiles;
}

/*--------------------------------------------------------------------------------------*/

void GraphicsAntItem::updateGraphics( const AntPosition& position )
{
  if( m_scene )
  {
    /* The position passed in is the centre of the item so we need to cater for the
     * offset to the item's top left corner. */
    QPointF pointF( qreal( position.x() - boundingRect().width() / 2 ),
                    qreal( position.y() - boundingRect().height() / 2 ) );
    setPos( pointF );
  }
}

/*--------------------------------------------------------------------------------------*/

void GraphicsAntItem::showFoundGraphics()
{
  QPixmap pixMap( ":/resources/foundant.png" );
  setPixmap( pixMap.scaled( AntConfig::AntSize, AntConfig::AntSize, Qt::KeepAspectRatio ) );
}

/*--------------------------------------------------------------------------------------*/

void GraphicsAntItem::showForageGraphics()
{
  QPixmap pixMap( ":/resources/ant.png" );
  setPixmap( pixMap.scaled( AntConfig::AntSize, AntConfig::AntSize, Qt::KeepAspectRatio ) );
}

/*--------------------------------------------------------------------------------------*/
