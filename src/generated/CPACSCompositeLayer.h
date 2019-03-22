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
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSComposite

    // generated from /xsd:schema/xsd:complexType[146]
    /// @brief compositeLayerType
    /// 
    /// CompositeLayer type, conatining data of a composite
    /// layer
    /// 
    class CPACSCompositeLayer
    {
    public:
        TIGL_EXPORT CPACSCompositeLayer();
        TIGL_EXPORT virtual ~CPACSCompositeLayer();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetName() const;
        TIGL_EXPORT virtual void SetName(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const double& GetThickness() const;
        TIGL_EXPORT virtual void SetThickness(const double& value);

        TIGL_EXPORT virtual const double& GetPhi() const;
        TIGL_EXPORT virtual void SetPhi(const double& value);

        TIGL_EXPORT virtual const std::string& GetMaterialUID() const;
        TIGL_EXPORT virtual void SetMaterialUID(const std::string& value);

    protected:
        /// Name of layer
        boost::optional<std::string> m_name;

        /// Description of layer
        boost::optional<std::string> m_description;

        /// Thickness of layer
        double                       m_thickness;

        /// Angle of layer in degree
        double                       m_phi;

        /// Material UID of the layer
        std::string                  m_materialUID;

    private:
#ifdef HAVE_CPP11
        CPACSCompositeLayer(const CPACSCompositeLayer&) = delete;
        CPACSCompositeLayer& operator=(const CPACSCompositeLayer&) = delete;

        CPACSCompositeLayer(CPACSCompositeLayer&&) = delete;
        CPACSCompositeLayer& operator=(CPACSCompositeLayer&&) = delete;
#else
        CPACSCompositeLayer(const CPACSCompositeLayer&);
        CPACSCompositeLayer& operator=(const CPACSCompositeLayer&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSCompositeLayer = generated::CPACSCompositeLayer;
#else
typedef generated::CPACSCompositeLayer CCPACSCompositeLayer;
#endif
} // namespace tigl
