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
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // CPACSControlSurfaceStep

    // generated from /xsd:schema/xsd:complexType[732]
    /// @brief pointXZType
    /// 
    /// Point type, containing an xz data doublet.
    /// 
    class CPACSPointXZ
    {
    public:
        TIGL_EXPORT CPACSPointXZ(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSPointXZ();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetX() const;
        TIGL_EXPORT virtual void SetX(const double& value);

        TIGL_EXPORT virtual const double& GetZ() const;
        TIGL_EXPORT virtual void SetZ(const double& value);

    protected:
        CTiglUIDManager* m_uidMgr;

        std::string m_uID;

        /// X-Component
        double      m_x;

        /// Z-Component
        double      m_z;

    private:
#ifdef HAVE_CPP11
        CPACSPointXZ(const CPACSPointXZ&) = delete;
        CPACSPointXZ& operator=(const CPACSPointXZ&) = delete;

        CPACSPointXZ(CPACSPointXZ&&) = delete;
        CPACSPointXZ& operator=(CPACSPointXZ&&) = delete;
#else
        CPACSPointXZ(const CPACSPointXZ&);
        CPACSPointXZ& operator=(const CPACSPointXZ&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSPointXZ = generated::CPACSPointXZ;
#else
typedef generated::CPACSPointXZ CCPACSPointXZ;
#endif
} // namespace tigl
