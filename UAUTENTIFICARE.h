//---------------------------------------------------------------------------

#ifndef UAUTENTIFICAREH
#define UAUTENTIFICAREH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TFAUTENTIFICARE : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TPanel *Panel2;
	TEdit *EOPERATOR;
	TEdit *EPAROLA;
	TButton *Button1;
	TButton *Button2;
	TComboBox *EFIRMA;
	TImage *r;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall EFIRMAKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall EPAROLAKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:     // User declarations
  int UTILIZATOR_ID;
	__fastcall TFAUTENTIFICARE(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAUTENTIFICARE *FAUTENTIFICARE;
//---------------------------------------------------------------------------
#endif
