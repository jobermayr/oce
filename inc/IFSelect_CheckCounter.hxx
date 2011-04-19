// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IFSelect_CheckCounter_HeaderFile
#define _IFSelect_CheckCounter_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IFSelect_CheckCounter_HeaderFile
#include <Handle_IFSelect_CheckCounter.hxx>
#endif

#ifndef _Handle_MoniTool_SignText_HeaderFile
#include <Handle_MoniTool_SignText.hxx>
#endif
#ifndef _IFSelect_SignatureList_HeaderFile
#include <IFSelect_SignatureList.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Interface_InterfaceModel_HeaderFile
#include <Handle_Interface_InterfaceModel.hxx>
#endif
class MoniTool_SignText;
class Interface_CheckIterator;
class Interface_InterfaceModel;


//! A CheckCounter allows to see a CheckList (i.e. CheckIterator) <br>
//!           not per entity, its messages, but per message, the entities <br>
//!           attached (count and list). Because many messages can be <br>
//!           repeated if they are due to systematic errors <br>
class IFSelect_CheckCounter : public IFSelect_SignatureList {

public:

  //! Creates a CheckCounter, empty ready to work <br>
  Standard_EXPORT   IFSelect_CheckCounter(const Standard_Boolean withlist = Standard_False);
  //! Sets a specific signature <br>
//!           Else, the current SignType (in the model) is used <br>
  Standard_EXPORT     void SetSignature(const Handle(MoniTool_SignText)& sign) ;
  //! Returns the Signature; <br>
  Standard_EXPORT     Handle_MoniTool_SignText Signature() const;
  //! Analyses a CheckIterator according a Model (which detains the <br>
//!           entities for which the CheckIterator has messages), i.e. <br>
//!           counts messages for entities <br>
//!           If <original> is True, does not consider final messages but <br>
//!             those before interpretation (such as inserting variables : <br>
//!             integers, reals, strings) <br>
//!           If <failsonly> is True, only Fails are considered <br>
//!           Remark : global messages are recorded with a Null entity <br>
  Standard_EXPORT     void Analyse(const Interface_CheckIterator& list,const Handle(Interface_InterfaceModel)& model,const Standard_Boolean original = Standard_False,const Standard_Boolean failsonly = Standard_False) ;




  DEFINE_STANDARD_RTTI(IFSelect_CheckCounter)

protected:




private: 


Handle_MoniTool_SignText thesign;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif