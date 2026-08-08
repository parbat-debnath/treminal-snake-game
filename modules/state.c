#include "../includes/definition.h"
#include "../includes/state.h"
#include "../includes/logic.h"
#include "../includes/style.h"
#include "../includes/storage.h"
#include "../includes/renderer.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void startGame(state* st)
{
     srand(time(NULL));
     
     st->gameArea.height = HEIGHT;
     st->gameArea.width = WIDTH;
     st->gameArea.x = BOX_START_X;
     st->gameArea.y = BOX_START_Y;
     st->isGameOver = false;
     st->isGamePaused = false;

     st->score = 0;

     if(st->snake.head == NULL)
     {
          st->snake.head = malloc(sizeof(*(st->snake.head)));
          if(st->snake.head == NULL)
          {
               exit(1);
          }
     }

     st->snake.head->x = BOX_START_X + WIDTH / 2 - 3;
     st->snake.head->y = BOX_START_Y + HEIGHT / 2;
     st->snake.head->real_x = st->snake.head->x;
     st->snake.head->real_y = st->snake.head->y;
     st->snake.head->dx = RIGHT;
     st->snake.head->dy = 0;
     strcpy(st->snake.head->color, BG_BLACK);
     st->snake.head->sym = 'o';
     st->snake.head->next = NULL;

     st->fruit.score = 1;
     st->fruit.sym = ' ';
     strcpy(st->fruit.color, BG_BRIGHT_GREEN);
     setFruitPosition(st);
}

void restartGame(state* st)
{
     st->isGameOver = false;
     st->isGamePaused = false;

     st->score = 0;

     if(st->snake.head == NULL)
     {
          st->snake.head = malloc(sizeof(*(st->snake.head)));
          if(st->snake.head == NULL)
          {
               exit(1);
          }
     }

     st->snake.head->x = BOX_START_X + WIDTH / 2 - 3;
     st->snake.head->y = BOX_START_Y + HEIGHT / 2;
     st->snake.head->real_x = st->snake.head->x;
     st->snake.head->real_y = st->snake.head->y;
     st->snake.head->dx = RIGHT;
     st->snake.head->dy = 0;
     strcpy(st->snake.head->color, BG_BLACK);
     st->snake.head->sym = 'o';
     st->snake.head->next = NULL;

     st->fruit.score = 1;
     st->fruit.sym = ' ';
     strcpy(st->fruit.color, BG_BRIGHT_GREEN);
     setFruitPosition(st);
     clearGameArea();
}