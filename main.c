#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "includes/renderer.h"
#include "includes/definition.h"
#include "includes/style.h"
#include "includes/logic.h"
#include "includes/input.h"
#include "includes/storage.h"

int main()
{
     hideCursor();
     clock_t lastTime = clock();
     
     state st;
     memset(&st, 0, sizeof(state));
     
     if(!load(&st))
     {
          startGame(&st);
     }

     renderInitScreen(&st);

     while (true)
     {

          clock_t currentTime = clock();
          double deltaTime = (double) (currentTime - lastTime) / CLOCKS_PER_SEC;
          
          handleInput(&st);
          
          if(deltaTime < 0.066) // 60 FPS
          {
               continue;
          }
          
          lastTime = currentTime;
          
          
          if(st.isGameOver)
          {
               displayGameOver(&st);
          }
          else if(st.score >= st.gameArea.height * st.gameArea.width * st.fruit.score)
          {
               renderVictory();
          }
          else
          {
               render(&st, deltaTime);
          }

          renderScore(&st);
          
     }

     save(&st);
     return 0;
}