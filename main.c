#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "modules/renderer.h"

int main()
{
     hideCursor();
     clock_t lastTime = clock();
     
     renderGrid(5, 4, NULL, 0, 0);
     
     while (true)
     {
          clock_t currentTime = clock();
          double deltaTime = (double) (currentTime - lastTime) / CLOCKS_PER_SEC;
          
          if(deltaTime < 0.033) continue; // 60 FPS
          clearScreen();

     }
     
}