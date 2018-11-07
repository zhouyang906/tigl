/* 
* Copyright (C) 2016 Airbus Defence and Space
*
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
#include "CCPACSWingRibsPositioning.h"

#include "CCPACSWingCSStructure.h"
#include "CCPACSWingRibsDefinition.h"
#include "CTiglError.h"
#include "CTiglLogging.h"

namespace tigl
{

CCPACSWingRibsPositioning::CCPACSWingRibsPositioning(CCPACSWingRibsDefinition* parent)
    : generated::CPACSWingRibsPositioning(parent) {}

void CCPACSWingRibsPositioning::SetRibReference(const std::string& value)
{
    generated::CPACSWingRibsPositioning::SetRibReference(value);
    invalidateStructure();
}

void CCPACSWingRibsPositioning::SetRibStart(const std::string& value)
{
    generated::CPACSWingRibsPositioning::SetRibStart(value);
    invalidateStructure();
}

void CCPACSWingRibsPositioning::SetRibEnd(const std::string& value)
{
    generated::CPACSWingRibsPositioning::SetRibEnd(value);
    invalidateStructure();
}

CCPACSWingRibsPositioning::StartDefinitionType CCPACSWingRibsPositioning::GetStartDefinitionType() const
{
    if (m_etaStart_choice1)
        return ETA_START;

    if (m_sparPositionStartUID_choice2)
        return SPARPOSITION_START;
    throw CTiglError("Invalid start definition");
}

void CCPACSWingRibsPositioning::SetEtaStart(double eta, const std::string& referenceUid)
{
    generated::CPACSWingRibsPositioning::GetEtaStart_choice1(tigl::CreateIfNotExists).SetEta(eta);
    generated::CPACSWingRibsPositioning::GetEtaStart_choice1(tigl::CreateIfNotExists).SetReferenceUID(referenceUid);

    m_sparPositionStartUID_choice2 = boost::none;

    // invalidate whole component segment structure, since cells could reference the ribs
    invalidateStructure();
}

void CCPACSWingRibsPositioning::SetSparPositionStartUID(const std::string& uid)
{
    generated::CPACSWingRibsPositioning::SetSparPositionStartUID_choice2(uid);

    m_etaStart_choice1 = boost::none;

    invalidateStructure();
}

CCPACSWingRibsPositioning::EndDefinitionType CCPACSWingRibsPositioning::GetEndDefinitionType() const
{
    if (m_etaEnd_choice1)
        return ETA_END;
    if (m_sparPositionEndUID_choice2)
        return SPARPOSITION_END;
    throw CTiglError("Invalid end definition");
}

void CCPACSWingRibsPositioning::SetEtaEnd(double eta, const std::string& referenceUid)
{
    generated::CPACSWingRibsPositioning::GetEtaEnd_choice1(tigl::CreateIfNotExists).SetEta(eta);
    generated::CPACSWingRibsPositioning::GetEtaEnd_choice1(tigl::CreateIfNotExists).SetReferenceUID(referenceUid);

    m_sparPositionEndUID_choice2 = boost::none;

    invalidateStructure();
}

void CCPACSWingRibsPositioning::SetSparPositionEndUID(const std::string& uid)
{
    generated::CPACSWingRibsPositioning::SetSparPositionEndUID_choice2(uid);

    m_etaEnd_choice1 = boost::none;

    invalidateStructure();
}

CCPACSWingRibsPositioning::RibCountDefinitionType CCPACSWingRibsPositioning::GetRibCountDefinitionType() const
{
    if (m_spacing_choice1)
        return SPACING;
    if (m_numberOfRibs_choice2)
        return NUMBER_OF_RIBS;
    throw CTiglError("Invalid rib count definition");
}

void CCPACSWingRibsPositioning::SetNumberOfRibs(int numRibs)
{
    m_numberOfRibs_choice2 = numRibs;

    m_spacing_choice1 = boost::none;

    invalidateStructure();
}

void CCPACSWingRibsPositioning::SetSpacing(double value)
{
    m_spacing_choice1 = value;

    m_numberOfRibs_choice2 = boost::none;

    invalidateStructure();
}

void CCPACSWingRibsPositioning::invalidateStructure()
{
    GetParent()->GetParent()->GetParent()->Invalidate();
}

void CCPACSWingRibsPositioning::SetRibCrossingBehaviour(const generated::CPACSRibCrossingBehaviour& value)
{
    generated::CPACSWingRibsPositioning::SetRibCrossingBehaviour(value);
    invalidateStructure();
}

void CCPACSWingRibsPositioning::Invalidate()
{
    invalidateStructure();
}

} // end namespace tigl
