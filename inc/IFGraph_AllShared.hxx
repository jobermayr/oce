// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IFGraph_AllShared_HeaderFile
#define _IFGraph_AllShared_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Interface_Graph_HeaderFile
#include <Interface_Graph.hxx>
#endif
#ifndef _Interface_GraphContent_HeaderFile
#include <Interface_GraphContent.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
class Interface_Graph;
class Standard_Transient;
class Interface_EntityIterator;


//! this class determines all Entities shared by some specific <br>
//!           ones, at any level (those which will be lead in a Transfer <br>
//!           for instance) <br>
class IFGraph_AllShared  : public Interface_GraphContent {
public:

  DEFINE_STANDARD_ALLOC

  //! creates an AllShared from a graph, empty ready to be filled <br>
  Standard_EXPORT   IFGraph_AllShared(const Interface_Graph& agraph);
  //! creates an AllShared which memrizes Entities shared by a given <br>
//!           one, at any level, including itself <br>
  Standard_EXPORT   IFGraph_AllShared(const Interface_Graph& agraph,const Handle(Standard_Transient)& ent);
  //! adds an entity and its shared ones to the list (allows to <br>
//!           cumulate all Entities shared by some ones) <br>
  Standard_EXPORT     void GetFromEntity(const Handle(Standard_Transient)& ent) ;
  //! Adds Entities from an EntityIterator and all their shared <br>
//!           ones at any level <br>
  Standard_EXPORT     void GetFromIter(const Interface_EntityIterator& iter) ;
  //! Allows to restart on a new data set <br>
  Standard_EXPORT     void ResetData() ;
  //! does the specific evaluation (shared entities atall levels) <br>
  Standard_EXPORT   virtual  void Evaluate() ;





protected:





private:



Interface_Graph thegraph;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
