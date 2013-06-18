/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2013-06-18 Martin Siggel <Martin.Siggel@dlr.de>
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

#include "CTiglShapeCache.h"
#include "test.h"

#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Trsf.hxx>

TEST(ShapeCache, GetNShapes){
    tigl::CTiglShapeCache cache;
    TopoDS_Shape shape;
    
    ASSERT_EQ(0, cache.GetNShapesOfType("blubb"));
    cache.GetContainer()["blubb::0"] = shape;
    
    ASSERT_EQ(1, cache.GetNShape());
    ASSERT_EQ(1, cache.GetNShapesOfType("blubb"));
    
    cache.GetContainer()["blubb::1"] = shape;
    
    ASSERT_EQ(2, cache.GetNShape());
    ASSERT_EQ(2, cache.GetNShapesOfType("blubb"));
    
    cache.GetContainer()["flupp::0"] = shape;
    
    ASSERT_EQ(3, cache.GetNShape());
    ASSERT_EQ(2, cache.GetNShapesOfType("blubb"));
    ASSERT_EQ(1, cache.GetNShapesOfType("flupp"));
    
    cache.Clear();
    
    ASSERT_EQ(0, cache.GetNShape());
    ASSERT_EQ(0, cache.GetNShapesOfType("blubb"));
}

TEST(ShapeCache, Insert){
    tigl::CTiglShapeCache cache;
    TopoDS_Shape shape;
    
    cache.Insert(shape, "blubb");
    ASSERT_EQ(1, cache.GetNShapesOfType("blubb"));
    
    cache.Insert(shape, "blubb");
    ASSERT_EQ(2, cache.GetNShapesOfType("blubb"));
    
    cache.Insert(shape, "flubb");
    ASSERT_EQ(2, cache.GetNShapesOfType("blubb"));
    ASSERT_EQ(1, cache.GetNShapesOfType("flubb"));
}

TEST(ShapeCache, Remove){
    tigl::CTiglShapeCache cache;
    TopoDS_Shape shape;
    
    cache.Remove("blubb");
    ASSERT_EQ(0, cache.GetNShapesOfType("blubb"));
    
    cache.Insert(shape, "blubb");
    cache.Remove("blubb");
    ASSERT_EQ(0, cache.GetNShapesOfType("blubb"));
    
    cache.Insert(shape, "blubb");
    cache.Insert(shape, "blubb");
    cache.Insert(shape, "flupp");
    cache.Remove("blubb");
    ASSERT_EQ(0, cache.GetNShapesOfType("blubb"));
    ASSERT_EQ(1, cache.GetNShape());
    
    cache.Remove("flupp");
    ASSERT_EQ(0, cache.GetNShape());
}

TEST(ShapeCache, Get){
    tigl::CTiglShapeCache cache;
    
    // create 3 different shapes
    BRepBuilderAPI_MakeWire wireBuilder(BRepBuilderAPI_MakeEdge(gp_Pnt(1,0,0), gp_Pnt(1,1,0)));
    TopoDS_Shape shape1(wireBuilder.Wire()), shape2(wireBuilder.Wire()), shape3(wireBuilder.Wire());
    
    gp_Trsf trafo1, trafo2, trafo3;
    trafo1.SetScaleFactor(1.0);
    trafo2.SetScaleFactor(2.0);
    trafo3.SetScaleFactor(3.0);
    shape1.Move(trafo1);
    shape2.Move(trafo2);
    shape3.Move(trafo3);
    
    ASSERT_FALSE(shape1.IsEqual(shape2));
    ASSERT_FALSE(shape1.IsEqual(shape3));
    ASSERT_FALSE(shape2.IsEqual(shape3));
    
    ASSERT_FALSE(shape1.IsNull());
    ASSERT_FALSE(shape2.IsNull());
    ASSERT_FALSE(shape3.IsNull());
    
    TopoDS_Shape shape = cache.GetShape("blubb");
    ASSERT_EQ(1, shape.IsNull());
    
    cache.Insert(shape1, "blubb");
    shape = cache.GetShape("blubb");
    ASSERT_EQ(1, shape.IsEqual(shape1));
    ASSERT_EQ(0, shape.IsEqual(shape2));
    
    cache.Insert(shape2, "blubb");
    shape = cache.GetShape("blubb");
    ASSERT_EQ(1, shape.IsEqual(shape1));
    
    shape = cache.GetShape("blubb", 1);
    ASSERT_EQ(1, shape.IsEqual(shape2));
    
    shape = cache.GetShape("blubb", 2);
    ASSERT_EQ(1, shape.IsNull());
}
