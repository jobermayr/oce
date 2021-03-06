// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Extrema_HArray2OfPOnCurv_HeaderFile
#define _Extrema_HArray2OfPOnCurv_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Extrema_HArray2OfPOnCurv_HeaderFile
#include <Handle_Extrema_HArray2OfPOnCurv.hxx>
#endif

#ifndef _Extrema_Array2OfPOnCurv_HeaderFile
#include <Extrema_Array2OfPOnCurv.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class Standard_RangeError;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class Standard_DimensionMismatch;
class Extrema_POnCurv;
class Extrema_Array2OfPOnCurv;



class Extrema_HArray2OfPOnCurv : public MMgt_TShared {

public:

  
      Extrema_HArray2OfPOnCurv(const Standard_Integer R1,const Standard_Integer R2,const Standard_Integer C1,const Standard_Integer C2);
  
      Extrema_HArray2OfPOnCurv(const Standard_Integer R1,const Standard_Integer R2,const Standard_Integer C1,const Standard_Integer C2,const Extrema_POnCurv& V);
  
        void Init(const Extrema_POnCurv& V) ;
  
        Standard_Integer ColLength() const;
  
        Standard_Integer RowLength() const;
  
        Standard_Integer LowerCol() const;
  
        Standard_Integer LowerRow() const;
  
        Standard_Integer UpperCol() const;
  
        Standard_Integer UpperRow() const;
  
        void SetValue(const Standard_Integer Row,const Standard_Integer Col,const Extrema_POnCurv& Value) ;
  
       const Extrema_POnCurv& Value(const Standard_Integer Row,const Standard_Integer Col) const;
  
        Extrema_POnCurv& ChangeValue(const Standard_Integer Row,const Standard_Integer Col) ;
  
       const Extrema_Array2OfPOnCurv& Array2() const;
  
        Extrema_Array2OfPOnCurv& ChangeArray2() ;




  DEFINE_STANDARD_RTTI(Extrema_HArray2OfPOnCurv)

protected:




private: 


Extrema_Array2OfPOnCurv myArray;


};

#define ItemHArray2 Extrema_POnCurv
#define ItemHArray2_hxx <Extrema_POnCurv.hxx>
#define TheArray2 Extrema_Array2OfPOnCurv
#define TheArray2_hxx <Extrema_Array2OfPOnCurv.hxx>
#define TCollection_HArray2 Extrema_HArray2OfPOnCurv
#define TCollection_HArray2_hxx <Extrema_HArray2OfPOnCurv.hxx>
#define Handle_TCollection_HArray2 Handle_Extrema_HArray2OfPOnCurv
#define TCollection_HArray2_Type_() Extrema_HArray2OfPOnCurv_Type_()

#include <TCollection_HArray2.lxx>

#undef ItemHArray2
#undef ItemHArray2_hxx
#undef TheArray2
#undef TheArray2_hxx
#undef TCollection_HArray2
#undef TCollection_HArray2_hxx
#undef Handle_TCollection_HArray2
#undef TCollection_HArray2_Type_


// other Inline functions and methods (like "C++: function call" methods)


#endif
