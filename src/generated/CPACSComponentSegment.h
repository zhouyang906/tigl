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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSWingCSStructure.h>
#include <string>
#include <tixi.h>
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingComponentSegments;

namespace generated
{
    // This class is used in:
    // CPACSComponentSegments

    // generated from /xsd:schema/xsd:complexType[142]
    class CPACSComponentSegment
    {
    public:
        TIGL_EXPORT CPACSComponentSegment(CCPACSWingComponentSegments* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSComponentSegment();

        TIGL_EXPORT CCPACSWingComponentSegments* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetFromElementUID() const;
        TIGL_EXPORT virtual void SetFromElementUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetToElementUID() const;
        TIGL_EXPORT virtual void SetToElementUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<CCPACSWingCSStructure>& GetStructure() const;
        TIGL_EXPORT virtual boost::optional<CCPACSWingCSStructure>& GetStructure();

        TIGL_EXPORT virtual CCPACSWingCSStructure& GetStructure(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStructure();

    protected:
        CCPACSWingComponentSegments* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                            m_uID;
        std::string                            m_name;
        boost::optional<std::string>           m_description;
        std::string                            m_fromElementUID;
        std::string                            m_toElementUID;
        boost::optional<CCPACSWingCSStructure> m_structure;

    private:
#ifdef HAVE_CPP11
        CPACSComponentSegment(const CPACSComponentSegment&) = delete;
        CPACSComponentSegment& operator=(const CPACSComponentSegment&) = delete;

        CPACSComponentSegment(CPACSComponentSegment&&) = delete;
        CPACSComponentSegment& operator=(CPACSComponentSegment&&) = delete;
#else
        CPACSComponentSegment(const CPACSComponentSegment&);
        CPACSComponentSegment& operator=(const CPACSComponentSegment&);
#endif
    };
} // namespace generated

// CPACSComponentSegment is customized, use type CCPACSWingComponentSegment directly
} // namespace tigl
