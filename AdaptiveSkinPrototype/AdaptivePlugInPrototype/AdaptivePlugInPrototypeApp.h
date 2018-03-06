// AdaptivePlugInPrototype.h : main header file for the AdaptivePlugInPrototype DLL.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h" // main symbols

// CAdaptivePlugInPrototypeApp
// See AdaptivePlugInPrototypeApp.cpp for the implementation of this class
//

class CAdaptivePlugInPrototypeApp : public CWinApp
{
public:
  // CRITICAL: DO NOT CALL RHINO SDK FUNCTIONS HERE!
  // Only standard MFC DLL instance construction belongs here. 
  // All other significant initialization should take place in
  // CAdaptivePlugInPrototypePlugIn::OnLoadPlugIn().
	CAdaptivePlugInPrototypeApp() = default;

  // CRITICAL: DO NOT CALL RHINO SDK FUNCTIONS HERE!
  // Only standard MFC DLL instance initialization belongs here. 
  // All other significant initialization should take place in
  // CAdaptivePlugInPrototypePlugIn::OnLoadPlugIn().
	BOOL InitInstance() override;
  
  // CRITICAL: DO NOT CALL RHINO SDK FUNCTIONS HERE!
  // Only standard MFC DLL instance clean up belongs here. 
  // All other significant cleanup should take place in either
  // CAdaptivePlugInPrototypePlugIn::OnSaveAllSettings() or
  // CAdaptivePlugInPrototypePlugIn::OnUnloadPlugIn().  
	int ExitInstance() override;
  
	DECLARE_MESSAGE_MAP()
};
