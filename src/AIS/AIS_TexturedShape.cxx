// Created on: 2001-07-02
// Created by: Mathias BOSSHARD
// Copyright (c) 2001-2014 OPEN CASCADE SAS
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

// Modified:
////////////////////////////////////////////////////////////////////////


#include <AIS_TexturedShape.ixx>
#include <Standard_ErrorHandler.hxx>

#include <AIS_Drawer.hxx>
#include <AIS_InteractiveContext.hxx>
#include <BRepTools.hxx>
#include <gp_Pnt2d.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_Group.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_Texture2Dmanual.hxx>
#include <Precision.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Root.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <StdPrs_ShadedShape.hxx>
#include <StdPrs_WFDeflectionShape.hxx>
#include <StdPrs_WFShape.hxx>
#include <TopExp_Explorer.hxx>

//=======================================================================
//function : AIS_TexturedShape
//purpose  :
//=======================================================================
AIS_TexturedShape::AIS_TexturedShape (const TopoDS_Shape& theShape)
: AIS_Shape (theShape),
  myPredefTexture (Graphic3d_NameOfTexture2D(0)),
  myTextureFile (""),
  DoRepeat (Standard_True),
  myURepeat (1.0),
  myVRepeat (1.0),
  DoMapTexture (Standard_True),
  DoSetTextureOrigin (Standard_True),
  myUOrigin (0.0),
  myVOrigin (0.0),
  DoSetTextureScale (Standard_True),
  myScaleU (1.0),
  myScaleV (1.0),
  DoShowTriangles (Standard_False),
  myModulate (Standard_True)
{
}

//=======================================================================
//function : SetTextureFileName
//purpose  :
//=======================================================================
void AIS_TexturedShape::SetTextureFileName (const TCollection_AsciiString& theTextureFileName)
{
  if (theTextureFileName.IsIntegerValue())
  {
    if (theTextureFileName.IntegerValue() < Graphic3d_Texture2D::NumberOfTextures()
     && theTextureFileName.IntegerValue() >= 0)
    {
      myPredefTexture = Graphic3d_NameOfTexture2D (theTextureFileName.IntegerValue());
    }
    else
    {
      std::cout << "Texture " << theTextureFileName << " doesn't exist \n";
      std::cout << "Using Texture 0 instead ...\n";
      myPredefTexture = Graphic3d_NameOfTexture2D (0);
    }
    myTextureFile = "";
  }
  else
  {
    myTextureFile   = theTextureFileName;
    myPredefTexture = Graphic3d_NameOfTexture2D (Graphic3d_NOT_2D_UNKNOWN);
  }
}

//=======================================================================
//function : SetTextureRepeat
//purpose  :
//=======================================================================

void AIS_TexturedShape::SetTextureRepeat (const Standard_Boolean theRepeatYN,
                                          const Standard_Real    theURepeat,
                                          const Standard_Real    theVRepeat)
{
  DoRepeat  = theRepeatYN;
  myURepeat = theURepeat;
  myVRepeat = theVRepeat;
}

//=======================================================================
//function : SetTextureMapOn
//purpose  :
//=======================================================================

void AIS_TexturedShape::SetTextureMapOn()
{
  DoMapTexture = Standard_True;
}

//=======================================================================
//function : SetTextureMapOff
//purpose  :
//=======================================================================

void AIS_TexturedShape::SetTextureMapOff()
{
  DoMapTexture = Standard_False;
}

//=======================================================================
//function : SetTextureOrigin
//purpose  :
//=======================================================================

void AIS_TexturedShape::SetTextureOrigin (const Standard_Boolean toSetTextureOriginYN,
                                          const Standard_Real    theUOrigin,
                                          const Standard_Real    theVOrigin)
{
  DoSetTextureOrigin = toSetTextureOriginYN;
  myUOrigin = theUOrigin;
  myVOrigin = theVOrigin;
}

//=======================================================================
//function : SetTextureScale
//purpose  :
//=======================================================================

void AIS_TexturedShape::SetTextureScale (const Standard_Boolean toSetTextureScaleYN,
                                         const Standard_Real    theScaleU,
                                         const Standard_Real    theScaleV)
{
  DoSetTextureScale = toSetTextureScaleYN;
  myScaleU = theScaleU;
  myScaleV = theScaleV;
}

//=======================================================================
//function : ShowTriangles
//purpose  :
//=======================================================================

void AIS_TexturedShape::ShowTriangles (const Standard_Boolean toShowTrianglesYN)
{
  DoShowTriangles = toShowTrianglesYN;
}

//=======================================================================
//function : EnableTextureModulate
//purpose  :
//=======================================================================

void AIS_TexturedShape::EnableTextureModulate()
{
  myModulate = Standard_True;
}

//=======================================================================
//function : DisableTextureModulate
//purpose  :
//=======================================================================

void AIS_TexturedShape::DisableTextureModulate()
{
  myModulate = Standard_False;
}

//=======================================================================
//function : UpdateAttributes
//purpose  :
//=======================================================================

void AIS_TexturedShape::UpdateAttributes()
{
  Prs3d_ShadingAspect aDummy;
  myAspect = aDummy.Aspect();
  Handle(Prs3d_Presentation) aPrs = Presentation();
  if (!DoMapTexture)
  {
    myAspect->SetTextureMapOff();
    return;
  }

  if (myPredefTexture != Graphic3d_NOT_2D_UNKNOWN)
    mytexture = new Graphic3d_Texture2Dmanual (myPredefTexture);
  else
    mytexture = new Graphic3d_Texture2Dmanual (myTextureFile.ToCString());

  myAspect->SetTextureMapOn();

  myAspect->SetTextureMap (mytexture);
  if (!mytexture->IsDone())
  {
    std::cout << "An error occured while building texture \n";
    return;
  }

  if (DoShowTriangles)
    myAspect->SetEdgeOn();
  else
    myAspect->SetEdgeOff();

  Prs3d_Root::CurrentGroup (aPrs)->SetGroupPrimitivesAspect (myAspect);
}

//=======================================================================
//function : Compute
//purpose  :
//=======================================================================

void AIS_TexturedShape::Compute (const Handle(PrsMgr_PresentationManager3d)& /*thePresManager*/,
                                 const Handle(Prs3d_Presentation)&           thePrs,
                                 const Standard_Integer                      theMode)
{
  thePrs->Clear();

  if (myshape.IsNull())
  {
    return;
  }

  if (myshape.ShapeType() > TopAbs_FACE && myshape.ShapeType() < TopAbs_SHAPE)
  {
    thePrs->SetVisual (Graphic3d_TOS_ALL);
    thePrs->SetDisplayPriority (myshape.ShapeType() + 2);
  }

  if (myshape.ShapeType() == TopAbs_COMPOUND)
  {
    TopExp_Explorer anExplor (myshape, TopAbs_VERTEX);
    if (!anExplor.More())
    {
      return;
    }
  }

  if (IsInfinite())
  {
    thePrs->SetInfiniteState (Standard_True);
  }

  switch (theMode)
  {
    case 0: // Wireframe
    {
      StdPrs_WFDeflectionShape::Add (thePrs, myshape, myDrawer);
      break;
    }
    case 1: // Shading
    {
      Standard_Real prevangle = 0.0;
      Standard_Real newangle = 0.0;
      Standard_Real prevcoeff = 0.0;
      Standard_Real newcoeff = 0.0;

      Standard_Boolean isOwnDeviationAngle = OwnDeviationAngle(newangle,prevangle);
      Standard_Boolean isOwnDeviationCoefficient = OwnDeviationCoefficient(newcoeff,prevcoeff);
      if (((Abs (newangle - prevangle) > Precision::Angular()) && isOwnDeviationAngle) ||
          ((Abs (newcoeff - prevcoeff) > Precision::Confusion()) && isOwnDeviationCoefficient)) {
        BRepTools::Clean (myshape);
      }
      if (myshape.ShapeType() > TopAbs_FACE)
      {
        StdPrs_WFDeflectionShape::Add (thePrs, myshape, myDrawer);
        break;
      }
      myDrawer->SetShadingAspectGlobal (Standard_False);
      if (IsInfinite())
      {
        StdPrs_WFDeflectionShape::Add (thePrs, myshape, myDrawer);
        break;
      }
      try
      {
        OCC_CATCH_SIGNALS
        StdPrs_ShadedShape::Add (thePrs, myshape, myDrawer);
      }
      catch (Standard_Failure)
      {
        std::cout << "AIS_TexturedShape::Compute() in ShadingMode failed \n";
        StdPrs_WFShape::Add (thePrs, myshape, myDrawer);
      }
      break;
    }

    case 2: // Bounding box
    {
      if (IsInfinite())
      {
        StdPrs_WFDeflectionShape::Add (thePrs, myshape, myDrawer);
      }
      else
      {
        AIS_Shape::DisplayBox (thePrs, BoundingBox(), myDrawer);
      }
      break;
    }

    case 3: // texture mapping on triangulation
    {
      BRepTools::Clean (myshape);
      BRepTools::Update (myshape);

      {
        Handle(Prs3d_ShadingAspect) aPrs3d_ShadingAspect = new Prs3d_ShadingAspect();
        myAspect = aPrs3d_ShadingAspect->Aspect();

        // Issue 23115: copy polygon offset settings passed through myDrawer
        if (HasPolygonOffsets())
        {
          Standard_Integer aMode;
          Standard_ShortReal aFactor, aUnits;
          PolygonOffsets(aMode, aFactor, aUnits);
          myAspect->SetPolygonOffsets(aMode, aFactor, aUnits);
        }
      }
      if (!DoMapTexture)
      {
        myAspect->SetTextureMapOff();
        return;
      }
      myAspect->SetTextureMapOn();

      if (myPredefTexture != Graphic3d_NOT_2D_UNKNOWN)
        mytexture = new Graphic3d_Texture2Dmanual (myPredefTexture);
      else
        mytexture = new Graphic3d_Texture2Dmanual (myTextureFile.ToCString());

      if (!mytexture->IsDone())
      {
        std::cout << "An error occured while building texture \n";
        return;
      }

      if (myModulate)
        mytexture->EnableModulate();
      else
        mytexture->DisableModulate();

      myAspect->SetTextureMap (mytexture);
      if (DoShowTriangles)
        myAspect->SetEdgeOn();
      else
        myAspect->SetEdgeOff();

      if (DoRepeat)
        mytexture->EnableRepeat();
      else
        mytexture->DisableRepeat();

      const gp_Pnt2d aUVOrigin (myUOrigin, myVOrigin);
      const gp_Pnt2d aUVRepeat (myURepeat, myVRepeat);
      const gp_Pnt2d aUVScale  (myScaleU,  myScaleV);
      try
      {
        OCC_CATCH_SIGNALS
        StdPrs_ShadedShape::Add (thePrs, myshape, myDrawer,
                                 Standard_True, aUVOrigin, aUVRepeat, aUVScale);
        // within primitive arrays - object should be in one group of primitives
        Prs3d_Root::CurrentGroup (thePrs)->SetGroupPrimitivesAspect (myAspect);
      }
      catch (Standard_Failure)
      {
        std::cout << "AIS_TexturedShape::Compute() in ShadingMode failed \n";
        StdPrs_WFShape::Add (thePrs, myshape, myDrawer);
      }
      break;
    }
  }
}

Standard_Boolean AIS_TexturedShape::TextureMapState() const
{
  return DoMapTexture;
}

Standard_Real AIS_TexturedShape::URepeat() const
{
  return myURepeat;
}

Standard_Boolean AIS_TexturedShape::TextureRepeat() const
{
  return DoRepeat;
}

Standard_Real AIS_TexturedShape::Deflection() const
{
  return myDeflection;
}

Standard_CString AIS_TexturedShape::TextureFile() const
{
  return myTextureFile.ToCString();
}

Standard_Real AIS_TexturedShape::VRepeat() const
{
  return myVRepeat;
}

Standard_Boolean AIS_TexturedShape::ShowTriangles() const
{
  return DoShowTriangles;
}

Standard_Real AIS_TexturedShape::TextureUOrigin() const
{
  return myUOrigin;
}

Standard_Real AIS_TexturedShape::TextureVOrigin() const
{
  return myVOrigin;
}

Standard_Real AIS_TexturedShape::TextureScaleU() const
{
  return myScaleU;
}

Standard_Real AIS_TexturedShape::TextureScaleV() const
{
  return myScaleV;
}

Standard_Boolean AIS_TexturedShape::TextureScale() const
{
  return DoSetTextureScale;
}

Standard_Boolean AIS_TexturedShape::TextureOrigin() const
{
  return DoSetTextureOrigin;
}

Standard_Boolean AIS_TexturedShape::TextureModulate() const
{
  return myModulate;
}
