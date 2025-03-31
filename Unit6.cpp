//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit5.h"
#include "Unit6.h"
#include "uMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormClose(TObject *Sender, TCloseAction &Action)
{
	Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Image1Click(TObject *Sender)
{
    Form6->Close();
}
//---------------------------------------------------------------------------




void __fastcall TForm6::Image8Click(TObject *Sender)
{
	OpenDialog1->Execute();
	try
	{
		Image10->Bitmap->LoadFromFile(OpenDialog1->FileName);
	}
	catch(...)
	{
		ShowMessage("Please select an image");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Image4Click(TObject *Sender)
{
	CameraComponentForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Image5Click(TObject *Sender)
{
    Glyph1->ImageIndex=abs(Glyph1->ImageIndex-1);
	Glyph2->ImageIndex=abs(Glyph1->ImageIndex-1);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Image6Click(TObject *Sender)
{
	Glyph1->ImageIndex=abs(Glyph1->ImageIndex-1);
	Glyph2->ImageIndex=abs(Glyph1->ImageIndex-1);
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Image11Click(TObject *Sender)
{
	if (Glyph3->ImageIndex==0)
	{
		Label3->Visible=True;
		Edit3->Visible=True;
	}
	else
	{
		Label3->Visible=False;
		Edit3->Visible=False;
	}
	Glyph3->ImageIndex=abs(Glyph3->ImageIndex-1);
}
//---------------------------------------------------------------------------


