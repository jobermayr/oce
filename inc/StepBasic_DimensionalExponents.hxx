// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepBasic_DimensionalExponents_HeaderFile
#define _StepBasic_DimensionalExponents_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepBasic_DimensionalExponents_HeaderFile
#include <Handle_StepBasic_DimensionalExponents.hxx>
#endif

#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif



class StepBasic_DimensionalExponents : public MMgt_TShared {

public:

  //! Returns a DimensionalExponents <br>
  Standard_EXPORT   StepBasic_DimensionalExponents();
  
  Standard_EXPORT   virtual  void Init(const Standard_Real aLengthExponent,const Standard_Real aMassExponent,const Standard_Real aTimeExponent,const Standard_Real aElectricCurrentExponent,const Standard_Real aThermodynamicTemperatureExponent,const Standard_Real aAmountOfSubstanceExponent,const Standard_Real aLuminousIntensityExponent) ;
  
  Standard_EXPORT     void SetLengthExponent(const Standard_Real aLengthExponent) ;
  
  Standard_EXPORT     Standard_Real LengthExponent() const;
  
  Standard_EXPORT     void SetMassExponent(const Standard_Real aMassExponent) ;
  
  Standard_EXPORT     Standard_Real MassExponent() const;
  
  Standard_EXPORT     void SetTimeExponent(const Standard_Real aTimeExponent) ;
  
  Standard_EXPORT     Standard_Real TimeExponent() const;
  
  Standard_EXPORT     void SetElectricCurrentExponent(const Standard_Real aElectricCurrentExponent) ;
  
  Standard_EXPORT     Standard_Real ElectricCurrentExponent() const;
  
  Standard_EXPORT     void SetThermodynamicTemperatureExponent(const Standard_Real aThermodynamicTemperatureExponent) ;
  
  Standard_EXPORT     Standard_Real ThermodynamicTemperatureExponent() const;
  
  Standard_EXPORT     void SetAmountOfSubstanceExponent(const Standard_Real aAmountOfSubstanceExponent) ;
  
  Standard_EXPORT     Standard_Real AmountOfSubstanceExponent() const;
  
  Standard_EXPORT     void SetLuminousIntensityExponent(const Standard_Real aLuminousIntensityExponent) ;
  
  Standard_EXPORT     Standard_Real LuminousIntensityExponent() const;




  DEFINE_STANDARD_RTTI(StepBasic_DimensionalExponents)

protected:




private: 


Standard_Real lengthExponent;
Standard_Real massExponent;
Standard_Real timeExponent;
Standard_Real electricCurrentExponent;
Standard_Real thermodynamicTemperatureExponent;
Standard_Real amountOfSubstanceExponent;
Standard_Real luminousIntensityExponent;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
