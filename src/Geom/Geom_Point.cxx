// Created on: 1993-03-10
// Created by: JCV
// Copyright (c) 1993-1999 Matra Datavision
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

#include <Geom_Point.ixx>


typedef Handle(Geom_Point) Handle(Point);
typedef Geom_Point         Point;


Standard_Real Geom_Point::Distance (const Handle(Point)& Other) const {

  gp_Pnt P1 = this->Pnt ();
  gp_Pnt P2 = Other->Pnt ();
  return P1.Distance (P2);
}


Standard_Real Geom_Point::SquareDistance (const Handle(Point)& Other) const {

  gp_Pnt P1 = this->Pnt ();
  gp_Pnt P2 = Other->Pnt ();
  return P1.SquareDistance (P2);
}
