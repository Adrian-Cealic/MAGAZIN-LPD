//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UAutentificare.h"
#include "UDM.h"
#include "UMAIN.h"
#include "UReceptie.h"
#include "IniFiles.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFAUTENTIFICARE *FAUTENTIFICARE;
TIniFile *Ini = new TIniFile(GetCurrentDir()+"/options.ini");
//---------------------------------------------------------------------------
__fastcall TFAUTENTIFICARE::TFAUTENTIFICARE(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFAUTENTIFICARE::FormShow(TObject *Sender)
{
	  DM->QLIBER->Close();
	  DM->QLIBER->SQL->Clear();
	  DM->QLIBER->SQL->Add("SELECT * FROM FIRMA");
	  DM->QLIBER->Open();
	  while(!DM->QLIBER->Eof)
	  {
		  EFIRMA->Items->Add(DM->QLIBER->FieldByName("nume")->AsString);
		  DM->QLIBER->Next();
	  }
	  EFIRMA->Text=Ini->ReadString("Autentificare","Firma","");
	  EOPERATOR->Text=Ini->ReadString("Autentificare","Utilizator","");
}
//---------------------------------------------------------------------------
void __fastcall TFAUTENTIFICARE::EFIRMAKeyPress(TObject *Sender, System::WideChar &Key)
{
	 Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TFAUTENTIFICARE::Button2Click(TObject *Sender)
{
     if(MessageDlg("Dvs intr-adevar doriti sa inchideti sistemul?", mtInformation,TMsgDlgButtons() << mbYes << mbNo,0)==mrYes)
	 {
          Application->Terminate();
	 }
}
//---------------------------------------------------------------------------
void __fastcall TFAUTENTIFICARE::Button1Click(TObject *Sender)
{
	 if((EFIRMA->Text!="")&&(EOPERATOR->Text!="")&&(EPAROLA->Text!=""))
	 {
		 DM->QAUTENTIFICARE->Close();
		 DM->QAUTENTIFICARE->ParamByName("username")->AsString=EOPERATOR->Text;
		 DM->QAUTENTIFICARE->ParamByName("pass")->AsString=EPAROLA->Text;
		 DM->QAUTENTIFICARE->ParamByName("nume")->AsString=EFIRMA->Text;
		 DM->QAUTENTIFICARE->Open();
		 if(!DM->QAUTENTIFICARE->IsEmpty())
		 {
			 Ini->WriteString("AUTENTIFICARE","Firma",EFIRMA->Text);
			 Ini->WriteString("AUTENTIFICARE","Utilizator",EOPERATOR->Text);
			 Close();
			 FMAIN->Label2->Caption=DM->QAUTENTIFICAREOPERATOR->AsString;
			 FMAIN->Label3->Caption=DM->QAUTENTIFICAREFUNCTIA->AsString;
			 FMAIN->Label19->Caption=DM->QAUTENTIFICAREFIRMA->AsString;
			 RECEPTIE->Label2->Caption=DM->QAUTENTIFICAREOPERATOR->AsString;
			 RECEPTIE->Label3->Caption=DM->QAUTENTIFICAREFUNCTIA->AsString;
			 UTILIZATOR_ID=DM->QAUTENTIFICAREFIRMA_OPERATOR_ID->AsInteger;
			 FMAIN->AlphaBlend=false;
		 }
	 }
	 else
	 {
		 ShowMessage("Nu sunt indicate toate datele de autentificare!");
	 }
}
//---------------------------------------------------------------------------
void __fastcall TFAUTENTIFICARE::EPAROLAKeyPress(TObject *Sender, System::WideChar &Key)
{
     if(Key==13) Button1->Click();
}
//---------------------------------------------------------------------------




