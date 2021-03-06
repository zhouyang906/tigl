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
#include <CCPACSEtaIsoLine.h>
#include <string>
#include <tixi.h>
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    class CPACSControlSurfaceWingCutOut;

    // This class is used in:
    // CPACSControlSurfaceWingCutOut

    // generated from /xsd:schema/xsd:complexType[188]
    /// @brief Border type for the inner and outer border of a wing
    /// cut out
    /// 
    /// Maybe applied to specifiy inner and outer border of
    /// the cutout either via eta or rib references
    /// @see wingCutOut
    /// 
    class CPACSControlSurfaceSkinCutOutBorder
    {
    public:
        TIGL_EXPORT CPACSControlSurfaceSkinCutOutBorder(CPACSControlSurfaceWingCutOut* parent);

        TIGL_EXPORT virtual ~CPACSControlSurfaceSkinCutOutBorder();

        TIGL_EXPORT CPACSControlSurfaceWingCutOut* GetParent();

        TIGL_EXPORT const CPACSControlSurfaceWingCutOut* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetRibDefinitionUID_choice1() const;
        TIGL_EXPORT virtual void SetRibDefinitionUID_choice1(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetRibNumber_choice1() const;
        TIGL_EXPORT virtual void SetRibNumber_choice1(const boost::optional<int>& value);

        TIGL_EXPORT virtual const boost::optional<CCPACSEtaIsoLine>& GetEtaLE_choice2() const;
        TIGL_EXPORT virtual boost::optional<CCPACSEtaIsoLine>& GetEtaLE_choice2();

        TIGL_EXPORT virtual const boost::optional<CCPACSEtaIsoLine>& GetEtaTE_choice2() const;
        TIGL_EXPORT virtual boost::optional<CCPACSEtaIsoLine>& GetEtaTE_choice2();

        TIGL_EXPORT virtual CCPACSEtaIsoLine& GetEtaLE_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveEtaLE_choice2();

        TIGL_EXPORT virtual CCPACSEtaIsoLine& GetEtaTE_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveEtaTE_choice2();

    protected:
        CPACSControlSurfaceWingCutOut* m_parent;

        /// Link to a rib definition
        boost::optional<std::string>      m_ribDefinitionUID_choice1;

        /// Rib number in the corresponding
        /// ribDefinitionUID
        boost::optional<int>              m_ribNumber_choice1;

        /// Spanwise location of the border at the
        /// leading edge of the cut out
        boost::optional<CCPACSEtaIsoLine> m_etaLE_choice2;

        /// Spanwise location of the border at the
        /// trailing edge of the cut out
        boost::optional<CCPACSEtaIsoLine> m_etaTE_choice2;

    private:
        CPACSControlSurfaceSkinCutOutBorder(const CPACSControlSurfaceSkinCutOutBorder&) = delete;
        CPACSControlSurfaceSkinCutOutBorder& operator=(const CPACSControlSurfaceSkinCutOutBorder&) = delete;

        CPACSControlSurfaceSkinCutOutBorder(CPACSControlSurfaceSkinCutOutBorder&&) = delete;
        CPACSControlSurfaceSkinCutOutBorder& operator=(CPACSControlSurfaceSkinCutOutBorder&&) = delete;
    };
} // namespace generated

// CPACSControlSurfaceSkinCutOutBorder is customized, use type CCPACSControlSurfaceSkinCutOutBorder directly

// Aliases in tigl namespace
using CCPACSControlSurfaceWingCutOut = generated::CPACSControlSurfaceWingCutOut;
} // namespace tigl
