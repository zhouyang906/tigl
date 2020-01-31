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
#include "CPACSTrailingEdgeDevice.h"
#include "CPACSTrailingEdgeDevices.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSTrailingEdgeDevice::CPACSTrailingEdgeDevice(CPACSTrailingEdgeDevices* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_outerShape(reinterpret_cast<CCPACSTrailingEdgeDevice*>(this))
        , m_path(reinterpret_cast<CCPACSTrailingEdgeDevice*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSTrailingEdgeDevice::~CPACSTrailingEdgeDevice()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CPACSTrailingEdgeDevices* CPACSTrailingEdgeDevice::GetParent() const
    {
        return m_parent;
    }

    CPACSTrailingEdgeDevices* CPACSTrailingEdgeDevice::GetParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSTrailingEdgeDevice::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSTrailingEdgeDevice::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSTrailingEdgeDevice::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element parentUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/parentUID")) {
            m_parentUID = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/parentUID");
            if (m_parentUID.empty()) {
                LOG(WARNING) << "Required element parentUID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element parentUID is missing at xpath " << xpath;
        }

        // read element outerShape
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/outerShape")) {
            m_outerShape.ReadCPACS(tixiHandle, xpath + "/outerShape");
        }
        else {
            LOG(ERROR) << "Required element outerShape is missing at xpath " << xpath;
        }

        // read element wingCutOut
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/wingCutOut")) {
            m_wingCutOut = boost::in_place(reinterpret_cast<CCPACSTrailingEdgeDevice*>(this));
            try {
                m_wingCutOut->ReadCPACS(tixiHandle, xpath + "/wingCutOut");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read wingCutOut at xpath " << xpath << ": " << e.what();
                m_wingCutOut = boost::none;
            }
        }

        // read element structure
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structure")) {
            m_structure = boost::in_place(reinterpret_cast<CCPACSTrailingEdgeDevice*>(this), m_uidMgr);
            try {
                m_structure->ReadCPACS(tixiHandle, xpath + "/structure");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read structure at xpath " << xpath << ": " << e.what();
                m_structure = boost::none;
            }
        }

        // read element path
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/path")) {
            m_path.ReadCPACS(tixiHandle, xpath + "/path");
        }
        else {
            LOG(ERROR) << "Required element path is missing at xpath " << xpath;
        }

        // read element tracks
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/tracks")) {
            m_tracks = boost::in_place(reinterpret_cast<CCPACSTrailingEdgeDevice*>(this), m_uidMgr);
            try {
                m_tracks->ReadCPACS(tixiHandle, xpath + "/tracks");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read tracks at xpath " << xpath << ": " << e.what();
                m_tracks = boost::none;
            }
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSTrailingEdgeDevice::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element parentUID
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/parentUID");
        tixi::TixiSaveElement(tixiHandle, xpath + "/parentUID", m_parentUID);

        // write element outerShape
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/outerShape");
        m_outerShape.WriteCPACS(tixiHandle, xpath + "/outerShape");

        // write element wingCutOut
        if (m_wingCutOut) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/wingCutOut");
            m_wingCutOut->WriteCPACS(tixiHandle, xpath + "/wingCutOut");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/wingCutOut")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/wingCutOut");
            }
        }

        // write element structure
        if (m_structure) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/structure");
            m_structure->WriteCPACS(tixiHandle, xpath + "/structure");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/structure")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/structure");
            }
        }

        // write element path
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/path");
        m_path.WriteCPACS(tixiHandle, xpath + "/path");

        // write element tracks
        if (m_tracks) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/tracks");
            m_tracks->WriteCPACS(tixiHandle, xpath + "/tracks");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/tracks")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/tracks");
            }
        }

    }

    const std::string& CPACSTrailingEdgeDevice::GetUID() const
    {
        return m_uID;
    }

    void CPACSTrailingEdgeDevice::SetUID(const std::string& value)
    {
        if (m_uidMgr) {
            m_uidMgr->TryUnregisterObject(m_uID);
            m_uidMgr->RegisterObject(value, *this);
        }
        m_uID = value;
    }

    const std::string& CPACSTrailingEdgeDevice::GetName() const
    {
        return m_name;
    }

    void CPACSTrailingEdgeDevice::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSTrailingEdgeDevice::GetDescription() const
    {
        return m_description;
    }

    void CPACSTrailingEdgeDevice::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const std::string& CPACSTrailingEdgeDevice::GetParentUID() const
    {
        return m_parentUID;
    }

    void CPACSTrailingEdgeDevice::SetParentUID(const std::string& value)
    {
        m_parentUID = value;
    }

    const CCPACSControlSurfaceOuterShapeTrailingEdge& CPACSTrailingEdgeDevice::GetOuterShape() const
    {
        return m_outerShape;
    }

    CCPACSControlSurfaceOuterShapeTrailingEdge& CPACSTrailingEdgeDevice::GetOuterShape()
    {
        return m_outerShape;
    }

    const boost::optional<CCPACSControlSurfaceWingCutOut>& CPACSTrailingEdgeDevice::GetWingCutOut() const
    {
        return m_wingCutOut;
    }

    boost::optional<CCPACSControlSurfaceWingCutOut>& CPACSTrailingEdgeDevice::GetWingCutOut()
    {
        return m_wingCutOut;
    }

    const boost::optional<CCPACSWingCSStructure>& CPACSTrailingEdgeDevice::GetStructure() const
    {
        return m_structure;
    }

    boost::optional<CCPACSWingCSStructure>& CPACSTrailingEdgeDevice::GetStructure()
    {
        return m_structure;
    }

    const CPACSControlSurfacePath& CPACSTrailingEdgeDevice::GetPath() const
    {
        return m_path;
    }

    CPACSControlSurfacePath& CPACSTrailingEdgeDevice::GetPath()
    {
        return m_path;
    }

    const boost::optional<CPACSControlSurfaceTracks>& CPACSTrailingEdgeDevice::GetTracks() const
    {
        return m_tracks;
    }

    boost::optional<CPACSControlSurfaceTracks>& CPACSTrailingEdgeDevice::GetTracks()
    {
        return m_tracks;
    }

    CCPACSControlSurfaceWingCutOut& CPACSTrailingEdgeDevice::GetWingCutOut(CreateIfNotExistsTag)
    {
        if (!m_wingCutOut)
            m_wingCutOut = boost::in_place(reinterpret_cast<CCPACSTrailingEdgeDevice*>(this));
        return *m_wingCutOut;
    }

    void CPACSTrailingEdgeDevice::RemoveWingCutOut()
    {
        m_wingCutOut = boost::none;
    }

    CCPACSWingCSStructure& CPACSTrailingEdgeDevice::GetStructure(CreateIfNotExistsTag)
    {
        if (!m_structure)
            m_structure = boost::in_place(reinterpret_cast<CCPACSTrailingEdgeDevice*>(this), m_uidMgr);
        return *m_structure;
    }

    void CPACSTrailingEdgeDevice::RemoveStructure()
    {
        m_structure = boost::none;
    }

    CPACSControlSurfaceTracks& CPACSTrailingEdgeDevice::GetTracks(CreateIfNotExistsTag)
    {
        if (!m_tracks)
            m_tracks = boost::in_place(reinterpret_cast<CCPACSTrailingEdgeDevice*>(this), m_uidMgr);
        return *m_tracks;
    }

    void CPACSTrailingEdgeDevice::RemoveTracks()
    {
        m_tracks = boost::none;
    }

} // namespace generated
} // namespace tigl
