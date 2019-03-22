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
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingSparSegment;
class CCPACSWingSpars;

namespace generated
{
    // This class is used in:
    // CPACSWingSpar

    // generated from /xsd:schema/xsd:complexType[829]
    /// @brief Spar segments of the wing.
    /// 
    /// sparSegmentsType, containing multiple sparSegment
    /// (=spars) of the wing.
    /// 
    class CPACSSparSegments
    {
    public:
        TIGL_EXPORT CPACSSparSegments(CCPACSWingSpars* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSSparSegments();

        TIGL_EXPORT CCPACSWingSpars* GetParent();

        TIGL_EXPORT const CCPACSWingSpars* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSWingSparSegment> >& GetSparSegments() const;
        TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSWingSparSegment> >& GetSparSegments();

        TIGL_EXPORT virtual CCPACSWingSparSegment& AddSparSegment();
        TIGL_EXPORT virtual void RemoveSparSegment(CCPACSWingSparSegment& ref);

    protected:
        CCPACSWingSpars* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<unique_ptr<CCPACSWingSparSegment> > m_sparSegments;

    private:
#ifdef HAVE_CPP11
        CPACSSparSegments(const CPACSSparSegments&) = delete;
        CPACSSparSegments& operator=(const CPACSSparSegments&) = delete;

        CPACSSparSegments(CPACSSparSegments&&) = delete;
        CPACSSparSegments& operator=(CPACSSparSegments&&) = delete;
#else
        CPACSSparSegments(const CPACSSparSegments&);
        CPACSSparSegments& operator=(const CPACSSparSegments&);
#endif
    };
} // namespace generated

// CPACSSparSegments is customized, use type CCPACSWingSparSegments directly
} // namespace tigl
