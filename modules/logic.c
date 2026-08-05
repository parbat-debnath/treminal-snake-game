#include "../includes/definition.h"
#include "../includes/state.h"
#include <stdio.h>
#include <math.h>

void updateSnake(state *st, double dt)
{
     node* head = st->snake.head;

     double curr_real_x = head->real_x;
     double curr_real_y = head->real_y;
     int curr_x = head->x;
     int curr_y = head->y;

     // colliison detection

     if((curr_x >= BOX_START_X + WIDTH - 2 && head->dx == RIGHT) || (curr_x <= BOX_START_X + 1 && head->dx == LEFT)
          || (curr_y >= BOX_START_Y + HEIGHT - 2 && head->dy == BOTTOM) || (curr_y <= BOX_START_Y + 1 && head->dy == UP))
     {
          // code

          return;
     }

     // code for head
     
     if(head->dx == LEFT)
     {
          head->real_x -= SPEED * dt;
          
          if(fabs((int) head->real_x - head->x) >= 1)
          {
               head->x = (int) head->real_x;
          }
     }
     if(head->dx == RIGHT)
     {
          head->real_x += SPEED * dt;
          
          if(fabs((int) head->real_x - head->x) >= 1)
          {
               head->x = (int) head->real_x;
          }
     }
     if(head->dy == UP)
     {
          head->real_y -= SPEED * dt;
          
          if(fabs((int) head->real_y - head->y) >= 1)
          {
               head->y = (int) head->real_y;
          }
     }
     if(head->dy == BOTTOM)
     {
          head->real_y += SPEED * dt;
          
          if(fabs((int) head->real_y - head->y) >= 1)
          {
               head->y = (int) head->real_y;
          }
     }
     
     
     if(curr_x != head->x || curr_y != head->y)
     {
          node* tempNode = head->next;
          
          while (tempNode != NULL)
          {
               double temp_real_x = tempNode->real_x;
               double temp_real_y = tempNode->real_y;
               int temp_x = tempNode->x;
               int temp_y = tempNode->y;
     
               tempNode->real_x = curr_real_x;
               tempNode->real_y = curr_real_y;
               
               tempNode->x = curr_x;
               tempNode->y = curr_y;
               
               curr_real_x = temp_real_x;
               curr_real_y = temp_real_y;
               curr_x = temp_x;
               curr_y = temp_y;
     
               tempNode = tempNode->next;
          }
     }
     
}