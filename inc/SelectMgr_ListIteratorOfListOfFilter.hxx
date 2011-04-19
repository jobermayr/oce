// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _SelectMgr_ListIteratorOfListOfFilter_HeaderFile
#define _SelectMgr_ListIteratorOfListOfFilter_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _Standard_Address_HeaderFile
#include <Standard_Address.hxx>
#endif
#ifndef _Handle_SelectMgr_Filter_HeaderFile
#include <Handle_SelectMgr_Filter.hxx>
#endif
#ifndef _Handle_SelectMgr_ListNodeOfListOfFilter_HeaderFile
#include <Handle_SelectMgr_ListNodeOfListOfFilter.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class Standard_NoMoreObject;
class Standard_NoSuchObject;
class SelectMgr_ListOfFilter;
class SelectMgr_Filter;
class SelectMgr_ListNodeOfListOfFilter;



class SelectMgr_ListIteratorOfListOfFilter  {
public:

  void* operator new(size_t,void* anAddress) 
  {
    return anAddress;
  }
  void* operator new(size_t size) 
  {
    return Standard::Allocate(size); 
  }
  void  operator delete(void *anAddress) 
  {
    if (anAddress) Standard::Free((Standard_Address&)anAddress); 
  }

  
  Standard_EXPORT   SelectMgr_ListIteratorOfListOfFilter();
  
  Standard_EXPORT   SelectMgr_ListIteratorOfListOfFilter(const SelectMgr_ListOfFilter& L);
  
  Standard_EXPORT     void Initialize(const SelectMgr_ListOfFilter& L) ;
  
        Standard_Boolean More() const;
  
  Standard_EXPORT     void Next() ;
  
  Standard_EXPORT     Handle_SelectMgr_Filter& Value() const;


friend class SelectMgr_ListOfFilter;



protected:





private:



Standard_Address current;
Standard_Address previous;


};

#define Item Handle_SelectMgr_Filter
#define Item_hxx <SelectMgr_Filter.hxx>
#define TCollection_ListNode SelectMgr_ListNodeOfListOfFilter
#define TCollection_ListNode_hxx <SelectMgr_ListNodeOfListOfFilter.hxx>
#define TCollection_ListIterator SelectMgr_ListIteratorOfListOfFilter
#define TCollection_ListIterator_hxx <SelectMgr_ListIteratorOfListOfFilter.hxx>
#define Handle_TCollection_ListNode Handle_SelectMgr_ListNodeOfListOfFilter
#define TCollection_ListNode_Type_() SelectMgr_ListNodeOfListOfFilter_Type_()
#define TCollection_List SelectMgr_ListOfFilter
#define TCollection_List_hxx <SelectMgr_ListOfFilter.hxx>

#include <TCollection_ListIterator.lxx>

#undef Item
#undef Item_hxx
#undef TCollection_ListNode
#undef TCollection_ListNode_hxx
#undef TCollection_ListIterator
#undef TCollection_ListIterator_hxx
#undef Handle_TCollection_ListNode
#undef TCollection_ListNode_Type_
#undef TCollection_List
#undef TCollection_List_hxx


// other Inline functions and methods (like "C++: function call" methods)


#endif