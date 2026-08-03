#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "includes/renderer.h"
#include "includes/definition.h"
#include "includes/style.h"

int main()
{
     hideCursor();
     clock_t lastTime = clock();

     snake s;
     node h = {
          .color = BG_BLUE,
          .x = BOX_START_X + WIDTH / 2,
          .y = BOX_START_Y + HEIGHT / 2,
          .sym = ' '
     };

     node n = {
          .color = BG_YELLOW,
          .x = BOX_START_X + WIDTH / 2 - 1,
          .y = BOX_START_Y + HEIGHT / 2,
          .sym = ' '
     };

     h.next = &n;

     s.head = &h;
     
     clearScreen();
     renderGameArea();
     
     while (true)
     {
          clock_t currentTime = clock();
          double deltaTime = (double) (currentTime - lastTime) / CLOCKS_PER_SEC;
          
          if(deltaTime < 0.033) continue; // 60 FPS
          
          renderSnake(s.head);
     }
     
}