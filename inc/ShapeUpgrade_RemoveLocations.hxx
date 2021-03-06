// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeUpgrade_RemoveLocations_HeaderFile
#define _ShapeUpgrade_RemoveLocations_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_ShapeUpgrade_RemoveLocations_HeaderFile
#include <Handle_ShapeUpgrade_RemoveLocations.hxx>
#endif

#ifndef _TopAbs_ShapeEnum_HeaderFile
#include <TopAbs_ShapeEnum.hxx>
#endif
#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _TopTools_DataMapOfShapeShape_HeaderFile
#include <TopTools_DataMapOfShapeShape.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class TopoDS_Shape;


//! Removes all locations sub-shapes of specified shape <br>
class ShapeUpgrade_RemoveLocations : public MMgt_TShared {

public:

  //!Empy constructor <br>
  Standard_EXPORT   ShapeUpgrade_RemoveLocations();
  //!Removes all location correspodingly to RemoveLevel. <br>
  Standard_EXPORT     Standard_Boolean Remove(const TopoDS_Shape& theShape) ;
  //!Returns shape with removed locatins. <br>
        TopoDS_Shape GetResult() const;
  //!sets level starting with that location will be removed, <br>
//!         by default TopAbs_SHAPE. In this case locations will be kept for specified shape <br>
//!         and if specified shape is TopAbs_COMPOUND for sub-shapes of first level. <br>
        void SetRemoveLevel(const TopAbs_ShapeEnum theLevel) ;
  //!sets level starting with that location will be removed.Value of level can be set to <br>
//!         TopAbs_SHAPE,TopAbs_COMPOUND,TopAbs_SOLID,TopAbs_SHELL,TopAbs_FACE.By default TopAbs_SHAPE. <br>
//!         In this case location will be removed for all shape types for exception of compound. <br>
        TopAbs_ShapeEnum RemoveLevel() const;
  //! Returns modified shape obtained from initial shape. <br>
        TopoDS_Shape ModifiedShape(const TopoDS_Shape& theInitShape) const;




  DEFINE_STANDARD_RTTI(ShapeUpgrade_RemoveLocations)

protected:




private: 

  
  Standard_EXPORT     Standard_Boolean MakeNewShape(const TopoDS_Shape& theShape,const TopoDS_Shape& theAncShape,TopoDS_Shape& theNewShape,const Standard_Boolean theRemoveLoc) ;

TopAbs_ShapeEnum myLevelRemoving;
TopoDS_Shape myShape;
TopTools_DataMapOfShapeShape myMapNewShapes;


};


#include <ShapeUpgrade_RemoveLocations.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
