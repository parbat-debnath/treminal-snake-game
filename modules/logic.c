#include "../includes/definition.h"
#include "../includes/state.h"
#include <stdio.h>
#include <math.h>

void updateSnake(state *st, double dt)
{
     
     node* tempNode = st->snake.head; // head
     
     // collision
     if(tempNode->x - BOX_START_X >= WIDTH - 2 
          || tempNode->x - BOX_START_X <= 1)
     {
          // code 
          printf("Collision");
          return;
     }
     if(tempNode->y - BOX_START_Y >= HEIGHT - 2
          || tempNode->y - BOX_START_Y <= 1)
     {
          // code 
          printf("Collision");
          return;
     }

     double next_x = tempNode->x;
     double next_y = tempNode->y;

     if(tempNode->dx == RIGHT)
     {
          tempNode->x = tempNode->x + SPEED * dt;
     }
     else if(tempNode->dx == LEFT)
     {
          tempNode->x = tempNode->x - SPEED * dt;
     }
     else if(tempNode->dy == UP)
     {
          tempNode->y = tempNode->y - SPEED * dt;
     }
     else if(tempNode->dy == BOTTOM)
     {
          tempNode->y = tempNode->y + SPEED * dt;
     }

     tempNode = tempNode->next;

     while (tempNode != NULL)
     {    
          double temp_x = tempNode->x;
          double temp_y = tempNode->y;

          if(fabs(temp_x - next_x) >= 1)
          {
               tempNode->x = next_x;
          }
          if (fabs(temp_y - next_y) >= 1)
          {
               tempNode->y = next_y;
          }
          
          
          next_x = temp_x;
          next_y = temp_y;

          tempNode = tempNode->next;
     }
     
}