// AdaptivePlugInPrototypePlugIn.h : main header file for the AdaptivePlugInPrototype plug-in.
//

#pragma once

// CAdaptivePlugInPrototypePlugIn
// See AdaptivePlugInPrototypePlugIn.cpp for the implementation of this class
//

class CAdaptivePlugInPrototypePlugIn : public CRhinoUtilityPlugIn
{
public:
  // CAdaptivePlugInPrototypePlugIn constructor. The constructor is called when the
  // plug-in is loaded and "thePlugIn" is constructed. Once the plug-in
  // is loaded, CAdaptivePlugInPrototypePlugIn::OnLoadPlugIn() is called. The
  // constructor should be simple and solid. Do anything that might fail in
  // CAdaptivePlugInPrototypePlugIn::OnLoadPlugIn().
  CAdaptivePlugInPrototypePlugIn();
  
  // CAdaptivePlugInPrototypePlugIn destructor. The destructor is called to destroy
  // "thePlugIn" when the plug-in is unloaded. Immediately before the
  // DLL is unloaded, CAdaptivePlugInPrototypePlugIn::OnUnloadPlugin() is called. Do
  // not do too much here. Be sure to clean up any memory you have allocated
  // with onmalloc(), onrealloc(), oncalloc(), or onstrdup().
  ~CAdaptivePlugInPrototypePlugIn() = default;

  // Required overrides
  
  // Plug-in name display string. This name is displayed by Rhino when
  // loading the plug-in, in the plug-in help menu, and in the Rhino
  // interface for managing plug-ins. 
  const wchar_t* PlugInName() const override;
  
  // Plug-in version display string. This name is displayed by Rhino
  // when loading the plug-in and in the Rhino interface for 
  // managing plug-ins.
  const wchar_t* PlugInVersion() const override;
  
  // Plug-in unique identifier. The identifier is used by Rhino for
  // managing plug-ins.
  GUID PlugInID() const override;
  
  // Additional overrides
  
  // Called after the plug-in is loaded and the constructor has been
  // run. This is a good place to perform any significant initialization,
  // license checking, and so on.  This function must return TRUE for
  // the plug-in to continue to load.  
  BOOL OnLoadPlugIn() override;
  
  // Called one time when plug-in is about to be unloaded. By this time,
  // Rhino's mainframe window has been destroyed, and some of the SDK
  // managers have been deleted. There is also no active document or active
  // view at this time. Thus, you should only be manipulating your own objects.
  // or tools here.  
  void OnUnloadPlugIn() override;

  // Skin DLL menu update handler
  //void OnInitPlugInMenuPopups(WPARAM wparam, LPARAM lparam);

  // Skin DLL menu command handler
  //BOOL OnPlugInMenuCommand(WPARAM wparam);

  // Change to CRhinoPlugIn::load_plugin_at_startup
  //plugin_load_time PlugInLoadTime() override;
  plugin_load_time PlugInLoadTime() override;

  /*
  // Skin DLL menu update handler
  void OnInitPlugInMenuPopups(WPARAM wparam, LPARAM lparam);

  // Skin DLL menu command handler
  BOOL OnPlugInMenuCommand(WPARAM wparam);
  */

  

  //CRhinoCommand::result RunCommand(const CRhinoCommandContext& context);

private:
  ON_wString m_plugin_version;

  // TODO: Add additional class information here
  CMenu m_menu;
};

// Return a reference to the one and only CAdaptivePlugInPrototypePlugIn object
CAdaptivePlugInPrototypePlugIn& AdaptivePlugInPrototypePlugIn();



