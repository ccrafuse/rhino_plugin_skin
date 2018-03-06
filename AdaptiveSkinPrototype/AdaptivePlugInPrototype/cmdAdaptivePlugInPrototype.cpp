// cmdAdaptivePlugInPrototype.cpp : command file
//

#include "StdAfx.h"
#include "AdaptivePlugInPrototypePlugIn.h"
#include "Resource.h"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN AdaptivePlugInPrototype command
//

#pragma region AdaptivePlugInPrototype command

// Do NOT put the definition of class CCommandAdaptivePlugInPrototype in a header
// file. There is only ONE instance of a CCommandAdaptivePlugInPrototype class
// and that instance is the static theAdaptivePlugInPrototypeCommand that appears
// immediately below the class definition.

class CCommandAdaptivePlugInPrototype : public CRhinoCommand
{
public:
  // The one and only instance of CCommandAdaptivePlugInPrototype is created below.
  // No copy constructor or operator= is required.
  // Values of member variables persist for the duration of the application.

  // CCommandAdaptivePlugInPrototype::CCommandAdaptivePlugInPrototype()
  // is called exactly once when static theAdaptivePlugInPrototypeCommand is created.
  CCommandAdaptivePlugInPrototype() = default;

  // CCommandAdaptivePlugInPrototype::~CCommandAdaptivePlugInPrototype()
  // is called exactly once when static theAdaptivePlugInPrototypeCommand is destroyed.
  // The destructor should not make any calls to the Rhino SDK. 
  // If your command has persistent settings, then override 
  // CRhinoCommand::SaveProfile and CRhinoCommand::LoadProfile.
  ~CCommandAdaptivePlugInPrototype() = default;

  // Returns a unique UUID for this command.
  // If you try to use an id that is already being used, then
  // your command will not work. Use GUIDGEN.EXE to make unique UUID.
  UUID CommandUUID() override
  {
    // {40F34E8F-E2E9-4047-8A22-0E5908170F04}
    static const GUID AdaptivePlugInPrototypeCommand_UUID =
    { 0x40F34E8F, 0xE2E9, 0x4047, { 0x8A, 0x22, 0xE, 0x59, 0x8, 0x17, 0xF, 0x4 } };
    return AdaptivePlugInPrototypeCommand_UUID;
  }

  // Returns the English command name.
  // If you want to provide a localized command name, then override 
  // CRhinoCommand::LocalCommandName.
  const wchar_t* EnglishCommandName() override { return L"AdaptiveCmd1"; }

  // Rhino calls RunCommand to run the command.
  CRhinoCommand::result RunCommand(const CRhinoCommandContext& context) override;

  BOOL LoadMyMenu();

  BOOL UnloadMyMenu();

private:
	CMenu m_menu;
};

// The one and only CCommandAdaptivePlugInPrototype object
// Do NOT create any other instance of a CCommandAdaptivePlugInPrototype class.
static class CCommandAdaptivePlugInPrototype theAdaptivePlugInPrototypeCommand;



BOOL CCommandAdaptivePlugInPrototype::LoadMyMenu()
{
	
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (0 == m_menu.GetSafeHmenu())
	{
		if (!m_menu.LoadMenu(IDR_MENU1))
		{
			return FALSE;
		}

	}

	// Find a location in Rhino's menu to insert our
	// menu item. For this example, we will insert our
	// menu on the "Tools" menu just below the "Commands"
	// item.
	HMENU hParent = 0;
	int index = 0;
	//if( !RhinoApp().FindRhinoMenuItem(L"&File::&Print...Ctrl+P", hParent, index) )
	if (!RhinoApp().FindRhinoMenuItem(L"Too&ls::&Commands", hParent, index))
	{
		m_menu.DestroyMenu();
		return FALSE;
	}

	// Create and initialize a MENUITEMINFO struct.
	MENUITEMINFO mi;
	memset(&mi, 0, sizeof(mi));
	mi.cbSize = sizeof(mi);

	// Fill in our menu info
	//mi.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE | MIIM_SUBMENU;
	mi.fMask = MIIM_TYPE | MIIM_STATE | MIIM_SUBMENU;
	//mi.wID = MF_POPUP;
	mi.fType = MFT_STRING;

	ON_wString wstr = L"MyMenu";
	mi.dwTypeData = wstr.Array();

	mi.fState = MFS_ENABLED;
	mi.hSubMenu = m_menu.GetSafeHmenu();
	//mi.hSubMenu = ::GetSubMenu(mi.hSubMenu, 0);
	//mi.wID = IDR_MENU1;

	// Add our menu to Rhino's menu
	BOOL rc = CAdaptivePlugInPrototypePlugIn().InsertPlugInItemToRhinoMenu(hParent, index + 1, &mi);
	if (!rc)
		m_menu.DestroyMenu();

	return rc;
	
	return TRUE;
}

BOOL CCommandAdaptivePlugInPrototype::UnloadMyMenu()
{
	/*
	BOOL rc = FALSE;

	// Find our menu item in Rhino's menu.
	HMENU hParent = 0;
	int index = 0;
	if (RhinoApp().FindRhinoMenuItem(L"Too&ls::MyMenu", hParent, index))
	{
		// Remove our menu item.
		if (::RemoveMenu(hParent, index, MF_BYPOSITION))
		{
			// Redraw Rhino's menu bar.
			DrawMenuBar(RhinoApp().MainWnd());
			m_menu.DestroyMenu();
			rc = TRUE;
		}
	}

	return rc;
	*/
	return TRUE;
}


CRhinoCommand::result CCommandAdaptivePlugInPrototype::RunCommand(const CRhinoCommandContext& context)
{
	bool bVisible = (m_menu.GetSafeHmenu()) ? true : false;

	ON_wString prompt;
	prompt.Format(L"%s is %s. New value",
		EnglishCommandName(),
		bVisible ? L"visible" : L"hidden"
	);

	CRhinoGetOption go;
	go.SetCommandPrompt(prompt);
	int s_opt = go.AddCommandOption(RHCMDOPTNAME(L"Show"));
	int h_opt = go.AddCommandOption(RHCMDOPTNAME(L"Hide"));
	int t_opt = go.AddCommandOption(RHCMDOPTNAME(L"Toggle"));
	go.GetOption();
	if (go.CommandResult() != success)
		return go.CommandResult();

	const CRhinoCommandOption* opt = go.Option();
	if (0 == opt)
		return failure;

	if (opt->m_option_index == s_opt)
	{
		if (false == bVisible)
			LoadMyMenu();
	}
	else if (opt->m_option_index == h_opt)
	{
		if (true == bVisible)
			UnloadMyMenu();
	}
	else
	{
		if (true == bVisible)
			UnloadMyMenu();
		else
			LoadMyMenu();
	}

	return success;
}

#pragma endregion

//
// END AdaptivePlugInPrototype command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
