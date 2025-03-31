//---------------------------------------------------------------------------

#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <Data.Bind.Components.hpp>
#include <Data.Bind.DBScope.hpp>
#include <Data.Bind.EngExt.hpp>
#include <Data.Bind.Grid.hpp>
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
#include <Fmx.Bind.DBEngExt.hpp>
#include <Fmx.Bind.Editors.hpp>
#include <Fmx.Bind.Grid.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.ScrollBox.hpp>
#include <REST.Client.hpp>
#include <REST.Response.Adapter.hpp>
#include <REST.Types.hpp>
#include <System.Bindings.Outputs.hpp>
#include <System.Rtti.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TBrushObject *Brush1;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TStringGrid *StringGrid1;
	TRESTClient *RESTClient1;
	TRESTRequest *RESTRequest1;
	TRESTResponse *RESTResponse1;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter1;
	TFDMemTable *FDMemTable1;
	TBindSourceDB *BindSourceDB1;
	TBindingsList *BindingsList1;
	TBindSourceDB *BindSourceDB2;
	TRESTRequest *RESTRequest2;
	TRESTResponse *RESTResponse2;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter2;
	TFDMemTable *FDMemTable2;
	TRESTRequest *RESTRequest3;
	TRESTResponse *RESTResponse3;
	TRESTResponseDataSetAdapter *RESTResponseDataSetAdapter3;
	TFDMemTable *FDMemTable3;
	TBindSourceDB *BindSourceDB3;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB2;
	TStringGrid *StringGrid2;
	TStringGrid *StringGrid3;
	TBindSourceDB *BindSourceDB4;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB4;
	TLinkGridToDataSource *LinkGridToDataSourceBindSourceDB3;
	TImage *Image1;
	TImage *Image5;
	TGlyph *Glyph1;
	TImageList *ImageList1;
	TImage *Image6;
	TImage *Image7;
	TImage *Image8;
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
    int imagesw;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
