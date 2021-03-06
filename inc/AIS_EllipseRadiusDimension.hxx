// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_EllipseRadiusDimension_HeaderFile
#define _AIS_EllipseRadiusDimension_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_AIS_EllipseRadiusDimension_HeaderFile
#include <Handle_AIS_EllipseRadiusDimension.hxx>
#endif

#ifndef _gp_Elips_HeaderFile
#include <gp_Elips.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Geom_OffsetCurve_HeaderFile
#include <Handle_Geom_OffsetCurve.hxx>
#endif
#ifndef _AIS_Relation_HeaderFile
#include <AIS_Relation.hxx>
#endif
#ifndef _AIS_KindOfDimension_HeaderFile
#include <AIS_KindOfDimension.hxx>
#endif
#ifndef _AIS_KindOfSurface_HeaderFile
#include <AIS_KindOfSurface.hxx>
#endif
#ifndef _Handle_Geom_Surface_HeaderFile
#include <Handle_Geom_Surface.hxx>
#endif
class Geom_OffsetCurve;
class TopoDS_Shape;
class TCollection_ExtendedString;
class Geom_Surface;



//!  Computes  geometry  (  basis  curve  and  plane  of  dimension) <br>
//!  for  input  shape  aShape  from  TopoDS <br>
//!  Root  class  for MinRadiusDimension  and  MaxRadiusDimension <br>
class AIS_EllipseRadiusDimension : public AIS_Relation {

public:

  
  Standard_EXPORT   virtual  AIS_KindOfDimension KindOfDimension() const;
  
  Standard_EXPORT   virtual  Standard_Boolean IsMovable() const;
  
  Standard_EXPORT     void ComputeGeometry() ;




  DEFINE_STANDARD_RTTI(AIS_EllipseRadiusDimension)

protected:

  
  Standard_EXPORT   AIS_EllipseRadiusDimension(const TopoDS_Shape& aShape,const TCollection_ExtendedString& aText);

gp_Elips myEllipse;
Standard_Real myFirstPar;
Standard_Real myLastPar;
Standard_Boolean myIsAnArc;
Handle_Geom_OffsetCurve myOffsetCurve;
Standard_Real myOffset;
Standard_Boolean myIsOffset;


private: 

  
  Standard_EXPORT     void ComputeFaceGeometry() ;
  
  Standard_EXPORT     void ComputeCylFaceGeometry(const AIS_KindOfSurface aSurfType,const Handle(Geom_Surface)& aSurf,const Standard_Real Offset) ;
  
  Standard_EXPORT     void ComputePlanarFaceGeometry() ;
  
  Standard_EXPORT     void ComputeEdgeGeometry() ;



};





// other Inline functions and methods (like "C++: function call" methods)


#endif
