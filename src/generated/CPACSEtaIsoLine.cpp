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
#include "CCPACSControlSurfaceBorderTrailingEdge.h"
#include "CCPACSControlSurfaceSkinCutOutBorder.h"
#include "CCPACSControlSurfaceTrackType.h"
#include "CCPACSWingCellPositionSpanwise.h"
#include "CPACSControlSurfaceAirfoil.h"
#include "CPACSCutOutProfile.h"
#include "CPACSEtaIsoLine.h"
#include "CPACSSparCell.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSEtaIsoLine::CPACSEtaIsoLine(CCPACSWingCellPositionSpanwise* parent)
        : m_eta(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSWingCellPositionSpanwise);
    }

    CPACSEtaIsoLine::CPACSEtaIsoLine(CPACSControlSurfaceAirfoil* parent)
        : m_eta(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSControlSurfaceAirfoil);
    }

    CPACSEtaIsoLine::CPACSEtaIsoLine(CCPACSControlSurfaceBorderTrailingEdge* parent)
        : m_eta(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSControlSurfaceBorderTrailingEdge);
    }

    CPACSEtaIsoLine::CPACSEtaIsoLine(CCPACSControlSurfaceSkinCutOutBorder* parent)
        : m_eta(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSControlSurfaceSkinCutOutBorder);
    }

    CPACSEtaIsoLine::CPACSEtaIsoLine(CCPACSControlSurfaceTrackType* parent)
        : m_eta(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSControlSurfaceTrackType);
    }

    CPACSEtaIsoLine::CPACSEtaIsoLine(CPACSCutOutProfile* parent)
        : m_eta(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSCutOutProfile);
    }

    CPACSEtaIsoLine::CPACSEtaIsoLine(CPACSSparCell* parent)
        : m_eta(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSSparCell);
    }

    CPACSEtaIsoLine::~CPACSEtaIsoLine()
    {
    }

    void CPACSEtaIsoLine::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element eta
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/eta")) {
            m_eta = tixi::TixiGetElement<double>(tixiHandle, xpath + "/eta");
        }
        else {
            LOG(ERROR) << "Required element eta is missing at xpath " << xpath;
        }

        // read element referenceUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/referenceUID")) {
            m_referenceUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/referenceUID");
            if (m_referenceUID.empty()) {
                LOG(WARNING) << "Required element referenceUID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element referenceUID is missing at xpath " << xpath;
        }

    }

    void CPACSEtaIsoLine::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element eta
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/eta");
        tixi::TixiSaveElement(tixiHandle, xpath + "/eta", m_eta);

        // write element referenceUID
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/referenceUID");
        tixi::TixiSaveElement(tixiHandle, xpath + "/referenceUID", m_referenceUID);

    }

    const double& CPACSEtaIsoLine::GetEta() const
    {
        return m_eta;
    }

    void CPACSEtaIsoLine::SetEta(const double& value)
    {
        m_eta = value;
    }

    const std::string& CPACSEtaIsoLine::GetReferenceUID() const
    {
        return m_referenceUID;
    }

    void CPACSEtaIsoLine::SetReferenceUID(const std::string& value)
    {
        m_referenceUID = value;
    }

} // namespace generated
} // namespace tigl