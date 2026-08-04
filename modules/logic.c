#include "../includes/definition.h"
#include "../includes/state.h"
#include <stdio.h>

void updateSnake(state *st, double dt)
{

     node* tempNode = st->snake.head;

     if(tempNode->x - BOX_START_X >= WIDTH - 2 
          || tempNode->x - BOX_START_X <= 1)
     {
          // code for collision
          printf("Collision");
          return;
     }
     if(tempNode->y - BOX_START_Y >= HEIGHT - 2
          || tempNode->y - BOX_START_Y <= 1)
     {
          // code for collision
          printf("Collision");
          return;
     }

     while (tempNode != NULL)
     {
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

          int dx = tempNode->dx; // temporary variables
          int dy = tempNode->dy;
          tempNode = tempNode->next;

          if(tempNode)
          {
               tempNode->dx = dx;
               tempNode->dy = dy;
          }
     }
     
}