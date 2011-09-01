// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepFEA_ElementOrElementGroup_HeaderFile
#define _StepFEA_ElementOrElementGroup_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _StepData_SelectType_HeaderFile
#include <StepData_SelectType.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Handle_StepFEA_ElementRepresentation_HeaderFile
#include <Handle_StepFEA_ElementRepresentation.hxx>
#endif
#ifndef _Handle_StepFEA_ElementGroup_HeaderFile
#include <Handle_StepFEA_ElementGroup.hxx>
#endif
class Standard_Transient;
class StepFEA_ElementRepresentation;
class StepFEA_ElementGroup;


//! Representation of STEP SELECT type ElementOrElementGroup <br>
class StepFEA_ElementOrElementGroup  : public StepData_SelectType {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  //! Empty constructor <br>
  Standard_EXPORT   StepFEA_ElementOrElementGroup();
  //! Recognizes a kind of ElementOrElementGroup select type <br>
//!          1 -> ElementRepresentation from StepFEA <br>
//!          2 -> ElementGroup from StepFEA <br>
//!          0 else <br>
  Standard_EXPORT     Standard_Integer CaseNum(const Handle(Standard_Transient)& ent) const;
  //! Returns Value as ElementRepresentation (or Null if another type) <br>
  Standard_EXPORT     Handle_StepFEA_ElementRepresentation ElementRepresentation() const;
  //! Returns Value as ElementGroup (or Null if another type) <br>
  Standard_EXPORT     Handle_StepFEA_ElementGroup ElementGroup() const;





protected:





private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif