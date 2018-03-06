#pragma once

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//
// BEGIN MenuTest command
//

#pragma region MenuTest command

class CCommandMenuTest : public CRhinoCommand
{
public:
	CCommandMenuTest() = default;
	UUID CommandUUID() override
	{
		// {3516E68A-C61F-45E1-A148-B2D61915BA12}
		static const GUID MenuTestCommand_UUID =
		{ 0x3516E68A, 0xC61F, 0x45E1,{ 0xA1, 0x48, 0xB2, 0xD6, 0x19, 0x15, 0xBA, 0x12 } };
		return MenuTestCommand_UUID;
	}
	const wchar_t* EnglishCommandName() override { return L"MenuTest"; }
	CRhinoCommand::result RunCommand(const CRhinoCommandContext& context) override;
};

// The one and only CCommandMenuTest object
static class CCommandMenuTest theMenuTestCommand;

CRhinoCommand::result CCommandMenuTest::RunCommand(const CRhinoCommandContext& context)
{
	ON_wString str;
	str.Format(L"The \"%s\" command is under construction.\n", EnglishCommandName());
	if (context.IsInteractive())
		RhinoMessageBox(str, EnglishCommandName(), MB_OK);
	else
		RhinoApp().Print(str);
	return CRhinoCommand::success;
}

#pragma endregion

//
// END MenuTest command
//
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
