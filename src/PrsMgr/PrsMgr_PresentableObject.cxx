// Created on: 1997-12-16
// Created by: Jean Louis Frenkel
// Copyright (c) 1997-1999 Matra Datavision
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

// Modified by Rob
// 16-dec-1997  : Update Flag for Presentations. 


#include <PrsMgr_PresentableObject.ixx>
#include <PrsMgr_Presentation.hxx>
#include <PrsMgr_Presentation3d.hxx>
#include <PrsMgr_ModedPresentation.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <TColStd_ListIteratorOfListOfInteger.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <Graphic3d_TypeOfStructure.hxx>
#include <Geom_Transformation.hxx>

//=======================================================================
//function : PrsMgr_PresentableObject
//purpose  : 
//=======================================================================
PrsMgr_PresentableObject::PrsMgr_PresentableObject(const PrsMgr_TypeOfPresentation3d aTypeOfPresentation3d)
     :myPresentations(),myTypeOfPresentation3d(aTypeOfPresentation3d)
{
  myTransformPersistence.Flag = 0;
  myTransformPersistence.Point.x = 0.0;
  myTransformPersistence.Point.y = 0.0;
  myTransformPersistence.Point.z = 0.0;
}

//=======================================================================
//function : Fill
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::Fill (const Handle(PrsMgr_PresentationManager)& aPresentationManager,
                                     const Handle(PrsMgr_Presentation)& aPresentation,
                                     const Standard_Integer aMode)
{
  if (aPresentation->DynamicType() == STANDARD_TYPE (PrsMgr_Presentation3d))
  {
    Handle(PrsMgr_PresentationManager3d) aPrsMgr3d =
      (Handle(PrsMgr_PresentationManager3d)&)aPresentationManager;
    Handle(PrsMgr_Presentation3d) aPrs3d = 
      (Handle(PrsMgr_Presentation3d)&)aPresentation;
    Handle(Prs3d_Presentation) aStruct3d = aPrs3d->Presentation();

    Compute (aPrsMgr3d, aStruct3d, aMode);
    UpdateLocation (aStruct3d);
    aStruct3d->SetClipPlanes (myClipPlanes);
    aStruct3d->SetTransformPersistence (GetTransformPersistenceMode(), GetTransformPersistencePoint());
  }
}

//=======================================================================
//function : Compute
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::Compute(const Handle(PrsMgr_PresentationManager3d)& /*aPresentationManager*/,
				       const Handle(Prs3d_Presentation)& /*aPresentation*/,
                                       const Standard_Integer /*aMode*/) 
{
  Standard_NotImplemented::Raise("cannot compute in a 3d visualizer");
}

//=======================================================================
//function : Compute
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::Compute(const Handle(Prs3d_Projector)& /*aProjector*/,
                                       const Handle(Prs3d_Presentation)& /*aPresentation*/)
{
  Standard_NotImplemented::Raise("cannot compute under a specific projector");
}

//=======================================================================
//function : Compute
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::Compute(const Handle(Prs3d_Projector)& /* aProjector*/,
                                       const Handle(Geom_Transformation)& /*aTrsf*/,
				                               const Handle(Prs3d_Presentation)& /*aPresentation*/)
{
  Standard_NotImplemented::Raise("cannot compute under a specific projector");
}

//=======================================================================
//function : Update
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::Update (const Standard_Boolean AllModes) {
  Standard_Integer l = myPresentations.Length();
  Handle(PrsMgr_PresentationManager) PM; 
  for (Standard_Integer i=1; i <= l; i++) {
    PM = myPresentations(i).Presentation()->PresentationManager();
    if(AllModes) 
      PM->Update(this,myPresentations(i).Mode());
    else{
      if(PM->IsDisplayed(this,myPresentations(i).Mode()) ||
	 PM->IsHighlighted(this,myPresentations(i).Mode())){
	PM->Update(this,myPresentations(i).Mode());
      }
      else
	SetToUpdate(myPresentations(i).Mode());
    }
  }
}

//=======================================================================
//function : Update
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::Update (const Standard_Integer aMode, const Standard_Boolean ClearOther) {
  Standard_Integer l = myPresentations.Length();
  for (Standard_Integer i=1; i <= l; i++) {
    if( myPresentations(i).Mode() == aMode){
       Handle(PrsMgr_PresentationManager) PM=
	 myPresentations(i).Presentation()->PresentationManager();
       
       if(PM->IsDisplayed(this,aMode) ||
	  PM->IsHighlighted(this,aMode)){
	 PM->Update(this,aMode);
	 myPresentations(i).Presentation()->SetUpdateStatus(Standard_False);
	 
       }
       else
	 SetToUpdate(myPresentations(i).Mode());
     }
    
  }
  if(ClearOther) {
    PrsMgr_Presentations save;
    save =  myPresentations; 
    myPresentations.Clear();
    for (Standard_Integer i=1; i <= l; i++) {
      if( save(i).Mode() == aMode) myPresentations.Append(save(i));
    }
  }

}

//=======================================================================
//function : Presentations
//purpose  : 
//=======================================================================
PrsMgr_Presentations& PrsMgr_PresentableObject::Presentations() {
  return myPresentations;
}

//=======================================================================
//function : HasLocation
//purpose  : 
//=======================================================================
Standard_Boolean PrsMgr_PresentableObject::HasLocation() const 
{
  return !Location().IsIdentity();
}

//=======================================================================
//function : SetToUpdate
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::SetToUpdate(const Standard_Integer aMode)
{
  for(Standard_Integer IP =1; IP<=myPresentations.Length();IP++){
    if(myPresentations(IP).Mode()==aMode)
      myPresentations(IP).Presentation()->SetUpdateStatus(Standard_True);
  }
}

//=======================================================================
//function : SetToUpdate
//purpose  :
//=======================================================================
void PrsMgr_PresentableObject::SetToUpdate()
{
  for(Standard_Integer IP =1; IP<=myPresentations.Length();IP++){
    myPresentations(IP).Presentation()->SetUpdateStatus(Standard_True);
  }
}

//=======================================================================
//function : ToBeUpdated
//purpose  : gets the list of modes to be updated
//=======================================================================
void PrsMgr_PresentableObject::ToBeUpdated(TColStd_ListOfInteger& OutList) const
{
  OutList.Clear();
  // on dimensionne les buckets a la taille de la seq.
  static TColStd_MapOfInteger MI(myPresentations.Length()); 
  
  for(Standard_Integer IP =1; IP<=myPresentations.Length();IP++){
    const PrsMgr_ModedPresentation& MP = myPresentations(IP);
    if(MP.Presentation()->MustBeUpdated())
      if(!MI.Contains(MP.Mode())){
	OutList.Append(MP.Mode());
	MI.Add(MP.Mode());
      }
  }
  MI.Clear();
}

//=======================================================================
//function : SetTypeOfPresentation
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::SetTypeOfPresentation(const PrsMgr_TypeOfPresentation3d aType)
{
  myTypeOfPresentation3d = aType;
  
  for(Standard_Integer IP =1; IP<=myPresentations.Length();IP++){
    const Handle(PrsMgr_Presentation)& P = myPresentations(IP).Presentation();
    if(P->KindOfPresentation()==PrsMgr_KOP_3D){
      Graphic3d_TypeOfStructure Typ = 
	(myTypeOfPresentation3d == PrsMgr_TOP_ProjectorDependant)?
	  Graphic3d_TOS_COMPUTED : Graphic3d_TOS_ALL;
      (*(Handle(PrsMgr_Presentation3d)*)&P)->Presentation()->SetVisual(Typ);
    }
  }
}

//=======================================================================
//function : SetLocation
//purpose  : WARNING : use with only 3D objects...
//=======================================================================
void PrsMgr_PresentableObject::SetLocation(const TopLoc_Location& aLoc) 
{
  if(aLoc.IsIdentity()) return;
  myLocation = aLoc;
  UpdateLocation();
}

//=======================================================================
//function : ReSetLocation
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::ResetLocation() 
{
  TopLoc_Location aLoc;
  Handle(Geom_Transformation) G = new Geom_Transformation(aLoc.Transformation());

  for(Standard_Integer i=1;i<=myPresentations.Length();i++){
    const Handle(PrsMgr_Presentation)& P = myPresentations(i).Presentation();
    if(P->KindOfPresentation()==PrsMgr_KOP_3D){
      (*((Handle(PrsMgr_Presentation3d)*)&P))->Transform(G);
    }
  }
  myLocation = aLoc;
}

//=======================================================================
//function : UpdateLocation
//purpose  :
//=======================================================================
void PrsMgr_PresentableObject::UpdateLocation()
{
  if(!HasLocation()) return;
  Handle(Geom_Transformation) G = new Geom_Transformation(Location().Transformation());
  if(G->Trsf().Form()==gp_Identity) return;
  for (Standard_Integer i=1;i<=myPresentations.Length();i++){
    const Handle(PrsMgr_Presentation)& P = myPresentations(i).Presentation();
    if(P->KindOfPresentation()==PrsMgr_KOP_3D){
      (*((Handle(PrsMgr_Presentation3d)*)&P))->Transform(G);
    }
  }
}

//=======================================================================
//function : UpdateLocation
//purpose  : 
//=======================================================================
void PrsMgr_PresentableObject::UpdateLocation(const Handle(Prs3d_Presentation)& P)
{
  if(myLocation.IsIdentity()) return;
  Handle(Geom_Transformation) G = new Geom_Transformation(Location().Transformation());
  P->Transform(G);
  
}

//=======================================================================
//function : SetTransformPersistence
//purpose  : 
//=======================================================================
void  PrsMgr_PresentableObject::SetTransformPersistence( const Graphic3d_TransModeFlags& TheFlag,
							 const gp_Pnt& ThePoint )
{
  myTransformPersistence.Flag = TheFlag;
  myTransformPersistence.Point.x = (Standard_ShortReal)ThePoint.X();
  myTransformPersistence.Point.y = (Standard_ShortReal)ThePoint.Y();
  myTransformPersistence.Point.z = (Standard_ShortReal)ThePoint.Z();

  Handle(Graphic3d_Structure) aStruct;
  for( Standard_Integer i = 1, n = myPresentations.Length(); i <= n; i++ ) 
    {
      Handle(PrsMgr_Presentation3d) aPrs3d =
	Handle(PrsMgr_Presentation3d)::DownCast( myPresentations(i).Presentation() );
      if ( !aPrs3d.IsNull() ) 
	{
	  aStruct = Handle(Graphic3d_Structure)::DownCast( aPrs3d->Presentation() );
	  if( !aStruct.IsNull() )
	    aStruct->SetTransformPersistence( TheFlag, ThePoint );
	}
    }
}

//=======================================================================
//function : SetTransformPersistence
//purpose  : 
//=======================================================================
void  PrsMgr_PresentableObject::SetTransformPersistence( 
				       const Graphic3d_TransModeFlags& TheFlag )
{
  SetTransformPersistence( TheFlag, gp_Pnt(0,0,0) );
}

//=======================================================================
//function : GetTransformPersistence
//purpose  : 
//=======================================================================
Graphic3d_TransModeFlags  PrsMgr_PresentableObject::GetTransformPersistenceMode() const
{
  return myTransformPersistence.Flag;
}

//=======================================================================
//function : GetTransformPersistence
//purpose  : 
//=======================================================================
gp_Pnt  PrsMgr_PresentableObject::GetTransformPersistencePoint() const
{
  return gp_Pnt( myTransformPersistence.Point.x, myTransformPersistence.Point.y, myTransformPersistence.Point.z );
}

//=======================================================================
//function : SetZLayer
//purpose  :
//=======================================================================
void PrsMgr_PresentableObject::SetZLayer 
  (const Handle(PrsMgr_PresentationManager)& thePrsMgr,
   const Standard_Integer theLayerId)
{
  if (!thePrsMgr.IsNull())
    thePrsMgr->SetZLayer (this, theLayerId);
}

//=======================================================================
//function : GetZLayer
//purpose  :
//=======================================================================
Standard_Integer PrsMgr_PresentableObject::GetZLayer 
  (const Handle(PrsMgr_PresentationManager)& thePrsMgr) const
{
  if (!thePrsMgr.IsNull())
    return thePrsMgr->GetZLayer (this);

  return -1;
}

// =======================================================================
// function : AddClipPlane
// purpose  :
// =======================================================================
void PrsMgr_PresentableObject::AddClipPlane (const Handle(Graphic3d_ClipPlane)& thePlane)
{
  // add to collection and process changes
  myClipPlanes.Append (thePlane);
  UpdateClipping();
}

// =======================================================================
// function : RemoveClipPlane
// purpose  :
// =======================================================================
void PrsMgr_PresentableObject::RemoveClipPlane (const Handle(Graphic3d_ClipPlane)& thePlane)
{
  // remove from collection and process changes
  Graphic3d_SequenceOfHClipPlane::Iterator aPlaneIt (myClipPlanes);
  for (; aPlaneIt.More(); aPlaneIt.Next())
  {
    const Handle(Graphic3d_ClipPlane)& aPlane = aPlaneIt.Value();
    if (aPlane != thePlane)
      continue;

    myClipPlanes.Remove (aPlaneIt);
    UpdateClipping();
    return;
  }
}

// =======================================================================
// function : SetClipPlanes
// purpose  :
// =======================================================================
void PrsMgr_PresentableObject::SetClipPlanes (const Graphic3d_SequenceOfHClipPlane& thePlanes)
{
  // change collection and process changes
  myClipPlanes = thePlanes;
  UpdateClipping();
}

// =======================================================================
// function : UpdateClipping
// purpose  :
// =======================================================================
void PrsMgr_PresentableObject::UpdateClipping()
{
  // affect generated structures
  for (Standard_Integer aPrsIt = 1; aPrsIt <= myPresentations.Length(); ++aPrsIt)
  {
    // pass over presentation manager 3d mechanism right to the structures -
    // we do not interested in display mode collections.
    const PrsMgr_ModedPresentation& aModedPrs = myPresentations (aPrsIt);

    Handle(PrsMgr_Presentation3d) aPrs = 
      Handle(PrsMgr_Presentation3d)::DownCast (aModedPrs.Presentation());

    if (aPrs.IsNull())
      continue;

    Handle(Prs3d_Presentation) aStruct3d = aPrs->Presentation();
    if (aStruct3d.IsNull())
      continue;

    aStruct3d->SetClipPlanes (myClipPlanes);
  }
}
