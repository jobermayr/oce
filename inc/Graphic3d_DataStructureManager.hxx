// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Graphic3d_DataStructureManager_HeaderFile
#define _Graphic3d_DataStructureManager_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Graphic3d_DataStructureManager_HeaderFile
#include <Handle_Graphic3d_DataStructureManager.hxx>
#endif

#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif


//!	This class allows the definition of a manager to <br>
//!		which the graphic objects are associated. <br>
//!		It allows them to be globally manipulated. <br>
//!		It defines the global attributes. <br>
class Graphic3d_DataStructureManager : public MMgt_TShared {

public:

  //! Deletes the manager <me>. <br>
  Standard_EXPORT   virtual  void Destroy() ;
~Graphic3d_DataStructureManager()
{
  Destroy();
}



  DEFINE_STANDARD_RTTI(Graphic3d_DataStructureManager)

protected:

  //! Initializes the manager <me>. <br>
  Standard_EXPORT   Graphic3d_DataStructureManager();



private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif
