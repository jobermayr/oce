// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepAP214_AppliedExternalIdentificationAssignment_HeaderFile
#define _StepAP214_AppliedExternalIdentificationAssignment_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepAP214_AppliedExternalIdentificationAssignment_HeaderFile
#include <Handle_StepAP214_AppliedExternalIdentificationAssignment.hxx>
#endif

#ifndef _Handle_StepAP214_HArray1OfExternalIdentificationItem_HeaderFile
#include <Handle_StepAP214_HArray1OfExternalIdentificationItem.hxx>
#endif
#ifndef _StepBasic_ExternalIdentificationAssignment_HeaderFile
#include <StepBasic_ExternalIdentificationAssignment.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
#ifndef _Handle_StepBasic_IdentificationRole_HeaderFile
#include <Handle_StepBasic_IdentificationRole.hxx>
#endif
#ifndef _Handle_StepBasic_ExternalSource_HeaderFile
#include <Handle_StepBasic_ExternalSource.hxx>
#endif
class StepAP214_HArray1OfExternalIdentificationItem;
class TCollection_HAsciiString;
class StepBasic_IdentificationRole;
class StepBasic_ExternalSource;


//! Representation of STEP entity AppliedExternalIdentificationAssignment <br>
class StepAP214_AppliedExternalIdentificationAssignment : public StepBasic_ExternalIdentificationAssignment {

public:

  //! Empty constructor <br>
  Standard_EXPORT   StepAP214_AppliedExternalIdentificationAssignment();
  //! Initialize all fields (own and inherited) <br>
  Standard_EXPORT     void Init(const Handle(TCollection_HAsciiString)& aIdentificationAssignment_AssignedId,const Handle(StepBasic_IdentificationRole)& aIdentificationAssignment_Role,const Handle(StepBasic_ExternalSource)& aExternalIdentificationAssignment_Source,const Handle(StepAP214_HArray1OfExternalIdentificationItem)& aItems) ;
  //! Returns field Items <br>
  Standard_EXPORT     Handle_StepAP214_HArray1OfExternalIdentificationItem Items() const;
  //! Set field Items <br>
  Standard_EXPORT     void SetItems(const Handle(StepAP214_HArray1OfExternalIdentificationItem)& Items) ;




  DEFINE_STANDARD_RTTI(StepAP214_AppliedExternalIdentificationAssignment)

protected:




private: 


Handle_StepAP214_HArray1OfExternalIdentificationItem theItems;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
