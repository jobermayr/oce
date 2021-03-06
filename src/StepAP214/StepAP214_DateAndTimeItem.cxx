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

#include <StepAP214_DateAndTimeItem.ixx>
#include <Interface_Macros.hxx>

StepAP214_DateAndTimeItem::StepAP214_DateAndTimeItem () {  }

Standard_Integer StepAP214_DateAndTimeItem::CaseNum(const Handle(Standard_Transient)& ent) const
{
  if (ent.IsNull()) return 0;
  if (ent->IsKind(STANDARD_TYPE(StepBasic_ApprovalPersonOrganization))) return 1;
  if (ent->IsKind(STANDARD_TYPE(StepAP214_AppliedPersonAndOrganizationAssignment))) return 2;
  if (ent->IsKind(STANDARD_TYPE(StepAP214_AppliedOrganizationAssignment))) return 3;
  if (ent->IsKind(STANDARD_TYPE(StepRepr_AssemblyComponentUsageSubstitute))) return 4;
  if (ent->IsKind(STANDARD_TYPE(StepBasic_DocumentFile))) return 5;
  if (ent->IsKind(STANDARD_TYPE(StepBasic_Effectivity))) return 6;
  if (ent->IsKind(STANDARD_TYPE(StepRepr_MaterialDesignation))) return 7;
  if (ent->IsKind(STANDARD_TYPE(StepVisual_MechanicalDesignGeometricPresentationRepresentation))) return 8;
  if (ent->IsKind(STANDARD_TYPE(StepVisual_PresentationArea))) return 9;
  if (ent->IsKind(STANDARD_TYPE(StepBasic_Product))) return 10;
  if (ent->IsKind(STANDARD_TYPE(StepBasic_ProductDefinition))) return 11;
  if (ent->IsKind(STANDARD_TYPE(StepBasic_ProductDefinitionFormation))) return 12;
  if (ent->IsKind(STANDARD_TYPE(StepBasic_ProductDefinitionRelationship))) return 13;
  if (ent->IsKind(STANDARD_TYPE(StepRepr_PropertyDefinition))) return 14;
  if (ent->IsKind(STANDARD_TYPE(StepShape_ShapeRepresentation))) return 15;
  if (ent->IsKind(STANDARD_TYPE(StepBasic_SecurityClassification))) return 16;
  
  return 0;
}

Handle(StepBasic_ApprovalPersonOrganization) StepAP214_DateAndTimeItem::ApprovalPersonOrganization () const
{
	return GetCasted(StepBasic_ApprovalPersonOrganization,Value());
}

Handle(StepAP214_AppliedPersonAndOrganizationAssignment) StepAP214_DateAndTimeItem::AppliedPersonAndOrganizationAssignment () const
{
	return GetCasted(StepAP214_AppliedPersonAndOrganizationAssignment,Value());
}

Handle(StepAP214_AppliedOrganizationAssignment) StepAP214_DateAndTimeItem::AppliedOrganizationAssignment() const
{  return GetCasted(StepAP214_AppliedOrganizationAssignment,Value());  }


Handle(StepBasic_Effectivity) StepAP214_DateAndTimeItem::Effectivity() const
{  return GetCasted(StepBasic_Effectivity,Value());  }


