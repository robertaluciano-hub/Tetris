#include <raylib.h>
#include <iostream>
#include "grid.h"
#include "game.h"
#include "colors.h"

double lastUpdateTime = 0;

bool eventTriggered(double interval) {
   double currentTime = GetTime();
   if (currentTime - lastUpdateTime >= interval) {
      lastUpdateTime = currentTime;
      return true;
   }
   return false;
}

int main() 
{
   Color darkblue = {44, 44, 127, 255};
   InitWindow(500, 620, "Tetris");  
   SetTargetFPS(60);

   Font font = LoadFontEx("font/monogram.ttf", 64, 0, 0);
   Game game = Game();

   // WindowShouldClose intercetta la pressione del tasto Esc oppure il click sulla X e in questi casi, restituisce True
   while(WindowShouldClose() == false) {
      game.handleInput();
      if (eventTriggered(0.2)) {
         game.moveBlockDown();
      }
      BeginDrawing();
      ClearBackground(darkblue);
      DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
      DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
      if(game.gameOver) {  
         DrawTextEx(font, "Game Over", {320, 450}, 38, 2, WHITE);
      }
      DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
      char scoreText[10];
      sprintf(scoreText, "%d", game.score);
      Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
      DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);
      DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
      game.draw();
      EndDrawing();
   }

   CloseWindow();
}