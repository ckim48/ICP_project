//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image4Click(TObject *Sender)
{
	Form3->Close();
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	Form1->Show();	
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image2Click(TObject *Sender)
{
    Form3->Close();
	Form4->Show();
}
//---------------------------------------------------------------------------

