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

#include <cassert>
#include <CCPACSWingSparSegment.h>
#include "CCPACSWingSpars.h"
#include "CPACSSparSegments.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSparSegments::CPACSSparSegments(CCPACSWingSpars* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSSparSegments::~CPACSSparSegments()
    {
    }

    CCPACSWingSpars* CPACSSparSegments::GetParent() const
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSSparSegments::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSparSegments::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSparSegments::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element sparSegment
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparSegment")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/sparSegment", m_sparSegments, reinterpret_cast<CCPACSWingSparSegments*>(this), m_uidMgr);
        }

    }

    void CPACSSparSegments::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element sparSegment
        tixi::TixiSaveElements(tixiHandle, xpath + "/sparSegment", m_sparSegments);

    }

    const std::vector<unique_ptr<CCPACSWingSparSegment> >& CPACSSparSegments::GetSparSegments() const
    {
        return m_sparSegments;
    }

    std::vector<unique_ptr<CCPACSWingSparSegment> >& CPACSSparSegments::GetSparSegments()
    {
        return m_sparSegments;
    }

    CCPACSWingSparSegment& CPACSSparSegments::AddSparSegment()
    {
        m_sparSegments.push_back(make_unique<CCPACSWingSparSegment>(reinterpret_cast<CCPACSWingSparSegments*>(this), m_uidMgr));
        return *m_sparSegments.back();
    }

    void CPACSSparSegments::RemoveSparSegment(CCPACSWingSparSegment& ref)
    {
        for (std::size_t i = 0; i < m_sparSegments.size(); i++) {
            if (m_sparSegments[i].get() == &ref) {
                m_sparSegments.erase(m_sparSegments.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
