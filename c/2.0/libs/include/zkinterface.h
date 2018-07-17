#ifndef ZKINTERFACE_H
#define ZKINTERFACE_H

#ifndef APICALL
#define APICALL __stdcall
#endif


#ifndef ZKAPI
#define ZKAPI __stdcall
#endif

#ifndef ZKINTERFACE
#ifndef _USRDLL 
#ifdef _LIB
#define ZKINTERFACE
#else
#define ZKINTERFACE __declspec(dllimport)
#endif
#else	//_ZKDLL
#define ZKINTERFACE
#endif	//_ZKDLL
#endif



#endif	//ZKINTERFACE_H