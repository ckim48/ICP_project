//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.Memo.Types.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <FMX.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TBrushObject *Brush1;
	TLabel *Label1;
	TEdit *Edit1;
	TImage *Image1;
	TLabel *Label2;
	TLabel *Z;
	TImage *Image3;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TEdit *Edit2;
	TCheckBox *CheckBox1;
	TLabel *Label5;
	TLabel *Label6;
	TComboBox *ComboBox1;
	TImage *Image7;
	TGlyph *Glyph1;
	TImageList *ImageList1;
	TImageList *ImageList2;
	TGlyph *Glyph2;
	TImage *Image8;
	TImage *Image9;
	TOpenDialog *OpenDialog1;
	TImage *Image10;
	TImage *Image2;
	TLabel *Label3;
	TEdit *Edit3;
	TEdit *Edit4;
	TImage *Image11;
	TGlyph *Glyph3;
	TImageList *ImageList3;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image8Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Image11Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
