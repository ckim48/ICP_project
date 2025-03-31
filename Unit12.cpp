//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit12.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm12 *Form12;
TPanel *e[64];
TImage* f[64];
String Rb_Caption[64];
int s=0,j=300;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm12::Button1Click(TObject *Sender)
{
	Rb_Caption[s]="Panel"+IntToStr(s);
	TPanel* Sample=Panel1;
	e[s] = new TPanel(this);
	e[s]->Parent=this;
	e[s]->Position->X=10;
	e[s]->Position->Y=10+(80*s);
	e[s]->Width=Sample->Width;
	e[s]->Height=Sample->Height;
	e[s]->Visible=True;

	TImage* Proto=Image1;
	f[s] = new TImage(this);
	Proto->Parent=e[s];
	Proto->Width=68;
	Proto->Height=65;
	Proto->Visible=True;
	Proto->Position->X=10;
	Proto->Position->Y=0;
	s++;
}
//---------------------------------------------------------------------------

void __fastcall TForm12::Button2Click(TObject *Sender)
{
	for (int i=0 ; i < s; i++) {
		delete e[i];
		delete f[i];
	}
	s=0;
}
//---------------------------------------------------------------------------
/*
RESTRequest6->AddBody(BODY, ctAPPLICATION_JSON);
RESTRequest6->Method = rmGET;
RESTRequest6->Execute();
TJSONValue *JSONObjectValue = RESTResponse6->JSONValue;
AnsiString RESP_stdErr = JSONObjectValue->GetValue<String>("error");
RESP_stdOut = JSONObjectValue->GetValue<String>("result");
RESP_time = JSONObjectValue->GetValue<String>("time");

여기서 lost, load image, account,잃어버린 위치  등 찾아주기
*/
void __fastcall TForm12::FormCreate(TObject *Sender)
{
	// Fetch data using REST request
	RESTRequest2->Execute();
	String response = RESTResponse2->Content; // Response content

	// Optionally, display the raw response
	Memo1->Lines->Add(response);
	ShowMessage(response);

	// Parse the JSON response string
	TJSONObject* json = static_cast<TJSONObject*>(TJSONObject::ParseJSONValue(response));
	ShowMessage(1);

    // Check if the parsing was successful
    if (json != nullptr)
	{
		ShowMessage(2);
		// Get the result array from the JSON response (assuming it's an array of lost items)
		TJSONArray* resultArray = static_cast<TJSONArray*>(TJSONObject::ParseJSONValue(response));
		ShowMessage(3);
		// If the array is valid, start processing each item
		if (resultArray != nullptr)
        {
			for (int i = 0; i < resultArray->Count; i++) {
				ShowMessage(i);
                TJSONObject* item = static_cast<TJSONObject*>(resultArray->Items[i]);

                // Extract values from each item in the array
				String id = static_cast<TJSONString*>(item->Get("ID")->JsonValue)->Value();
                String title = static_cast<TJSONString*>(item->Get("Title")->JsonValue)->Value();
				String lostDate = static_cast<TJSONString*>(item->Get("Lost Date")->JsonValue)->Value();
                String lostItem = static_cast<TJSONString*>(item->Get("Lost Item")->JsonValue)->Value();
				String lostLocation = static_cast<TJSONString*>(item->Get("Lost Location")->JsonValue)->Value();
                String itemDescription = static_cast<TJSONString*>(item->Get("Item Description")->JsonValue)->Value();
                String deliveryPreference = static_cast<TJSONString*>(item->Get("Delivery Preference")->JsonValue)->Value();
                String meetUpAt = static_cast<TJSONString*>(item->Get("Meet Up @")->JsonValue)->Value();
				String allowSuggestion = static_cast<TJSONString*>(item->Get("Allow Suggestion")->JsonValue)->Value();
				String imageFile = static_cast<TJSONString*>(item->Get("Image File")->JsonValue)->Value();

				// Dynamically create a new panel and image for each item
				ShowMessage(id + title + lostItem + lostLocation + lostDate + imageFile + i);
			}
		}
	}
	else {
		ShowMessage("Failed to parse JSON response.");
	}
}
