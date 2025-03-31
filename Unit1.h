//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Graphics.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.ObjectScope.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <REST.Client.hpp>
#include <REST.Response.Adapter.hpp>
#include <REST.Types.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TLabel *Label5;
	TLabel *Label1;
	TLabel *Label2;
	TImage *Image4;
	TTimer *Timer1;
	TImage *Image6;
	TEdit *Edit1;
	TEdit *Edit2;
	TImage *Image5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TEdit *Edit3;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TImage *Image7;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit5;
	TComboBox *ComboBox3;
	TRectangle *Rectangle1;
	TBrushObject *Brush1;
	TText *Text1;
	TText *Text2;
	TText *Text3;
	TLabel *Label3;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter1;
	TFDMemTable *FDMemTable1;
	TGlyph *Glyph1;
	TImageList *ImageList1;
	TImage *Image9;
	TLabel *Label4;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Text1MouseEnter(TObject *Sender);
	void __fastcall Text2MouseLeave(TObject *Sender);
	void __fastcall Text2MouseEnter(TObject *Sender);
	void __fastcall Text1MouseLeave(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image9Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
