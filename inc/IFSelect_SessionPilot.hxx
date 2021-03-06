// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IFSelect_SessionPilot_HeaderFile
#define _IFSelect_SessionPilot_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IFSelect_SessionPilot_HeaderFile
#include <Handle_IFSelect_SessionPilot.hxx>
#endif

#ifndef _Handle_IFSelect_WorkSession_HeaderFile
#include <Handle_IFSelect_WorkSession.hxx>
#endif
#ifndef _TCollection_AsciiString_HeaderFile
#include <TCollection_AsciiString.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _TColStd_Array1OfAsciiString_HeaderFile
#include <TColStd_Array1OfAsciiString.hxx>
#endif
#ifndef _TColStd_Array1OfInteger_HeaderFile
#include <TColStd_Array1OfInteger.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _TColStd_SequenceOfAsciiString_HeaderFile
#include <TColStd_SequenceOfAsciiString.hxx>
#endif
#ifndef _IFSelect_Activator_HeaderFile
#include <IFSelect_Activator.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Handle_IFSelect_WorkLibrary_HeaderFile
#include <Handle_IFSelect_WorkLibrary.hxx>
#endif
#ifndef _IFSelect_ReturnStatus_HeaderFile
#include <IFSelect_ReturnStatus.hxx>
#endif
#ifndef _Handle_IFSelect_SignCounter_HeaderFile
#include <Handle_IFSelect_SignCounter.hxx>
#endif
#ifndef _IFSelect_PrintCount_HeaderFile
#include <IFSelect_PrintCount.hxx>
#endif
class IFSelect_WorkSession;
class Standard_Transient;
class IFSelect_WorkLibrary;
class TCollection_AsciiString;
class IFSelect_SignCounter;


//! A SessionPilot is intended to make easier the use of a <br>
//!           WorkSession. It receives commands, under alphanumeric form, <br>
//!           then calls a library of Activators to interprete and run them. <br>
//! <br>
//!           Then, WorkSession just records data required to work : <br>
//!           Rules for Selection, Dispatch ... ; File Data (InterfaceModel <br>
//!           and results of Evaluations and Transfer as required). <br>
//!           SessionPilot records and works with alphanumeric commands and <br>
//!           their results (under a very simple form). It calls a list of <br>
//!           Activators to perform the actions. <br>
//! <br>
//!           A Command can have several forms : <br>
//!           - classic execution, to list, evaluate, or enrich the session <br>
//!           - command which creates a new item (a Selection for instance) <br>
//!             such a command should not add it to the session, but make it <br>
//!             recorded by the Pilot (method RecordItem). The Pilot will <br>
//!             add the item in the session, with no name <br>
//!           -> such a command may be called : <br>
//!             - directly, it will add an item with no name <br>
//!             - by command xset, in the following form : <br>
//!             xset name command ...  calls the command and adds the item <br>
//!               to the session under the specified name (if not yet known) <br>
//! <br>
//!           Thus, to a specific Norm or way of working, only Activators <br>
//!           change. A specific Initialisation can be done by starting <br>
//!           with a specific set of commands. <br>
//! <br>
//!           In addition, SessionPilot is a sub-type of Activator, to <br>
//!           recognize some built-in commands : exit/x, help/?, control of <br>
//!           command line, and commands xstep xset ... See method Do <br>
//! <br>
//!           At least, empty lines and comment lines (beginning by '#') <br>
//!           are skipped (comment lines are display if read from file) <br>
class IFSelect_SessionPilot : public IFSelect_Activator {

public:

  //! Creates an empty SessionPilot, with a prompt which will be <br>
//!           displayed on querying commands. If not precised (""), this <br>
//!           prompt is set to "Test-XSTEP>" <br>
  Standard_EXPORT   IFSelect_SessionPilot(const Standard_CString prompt = "");
  //! Returns the WorkSession which is worked on <br>
  Standard_EXPORT     Handle_IFSelect_WorkSession Session() const;
  //! Returns the WorKlibrary (Null if not set). WorkLibrary is used <br>
//!           to Read and Write Files, according to the Norm <br>
  Standard_EXPORT     Handle_IFSelect_WorkLibrary Library() const;
  //! Returns the Record Mode for Commands. Default is False. <br>
  Standard_EXPORT     Standard_Boolean RecordMode() const;
  //! Sets a WorkSession to be worked on <br>
  Standard_EXPORT     void SetSession(const Handle(IFSelect_WorkSession)& WS) ;
  //! Sets a WorkLibrary <br>
  Standard_EXPORT     void SetLibrary(const Handle(IFSelect_WorkLibrary)& WL) ;
  //! Changes the RecordMode. <br>
  Standard_EXPORT     void SetRecordMode(const Standard_Boolean mode) ;
  //! Sets the value of the Command Line to be interpreted <br>
//!           Also prepares the interpretation (splitting by blanks) <br>
  Standard_EXPORT     void SetCommandLine(const TCollection_AsciiString& command) ;
  //! Returns the Command Line to be interpreted <br>
  Standard_EXPORT    const TCollection_AsciiString& CommandLine() const;
  //! Returns the part of the command line which begins at argument <br>
//!           <numarg> between 0 and NbWords-1 (by default, all the line) <br>
//!           Empty string if out of range <br>
  Standard_EXPORT     Standard_CString CommandPart(const Standard_Integer numarg = 0) const;
  //! Returns the count of words of the Command Line, separated by <br>
//!           blanks : 0 if empty, one if a command without args, else it <br>
//!           gives the count of args minus one. <br>
//!  Warning : limited to 10 (command title + 9 args) <br>
  Standard_EXPORT     Standard_Integer NbWords() const;
  //! Returns a word given its rank in the Command Line. Begins at 0 <br>
//!           which is the Command Title, 1 is the 1st arg., etc... <br>
  Standard_EXPORT    const TCollection_AsciiString& Word(const Standard_Integer num) const;
  //! Returns a word given its rank, as a CString. <br>
//!           As for Word, begins at 0 (the command name), etc... <br>
  Standard_EXPORT     Standard_CString Arg(const Standard_Integer num) const;
  //! Removes a word given its rank. Returns True if Done, False if <br>
//!           <num> is out of range <br>
  Standard_EXPORT     Standard_Boolean RemoveWord(const Standard_Integer num) ;
  //! Returns the count of recorded Commands <br>
  Standard_EXPORT     Standard_Integer NbCommands() const;
  //! Returns a recorded Command, given its rank (from 1) <br>
  Standard_EXPORT    const TCollection_AsciiString& Command(const Standard_Integer num) const;
  //! Allows to associate a Transient Value with the last execution <br>
//!           as a partial result <br>
//!           Returns RetDone if item is not Null, RetFail if item is Null <br>
//!           Remark : it is nullified for each Perform <br>
  Standard_EXPORT     IFSelect_ReturnStatus RecordItem(const Handle(Standard_Transient)& item) ;
  //! Returns the Transient Object which was recorded with the <br>
//!           current Line Command. If none was, returns a Null Handle <br>
  Standard_EXPORT     Handle_Standard_Transient RecordedItem() const;
  //! Clears the recorded informations (commands, objects) <br>
  Standard_EXPORT     void Clear() ;
  //! Reads commands from a Script File, named <file>. By default <br>
//!           (file = ""), reads from standard input with a prompt <br>
//!           Else (reading from a file), the read commands are displayed <br>
//!           onto standard output. Allows nested reads. Reading is stopped <br>
//!           either by command x or exit, or by reaching end of file <br>
//!           Return Value follows the rules of Do : RetEnd for normal end, <br>
//!           RetFail if script could not be opened <br>
  Standard_EXPORT     IFSelect_ReturnStatus ReadScript(const Standard_CString file = "") ;
  //! Executes the Command, itself (for built-in commands, which <br>
//!           have priority) or by using the list of Activators. <br>
//!           The value returned is : RetVoid if nothing done (void command) <br>
//!           RetDone if execution OK, RetEnd if END OF SESSION, RetError if <br>
//!           command unknown or incorrect, RetFail if error on execution <br>
//!           If execution is OK and RecordMode is set, this Command Line is <br>
//!           recorded to the list (see below). <br>
  Standard_EXPORT     IFSelect_ReturnStatus Perform() ;
  //! Executes the Commands, except that the command name (word 0) <br>
//!           is aliased. The rest of the command line is unchanged <br>
//!           If <alias> is empty, Executes with no change <br>
//! <br>
//!           Error status is returned if the alias is unknown as command <br>
  Standard_EXPORT     IFSelect_ReturnStatus ExecuteAlias(const TCollection_AsciiString& aliasname) ;
  //! Sets the Command then tries to execute it. Return value : <br>
//!           same as for Perform <br>
  Standard_EXPORT     IFSelect_ReturnStatus Execute(const TCollection_AsciiString& command) ;
  //! Executes a Counter in a general way <br>
//!           If <numword> is greater than count of command words, it counts <br>
//!           all the model. Else it considers the word <numword> as the <br>
//!           identifier of a Selection <br>
//!           <mode> gives the mode of printing results, default is <br>
//!           CountByItem <br>
  Standard_EXPORT     IFSelect_ReturnStatus ExecuteCounter(const Handle(IFSelect_SignCounter)& counter,const Standard_Integer numword,const IFSelect_PrintCount mode = IFSelect_CountByItem) ;
  //! Interprets a string value as an entity number : <br>
//!           if it gives an integer, returns its value <br>
//!           else, considers it as ENtityLabel (preferably case sensitive) <br>
//!           in case of failure, returns 0 <br>
  Standard_EXPORT     Standard_Integer Number(const Standard_CString val) const;
  //! Processes specific commands, which are : <br>
//!           x or exit for end of session <br>
//!           ? or help for help messages <br>
//!           xcommand to control command lines (Record Mode, List, Clear, <br>
//!             File Output ...) <br>
//!           xsource to execute a command file (no nesting allowed), <br>
//!             in case of error, source is stopped and keyword recovers <br>
//!           xstep is a simple prefix (useful in a wider environment, to <br>
//!             avoid conflicts on command names) <br>
//!           xset control commands which create items with names <br>
  Standard_EXPORT     IFSelect_ReturnStatus Do(const Standard_Integer number,const Handle(IFSelect_SessionPilot)& session) ;
  //! Help for specific commands (apart from general command help) <br>
  Standard_EXPORT     Standard_CString Help(const Standard_Integer number) const;




  DEFINE_STANDARD_RTTI(IFSelect_SessionPilot)

protected:




private: 


Handle_IFSelect_WorkSession thesession;
TCollection_AsciiString theprompt;
TCollection_AsciiString thecommand;
Standard_Integer thenbwords;
TColStd_Array1OfAsciiString thewords;
TColStd_Array1OfInteger thewordeb;
Standard_Boolean therecord;
Standard_Integer thenumrec;
Handle_Standard_Transient theobjrec;
TColStd_SequenceOfAsciiString thecomlist;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
