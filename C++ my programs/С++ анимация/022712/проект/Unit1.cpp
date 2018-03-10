//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
    Graphics::TBitmap *Fon=new Graphics::TBitmap(),
*Ris=new Graphics::TBitmap(),
*Fon_kadr=new Graphics::TBitmap();
int w_kadr,h_kadr,x,y;
        
TRect Rect_fon, Rect_kadr;
    int c;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
      //  int c;
 Form1->Edit1->Text="100";
  c=StrToInt( Form1->Edit1->Text);

  Fon->LoadFromFile("Ris2.bmp");
  Ris->LoadFromFile("Ris1.bmp");
 

  w_kadr=Ris->Width;
  h_kadr=Ris->Height;
  Fon_kadr->Width=w_kadr;
  Fon_kadr->Height=h_kadr;

   Ris->Transparent=true;

  x=-w_kadr;
  y=20;

  Rect_fon=Bounds(x,y,w_kadr,h_kadr);
  Rect_kadr=Bounds(0,0,w_kadr,h_kadr);
  Fon_kadr->Canvas->CopyRect(Rect_kadr,Fon->Canvas,Rect_fon);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{      c=StrToInt( Form1->Edit1->Text);
   Timer1->Interval=c;
         Image1->Canvas->CopyRect(Rect_fon,Fon_kadr->Canvas,Rect_kadr);
   x+=2;
   if (x>Image1->Width) x=-w_kadr;


   Rect_fon=Bounds(x,y,w_kadr,h_kadr);
   Fon_kadr->Canvas->CopyRect(Rect_kadr,Fon->Canvas,Rect_fon);


   Image1->Canvas->Draw(x,y,Ris);
}
//---------------------------------------------------------------------------
