/*
  Moving_Dot.pde
 */

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2.

// Global Variables
int xcoord = 0;
int ycoord = 7;
boolean aTreasure = false;
boolean bTreasure = false;
boolean cTreasure = false;
boolean dTreasure = false;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // RequiYellow code, line 2 of 2.
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  Serial.print("x = ");
  Serial.println(xcoord);
  Serial.print("y = ");
  Serial.println(ycoord);
  
  CheckButtonsPress();
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
  DrawPx(xcoord,ycoord,Yellow);
  DisplaySlate();
  delay(50);
  ClearSlate();
  
  Ocean();
  drawPlatforms();
  Treasure();
  DisplaySlate();
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
  EditColor(Orange, 10, 0, 2);

if(xcoord == 0 && ycoord == 3)
  aTreasure = true;
  
if (aTreasure == false)
  {
    DrawPx(0,3,Orange);
  }

if (aTreasure == true)
  {
    DrawPx(0,3,Blue);
  }
  
if(xcoord == 6 && ycoord == 4)
  bTreasure = true;
  
if (bTreasure == false)
  {
    DrawPx(6,4,Orange);
  }

if (bTreasure == true)
  {
    DrawPx(6,4,Blue);
  }
  
if(xcoord == 7 && ycoord == 1)
  cTreasure = true;
  
if (cTreasure == false)
  {
    DrawPx(7,1,Orange);
  }

if (cTreasure == true)
  {
    DrawPx(7,1,Blue);
  }

if(xcoord == 2 && ycoord == 5)
  dTreasure = true;
  
if (dTreasure == false)
  {
    DrawPx(2,5,Orange);
  }

if (dTreasure == true)
  {
    DrawPx(2,5,Blue);
  }
}
