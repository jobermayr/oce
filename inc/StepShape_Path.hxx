// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepShape_Path_HeaderFile
#define _StepShape_Path_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepShape_Path_HeaderFile
#include <Handle_StepShape_Path.hxx>
#endif

#ifndef _Handle_StepShape_HArray1OfOrientedEdge_HeaderFile
#include <Handle_StepShape_HArray1OfOrientedEdge.hxx>
#endif
#ifndef _StepShape_TopologicalRepresentationItem_HeaderFile
#include <StepShape_TopologicalRepresentationItem.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Handle_StepShape_OrientedEdge_HeaderFile
#include <Handle_StepShape_OrientedEdge.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class StepShape_HArray1OfOrientedEdge;
class TCollection_HAsciiString;
class StepShape_OrientedEdge;



class StepShape_Path : public StepShape_TopologicalRepresentationItem {

public:

  //! Returns a Path <br>
  Standard_EXPORT   StepShape_Path();
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName) ;
  
  Standard_EXPORT   virtual  void Init(const Handle(TCollection_HAsciiString)& aName,const Handle(StepShape_HArray1OfOrientedEdge)& aEdgeList) ;
  
  Standard_EXPORT   virtual  void SetEdgeList(const Handle(StepShape_HArray1OfOrientedEdge)& aEdgeList) ;
  
  Standard_EXPORT   virtual  Handle_StepShape_HArray1OfOrientedEdge EdgeList() const;
  
  Standard_EXPORT   virtual  Handle_StepShape_OrientedEdge EdgeListValue(const Standard_Integer num) const;
  
  Standard_EXPORT   virtual  Standard_Integer NbEdgeList() const;




  DEFINE_STANDARD_RTTI(StepShape_Path)

protected:




private: 


Handle_StepShape_HArray1OfOrientedEdge edgeList;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
