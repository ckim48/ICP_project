//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit6.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm5 *Form5;
int x=0,imagesw=0;
String filter="";
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Image2Click(TObject *Sender)
{
	Glyph1->ImageIndex=x;
	imagesw=1;
	Image7->Visible=True;
	StringGrid1->Visible = True;
	StringGrid2->Visible = False;
	StringGrid3->Visible = False;
	RESTRequest1->Resource = "/lost";
	RESTRequest1->Execute();
	FDMemTable1->Filter=filter;
	StringGrid1->Columns[0]->Width = 100;
	StringGrid1->Columns[1]->Width = 100;
	StringGrid1->Columns[2]->Width = 150;
	StringGrid1->Columns[3]->Width = 100;
	StringGrid1->Columns[4]->Width = 200;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image3Click(TObject *Sender)
{
	Glyph1->ImageIndex=x;
	imagesw=2;
    Image7->Visible=True;
	StringGrid1->Visible = False;
	StringGrid2->Visible = True;
	StringGrid3->Visible = False;
	RESTRequest2->Resource = "/found";
	RESTRequest2->Execute();
    FDMemTable2->Filter=filter;
	StringGrid2->Columns[0]->Width = 100;
	StringGrid2->Columns[1]->Width = 100;
	StringGrid2->Columns[2]->Width = 150;
	StringGrid2->Columns[3]->Width = 100;
	StringGrid2->Columns[4]->Width = 200;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image4Click(TObject *Sender)
{
	Glyph1->ImageIndex=-1;
	StringGrid1->Visible = False;
	StringGrid2->Visible = False;
	StringGrid3->Visible = True;
	RESTRequest3->Resource = "/helped?id="+Form1->Edit1->Text;
	RESTRequest3->Execute();
	StringGrid3->Columns[0]->Width = 100;
	StringGrid3->Columns[1]->Width = 100;
	StringGrid3->Columns[2]->Width = 150;
	StringGrid3->Columns[3]->Width = 150;
	StringGrid3->Columns[4]->Width = 150;
}
//---------------------------------------------------------------------------



void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
    Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Image6Click(TObject *Sender)
{
	if (imagesw!=0)
	{
		x=abs(Glyph1->ImageIndex-1);
		Glyph1->ImageIndex=x;
		filter="id='"+Form1->Edit1->Text+"'";
		if (x==0)
			filter="";
		if (imagesw==1)
			FDMemTable1->Filter=filter;
		else if (imagesw==2)
			FDMemTable2->Filter=filter;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm5::Image7Click(TObject *Sender)
{
	Form6->Show();
	Form5->Hide();
}
//---------------------------------------------------------------------------

