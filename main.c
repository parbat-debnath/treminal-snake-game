#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main()
{
  clock_t lastTime = clock();

  while(true)
  {
    clock_t currentTime = clock();
    double deltaTime = (double) (currentTime - lastTime) / CLOCKS_PER_SEC;


    if(deltaTime <= 0.0166) // 60 FPS
      continue;

    printf("deltaTime : %f, FPS : %.1f\n", deltaTime, 1.0 / deltaTime);
    lastTime = currentTime;
  }

  return 0;
}
