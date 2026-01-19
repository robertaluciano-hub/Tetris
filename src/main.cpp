#include <raylib.h>
#include "grid.h"
#include "game.h"

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
   InitWindow(300, 600, "Tetris");  
   SetTargetFPS(60);
   Game game = Game();

   // WindowShouldClose intercetta la pressione del tasto Esc oppure il click sulla X e in questi casi, restituisce True
   while(WindowShouldClose() == false) {
      game.handleInput();
      if (eventTriggered(1)) {
         game.moveBlockDown();
      }
      BeginDrawing();
      ClearBackground(darkblue);
      game.draw();
      EndDrawing();
   }

   CloseWindow();
}