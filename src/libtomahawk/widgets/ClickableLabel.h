/* === This file is part of Tomahawk Player - <http://tomahawk-player.org> ===
 *
 *   Copyright 2010-2011, Christian Muehlhaeuser <muesli@tomahawk-player.org>
 *   Copyright 2014,      Uwe L. Korn <uwelk@xhochy.com>
 *
 *   Tomahawk is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Tomahawk is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Tomahawk. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QTime>

#include "DllMacro.h"

class DLLEXPORT ClickableLabel : public QLabel
{
    Q_OBJECT

public:

    ClickableLabel( QWidget* parent );
    virtual ~ClickableLabel();

    void setOpacity( float opacity );

signals:
    void clicked();
    void resized( const QPoint& delta );

protected:
    void mousePressEvent( QMouseEvent* event );
    void mouseReleaseEvent( QMouseEvent* event );
    void mouseMoveEvent( QMouseEvent* event );

    void paintEvent( QPaintEvent* event );

private:
    QPoint m_dragPoint;
    bool m_pressed;
    bool m_moved;
    QTime m_time;
    float m_opacity;
};

#endif // CLICKABLELABEL_H
