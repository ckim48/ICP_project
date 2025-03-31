//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TBrushObject *Brush1;
	TLabel *Label4;
	TLabel *Label1;
	TImage *Image3;
	TImage *Image1;
	TImage *Image2;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label3;
	TLabel *Label5;
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
