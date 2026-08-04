#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "includes/renderer.h"
#include "includes/definition.h"
#include "includes/style.h"
#include "includes/logic.h"
#include "includes/input.h"

int main()
{
     hideCursor();
     clock_t lastTime = clock();

     
     snake s;
     node h = {
          .color = BG_BLUE,
          .x = BOX_START_X + WIDTH / 2,
          .y = BOX_START_Y + HEIGHT / 2,
          .sym = ' ',
          .dx = RIGHT,
          .dy = 0
     };
     
     node n = {
          .color = BG_YELLOW,
          .x = BOX_START_X + WIDTH / 2 - 1,
          .y = BOX_START_Y + HEIGHT / 2,
          .sym = ' ',
          .dx = RIGHT,
          .dy = 0
     };
     
     h.next = &n;
     
     s.head = &h;
     
     state st = {
          .snake = s
     };

     clearScreen();
     renderGameArea();
     
     while (true)
     {
          clock_t currentTime = clock();
          double deltaTime = (double) (currentTime - lastTime) / CLOCKS_PER_SEC;
          
          handleInput(&st);
          
          if(deltaTime < 0.033) // 60 FPS
          {
               continue;
          }
          
          lastTime = currentTime;
          
          clearSnake(&st);
          updateSnake(&st, deltaTime);
          renderSnake(&st);
     }
     
}