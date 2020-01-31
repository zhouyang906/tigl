// Copyright (c) 2018 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    class CPACSControlSurfacePath;

    // This class is used in:
    // CPACSControlSurfacePath

    // generated from /xsd:schema/xsd:complexType[181]
    /// @brief controlSurfaceHingePointType
    /// 
    /// The deflection path of a control surface is described
    /// with respect to two hinge points - one at the inner border of
    /// the control surface and one at the outer border of the control
    /// surface. Those two points are defined using the xsi and relative
    /// height coordinates of the parent. Therefore those points can also
    /// lay outbound of the control surface. Those two points defined
    /// the hinge line, which is a straight line between the two points.
    /// An example can be found below:
    /// @see path
    /// 
    class CPACSControlSurfaceHingePoint
    {
    public:
        TIGL_EXPORT CPACSControlSurfaceHingePoint(CPACSControlSurfacePath* parent);

        TIGL_EXPORT virtual ~CPACSControlSurfaceHingePoint();

        TIGL_EXPORT CPACSControlSurfacePath* GetParent();

        TIGL_EXPORT const CPACSControlSurfacePath* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const double& GetHingeXsi() const;
        TIGL_EXPORT virtual void SetHingeXsi(const double& value);

        TIGL_EXPORT virtual const double& GetHingeRelHeight() const;
        TIGL_EXPORT virtual void SetHingeRelHeight(const double& value);

    protected:
        CPACSControlSurfacePath* m_parent;

        /// Relative chordwise coordinate (xsi) of the
        /// hinge line point. Reference is the parent chord.
        double m_hingeXsi;

        /// Relative height of the hinge line point.
        /// Reference is the parent airfoil height.
        double m_hingeRelHeight;

    private:
        CPACSControlSurfaceHingePoint(const CPACSControlSurfaceHingePoint&) = delete;
        CPACSControlSurfaceHingePoint& operator=(const CPACSControlSurfaceHingePoint&) = delete;

        CPACSControlSurfaceHingePoint(CPACSControlSurfaceHingePoint&&) = delete;
        CPACSControlSurfaceHingePoint& operator=(CPACSControlSurfaceHingePoint&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSControlSurfaceHingePoint = generated::CPACSControlSurfaceHingePoint;
using CCPACSControlSurfacePath = generated::CPACSControlSurfacePath;
} // namespace tigl
