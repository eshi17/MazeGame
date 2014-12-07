/*
  MazeGame.pde
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2.

// Global Variables
int xcoord = 0;
int ycoord = 7;
int xsharka = 2;
int ysharka = 2;
int xsharkb = 7;
int ysharkb = 7;
int xsharkc = 1;
int ysharkc = 0;
boolean aTreasure = false;
boolean bTreasure = false;
boolean cTreasure = false;
boolean dTreasure = false;
boolean aAShark = false;
boolean bBShark = false;
boolean cCShark = false;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  Serial.print("x = ");
  Serial.println(xcoord); //checks x print
  Serial.print("y = ");
  Serial.println(ycoord); //checks y print
  EditColor(Orange, 10, 0, 2);

  CheckButtonsDown();
  if (Button_Right) //All code that prevents you from walking through walls comes from Brent Uramoto
  {
    if(xcoord < 7)
    {
      if(ReadPx(xcoord+1, ycoord) != White)
      {
        xcoord++;
      }
    }
  }
  
  if (Button_Left)
  {
    if(xcoord > 0)
    {
      if(ReadPx(xcoord-1, ycoord) != White)
      {
        xcoord--;
      }
    }
  }
  
  if (Button_Up)
  {
  if(ycoord < 7)
    {
      if(ReadPx(xcoord, ycoord+1) != White)
      {
        ycoord++;
      }
    }
  }
  
  if (Button_Down)
  {
    if(ycoord > 0)
      {
        if(ReadPx(xcoord, ycoord-1) != White)
        {
          ycoord--;
        }
      }
  }
  
  {
    aShark();
    DrawPx(xcoord,ycoord,Yellow);
  }
    DisplaySlate();
    delay(400);
    ClearSlate();
  Ocean();
  drawPlatforms();
  Treasure();
  winGame();
}
  
void drawPlatforms()
{
    EditColor(White, 16, 6, 7);
    DrawPx(0, 4, White);
    DrawPx(1, 4, White);
    DrawPx(2, 4, White);
    DrawPx(3, 3, White);
    DrawPx(0, 2, White);
    DrawPx(1, 2, White);
    DrawPx(0, 0, White);
    DrawPx(1, 0, White);
    DrawPx(3, 1, White);
    DrawPx(4, 1, White);
    DrawPx(6, 1, White);
    DrawPx(6, 2, White);
    DrawPx(7, 2, White);
    DrawPx(6, 3, White);
    DrawPx(5, 3, White);
    DrawPx(5, 5, White);
    DrawPx(5, 6, White);
    DrawPx(6, 6, White);
    DrawPx(1, 7, White);
    DrawPx(1, 6, White);
    DrawPx(5, 4, White);
}

void Ocean()
{
  EditColor(Blue, 0, 1, 2);
     for (int i = 0; i < 8; i++)
     for (int a = 0; a < 8; a++)
      DrawPx(i, a, Blue);
}

void Treasure()
{
  if(xcoord == 0 && ycoord == 3)
  {
    aTreasure = true;
  }
  
  if (aTreasure == false)
  {
    DrawPx(0,3,Orange);
  }

  if (aTreasure == true)
  {
    DrawPx(0,3,Blue);
  }
  
  if(xcoord == 6 && ycoord == 4)
  {
    bTreasure = true;
  }
  
  if (bTreasure == false)
  {
    DrawPx(6,4,Orange);
  }

  if (bTreasure == true)
  {
    DrawPx(6,4,Blue);
  }
  
  if(xcoord == 7 && ycoord == 1)
  {
  cTreasure = true;
  }
  
  if (cTreasure == false)
  {
    DrawPx(7,1,Orange);
  }

  if (cTreasure == true)
  {
    DrawPx(7,1,Blue);
  }

  if(xcoord == 2 && ycoord == 5)
  {
  dTreasure = true;
  }
  
  if (dTreasure == false)
  {
    DrawPx(2,5,Orange);
  }

  if (dTreasure == true)
  {
    DrawPx(2,5,Blue);
  }
}

void aShark()
{
  DrawPx(xsharka, ysharka, Dark);
  if (xsharka == 2)
  {
    if (ysharka == 2)
    {
      aAShark = false;
    }
  }
  if (aAShark == false)
  {
    xsharka = xsharka + 1;
  }
  if (xsharka == 6)
  {
    if (ysharka == 2)
    {
      aAShark = true;
    }
  }
  if (aAShark == true)
  {
    xsharka = xsharka - 1;
  }
  
  DrawPx(xsharkb, ysharkb, Dark);
  if (xsharkb == 7)
  {
    if (ysharkb == 7)
    {
      bBShark = false;
    }
  }
  if (bBShark == false)
  {
    ysharkb = ysharkb - 1;
  }
  if (xsharkb == 7)
  {
    if (ysharkb == 2)
    {
      bBShark = true;
    }
  }
  if (bBShark == true)
  {
    ysharkb = ysharkb + 1;
  }
    
  DrawPx(xsharkc, ysharkc, Dark);
  if (xsharkc == 2)
  {
    if (ysharkc == 0)
    {
      cCShark = false;
    }
  }
  if (cCShark == false)
  {
    xsharkc = xsharkc + 1;
  }
  if (xsharkc == 8)
  {
    if (ysharkc == 0)
    {
      cCShark = true;
    }
  }
  if (cCShark == true)
  {
    xsharkc = xsharkc - 1;
  }
  if(ReadPx(xcoord, ycoord) == Dark)
   {
     (xcoord = 0);
     (ycoord = 7);
     Ocean();
     drawPlatforms();
     Treasure();
     Tone_Start(ToneC3, 50);
     Tone_Start(ToneF3, 50);  
   }
}

void winGame()
{
  if (aTreasure == true)
    {
      if (bTreasure == true)
      {
        if (cTreasure == true)
        {
          if (dTreasure == true)
  {
  Ocean();
  DrawPx(4,7,DimYellow);
  DrawPx(3,6,DimYellow);
  DrawPx(4,6,DimYellow);
  DrawPx(2,5,DimYellow);
  DrawPx(3,5,DimYellow);
  DrawPx(4,5,DimYellow);
  DrawPx(5,5,DimYellow);
  DrawPx(0,4,DimYellow);
  DrawPx(1,4,DimYellow);
  DrawPx(2,4,DimYellow);
  DrawPx(3,4,DimYellow);
  DrawPx(4,4,DimYellow);
  DrawPx(5,4,DimYellow);
  DrawPx(6,4,DimYellow);
  DrawPx(7,4,DimYellow);
  DrawPx(1,3,DimYellow);
  DrawPx(2,3,DimYellow);
  DrawPx(3,3,DimYellow);
  DrawPx(4,3,DimYellow);
  DrawPx(5,3,DimYellow);
  DrawPx(6,3,DimYellow);
  DrawPx(2,2,DimYellow);
  DrawPx(3,2,DimYellow);
  DrawPx(4,2,DimYellow);
  DrawPx(5,2,DimYellow);
  DrawPx(1,1,DimYellow);
  DrawPx(2,1,DimYellow);
  DrawPx(5,1,DimYellow);
  DrawPx(6,1,DimYellow);
  DrawPx(1,0,DimYellow);
  DrawPx(6,0,DimYellow);
    Tone_Start(ToneA5,100);
      delay(150);
    Tone_Start(ToneB5,100);
      delay(150);
    Tone_Start(ToneC5,100);
      delay(150);
  aTreasure = false;
  bTreasure = false;
  cTreasure = false;
  dTreasure = false;
  xcoord = 0;
  ycoord = 7;
  }
        }
      }
    }
}
