//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URECEPTIE.h"
#include "UDM.h"
#include "UAUTENTIFICARE.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRECEPTIE *RECEPTIE;
int PAG=1,PRODUS_ID,FACTURA_ID,RECEPTIE_ID,UM_ID,EMITENT_ID,PAGG=1;
//---------------------------------------------------------------------------
__fastcall TRECEPTIE::TRECEPTIE(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::RB1Click(TObject *Sender)
{

      ECAUTA->Clear();
	  if(RB1->Checked)
	  {
		ECAUTA->TextHint="Denumire produs";
		ECAUTA->NumbersOnly=0;
	  }
		else
		{
		   ECAUTA->TextHint="Cod produs";
           ECAUTA->NumbersOnly=1;
		}
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::ECAUTAChange(TObject *Sender)
{
	if(ECAUTA->Text!=" ")
	{
	   DM->QPRODUS->Close();
	   DM->QPRODUS->SQL->Clear();
	   DM->QPRODUS->SQL->Add("SELECT * FROM PRODUSE WHERE");
	   if(RB1->Checked)
	   {
		   DM->QPRODUS->SQL->Add(" DENUMIRE LIKE '%"+ECAUTA->Text+"%'");
	   }
	   else
	   {
		  DM->QPRODUS->SQL->Add(" COD_PRODUS LIKE '%"+ECAUTA->Text+"%'");
       }
	   DM->QPRODUS->Open();
	}
	else
	{
		DM->QPRODUS->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton4Click(TObject *Sender)
{

   PAG=1;
   MENIU->TabVisible=0;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=1;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;

   RB1->Checked=1;
   ECAUTA->Clear();
   DM->QPRODUS->Close();
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::FormShow(TObject *Sender)
{
   MENIU->TabVisible=1;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------




void __fastcall TRECEPTIE::SpeedButton7Click(TObject *Sender)
{
   if(!DM->QEMITENT->IsEmpty())
   {
	   EEMITENT->Text=DM->QEMITENTDENUMIRE->AsString;
	   EMITENT_ID=DM->QEMITENTEMITENT_ID->AsInteger;
       SpeedButton8->Click();
   }


}
//---------------------------------------------------------------------------


void __fastcall TRECEPTIE::SpeedButton8Click(TObject *Sender)
{
   if(PAG==1)
   {
	  MENIU->TabVisible=1;
	  FACTURA->TabVisible=0;
   }
   else
   {
	   MENIU->TabVisible=0;
	   FACTURA->TabVisible=1;
   }

   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton9Click(TObject *Sender)
{
	if(!DM->QPRODUS->IsEmpty())
	{
	   EPRODUS1->Text=DM->QPRODUSDENUMIRE->AsString;
	   EPRODUS2->Text=DM->QPRODUSDENUMIRE->AsString;
	   PRODUS_ID=DM->QPRODUSPRODUSE_ID->AsInteger;
       SpeedButton8->Click();
	}
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton22Click(TObject *Sender)
{
	DM->QUM->Close();
	DM->QUM->Open();
	PAG=2;
	MENIU->TabVisible=0;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=0;
   UM->TabVisible=1;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton20Click(TObject *Sender)
{

	PAG=2;
	MENIU->TabVisible=0;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=1;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
   RB1->Checked=1;
   ECAUTA->Clear();
   DM->QPRODUS->Close();
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton14Click(TObject *Sender)
{
   if(!DM->QUM->IsEmpty())
   {
	   EUM1->Text=DM->QUMABREVIERE->AsString;
	   EUM2->Text=DM->QUMABREVIERE->AsString;
	   UM_ID=DM->QUMUNIT_MASURA_ID->AsInteger;
	   SpeedButton8->Click();
   }
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton29Click(TObject *Sender)
{
   DM->QEMITENT->Close();
   DM->QEMITENT->Open();
    PAG=2;
   MENIU->TabVisible=0;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=1;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton30Click(TObject *Sender)
{
  if((ESERIA->Text!="")&&(EEMITENT->Text!=""))
  {
	  DM->QLIBER->Close();
	  DM->QLIBER->SQL->Clear();
	  DM->QLIBER->SQL->Add("SELECT * FROM FACTURA_REC WHERE EMITENT_ID=:EID AND NR_FACTURA=:NR AND DATA_FACTURA=:DATAF");
	  DM->QLIBER->ParamByName("EID")->AsInteger=EMITENT_ID;
	  DM->QLIBER->ParamByName("NR")->AsString=ESERIA->Text;
	  DM->QLIBER->ParamByName("DATAF")->AsDate=EDATA->Date;
	  DM->QLIBER->Open();

	  if(DM->QLIBER->IsEmpty())  //nu este factura inregistrata
	  {
		  DM->PFACTURA->Close();
		  DM->PFACTURA->ParamByName("@E")->AsInteger=EMITENT_ID;
		  DM->PFACTURA->ParamByName("@N")->AsString=ESERIA->Text;
		  DM->PFACTURA->ParamByName("@D")->AsDate=EDATA->Date;
		  DM->PFACTURA->ExecProc();
		  FACTURA_ID=DM->PFACTURA->ParamByName("@RETURN_VALUE")->AsInteger;

		  FINREGISTRARE->TabVisible=1;
		  FMENIU->TabVisible=0;

	  }
	  else //deschidem factura
	  {
		   DM->QFACTURA->Close();
		   DM->QFACTURA->ParamByName("ID")->AsInteger=DM->QLIBER->FieldByName("FACTURA_REC_ID")->AsInteger;
		   DM->QFACTURA->Open();
		   FACTURA_ID=DM->QLIBER->FieldByName("FACTURA_REC_ID")->AsInteger;

		  FINREGISTRARE->TabVisible=0;
		  FMENIU->TabVisible=1;
	  }
		  FMAIN->TabVisible=0;
		  FEDITARE->TabVisible=0;

  }
  else
  {
      ShowMessage("Nu sunt indicate toate campurile necesare");
  }
}
//---------------------------------------------------------------------------


void __fastcall TRECEPTIE::SpeedButton2Click(TObject *Sender)
{
   FMAIN->TabVisible=1;
   FMENIU->TabVisible=0;
   FINREGISTRARE->TabVisible=0;
   FEDITARE->TabVisible=0;
   PAGG=1;
   DM->QFACTURA->Close();
   ESERIA->Clear();
   EEMITENT->Clear();

   MENIU->TabVisible=0;
   FACTURA->TabVisible=1;
   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton16Click(TObject *Sender)
{
   EPRODUS1->Clear();
   EUM1->Clear();
   EPRET1->Clear();
   EVANZARE1->Clear();
   EADAOS1->Clear();
   ESTOC1->Clear();
   ETVA1->ItemIndex=-1;


   FMAIN->TabVisible=0;
   FMENIU->TabVisible=0;
   FINREGISTRARE->TabVisible=1;
   FEDITARE->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::ETVA1Change(TObject *Sender)
{
	if((EPRET1->Text!="")&&(EPRET1->Text.ToDouble()>0)&&(EADAOS1->Text!="")&&(EADAOS1->Text.ToDouble()>0))
	{
		 float a;
		 a=EPRET1->Text.ToDouble()*(ETVA1->Text.ToDouble()/100);
		 EVANZARE1->Text=FloatToStr(EPRET1->Text.ToDouble()+a+EADAOS1->Text.ToDouble());

	}
	else
	{
		EVANZARE1->Clear();
    }
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton23Click(TObject *Sender)
{
   if((EPRODUS1->Text!="")&&(EUM1->Text!="")&&(EVANZARE1->Text!=""))
   {
	  DM->QLIBER->Close();
	  DM->QLIBER->SQL->Clear();
	  DM->QLIBER->SQL->Add("INSERT INTO RECEPTIE(FACTURA_REC_ID,FIRMA_OPERATOR_ID,PRODUSE_ID,UNIT_MASURA_ID,STOCK1,PRET_INTRARE,PRET_VANZ,TVA)");
	  DM->QLIBER->SQL->Add("VALUES(:FACTURA_REC_ID,:FIRMA_OPERATOR_ID,:PRODUSE_ID,:UNIT_MASURA_ID,:STOCK1,:PRET_INTRARE,:PRET_VANZ,:TVA)");
	  DM->QLIBER->ParamByName("FACTURA_REC_ID")->AsInteger=FACTURA_ID;
	  DM->QLIBER->ParamByName("FIRMA_OPERATOR_ID")->AsInteger=FAUTENTIFICARE->UTILIZATOR_ID;
	  DM->QLIBER->ParamByName("PRODUSE_ID")->AsInteger=PRODUS_ID;
	  DM->QLIBER->ParamByName("UNIT_MASURA_ID")->AsInteger=UM_ID;
	  DM->QLIBER->ParamByName("STOCK1")->AsInteger=ESTOC1->Text.ToInt();
	  DM->QLIBER->ParamByName("PRET_INTRARE")->AsFloat=EPRET1->Text.ToDouble();
	  DM->QLIBER->ParamByName("PRET_VANZ")->AsInteger=EVANZARE1->Text.ToDouble();
	  DM->QLIBER->ParamByName("TVA")->AsInteger=ETVA1->Text.ToInt();
	  DM->QLIBER->ExecSQL();

	EPRODUS1->Clear();
	EUM1->Clear();
	EPRET1->Clear();
	EVANZARE1->Clear();
	EADAOS1->Clear();
    ESTOC1->Clear();
	ETVA1->ItemIndex=-1;

    DM->QFACTURA->Close();
	DM->QFACTURA->ParamByName("ID")->AsInteger=FACTURA_ID;
	DM->QFACTURA->Open();

    ShowMessage("Inregistrare cu succes");
   }
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton24Click(TObject *Sender)
{
   FMAIN->TabVisible=0;
   FMENIU->TabVisible=1;
   FINREGISTRARE->TabVisible=0;
   FEDITARE->TabVisible=0;
}
//---------------------------------------------------------------------------


void __fastcall TRECEPTIE::SpeedButton17Click(TObject *Sender)
{
   if(!DM->QFACTURA->IsEmpty())
   {


   EPRODUS2->Text=DM->QFACTURADENUMIRE->AsString;
   EUM2->Text=DM->QFACTURAABREVIERE->AsString;
   EPRET2->Text=DM->QFACTURAPRET_INTRARE->AsString;
   EVANZARE2->Text=DM->QFACTURAPRET_VANZ->AsString;
   //EADAOS1->Text=DM->QFACTURA->AsString;
   ESTOC2->Text=DM->QFACTURASTOCK1->AsString;
   ETVA2->Text=DM->QFACTURATVA->AsString;

   PRODUS_ID=DM->QFACTURAPRODUSE_ID->AsInteger;
   FACTURA_ID=DM->QFACTURAFACTURA_REC_ID->AsInteger;
   UM_ID=DM->QFACTURAUNIT_MASURA_ID->AsInteger;


   FMAIN->TabVisible=0;
   FMENIU->TabVisible=0;
   FINREGISTRARE->TabVisible=0;
   FEDITARE->TabVisible=1;
   }
   else
   {
       ShowMessage("Nu sunt date de editat");
   }
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton27Click(TObject *Sender)
{
   if((EPRODUS2->Text!="")&&(EUM2->Text!="")&&(EVANZARE2->Text!=""))
   {
	  DM->QLIBER->Close();
	  DM->QLIBER->SQL->Clear();
	  DM->QLIBER->SQL->Add("UPDATE RECEPTIE SET PRODUSE_ID=:PRODUSE_ID,UNIT_MASURA_ID=:UNIT_MASURA_ID,STOCK1=:STOCK1,PRET_INTRARE=:PRET_INTRARE,PRET_VANZ=:PRET_VANZ,TVA=:TVA WHERE RECEPTIE_ID=:ID");
	  DM->QLIBER->ParamByName("ID")->AsInteger=DM->QFACTURARECEPTIE_ID->AsInteger;

	  DM->QLIBER->ParamByName("PRODUSE_ID")->AsInteger=PRODUS_ID;
	  DM->QLIBER->ParamByName("UNIT_MASURA_ID")->AsInteger=UM_ID;
	  DM->QLIBER->ParamByName("STOCK1")->AsInteger=ESTOC2->Text.ToInt();
	  DM->QLIBER->ParamByName("PRET_INTRARE")->AsFloat=EPRET2->Text.ToDouble();
	  DM->QLIBER->ParamByName("PRET_VANZ")->AsInteger=EVANZARE2->Text.ToDouble();
	  DM->QLIBER->ParamByName("TVA")->AsInteger=ETVA2->Text.ToInt();
	  DM->QLIBER->ExecSQL();

    DM->QFACTURA->Close();
	DM->QFACTURA->ParamByName("ID")->AsInteger=FACTURA_ID;
	DM->QFACTURA->Open();


	ShowMessage("Inregistrare cu succes");
    SpeedButton28->Click();
   }
}
//---------------------------------------------------------------------------




void __fastcall TRECEPTIE::EPRET2Change(TObject *Sender)
{
if((EPRET2->Text!="")&&(EPRET2->Text.ToDouble()>0)&&(EADAOS2->Text!="")&&(EADAOS2->Text.ToDouble()>0))
	{
		 float a;
		 a=EPRET2->Text.ToDouble()*(ETVA2->Text.ToDouble()/100);
		 EVANZARE2->Text=FloatToStr(EPRET2->Text.ToDouble()+a+EADAOS2->Text.ToDouble());

	}
	else
	{
		EVANZARE2->Clear();
	}
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton18Click(TObject *Sender)
{
   if(!DM->QFACTURA->IsEmpty())
   {
        DM->QLIBER->Close();
	  DM->QLIBER->SQL->Clear();
	  DM->QLIBER->SQL->Add("DELETE RECEPTIE WHERE RECEPTIE_ID=:ID");
	  DM->QLIBER->ParamByName("ID")->AsInteger=DM->QFACTURARECEPTIE_ID->AsInteger;
	  DM->QLIBER->ExecSQL();

    DM->QFACTURA->Close();
	DM->QFACTURA->ParamByName("ID")->AsInteger=FACTURA_ID;
	DM->QFACTURA->Open();
    ShowMessage("Eliminare cu succes");
   }
   else
   {
		ShowMessage("Nu sunt date de eliminat");
   }
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton19Click(TObject *Sender)
{
   if(PAGG==2)
   {
	  DATEFACTURA->TabVisible=1;
	  MENIU->TabVisible=0;
   }
   else
   {
	  DATEFACTURA->TabVisible=0;
	  MENIU->TabVisible=1;
   }
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton3Click(TObject *Sender)
{
 DM->QEMITENT->Close();
   DM->QEMITENT->Open();
    PAG=1;
   MENIU->TabVisible=0;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=1;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton5Click(TObject *Sender)
{
	DM->QUM->Close();
	DM->QUM->Open();
	PAG=1;
	MENIU->TabVisible=0;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=0;
   UM->TabVisible=1;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::CheckBox1Click(TObject *Sender)
{
   if(CheckBox1->Checked)
   {
	   Edit1->Enabled=1;
   }
   else
   {
       Edit1->Enabled=0;
   }
   Edit1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::CheckBox3Click(TObject *Sender)
{
if(CheckBox3->Checked)
   {
	   Edit2->Enabled=1;
   }
   else
   {
	   Edit2->Enabled=0;
   }
   Edit2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::CheckBox4Click(TObject *Sender)
{
if(CheckBox4->Checked)
   {
	   Edit3->Enabled=1;
   }
   else
   {
	   Edit3->Enabled=0;
   }
   Edit3->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton1Click(TObject *Sender)
{
   CheckBox2->Checked=0;
   CheckBox1->Checked=0;
   CheckBox3->Checked=0;
   CheckBox4->Checked=0;
   CheckBox5->Checked=0;

   DM->QDATEFACTURA->Close();
   MENIU->TabVisible=0;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=1;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::CheckBox2Click(TObject *Sender)
{
  if(CheckBox2->Checked)
  {
	  d1->Enabled=1;
	  d2->Enabled=1;
  }
  else
  {
	  d1->Enabled=0;
	  d2->Enabled=0;
  }
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::CheckBox5Click(TObject *Sender)
{
  if(CheckBox5->Checked)
  {
	  Edit4->Enabled=1;
  }
  else
  {
	  Edit4->Enabled=0;
	  Edit4->Clear();
  }
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton31Click(TObject *Sender)
{
AnsiString s1,s2,s3;


s1=" SELECT E.EMITENT_ID,E.DENUMIRE AS EMITENT,F.NR_FACTURA,F.DATA_FACTURA,COUNT(*) AS NR_POZ,SUM(R.PRET_INTRARE) AS PRET_INTRARE, ";
s1+=" SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TVA,SUM(R.PRET_INTRARE)+SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TOT ";

s3=" SELECT COUNT(*) AS NR,SUM(R.PRET_INTRARE) AS PRET_INTRARE, ";
s3+=" SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TVA,SUM(R.PRET_INTRARE)+SUM(R.PRET_INTRARE*TVA/100.0) AS PRET_TOT ";

s2=" FROM RECEPTIE R INNER JOIN PRODUSE P ON R.PRODUSE_ID=P.PRODUSE_ID ";
s2+="            INNER JOIN UNIT_MASURA UM ON UM.UNIT_MASURA_ID=R.UNIT_MASURA_ID ";
s2+="		   INNER JOIN FACTURA_REC F ON F.FACTURA_REC_ID=R.FACTURA_REC_ID ";
s2+="		   INNER JOIN FIRMA_OPERATOR FO ON FO.FIRMA_OPERATOR_ID=R.FIRMA_OPERATOR_ID ";
s2+="		   INNER JOIN OPERATOR O ON O.OPERATOR_ID=FO.FIRMA_OPERATOR_ID ";
s2+="		   INNER JOIN EMITENT E ON E.EMITENT_ID=F.EMITENT_ID ";
s2+="WHERE R.ACTIV=1 ";

if(CheckBox1->Checked) //nr factura
{
	s2+=" and nr_factura= "+Edit1->Text;
}
if(CheckBox2->Checked) //data factura
{
	s2+=" and data_factura beteween :d1 and :d2 ";
}

if(CheckBox3->Checked) //operator
{
	s2+=" and (o.nume like '%"+Edit2->Text+"%' or o.prenume like '%"+Edit2->Text+"%')";
}

if(CheckBox4->Checked)   //produs
{
   s2+="and r.PRODUSE_ID in (select produse_id from produse where denumire like '%"+Edit3->Text+"%')" ;
}

if(CheckBox5->Checked)   //emitent
{
   s2+="and E.DENUMIRE like '%"+Edit4->Text+"%'" ;
}

DM->QDATEFACTURA->Close();
DM->QDATEFACTURA->SQL->Clear();
DM->QDATEFACTURA->SQL->Add(s1+s2+" GROUP BY E.EMITENT_ID,E.DENUMIRE,F.NR_FACTURA,F.DATA_FACTURA ORDER BY F.DATA_FACTURA desc") ;
if(CheckBox2->Checked)
{
	DM->QDATEFACTURA->ParamByName("d1")->AsDate=d1->Date;
	DM->QDATEFACTURA->ParamByName("d2")->AsDate=d2->Date;
}
DM->QDATEFACTURA->Open();

DM->QLIBER->Close();
DM->QLIBER->SQL->Clear();
DM->QLIBER->SQL->Add(s3+s2);
if(CheckBox2->Checked)
{
	DM->QLIBER->ParamByName("d1")->AsDate=d1->Date;
	DM->QLIBER->ParamByName("d2")->AsDate=d2->Date;
}
DM->QLIBER->Open();

StatusBar1->Panels->Items[0]->Text="Inregistrari: "+DM->QLIBER->FieldByName("Nr")->AsString;
StatusBar1->Panels->Items[1]->Text=DM->QLIBER->FieldByName("PRET_INTRARE")->AsString;
StatusBar1->Panels->Items[2]->Text=DM->QLIBER->FieldByName("PRET_TVA")->AsString;
StatusBar1->Panels->Items[3]->Text=DM->QLIBER->FieldByName("PRET_TOT")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::DBGrid5DblClick(TObject *Sender)
{
  ESERIA->Text=DM->QDATEFACTURANR_FACTURA->AsString;
  EDATA->Date=DM->QDATEFACTURADATA_FACTURA->AsString;
  EEMITENT->Text=DM->QDATEFACTURAEMITENT->AsString;
  EMITENT_ID=DM->QDATEFACTURAEMITENT_ID->AsInteger;

   MENIU->TabVisible=0;
   FACTURA->TabVisible=1;
   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
   PAGG=2;
   SpeedButton30->Click();

}
//---------------------------------------------------------------------------

void __fastcall TRECEPTIE::SpeedButton32Click(TObject *Sender)
{
   MENIU->TabVisible=1;
   FACTURA->TabVisible=0;
   PRODUS->TabVisible=0;
   UM->TabVisible=0;
   EMITENT->TabVisible=0;
   DATEFACTURA->TabVisible=0;
   CLIENT->TabVisible=0;
}
//---------------------------------------------------------------------------

