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

#include <CCPACSStringVector.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSMaterial

    // generated from /xsd:schema/xsd:complexType[832]
    /// @brief Specific heat map, containing the specific heat capacity of a material at different temperatures.
    /// 
    /// The specific heat of a material can vary with the temperature. The vectors specificHeat and temperature
    /// must have the same size to be valid. The data should be linearly interpolated.
    /// 
    class CPACSSpecificHeatMap
    {
    public:
        TIGL_EXPORT CPACSSpecificHeatMap();
        TIGL_EXPORT virtual ~CPACSSpecificHeatMap();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSStringVector& GetTemperature() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetTemperature();

        TIGL_EXPORT virtual const CCPACSStringVector& GetSpecificHeat() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetSpecificHeat();

    protected:
        /// temperature in [K]
        CCPACSStringVector m_temperature;

        /// specific heat capacity of the material in [J/(kg*K)]
        CCPACSStringVector m_specificHeat;

    private:
        CPACSSpecificHeatMap(const CPACSSpecificHeatMap&) = delete;
        CPACSSpecificHeatMap& operator=(const CPACSSpecificHeatMap&) = delete;

        CPACSSpecificHeatMap(CPACSSpecificHeatMap&&) = delete;
        CPACSSpecificHeatMap& operator=(CPACSSpecificHeatMap&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSSpecificHeatMap = generated::CPACSSpecificHeatMap;
} // namespace tigl