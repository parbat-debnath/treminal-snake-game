#include "../includes/definition.h"
#include "../includes/state.h"
#include "../includes/style.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void setFruitPosition(state* st);
static bool hasNodeAtXY(int x, int y, state* st);
static int countNode(node *head);

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
          st->isGameOver = true;
          if(st->score > st->highScore) st->highScore = st->score;
          st->snake.head->sym = 'x';
          return;
     }
     
     // collision with body
     
     if(head->dx == RIGHT && hasNodeAtXY(head->x + 1, head->y, st)){
          st->isGameOver = true;
          if(st->score > st->highScore) st->highScore = st->score;
          st->snake.head->sym = 'x';
          return;
     }
     if(head->dx == LEFT && hasNodeAtXY(head->x - 1, head->y, st)){
          st->isGameOver = true;
          if(st->score > st->highScore) st->highScore = st->score;
          st->snake.head->sym = 'x';
          return;
     }
     if(head->dy == UP && hasNodeAtXY(head->x, head->y - 1, st)){
          st->isGameOver = true;
          if(st->score > st->highScore) st->highScore = st->score;
          st->snake.head->sym = 'x';
          return;
     }
     if(head->dy == BOTTOM && hasNodeAtXY(head->x, head->y + 1, st)){
          st->isGameOver = true;
          if(st->score > st->highScore) st->highScore = st->score;
          st->snake.head->sym = 'x';
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
     
     if(head->x == st->fruit.x && head->y == st->fruit.y) // score
     {
          st->score += st->fruit.score;
          setFruitPosition(st);

          node* n = malloc(sizeof(node));
          
          n->color = (countNode(st->snake.head) % 2 == 0) ? BG_BLACK : BG_RED;
          n->x = curr_x;
          n->y = curr_y;
          n->real_x = curr_real_x;
          n->real_y = curr_real_y;
          n->sym = '.';
          n->next = head->next;
          head->next = n;

          return;
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

void setFruitPosition(state* st)
{
     if(!st) return;

     int number_of_nodes = countNode(st->snake.head);
     int total_cells = (HEIGHT - 2) * (WIDTH - 2);
     int empty_cells = total_cells - number_of_nodes;

     if(empty_cells <= 0)
     {
          printf("VICTORY");
          return;
     }

     int target_empty_index = (rand() % empty_cells) + 1;
     int empty_counter = 0;

     for(int i = 1; i < HEIGHT - 1; i++)
     {
          for(int j = 1; j < WIDTH - 1; j++)
          {
               if(!hasNodeAtXY(j + BOX_START_X, i + BOX_START_Y, st)) // empty
               {
                    empty_counter++;
               }

               if(target_empty_index == empty_counter) // target found
               {
                    st->fruit.x = j + BOX_START_X;
                    st->fruit.y = i + BOX_START_Y;

                    return;
               }
          }
     }
}

static int countNode(node *head)
{
     int count = 0;
     node* tempNode = head;

     while (tempNode != NULL)
     {
          count++;
          tempNode = tempNode->next;
     }

     return count;
}

static bool hasNodeAtXY(int x, int y, state* st)
{
     node* tempNode = st->snake.head;

     while (tempNode != NULL)
     {
          if(tempNode->x == x 
               && tempNode->y == y)
          {
               return true;
          }

          tempNode = tempNode->next;
     }

     return false;
}