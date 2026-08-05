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
          .color = BG_BLACK,
          .x = BOX_START_X + WIDTH / 2,
          .real_x = BOX_START_X + WIDTH / 2,
          .y = BOX_START_Y + HEIGHT / 2,
          .real_y = BOX_START_Y + HEIGHT / 2,
          .sym = 'o',
          .dx = RIGHT,
          .dy = 0
     };
     
     s.head = &h;

     fruit f = {
          .x = BOX_START_X + 5,
          .y = BOX_START_Y + 5,
          .color = BG_BRIGHT_GREEN,
          .score = 10
     };

     state st = {
          .snake = s,
          .fruit = f
     };

     clearScreen();
     renderGameArea();
     renderFruit(&st);

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
          renderFruit(&st);
          renderSnake(&st);
     }
     
}