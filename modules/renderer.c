#include <stdio.h>
#include <stdlib.h>
#include "../includes/definition.h"
#include "../includes/style.h"
#include "../includes/state.h"

char demoGrid[10][10];
char buffer[4096];

void gotoxy(int x, int y)
{
     printf("\033[%d;%dH", y, x * 2);
}

gameArea g;

void initGameArea(gameArea* g)
{
     g->height = HEIGHT;
     g->width = WIDTH;
     g->x = BOX_START_X;
     g->y = BOX_START_Y;
}

void renderGameArea()
{
     initGameArea(&g);

     for (int i = 0; i < g.height; i++)
     {
          for (int j = 0; j < g.width; j++)
          {
               gotoxy(g.x + j, g.y + i);
               if(i == 0 || j == 0 || i == HEIGHT - 1 || j == WIDTH - 1)
               {
                    printf(BG_RED);
                    printf("  ");
                    printf(STYLE_RESET);
               }
               else
               {
                    printf(" ");
               }
          }

          printf("\n");
     }
}

void clearScreen()
{
     printf("\033[2J\033[H");
}

void clearGameArea() // dumped idea (not using)
{
     for (int i = 1; i < g.height - 1; i++)
     {
          for (int j = 1; j < g.width - 1; j++)
          {
               gotoxy(g.x + j, g.y + i);
               printf(" ");
          }
          
     }
     
}

void hideCursor()
{
     printf("\033[?25l");
}

void clearSnake(state *st)
{
     node* tempNode = st->snake.head;
     
     if(tempNode == NULL)
     {
          printf("Snake head is gone!");
          return;
     }

     while (tempNode != NULL)
     {
          gotoxy((int) tempNode->x, (int) tempNode->y);
          printf(STYLE_RESET);
          putchar(' ');
          putchar(' ');
          
          tempNode = tempNode->next;
     }
     
     fflush(stdout);
}

void renderSnake(state *st)
{

     node* tempNode = st->snake.head;
     if(tempNode == NULL)
     {
          printf("Snake head is gone!");
          return;
     }


     while (tempNode != NULL)
     {
          gotoxy((int) tempNode->x, (int) tempNode->y);
          printf(tempNode->color);
          putchar(tempNode->sym);
          putchar(' ');
          printf(STYLE_RESET);

          tempNode = tempNode->next;
     }
}
