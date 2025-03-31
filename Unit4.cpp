//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormActivate(TObject *Sender)
{
	Label2->Text = Form3->Edit3->Text.SubString(0, Form3->Edit3->Text.Pos("@")-1) + Form3->ComboBox3->Items->Strings[Form3->ComboBox3->ItemIndex].SubString(0, Form3->ComboBox3->Items->Strings[Form3->ComboBox3->ItemIndex].Pos(" "));
}
//---------------------------------------------------------------------------


