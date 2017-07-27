/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "keypoint.h"

#include <QtWidgets>

KeyPoint::KeyPoint(const QColor &color, int x)
{
	this->id = x;
	this->color = color;
	setZValue(id % 2);

	setFlags(ItemIsSelectable | ItemIsMovable);
	setAcceptHoverEvents(true);
}

QRectF KeyPoint::boundingRect() const
{
	return QRectF(0, 0, width_val, height_val);
}

void KeyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(widget);

	QColor fillColor = (option->state & QStyle::State_Selected) ? color.dark(150) : color;
	if (option->state & QStyle::State_MouseOver)
		fillColor = fillColor.light(125);

	const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
// 	if (lod < 0.001) {
// 		if (lod < 0.125) {
// 			painter->fillRect(QRectF(0, 0, 110, 70), fillColor);
// 			return;
// 		}
// 
// 		QBrush b = painter->brush();
// 		painter->setBrush(fillColor);
// 		painter->drawRect(13, 13, 97, 57);
// 		painter->setBrush(b);
// 		return;
// 	}

	QPen oldPen = painter->pen();
	QPen pen = oldPen;
	int width = 0;
	if (option->state & QStyle::State_Selected)
		width += 2;

	pen.setWidth(width);
	QBrush b = painter->brush();
	painter->setBrush(QBrush(fillColor.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

	//painter->drawRect(QRect(14, 14, 79, 39));
	painter->drawEllipse(QRect(0, 0, width_val, height_val));
	painter->setBrush(b);

// 	if (lod >= 1) {
// 		painter->setPen(QPen(Qt::gray, 1));
// 		painter->drawLine(15, 54, 94, 54);
// 		painter->drawLine(94, 53, 94, 15);
// 		painter->setPen(QPen(Qt::black, 0));
// 	}

	// Draw text
	if (lod > 0.001)
	{
		int fontsize = 14;
		QFont font("Times", fontsize);
		font.setStyleStrategy(QFont::ForceOutline);
		painter->setFont(font);
		painter->save();//
		painter->drawText(width_val / 2 - fontsize * 3 / 4, height_val / 2 + fontsize / 2, QString("%1").arg(id));
		painter->restore();
	}

	// Draw lines
// 	QVarLengthArray<QLineF, 36> lines;
// 	if (lod >= 0.5) {
// 		for (int i = 0; i <= 10; i += (lod > 0.5 ? 1 : 2)) {
// 			lines.append(QLineF(18 + 7 * i, 13, 18 + 7 * i, 5));
// 			lines.append(QLineF(18 + 7 * i, 54, 18 + 7 * i, 62));
// 		}
// 		for (int i = 0; i <= 6; i += (lod > 0.5 ? 1 : 2)) {
// 			lines.append(QLineF(5, 18 + i * 5, 13, 18 + i * 5));
// 			lines.append(QLineF(94, 18 + i * 5, 102, 18 + i * 5));
// 		}
// 	}
// 	if (lod >= 0.4) {
// 		const QLineF lineData[] = {
// 			QLineF(25, 35, 35, 35),
// 			QLineF(35, 30, 35, 40),
// 			QLineF(35, 30, 45, 35),
// 			QLineF(35, 40, 45, 35),
// 			QLineF(45, 30, 45, 40),
// 			QLineF(45, 35, 55, 35)
// 		};
// 		lines.append(lineData, 6);
// 	}
// 	painter->drawLines(lines.data(), lines.size());
}

void KeyPoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItem::mousePressEvent(event);
	update();
}

void KeyPoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItem::mouseMoveEvent(event);
	update();
}

void KeyPoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItem::mouseReleaseEvent(event);
	update();
}
