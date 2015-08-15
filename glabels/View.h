/*  View.h
 *
 *  Copyright (C) 2013  Jim Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef glabels_View_h
#define glabels_View_h

#include <QWidget>
#include <QPainter>

#include "LabelRegion.h"


namespace glabels
{
	// Forward References
	class LabelModel;
	class LabelModelObject;
	class Handle;


	///
	/// View Widget
	///
	class View : public QWidget
	{
		Q_OBJECT

		/////////////////////////////////////
		// Lifecycle
		/////////////////////////////////////
	public:
		View( QWidget *parent = 0 );


		/////////////////////////////////////
		// Signals
		/////////////////////////////////////
	signals:
		void contextMenuActivate();
		void zoomChanged();
		void pointerMoved( double x, double y );
		void pointerExited();
		void modeChanged();


		/////////////////////////////////////
		// Parameters
		/////////////////////////////////////
	public:
		double zoom() const;
		bool markupVisible() const;
		bool qridVisible() const;


		/////////////////////////////////////
		// Model
		/////////////////////////////////////
	public:
		void setModel( LabelModel* model );


		/////////////////////////////////////
		// Visibility operations
		/////////////////////////////////////
	public:
		void setGridVisible( bool visibleFlag );
		void setMarkupVisible( bool visibleFlag );


		/////////////////////////////////////
		// Zoom operations
		/////////////////////////////////////
	public:
		void zoomIn();
		void zoomOut();
		void zoom1To1();
		void zoomToFit();
		bool isZoomMax() const;
		bool isZoomMin() const;
	private:
		void setZoomReal( double zoom, bool zoomToFitFlag );


		/////////////////////////////////////
		// Mode operations
		/////////////////////////////////////
	public:
		void arrowMode();
		void createBoxMode();
		void createEllipseMode();
		void createLineMode();
		void createImageMode();
		void createTextMode();
		void createBarcodeMode();


		/////////////////////////////////////
		// Event handlers
		/////////////////////////////////////
	protected:
		void paintEvent( QPaintEvent* event );
		void resizeEvent( QResizeEvent* event );
		void mouseMoveEvent( QMouseEvent* event );
		void mousePressEvent( QMouseEvent* event );
		void mouseReleaseEvent( QMouseEvent* event );
		void leaveEvent( QEvent* event );


		/////////////////////////////////////
		// Private methods
		/////////////////////////////////////
	private:
		void drawBgLayer( QPainter* painter );
		void drawGridLayer( QPainter* painter );
		void drawMarkupLayer( QPainter* painter );
		void drawObjectsLayer( QPainter* painter );
		void drawFgLayer( QPainter* painter );
		void drawHighlightLayer( QPainter* painter );
		void drawSelectRegionLayer( QPainter* painter );

		void handleResizeMotion( double xWorld, double yWorld );


		/////////////////////////////////////
		// Private slots
		/////////////////////////////////////
	private:
		void onLabelChanged();
		void onLabelSizeChanged();


		/////////////////////////////////////
		// Private data
		/////////////////////////////////////
	private:
		enum State {
			IdleState,
			ArrowSelectRegion,
			ArrowMove,
			ArrowResize,
			CreateDrag
		};

		enum CreateType {
			Box,
			Ellipse,
			Line,
			Image,
			Text,
			Barcode
		};

		double              mZoom;
		bool                mZoomToFitFlag;

		bool                mMarkupVisible;
		bool                mGridVisible;

		double              mGridSpacing;

		LabelModel*         mModel;

		State               mState;

		/* ArrowSelectRegion state */
		bool                mSelectRegionVisible;
		LabelRegion         mSelectRegion;

		/* ArrowMove state */
		double              mMoveLastX;
		double              mMoveLastY;

		/* ArrowResize state */
		LabelModelObject*   mResizeObject;
		Handle*             mResizeHandle;
		bool                mResizeHonorAspect;

		/* CreateDrag state */
		bool                mInObjectCreateMode;
		CreateType          mCreateObjectType;
		LabelModelObject*   mCreateObject;
		double              mCreateX0;
		double              mCreateY0;


	};


}



#endif // glabels_View_h
