//---------------------------------------------------------------------------

#ifndef URECEPTIEH
#define URECEPTIEH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TRECEPTIE : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TImage *Image2;
	TLabel *Label2;
	TLabel *Label3;
	TImage *Image1;
	TLabel *Label1;
	TPageControl *PageControl1;
	TTabSheet *MENIU;
	TTabSheet *FACTURA;
	TTabSheet *PRODUS;
	TTabSheet *UM;
	TTabSheet *EMITENT;
	TImage *Image3;
	TLabel *Label4;
	TTabSheet *CLIENT;
	TLabel *Label5;
	TPanel *Panel3;
	TPanel *Panel4;
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TSpeedButton *SpeedButton5;
	TSpeedButton *SpeedButton6;
	TTabSheet *DATEFACTURA;
	TPanel *Panel5;
	TPanel *Panel6;
	TDBGrid *DBGrid1;
	TSpeedButton *SpeedButton7;
	TSpeedButton *SpeedButton8;
	TPanel *Panel7;
	TPanel *Panel8;
	TDBGrid *DBGrid2;
	TRadioGroup *RadioGroup1;
	TRadioButton *RB1;
	TRadioButton *RB2;
	TEdit *ECAUTA;
	TSpeedButton *SpeedButton9;
	TSpeedButton *SpeedButton10;
	TSpeedButton *SpeedButton11;
	TSpeedButton *SpeedButton12;
	TSpeedButton *SpeedButton13;
	TPanel *Panel9;
	TPanel *Panel10;
	TDBGrid *DBGrid3;
	TSpeedButton *SpeedButton14;
	TSpeedButton *SpeedButton15;
	TPanel *Panel11;
	TPanel *Panel12;
	TSpeedButton *SpeedButton21;
	TPanel *Panel13;
	TLabel *Label6;
	TEdit *ESERIA;
	TLabel *Label7;
	TDateTimePicker *EDATA;
	TEdit *EEMITENT;
	TLabel *Label8;
	TSpeedButton *SpeedButton29;
	TSpeedButton *SpeedButton30;
	TDBGrid *DBGrid4;
	TPageControl *PageControl2;
	TTabSheet *FMAIN;
	TTabSheet *FMENIU;
	TSpeedButton *SpeedButton16;
	TSpeedButton *SpeedButton17;
	TSpeedButton *SpeedButton18;
	TSpeedButton *SpeedButton19;
	TTabSheet *FINREGISTRARE;
	TSpeedButton *SpeedButton20;
	TSpeedButton *SpeedButton22;
	TSpeedButton *SpeedButton23;
	TSpeedButton *SpeedButton24;
	TEdit *EPRODUS1;
	TEdit *EUM1;
	TEdit *ESTOC1;
	TEdit *EPRET1;
	TEdit *EVANZARE1;
	TEdit *EADAOS1;
	TComboBox *ETVA1;
	TTabSheet *FEDITARE;
	TSpeedButton *SpeedButton25;
	TSpeedButton *SpeedButton26;
	TSpeedButton *SpeedButton27;
	TSpeedButton *SpeedButton28;
	TEdit *EUM2;
	TEdit *EPRODUS2;
	TEdit *EPRET2;
	TEdit *ESTOC2;
	TEdit *EADAOS2;
	TEdit *EVANZARE2;
	TComboBox *ETVA2;
	TPanel *Panel14;
	TPanel *Panel15;
	TDBGrid *DBGrid5;
	TCheckBox *CheckBox1;
	TEdit *Edit1;
	TCheckBox *CheckBox2;
	TDateTimePicker *d1;
	TDateTimePicker *d2;
	TCheckBox *CheckBox3;
	TEdit *Edit2;
	TCheckBox *CheckBox4;
	TEdit *Edit3;
	TSpeedButton *SpeedButton31;
	TPanel *Panel16;
	TStatusBar *StatusBar1;
	TCheckBox *CheckBox5;
	TEdit *Edit4;
	TSpeedButton *SpeedButton32;
	TSpeedButton *SpeedButton33;
	void __fastcall RB1Click(TObject *Sender);
	void __fastcall ECAUTAChange(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SpeedButton7Click(TObject *Sender);
	void __fastcall SpeedButton8Click(TObject *Sender);
	void __fastcall SpeedButton9Click(TObject *Sender);
	void __fastcall SpeedButton22Click(TObject *Sender);
	void __fastcall SpeedButton20Click(TObject *Sender);
	void __fastcall SpeedButton14Click(TObject *Sender);
	void __fastcall SpeedButton29Click(TObject *Sender);
	void __fastcall SpeedButton30Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton16Click(TObject *Sender);
	void __fastcall ETVA1Change(TObject *Sender);
	void __fastcall SpeedButton23Click(TObject *Sender);
	void __fastcall SpeedButton24Click(TObject *Sender);
	void __fastcall SpeedButton17Click(TObject *Sender);
	void __fastcall SpeedButton27Click(TObject *Sender);
	void __fastcall EPRET2Change(TObject *Sender);
	void __fastcall SpeedButton18Click(TObject *Sender);
	void __fastcall SpeedButton19Click(TObject *Sender);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall CheckBox3Click(TObject *Sender);
	void __fastcall CheckBox4Click(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall CheckBox5Click(TObject *Sender);
	void __fastcall SpeedButton31Click(TObject *Sender);
	void __fastcall DBGrid5DblClick(TObject *Sender);
	void __fastcall SpeedButton32Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TRECEPTIE(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRECEPTIE *RECEPTIE;
//---------------------------------------------------------------------------
#endif
