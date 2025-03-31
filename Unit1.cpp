//---------------------------------------------------------------------------
#include <fmx.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
int cnt=0,sw=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Image4->RotationAngle+=10;
	cnt+=10;
	if (cnt==360)
	{
		Timer1->Enabled=false;
		cnt=0;
		if (sw==0)
		{
			Label1->Text="Sign";
			Label2->Text="In";
			Edit1->Text="";
			Edit2->Text="";
			Label3->Visible=False;
			Label4->Visible=False;
			Image1->Visible=False;
			Image2->Visible=False;
			Image5->Visible=True;
			Edit1->Visible=True;
			Edit2->Visible=True;
			Text1->Visible=True;
			Text2->Visible=True;
			Label6->Visible=False;
			Edit3->Visible=False;
			Label9->Visible=False;
			ComboBox3->Visible=False;
			Label10->Visible=False;
			Edit5->Visible=False;
			Label7->Visible=False;
			Label8->Visible=False;
			ComboBox1->Visible=False;
			ComboBox2->Visible=False;
			Image7->Visible=False;
			Image6->Visible=True;
			Edit2->Password=True;
			Glyph1->ImageIndex=0;
		}
		else if (sw==1)
		{
			Label1->Text="Sign";
			Label2->Text="Up";
			ComboBox1->ItemIndex=-1;
			ComboBox2->ItemIndex=-1;
			ComboBox3->ItemIndex=-1;
			Edit3->Text="";
			Edit5->Text="";
			Label3->Visible=False;
			Label4->Visible=False;
			Image1->Visible=False;
			Image2->Visible=False;
			Image5->Visible=False;
			Edit1->Visible=False;
			Edit2->Visible=False;
			Text1->Visible=False;
			Text2->Visible=False;
			Label6->Visible=True;
			Edit3->Visible=True;
			Label9->Visible=True;
			ComboBox3->Visible=True;
			Label10->Visible=True;
			Edit5->Visible=True;
			Label7->Visible=True;
			Label8->Visible=False;
			ComboBox1->Visible=True;
			ComboBox2->Visible=False;
			Image7->Visible=True;
			Image6->Visible=True;
			Glyph1->ImageIndex=-1;
		}
		else if (sw==2)
		{
			Label3->Visible=False;
			Label4->Visible=False;
			Image1->Visible=True;
			Image2->Visible=True;
			Image4->Visible=True;
			Image5->Visible=False;
			Edit1->Visible=False;
			Edit2->Visible=False;
			Text1->Visible=False;
			Text2->Visible=False;
			Label6->Visible=False;
			Edit3->Visible=False;
			Label9->Visible=False;
			ComboBox3->Visible=False;
			Label10->Visible=False;
			Edit5->Visible=False;
			Label7->Visible=False;
			Label8->Visible=False;
			ComboBox1->Visible=False;
			ComboBox2->Visible=False;
			Image7->Visible=False;
			Image6->Visible=False;
			Text3->Text="";
			Glyph1->ImageIndex=-1;
		}
		else if (sw==3)
		{
			Label1->Text="Your";
			Label2->Text="ID";
			Label3->Visible=False;
			Label4->Visible=False;
			Text3->Text=Edit5->Text.SubString(0,Edit5->Text.Pos("@")-1)+ComboBox3->Items->Strings[ComboBox3->ItemIndex].SubString(0,ComboBox3->Items->Strings[ComboBox3->ItemIndex].Pos(" "));
			Image1->Visible=False;
			Image2->Visible=False;
			Image5->Visible=False;
			Edit1->Visible=False;
			Edit2->Visible=False;
			Text1->Visible=False;
			Text2->Visible=False;
			Label6->Visible=False;
			Edit3->Visible=False;
			Label9->Visible=False;
			ComboBox3->Visible=False;
			Label10->Visible=False;
			Edit5->Visible=False;
			Label7->Visible=False;
			Label8->Visible=False;
			ComboBox1->Visible=False;
			ComboBox2->Visible=False;
			Image7->Visible=False;
			Image6->Visible=True;
			Glyph1->ImageIndex=-1;
		}
		else if (sw==4)
		{
			if (Edit1->Text!="" && Edit2->Text!="")
			{
				RESTRequest1->Resource="login-check?id="+Edit1->Text+"&pw="+Edit2->Text;
				RESTRequest1->Execute();
                //ShowMessage(RESTResponse1->Content);
				if (RESTResponse1->Content=="true")
				{
                    Label3->Visible=False;
					Form1->Hide();
					Form5->Show();
				}
				else
				{
					Label3->Visible=False;
					Label4->Visible=True;
				}
			}
			else
			{
				Label4->Visible=False;
				Label3->Visible=True;
			}
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
	sw=0;
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
	Label1->Text="";
	Label2->Text="";
	sw=2;
	Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image7Click(TObject *Sender)
{
	int signupcompletesw=0;
	if (ComboBox1->ItemIndex==0)
	{
		if (ComboBox2->ItemIndex==-1)
			signupcompletesw=1;
	}
	if (ComboBox1->ItemIndex==-1||ComboBox3->ItemIndex==-1||Edit3->Text==""||Edit5->Text=="")
	{
		signupcompletesw=1;
	}
	if (signupcompletesw==0)
	{
		Label1->Text="";
		Label2->Text="";
		sw=3;
		Timer1->Enabled=true;
		String autogeneratedid=Edit5->Text.SubString(0,Edit5->Text.Pos("@")-1)+ComboBox3->Items->Strings[ComboBox3->ItemIndex].SubString(0,ComboBox3->Items->Strings[ComboBox3->ItemIndex].Pos(" "));
		RESTRequest1->Resource="password-correspond?school="+ComboBox3->Items->Strings[ComboBox3->ItemIndex]+"&email="+Edit5->Text;
		RESTRequest1->Execute();
		String schoolemailpassword = RESTResponse1->Content;
        String gradelevel="";
		if (ComboBox1->ItemIndex==0)
		{
			String selectedgrade=ComboBox2->Items->Strings[ComboBox2->ItemIndex];
			int spacepos=selectedgrade.Pos(" ");
			gradelevel=selectedgrade.SubString(spacepos+1,selectedgrade.Length()-spacepos);
			ShowMessage(gradelevel);
		}
		RESTRequest1->Resource="sign-up?fname="+Edit3->Text+"&id="+autogeneratedid+"&pw="+schoolemailpassword+"&school="+ComboBox3->Items->Strings[ComboBox3->ItemIndex]+"&email="+Edit5->Text+"&grade="+gradelevel+"&status="+ComboBox1->Items->Strings[ComboBox1->ItemIndex]; //schoolemailpassword에 저장할때 RESTResponse에서 password에 [""] 붙은거 빼야함, 'Grade 9'에서 'Grade ' 빼야함
		RESTRequest1->Execute();
		if (RESTResponse1->Content=="true")
			Label3->Text="You're already signed in.";
	}
	else
		Label3->Visible=True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
	sw=1;
	Timer1->Enabled=True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Text1MouseEnter(TObject *Sender)
{
	Text1->TextSettings->Font->Style=TFontStyles()<<TFontStyle::fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Text2MouseLeave(TObject *Sender)
{
	Text2->TextSettings->Font->Style=Text2->TextSettings->Font->Style>>TFontStyle::fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Text2MouseEnter(TObject *Sender)
{
	Text2->TextSettings->Font->Style=TFontStyles()<<TFontStyle::fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Text1MouseLeave(TObject *Sender)
{
	Text1->TextSettings->Font->Style=Text2->TextSettings->Font->Style>>TFontStyle::fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
	sw=4;
	Timer1->Enabled=True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9Click(TObject *Sender)
{
    int x;
	x=Glyph1->ImageIndex;
	Glyph1->ImageIndex=abs(x-1);
	if (x==1)
		Edit2->Password=True;
	else
		Edit2->Password=False;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	if (ComboBox1->ItemIndex==0)
	{
		Label8->Visible=True;
		ComboBox2->Visible=True;
	}
	else
	{
		Label8->Visible=False;
		ComboBox2->Visible=False;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
	if (ComboBox1->ItemIndex!=-1 && ComboBox2->ItemIndex!=-1 && ComboBox3->ItemIndex!=-1 && Edit3->Text=='\0' && Edit5->Text=='\0')
	{
        Label3->Visible=False;
	}
}
//---------------------------------------------------------------------------


