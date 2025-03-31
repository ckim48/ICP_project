//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TBrushObject *Brush1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit2;
	TImage *Image1;
	TImage *Image2;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit3;
	TImage *Image3;
	TImage *Image4;
	TComboBox *ComboBox3;
	TLabel *Z;
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Image2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
