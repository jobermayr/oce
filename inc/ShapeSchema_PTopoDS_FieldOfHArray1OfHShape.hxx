// This file is generated by WOK (CSFDBSchema).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeSchema_PTopoDS_FieldOfHArray1OfHShape_HeaderFile
#define _ShapeSchema_PTopoDS_FieldOfHArray1OfHShape_HeaderFile

#ifndef _Handle_Storage_Schema_HeaderFile
#include <Handle_Storage_Schema.hxx>
#endif
#ifndef _Storage_BaseDriver_HeaderFile
#include <Storage_BaseDriver.hxx>
#endif

#ifndef _ShapeSchema_PTopoDS_HShape_HeaderFile
#include <ShapeSchema_PTopoDS_HShape.hxx>
#endif


class PTopoDS_FieldOfHArray1OfHShape;

class ShapeSchema_PTopoDS_FieldOfHArray1OfHShape {
public:
  Standard_EXPORT static void SAdd(const PTopoDS_FieldOfHArray1OfHShape&,const Handle(Storage_Schema)& aSchema);
  Standard_EXPORT static void SWrite(const PTopoDS_FieldOfHArray1OfHShape&,Storage_BaseDriver& aDriver,const Handle(Storage_Schema)& aSchema);
  Standard_EXPORT static void SRead(PTopoDS_FieldOfHArray1OfHShape&,Storage_BaseDriver& aDriver,const Handle(Storage_Schema)& aSchema);
};
#endif