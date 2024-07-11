//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("UMAIN.cpp", FMAIN);
USEFORM("Unit1.cpp", FDATECEC);
USEFORM("URECEPTIE.cpp", RECEPTIE);
USEFORM("UDM.cpp", DM); /* TDataModule: File Type */
USEFORM("UAUTENTIFICARE.cpp", FAUTENTIFICARE);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Aqua Light Slate");
		Application->CreateForm(__classid(TFMAIN), &FMAIN);
		Application->CreateForm(__classid(TFAUTENTIFICARE), &FAUTENTIFICARE);
		Application->CreateForm(__classid(TRECEPTIE), &RECEPTIE);
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TFDATECEC), &FDATECEC);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
