/*  Layout.cpp
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

#include "Layout.h"

#include <math.h>

#include "privateConstants.h"


namespace libglabels
{

	bool Layout::is_similar_to( const Layout &b )
	{
		return ( (mNx == b.mNx)                           &&
			 (mNy == b.mNy)                           &&
			 (fabs(mX0 - b.mX0) < Constants::EPSILON) &&
			 (fabs(mY0 - b.mY0) < Constants::EPSILON) &&
			 (fabs(mDx - b.mDx) < Constants::EPSILON) &&
			 (fabs(mDy - b.mDy) < Constants::EPSILON) );
	}

}
