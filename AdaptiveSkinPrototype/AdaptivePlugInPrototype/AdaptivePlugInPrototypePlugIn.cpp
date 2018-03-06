// AdaptivePlugInPrototypePlugIn.cpp : defines the initialization routines for the plug-in.
//

#include "StdAfx.h"
#include "rhinoSdkPlugInDeclare.h"
#include "AdaptivePlugInPrototypePlugIn.h"
#include "Resource.h"
#include "rhinoSdkPlugIn.h"

// The plug-in object must be constructed before any plug-in classes derived
// from CRhinoCommand. The #pragma init_seg(lib) ensures that this happens.
#pragma warning(push)
#pragma warning(disable : 4073)
#pragma init_seg(lib)
#pragma warning(pop)

// Rhino plug-in declaration
RHINO_PLUG_IN_DECLARE

// Rhino plug-in name
// Provide a short, friendly name for this plug-in.
RHINO_PLUG_IN_NAME(L"AdaptivePlugInPrototype");

// Rhino plug-in id
// Provide a unique uuid for this plug-in.
RHINO_PLUG_IN_ID(L"317E000D-B81C-4577-94E7-A0ACC8E22C48");

// Rhino plug-in version
// Provide a version number string for this plug-in.
RHINO_PLUG_IN_VERSION(__DATE__ "  " __TIME__)

// Rhino plug-in description
// Provide a description of this plug-in.
RHINO_PLUG_IN_DESCRIPTION(L"AdaptivePlugInPrototype plug-in for Rhinoceros®");

// Rhino plug-in icon resource id
// Provide an icon resource this plug-in.
// Icon resource should contain 16, 24, 32, 48, and 256-pixel image sizes.
RHINO_PLUG_IN_ICON_RESOURCE_ID(IDI_ICON);

// Rhino plug-in developer declarations
// TODO: fill in the following developer declarations with
// your company information. Note, all of these declarations
// must be present or your plug-in will not load.
//
// When completed, delete the following #error directive.
//#error Developer declarations block is incomplete!
RHINO_PLUG_IN_DEVELOPER_ORGANIZATION(L"Adaptive Medical Technologies");
RHINO_PLUG_IN_DEVELOPER_ADDRESS(L"1344 Summer Street, Halifax, B3H 0A8");
RHINO_PLUG_IN_DEVELOPER_COUNTRY(L"Canada");
RHINO_PLUG_IN_DEVELOPER_PHONE(L"902.421.2733");
RHINO_PLUG_IN_DEVELOPER_FAX(L"902.421.2733");
RHINO_PLUG_IN_DEVELOPER_EMAIL(L"chris.rafuse@3dbolus.com");
RHINO_PLUG_IN_DEVELOPER_WEBSITE(L"http://www.3dbolus.com");
RHINO_PLUG_IN_UPDATE_URL(L"");

// The one and only CAdaptivePlugInPrototypePlugIn object
static class CAdaptivePlugInPrototypePlugIn thePlugIn;

/////////////////////////////////////////////////////////////////////////////
// CAdaptivePlugInPrototypePlugIn definition

CAdaptivePlugInPrototypePlugIn& AdaptivePlugInPrototypePlugIn()
{
  // Return a reference to the one and only CAdaptivePlugInPrototypePlugIn object
  return thePlugIn;
}

CAdaptivePlugInPrototypePlugIn::CAdaptivePlugInPrototypePlugIn()
{
  // Description:
  //   CAdaptivePlugInPrototypePlugIn constructor. The constructor is called when the
  //   plug-in is loaded and "thePlugIn" is constructed. Once the plug-in
  //   is loaded, CAdaptivePlugInPrototypePlugIn::OnLoadPlugIn() is called. The
  //   constructor should be simple and solid. Do anything that might fail in
  //   CAdaptivePlugInPrototypePlugIn::OnLoadPlugIn().

  // TODO: Add construction code here
  m_plugin_version = RhinoPlugInVersion();
}

/////////////////////////////////////////////////////////////////////////////
// Required overrides

const wchar_t* CAdaptivePlugInPrototypePlugIn::PlugInName() const
{
  // Description:
  //   Plug-in name display string.  This name is displayed by Rhino when
  //   loading the plug-in, in the plug-in help menu, and in the Rhino
  //   interface for managing plug-ins.

  // TODO: Return a short, friendly name for the plug-in.
  return RhinoPlugInName();
}

const wchar_t* CAdaptivePlugInPrototypePlugIn::PlugInVersion() const
{
  // Description:
  //   Plug-in version display string. This name is displayed by Rhino
  //   when loading the plug-in and in the Rhino interface for managing
  //   plug-ins.

  // TODO: Return the version number of the plug-in.
  return m_plugin_version;
}

GUID CAdaptivePlugInPrototypePlugIn::PlugInID() const
{
  // Description:
  //   Plug-in unique identifier. The identifier is used by Rhino to
  //   manage the plug-ins.

  // TODO: Return a unique identifier for the plug-in.
  // {317E000D-B81C-4577-94E7-A0ACC8E22C48}
  return ON_UuidFromString(RhinoPlugInId());
}

/////////////////////////////////////////////////////////////////////////////
// Additional overrides

BOOL CAdaptivePlugInPrototypePlugIn::OnLoadPlugIn()
{
  // Description:
  //   Called after the plug-in is loaded and the constructor has been
  //   run. This is a good place to perform any significant initialization,
  //   license checking, and so on.  This function must return TRUE for
  //   the plug-in to continue to load.

  // Remarks:
  //    Plug-ins are not loaded until after Rhino is started and a default document
  //    is created.  Because the default document already exists
  //    CRhinoEventWatcher::On????Document() functions are not called for the default
  //    document.  If you need to do any document initialization/synchronization then
  //    override this function and do it here.  It is not necessary to call
  //    CPlugIn::OnLoadPlugIn() from your derived class.

  // TODO: Add plug-in initialization code here.
  return TRUE;
}

void CAdaptivePlugInPrototypePlugIn::OnUnloadPlugIn()
{
  // Description:
  //    Called one time when plug-in is about to be unloaded. By this time,
  //    Rhino's mainframe window has been destroyed, and some of the SDK
  //    managers have been deleted. There is also no active document or active
  //    view at this time. Thus, you should only be manipulating your own objects.
  //    or tools here. 902 468 1351 x629 Jackie 

  // TODO: Add plug-in cleanup code here.
}

CRhinoPlugIn::plugin_load_time CAdaptivePlugInPrototypePlugIn::PlugInLoadTime()
{
	// Override to change load time to "at startup"
	return CRhinoPlugIn::load_plugin_at_startup;
}








/*
void CAdaptivePlugInPrototypePlugIn::OnInitPlugInMenuPopups(WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = (HMENU)wParam;
	if (NULL == hMenu)
		return;

	switch (GetMenuItemID(hMenu, LOWORD(lParam)))
	{
	case 1:
		::EnableMenuItem(hMenu, 1, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		break;
	case 2:
		::EnableMenuItem(hMenu, 2, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
		break;
		// TODO...
	}
}

BOOL CAdaptivePlugInPrototypePlugIn::OnPlugInMenuCommand(WPARAM wParam)
{
	ON_wString w;
	switch ((UINT)wParam)
	{
	case 1:
		w = L"Test Item One";
		break;
	case 2:
		w = L"Two";
		break;
	case 3:
		w = L"Disabled";
		break;
	case 4:
		w = L"Sub Menu A";
		break;
	case 5:
		w = L"Sub Menu B";
		break;
	case 6:
		w = L"Sub Menu Disabled";
		break;
	default:
		return true;
	}

	::RhinoMessageBox(w, L"OnMenu", MB_OK);
	return true;
}
*/