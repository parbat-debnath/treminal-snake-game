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
          .real_x = BOX_START_X + WIDTH / 2,
          .y = BOX_START_Y + HEIGHT / 2,
          .real_y = BOX_START_Y + HEIGHT / 2,
          .sym = ' ',
          .dx = RIGHT,
          .dy = 0
     };
     
     node n1 = {
          .color = BG_GREEN,
          .x = BOX_START_X + WIDTH / 2 - 1,
          .real_x = BOX_START_X + WIDTH / 2 - 1,
          .y = BOX_START_Y + HEIGHT / 2,
          .real_y = BOX_START_Y + HEIGHT / 2,
          .sym = ' ',
          .dx = RIGHT,
          .dy = 0
     };

     node n2 = {
          .color = BG_MAGENTA,
          .x = BOX_START_X + WIDTH / 2 - 2,
          .real_x = BOX_START_X + WIDTH / 2 - 2,
          .y = BOX_START_Y + HEIGHT / 2,
          .real_y = BOX_START_Y + HEIGHT / 2,
          .sym = ' ',
          .dx = RIGHT,
          .dy = 0
     };

     node n3 = {
          .color = BG_GREEN,
          .x = BOX_START_X + WIDTH / 2 - 3,
          .real_x = BOX_START_X + WIDTH / 2 - 3,
          .y = BOX_START_Y + HEIGHT / 2,
          .real_y = BOX_START_Y + HEIGHT / 2,
          .sym = ' ',
          .dx = RIGHT,
          .dy = 0
     };
     
     s.head = &h;
     h.next = &n1;
     n1.next = &n2;
     n2.next = &n3;

     
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