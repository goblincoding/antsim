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

#ifndef GRAPHICSWORLDTILE_H
#define GRAPHICSWORLDTILE_H

#include "ants/antworldtile.h"

#include <QGraphicsRectItem>
#include <QDomElement>

/*! \brief This class inherits from AntWorldTile and is responsible for the graphical aspects of the tiles. */

class GraphicsWorldTile : public AntWorldTile,
                          public QGraphicsRectItem
{
public:

  /*! Constructor. */
  explicit GraphicsWorldTile( const AntPosition& position, TileType type, QGraphicsItem* parent = 0 );

  /*! Serialises the tile data (width, length and coordinates) and returns it as a well-formed XML DOM element. */
  QDomElement serialise();

protected:
  /*! Re-implemented from AntWorldTile. */
  virtual void updateGraphics( TileType type );
};

#endif // GRAPHICSWORLDTILE_H
