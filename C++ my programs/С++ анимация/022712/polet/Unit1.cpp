//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
// создать три объекта - битовых образа
Graphics::TBitmap *Fon=new Graphics::TBitmap(),
*Ris=new Graphics::TBitmap(),
*Fon_kadr=new Graphics::TBitmap();
int w_kadr,h_kadr,x,y;
   // текущее положение картинки
   // размеры картинки



TRect Rect_fon, Rect_kadr;
// фон и картинка
      // положение и размер области фона,
        оторая должна быть восстановлена


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
//  Image1->Picture->LoadFromFile("factory.bmp");
  // загрузить фон и рисунок
 Fon->LoadFromFile("factory.bmp");
  Ris->LoadFromFile("aplane.bmp");
 
  // определитьа размеры фона и рисунка  
  w_kadr=Ris->Width;
  h_kadr=Ris->Height;
  Fon_kadr->Width=w_kadr;
  Fon_kadr->Height=h_kadr;
  // определим "прозрачный" цвет
   Ris->Transparent=true;
// начальное положение картинки
  x=-w_kadr;
  y=20;
 // определим сохраняемую область фона и рисунка  
  Rect_fon=Bounds(x,y,w_kadr,h_kadr);
  Rect_kadr=Bounds(0,0,w_kadr,h_kadr);
  Fon_kadr->Canvas->CopyRect(Rect_kadr,Fon->Canvas,Rect_fon);
}
//---------------------------------------------------------------------------
// обработка сигнала таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{ // восстановлением фона удалим рисунок

   Image1->Canvas->CopyRect(Rect_fon,Fon_kadr->Canvas,Rect_kadr);
   x+=2;
   if (x>Image1->Width) x=-w_kadr;
 // определим сохраняемую область фона

   Rect_fon=Bounds(x,y,w_kadr,h_kadr);
   Fon_kadr->Canvas->CopyRect(Rect_kadr,Fon->Canvas,Rect_fon);
 // выведем рисунок

   Image1->Canvas->Draw(x,y,Ris);
}
//---------------------------------------------------------------------------
