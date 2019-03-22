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
class CCPACSTrailingEdgeDevice;
class CCPACSControlSurfaces;

namespace generated
{
    // This class is used in:
    // CPACSControlSurfaces

    // generated from /xsd:schema/xsd:complexType[890]
    /// @brief Definition of the wings trailing edge devices.
    /// 
    /// Definition of the wings trailing edge devices.
    /// 
    class CPACSTrailingEdgeDevices
    {
    public:
        TIGL_EXPORT CPACSTrailingEdgeDevices(CCPACSControlSurfaces* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSTrailingEdgeDevices();

        TIGL_EXPORT CCPACSControlSurfaces* GetParent();

        TIGL_EXPORT const CCPACSControlSurfaces* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<unique_ptr<CCPACSTrailingEdgeDevice> >& GetTrailingEdgeDevices() const;
        TIGL_EXPORT virtual std::vector<unique_ptr<CCPACSTrailingEdgeDevice> >& GetTrailingEdgeDevices();

        TIGL_EXPORT virtual CCPACSTrailingEdgeDevice& AddTrailingEdgeDevice();
        TIGL_EXPORT virtual void RemoveTrailingEdgeDevice(CCPACSTrailingEdgeDevice& ref);

    protected:
        CCPACSControlSurfaces* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<unique_ptr<CCPACSTrailingEdgeDevice> > m_trailingEdgeDevices;

    private:
#ifdef HAVE_CPP11
        CPACSTrailingEdgeDevices(const CPACSTrailingEdgeDevices&) = delete;
        CPACSTrailingEdgeDevices& operator=(const CPACSTrailingEdgeDevices&) = delete;

        CPACSTrailingEdgeDevices(CPACSTrailingEdgeDevices&&) = delete;
        CPACSTrailingEdgeDevices& operator=(CPACSTrailingEdgeDevices&&) = delete;
#else
        CPACSTrailingEdgeDevices(const CPACSTrailingEdgeDevices&);
        CPACSTrailingEdgeDevices& operator=(const CPACSTrailingEdgeDevices&);
#endif
    };
} // namespace generated

// CPACSTrailingEdgeDevices is customized, use type CCPACSTrailingEdgeDevices directly
} // namespace tigl
