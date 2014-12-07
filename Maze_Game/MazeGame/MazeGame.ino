/*
  MazeGame.pde
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2.

// Global Variables
int xcoord = 0;
int ycoord = 7; //original location of player
int xsharka = 2;
int ysharka = 2;
int xsharkb = 7;
int ysharkb = 7;
int xsharkc = 1;
int ysharkc = 0; //original locations of sharks
boolean aTreasure = false;
boolean bTreasure = false;
boolean cTreasure = false;
boolean dTreasure = false;//existance of treasure
boolean aAShark = false;
boolean bBShark = false;
boolean cCShark = false;//direction of shark

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
  EditColor(Orange, 10, 0, 2); //edited orange to a vibrant pink color
  EditColor(Blue, 0, 1, 2);//edited blue to a duller blue
  EditColor(White, 16, 6, 7);//edited white to a duller white
  

  CheckButtonsDown();
  if (Button_Right) //All code that prevents you from walking through walls comes from Brent Uramoto
  {
    if(xcoord < 7)
    {
      if(ReadPx(xcoord+1, ycoord) != White) //if the dot is not on a white pixel, it can move
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
    delay(400); //had trouble making it "real time". Compromised both sharks and player so that it moves at an equal speed, although that makes the player a little slow
    ClearSlate();
  Ocean(); //blue screen
  drawPlatforms(); //white walls
  Treasure();//pink dots
  winGame();//yellow star+sounds
}
  
void drawPlatforms()
{
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
    DrawPx(5, 4, White); //no other way to code than hard code
}

void Ocean()
{
     for (int i = 0; i < 8; i++)
     for (int a = 0; a < 8; a++)
      DrawPx(i, a, Blue); //makes whole screen blue
}

void Treasure()
{
  if(xcoord == 0 && ycoord == 3)
  {
    aTreasure = true; //if player is on 0,3 then aTreasure variable becomes true (from false)
  }
  
  if (aTreasure == false) //originally aTreasure is false, so it appears pink
  {
    DrawPx(0,3,Orange);
  }

  if (aTreasure == true)//when turned true, treasure becomes blue, the same color as the ocean
  {
    DrawPx(0,3,Blue);
  }
  
  if(xcoord == 6 && ycoord == 4)
  {
    bTreasure = true; //same concept as above
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
  DrawPx(xsharka, ysharka, Dark);//if dot is on location, then aAShark is false
  if (xsharka == 2)
  {
    if (ysharka == 2)
    {
      aAShark = false;
    }
  }
  if (aAShark == false)//if location of shark is false, then shark moves towards designated location
  {
    xsharka = xsharka + 1;
  }
  if (xsharka == 6)
  {
    if (ysharka == 2)
    {
      aAShark = true;//once the shark reaches the rebound location (6,2), then aAShark becomes true
    }
  }
  if (aAShark == true) // if aAShark is true, then it goes towards original location
  {
    xsharka = xsharka - 1;
  }
  
  DrawPx(xsharkb, ysharkb, Dark); //same concept as above
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
  if(ReadPx(xcoord, ycoord) == Dark) //the game over; if player touches sharks, it goes back to original location; eaten treasures remain eaten (gives room for strategy).
   {
     (xcoord = 0);
     (ycoord = 7);
     Ocean();
     drawPlatforms();
     Treasure();
     Tone_Start(ToneC3, 50);
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
          if (dTreasure == true) //if all treasures are true (all treasures have been eaten), then game is won
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
  DrawPx(6,0,DimYellow); //giant yellow star
    Tone_Start(ToneA5,100);
      delay(150);
    Tone_Start(ToneB5,100);
      delay(150);
    Tone_Start(ToneC5,100);
      delay(150); //decent sounding noise
  aTreasure = false;
  bTreasure = false;
  cTreasure = false;
  dTreasure = false; //treasures become false, and game goes back to original state
  xcoord = 0;
  ycoord = 7; //player returns to original location
  }
        }
      }
    }
}
