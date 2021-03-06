/* 
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file 
* @brief  Implementation of routines for building a wire from a std::vector
*         of points by a BSpline interpolation.
*/

#ifndef CTIGLINTERPOLATEBSPLINEWIRE_H
#define CTIGLINTERPOLATEBSPLINEWIRE_H

#include "tigl_internal.h"
#include "ITiglWireAlgorithm.h"
#include "Geom_BSplineCurve.hxx"

namespace tigl 
{
// TODO(bgruber): prefixed _ as these enum values name clash with the one's of enum TiglContinuity
enum ETiglContinuity
{
    _C0,
    _C1
};

class CTiglInterpolateBsplineWire : public ITiglWireAlgorithm
{

public:
    // Constructor
    TIGL_EXPORT CTiglInterpolateBsplineWire();

    // Destructor
    TIGL_EXPORT ~CTiglInterpolateBsplineWire() override;

    // Builds the wire from the given points
    TIGL_EXPORT TopoDS_Wire BuildWire(const CPointContainer& points, bool forceClosed = false) const override;


    // if set to true, the endpoints of a closed wire will be c1 steady
    TIGL_EXPORT virtual void setEndpointContinuity(enum ETiglContinuity cont) { continuity = cont; }

    // Returns the algorithm code identifier for an algorithm
    TIGL_EXPORT TiglAlgorithmCode GetAlgorithmCode() const override;

    // Returns the point on the wire with the smallest x value
    TIGL_EXPORT gp_Pnt GetPointWithMinX(const CPointContainer& points) const override;

    // Returns the point on the wire with the biggest x value
    TIGL_EXPORT gp_Pnt GetPointWithMaxX(const CPointContainer& points) const override;

    // Returns the point on the wire with the smallest y value
    TIGL_EXPORT gp_Pnt GetPointWithMinY(const CPointContainer& points) const override;

    // Returns the point on the wire with the biggest y value
    TIGL_EXPORT gp_Pnt GetPointWithMaxY(const CPointContainer& points) const override;

protected:

private:
    // Copy constructor
    CTiglInterpolateBsplineWire(const CTiglInterpolateBsplineWire& );

    // Assignment operator
    void operator=(const CTiglInterpolateBsplineWire& );

    ETiglContinuity continuity;

};

} // end namespace tigl

#endif // CTIGLINTERPOLATEBSPLINEWIRE_H
