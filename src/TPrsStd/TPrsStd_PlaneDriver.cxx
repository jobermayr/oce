// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and / or modify it
// under the terms of the GNU Lesser General Public version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

#include <TPrsStd_PlaneDriver.ixx>

#include <TDF_Label.hxx>
#include <TDataXtd_Plane.hxx>
//#include <TDataStd_Datum.hxx>
#include <TDataXtd_Geometry.hxx>
#include <AIS_Plane.hxx>
#include <AIS_Drawer.hxx>
#include <AIS_InteractiveContext.hxx>
#include <TNaming_NamedShape.hxx>
#include <TNaming_Tool.hxx>
#include <Geom_Plane.hxx>
#include <gp_Pln.hxx>

//=======================================================================
//function :
//purpose  : 
//=======================================================================
TPrsStd_PlaneDriver::TPrsStd_PlaneDriver()
{
}

//=======================================================================
//function :
//purpose  : 
//=======================================================================
Standard_Boolean TPrsStd_PlaneDriver::Update (const TDF_Label& aLabel,
					     Handle(AIS_InteractiveObject)& anAISObject) 
{
  Handle(TDataXtd_Plane) apPlane;

  if ( !aLabel.FindAttribute(TDataXtd_Plane::GetID(), apPlane) ) {
    return Standard_False;
  }  

  gp_Pln pln;
  if (!TDataXtd_Geometry::Plane(aLabel,pln)) {
    return Standard_False;
  }
  Handle(Geom_Plane) apt = new Geom_Plane(pln);

  //  Update AIS
  Handle(AIS_Plane) aisplane;
  if (anAISObject.IsNull())
    aisplane = new AIS_Plane(apt,pln.Location());
  else {
    aisplane = Handle(AIS_Plane)::DownCast(anAISObject);
    if (aisplane.IsNull()) 
      aisplane = new AIS_Plane(apt,pln.Location());
    else {
      aisplane->SetComponent(apt); 
      aisplane->SetCenter(pln.Location());
      aisplane->ResetLocation();
      aisplane->SetToUpdate();
      aisplane->UpdateSelection();
    }
  }
  anAISObject = aisplane;
  return Standard_True;
}

