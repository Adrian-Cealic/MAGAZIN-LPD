//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UMAIN.h"
#include "UAUTENTIFICARE.h"
#include "UDM.h"
#include "URECEPTIE.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFMAIN *FMAIN;
int RECEPTIE_ID, CLIENT_ID = 1, CEC_ID;
float PROCENT = 0, PRET = 0;
//---------------------------------------------------------------------------
__fastcall TFMAIN::TFMAIN(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFMAIN::b1Click(TObject *Sender)
{
	if (b1->Visible)
		b1->Visible = 0;
	else
		b1->Visible = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::FormShow(TObject *Sender)
{
	FAUTENTIFICARE->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton3Click(TObject *Sender)
{
	RECEPTIE->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton5Click(TObject *Sender)
{
	if (EProdus->Text != "")
	{
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		if (CBClient->Checked == 0)
		{
			DM->QLIBER->SQL->Add(" SELECT * FROM RECEPTIE R INNER JOIN PRODUSE P ON R.PRODUSE_ID=P.PRODUSE_ID INNER JOIN UNIT_MASURA UM ON UM.UNIT_MASURA_ID=R.UNIT_MASURA_ID WHERE P.COD_PRODUS=:COD");
		}
		else
		{
			DM->QLIBER->SQL->Add(" SELECT C.NUME+' '+PRENUME AS NP,VALOAREA/100.0 AS PROCENT,* ");
			DM->QLIBER->SQL->Add(" FROM CLIENT C INNER JOIN DISCOUNT D ON C.DISCOUNT_ID=D.DISCOUNT_ID WHERE COD_CLIENT=:COD ");
		}
		DM->QLIBER->ParamByName("COD")->AsString = EProdus->Text;
		DM->QLIBER->Open();

		if (!DM->QLIBER->IsEmpty())
		{
			if (CBClient->Checked == 0) // se indica sa gasit produs
			{
				LProdus->Caption = DM->QLIBER->FieldByName("DENUMIRE")->AsString + ": " + DM->QLIBER->FieldByName("PRET_VANZ")->AsString + "/" + DM->QLIBER->FieldByName("ABREVIERE")->AsString;
				RECEPTIE_ID = DM->QLIBER->FieldByName("RECEPTIE_ID")->AsInteger;
				PRET = DM->QLIBER->FieldByName("PRET_VANZ")->AsFloat;

				// FORMAM CECUL
				// VERIFICAM DACA NU AVEM NICI UN PRODUS INREGISTRAT
				if (DM->QVANZARE->IsEmpty())
				{
					// formam cecul
					DM->PCEK->Close();
					DM->PCEK->ParamByName("@CLIENT")->AsInteger = CLIENT_ID;
					DM->PCEK->ParamByName("@OPER")->AsInteger = FAUTENTIFICARE->UTILIZATOR_ID;
					DM->PCEK->ExecProc();
					CEC_ID = DM->PCEK->ParamByName("@RETURN_VALUE")->AsInteger;
				}

				// ADAUGAM PRODUSUL IDENTIFICAT IN COS
				float SUMA_D = PRET * PROCENT;
				float SUMA_T = PRET - SUMA_D;
				DM->QLIBER->Close();
				DM->QLIBER->SQL->Clear();
				DM->QLIBER->SQL->Add(" INSERT INTO VANZARE(CEC_ID,RECEPTIE_ID,CANTITATEA,SUMA,SUMA_DISC,SUMA_TOTAL) ");
				DM->QLIBER->SQL->Add(" VALUES(:CEC_ID,:RECEPTIE_ID,:CANTITATEA,:SUMA,:SUMA_DISC,:SUMA_TOTAL) ");

				DM->QLIBER->ParamByName("CEC_ID")->AsInteger = CEC_ID;
				DM->QLIBER->ParamByName("RECEPTIE_ID")->AsInteger = RECEPTIE_ID;
				DM->QLIBER->ParamByName("CANTITATEA")->AsString = 1;
				DM->QLIBER->ParamByName("SUMA")->AsFloat = PRET;
				DM->QLIBER->ParamByName("SUMA_DISC")->AsFloat = SUMA_D;
				DM->QLIBER->ParamByName("SUMA_TOTAL")->AsFloat = SUMA_T;
				DM->QLIBER->ExecSQL();
			}
			else // daca sa depistat client
			{
				LClient->Caption = DM->QLIBER->FieldByName("NP")->AsString + ":discount  " + DM->QLIBER->FieldByName("VALOAREA")->AsString + "%";
				CLIENT_ID = DM->QLIBER->FieldByName("CLIENT_ID")->AsInteger;
				PROCENT = DM->QLIBER->FieldByName("PROCENT")->AsFloat;

				if (!DM->QVANZARE->IsEmpty())
				{ // modificam id-ul clientului in cec
					DM->QLIBER->Close();
					DM->QLIBER->SQL->Clear();
					DM->QLIBER->SQL->Add(" UPDATE CEC SET CLIENT_ID=:CLIENT_ID WHERE CEC_ID=:CEC_ID ");
					DM->QLIBER->ParamByName("CEC_ID")->AsInteger = CEC_ID;
					DM->QLIBER->ParamByName("CLIENT_ID")->AsInteger = CLIENT_ID;
					DM->QLIBER->ExecSQL();

					// recalculam pozitiile anterioare
					DM->QLIBER->Close();
					DM->QLIBER->SQL->Clear();
					DM->QLIBER->SQL->Add(" UPDATE VANZARE SET SUMA_DISC=SUMA* :PROCENT, SUMA_TOTAL=SUMA- (SUMA* :PROCENT) WHERE CEC_ID=:CEC_ID  ");
					DM->QLIBER->ParamByName("CEC_ID")->AsInteger = CEC_ID;
					DM->QLIBER->ParamByName("procent")->AsFloat = PROCENT;
					DM->QLIBER->ExecSQL();
				}
			}
			DM->QVANZARE->Close();
			DM->QVANZARE->ParamByName("CEC_ID")->AsInteger = CEC_ID;
			DM->QVANZARE->Open();

			// SA SE CALCULEZE SUMA CECULUI
			DM->QLIBER->Close();
			DM->QLIBER->SQL->Clear();
			DM->QLIBER->SQL->Add(" SELECT SUM (SUMA_TOTAL) AS SUMA_TOTAL FROM VANZARE WHERE CEC_ID=:CEC_ID ");
			DM->QLIBER->ParamByName("CEC_ID")->AsInteger = CEC_ID;
			DM->QLIBER->Open();
			Label10->Caption = DM->QLIBER->FieldByName("SUMA_TOTAL")->AsString;
		}
		else
		{
			LProdus->Caption = "NESPECIFICAT";
		}

		EProdus->Clear();
		EProdus->SetFocus();
		CBClient->Checked = 0;
	}
	else
	{
		LProdus->Caption = "NESPECIFICAT";
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton6Click(TObject *Sender)
{
	// ATRIBUIM NUMAR LA CEC

	DM->QLIBER->Close();
	DM->QLIBER->SQL->Clear();
	DM->QLIBER->SQL->Add(" UPDATE CEC SET NR_CEC=(SELECT ISNULL(MAX(NR_CEC),0) FROM CEC)+1, SUMA_CEC=:SUMA_CEC, NR_POZ=(SELECT COUNT(*) FROM VANZARE WHERE CEC_ID=:CEC_ID) WHERE CEC_ID=:CEC_ID ");
	DM->QLIBER->ParamByName("CEC_ID")->AsInteger = CEC_ID;
	DM->QLIBER->ParamByName("SUMA_CEC")->AsFloat = Label10->Caption.ToDouble();
	DM->QLIBER->ExecSQL();

	DM->QVANZARE->Close();
	DM->QVANZARE->ParamByName("CEC_ID")->AsInteger = CEC_ID;
	DM->QVANZARE->Open();

	// SA SE CALCULEZE SUMA din casa
	DM->QLIBER->Close();
	DM->QLIBER->SQL->Clear();
	DM->QLIBER->SQL->Add(" SELECT SUM (SUMA_TOTAL) AS SUMA_TOTAL FROM VANZARE V INNER JOIN CEC ON CEC.CEC_ID=V.CEC_ID WHERE CAST(DATA_CEC AS DATE)=CAST(GETDATE() AS DATE) AND FIRMA_OPERATOR_ID=:FIRMA_OPERATOR_ID ");
	DM->QLIBER->ParamByName("FIRMA_OPERATOR_ID")->AsInteger = FAUTENTIFICARE->UTILIZATOR_ID;
	DM->QLIBER->Open();
	Label17->Caption = DM->QLIBER->FieldByName("SUMA_TOTAL")->AsString;

	LProdus->Caption = "NESPECIFICAT";
	LClient->Caption = "NESPECIFICAT";
	CLIENT_ID = 1;
	PROCENT = 0;
	PRET = 0;
	DM->QVANZARE->Close();
	Label10->Caption = "0.00";
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton7Click(TObject *Sender)
{
	if (!DM->QVANZARE->IsEmpty())
	{
		Label25->Caption = DM->QVANZARE->FieldByName("DENUMIRE")->AsString;
		Edit2->Clear();
		Panel6->Visible = 1;
		PageControl1->ActivePageIndex = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton12Click(TObject *Sender)
{
	if ((Edit2->Text != "") && (Edit2->Text.ToDouble() > 0))
	{
		// recalculam pozitiile anterioare
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		DM->QLIBER->SQL->Add(" UPDATE VANZARE SET CANTITATEA=:CANTITATEA,SUMA=:CANTITATEA * :PRET, SUMA_DISC=:CANTITATEA * :PRET * :PROCENT, SUMA_TOTAL=:CANTITATEA * :PRET - (:CANTITATEA * :PRET * :PROCENT) WHERE VANZARE_ID=:VANZARE_ID  ");
		DM->QLIBER->ParamByName("VANZARE_ID")->AsInteger = DM->QVANZARE->FieldByName("VANZARE_ID")->AsInteger;
		DM->QLIBER->ParamByName("procent")->AsFloat = PROCENT;
		DM->QLIBER->ParamByName("PRET")->AsFloat = DM->QVANZARE->FieldByName("pret_vanz")->AsFloat;
		;
		DM->QLIBER->ParamByName("CANTITATEA")->AsInteger = Edit2->Text.ToInt();
		DM->QLIBER->ExecSQL();

		DM->QVANZARE->Close();
		DM->QVANZARE->ParamByName("CEC_ID")->AsInteger = CEC_ID;
		DM->QVANZARE->Open();

		// SA SE CALCULEZE SUMA CECULUI
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		DM->QLIBER->SQL->Add(" SELECT SUM (SUMA_TOTAL) AS SUMA_TOTAL FROM VANZARE WHERE CEC_ID=:CEC_ID ");
		DM->QLIBER->ParamByName("CEC_ID")->AsInteger = CEC_ID;
		DM->QLIBER->Open();
		Label10->Caption = DM->QLIBER->FieldByName("SUMA_TOTAL")->AsString;
		Panel6->Visible = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton8Click(TObject *Sender)
{
	if (!DM->QVANZARE->IsEmpty())
	{
		Label6->Caption = DM->QVANZARE->FieldByName("DENUMIRE")->AsString;
		Edit1->Clear();
		SpeedButton9->Enabled = 0;
		Panel6->Visible = 1;
		PageControl1->ActivePageIndex = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton11Click(TObject *Sender)
{
	DM->QLIBER->Close();
	DM->QLIBER->SQL->Clear();
	DM->QLIBER->SQL->Add(" select fo.tip_acces from firma_operator fo inner join operator o on fo.operator_id=o.operator_id where cod=:cod");
	DM->QLIBER->ParamByName("firma_id")->AsInteger = DM->QAUTENTIFICAREFIRMA_ID->AsInteger;
	DM->QLIBER->ParamByName("cod")->AsString = Edit1->Text;
	DM->QLIBER->Open();
	Edit1->Clear();

	if (!DM->QLIBER->IsEmpty() && (DM->QLIBER->FieldByName("tip_acces")->AsInteger == 1))
	{
		SpeedButton9->Enabled = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton9Click(TObject *Sender)
{

	if (MessageDlg("doriti sa eliminati produsul " + Label6->Caption + "?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		DM->QLIBER->SQL->Add(" delete vanzare where vanzare_id=:vanzare_id  ");
		DM->QLIBER->ParamByName("VANZARE_ID")->AsInteger = DM->QVANZARE->FieldByName("VANZARE_ID")->AsInteger;
		DM->QLIBER->ExecSQL();
		DM->QVANZARE->Close();
		DM->QVANZARE->ParamByName("CEC_ID")->AsInteger = CEC_ID;
		DM->QVANZARE->Open();
		// sa se calculeze suma cecului
		DM->QLIBER->Close();
		DM->QLIBER->SQL->Clear();
		DM->QLIBER->SQL->Add(" SELECT SUM(SUMA_TOTAL) AS SUMA_TOTAL FROM VANZARE WHERE CEC_ID=:CEC_ID");
		DM->QLIBER->ParamByName("CEC_ID")->AsInteger = CEC_ID;
		DM->QLIBER->Open();
		Label10->Caption = DM->QLIBER->FieldByName("SUMA_TOTAL")->AsString;
		Panel6->Visible = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMAIN::SpeedButton4Click(TObject *Sender)
{
	FDATECEC->DateTimePicker1->Date = Now();
	FDATECEC->DateTimePicker2->Date = Now();
	FDATECEC->SpeedButton1->Click();
	FDATECEC->ShowModal();
}
//---------------------------------------------------------------------------
