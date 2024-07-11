//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "UMAIN.h"
#include "UDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFDATECEC *FDATECEC;
//---------------------------------------------------------------------------
__fastcall TFDATECEC::TFDATECEC(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFDATECEC::SpeedButton1Click(TObject *Sender)
{
  DM->QDateCec->Close();
  DM->QDateCec->ParamByName("d1")->AsDate=DateTimePicker1->Date;
  DM->QDateCec->ParamByName("d2")->AsDate=DateTimePicker2->Date;
  DM->QDateCec->Open();

  PageControl1->ActivePageIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TFDATECEC::DBGrid1DblClick(TObject *Sender)
{
	   if(!DM->QDateCec->IsEmpty())
	   {
		  DM->QVANZARE->Close();
		  DM->QVANZARE->ParamByName("CEC_ID")->AsInteger=DM->QDateCec->FieldByName("CEC_ID")->AsInteger;
		  DM->QVANZARE->Open();
          PageControl1->ActivePageIndex=1;
	   }
	   else
	   {
		   ShowMessage("Nu sunt date");
       }
}
//---------------------------------------------------------------------------

void __fastcall TFDATECEC::FormClose(TObject *Sender, TCloseAction &Action)
{
  DM->QVANZARE->Close();
}
//---------------------------------------------------------------------------

