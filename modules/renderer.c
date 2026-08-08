#include <stdio.h>
#include <stdlib.h>
#include "../includes/definition.h"
#include "../includes/style.h"
#include "../includes/logic.h"
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
                    printf(BG_BRIGHT_WHITE);
                    printf("  ");
                    printf(STYLE_RESET);
               }
               else
               {
                    printf(BG_RGB(33, 33, 33));
                    printf("  ");
                    printf(STYLE_RESET);
               }
          }

          printf("\n");
     }
}

void clearScreen()
{
     printf("\033[2J\033[H");
}

void clearGameArea()
{
     printf(BG_RGB(33, 33, 33));
     for (int i = 1; i < g.height - 1; i++)
     {
          for (int j = 1; j < g.width - 1; j++)
          {
               gotoxy(g.x + j, g.y + i);
               printf("  ");
          }
          
     }
     printf(STYLE_RESET);
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
          printf(BG_RGB(33, 33, 33));
          putchar(' ');
          putchar(' ');
          printf(STYLE_RESET);
          
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

void renderFruit(state *st)
{
     gotoxy(st->fruit.x, st->fruit.y);
     printf(st->fruit.color);
     printf(FG_GREEN);
     putchar('|');
     printf(FG_WHITE);
     printf(BG_GREEN);
     putchar('|');
     printf(STYLE_RESET);
}

void renderScore(state* st)
{
     gotoxy(BOX_START_X + WIDTH + 10, BOX_START_Y);
     printf("SCORE%12d", st->score);
     gotoxy(BOX_START_X + WIDTH + 10, BOX_START_Y + 2);
     if(st->highScore <= st->score)
     {
          printf(BG_YELLOW);
          printf(FG_BLACK);
          printf("   [HIGH SCORE]  ");
          printf(STYLE_RESET);
     }
     else{
          printf("HIGH SCORE%7d", st->highScore);
     }
}

void displayGameOver(state* st)
{
     char* screen[] = {
          " o--------------------------------o ",
          " |                                | ",
          " |           ",
          " |                                | ",
          " |                                | ",
          " |                                | ",
          " o--------------------------------o "
     };

     printf(BG_BRIGHT_BLACK);
     // BG_RGB(33, 33, 33)
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 - 5);
     printf("%s", screen[0]);
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 - 4);
     printf("%s", screen[1]);
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 - 3);
     printf("%s", screen[2]);
     printf(BG_BLACK);
     printf(FG_RED);
     printf(" GAME OVER ");
     printf(STYLE_RESET);
     printf(BG_BRIGHT_BLACK);
     printf("          | ");
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 - 2);
     printf("%s", screen[3]);
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 - 1);
     printf(" |      SCORE         %5d       | ", st->score);
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2);
     printf(" |      HIGH SCORE    %5d       | ", st->highScore);
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 + 1);
     printf("%s", screen[4]);
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 + 2);
     printf(" |   QUIT [%sQ%s%s]     RESTART [%sENTER%s%s] | ", FG_BRIGHT_YELLOW, STYLE_RESET, BG_BRIGHT_BLACK, FG_BRIGHT_YELLOW, STYLE_RESET, BG_BRIGHT_BLACK);
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 + 3);
     printf("%s", screen[5]);
     gotoxy(BOX_START_X + WIDTH / 2 - 9, BOX_START_Y + HEIGHT / 2 + 4);
     printf("%s", screen[6]);

     printf(STYLE_RESET);
}

void renderBanner()
{
     int startX = 5, startY = 5;
     
     printf(BG_RGB(33, 33, 33));
     
     gotoxy(startX, startY);
     printf("                          ");
     startY++;
     gotoxy(startX, startY);
     printf(FG_BRIGHT_WHITE);
     printf("                          ");
     startY++;
     gotoxy(startX, startY);
     printf("                          ");
     startY++;
     gotoxy(startX, startY);
     printf("      %s   %s   %s   %s   %s   %s     ", BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_RGB(33, 33, 33));
     startY++;
     gotoxy(startX, startY);
     printf("      %s S %s n %s A %s k %s E %s     ", BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_RGB(33, 33, 33));
     startY++;
     gotoxy(startX, startY);
     printf("      %s   %s   %s   %s   %s   %s     ", BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_RGB(33, 33, 33));
     startY++;
     gotoxy(startX, startY);
     printf("                          ");
     startY++;
     gotoxy(startX, startY);
     printf("     by Parbat Debnath    ");
     startY++;
     gotoxy(startX, startY);
     printf("                          ");
     startY++;
     gotoxy(startX, startY);
     printf("                          ");
     startY++;

     printf(STYLE_RESET);
}

void renderVictory()
{
     int startX = BOX_START_X + WIDTH / 2 - 9, startY = BOX_START_Y + HEIGHT / 2 - 5;
     
     printf(BG_RGB(33, 33, 33));
     
     gotoxy(startX, startY);
     printf("                                 ");
     startY++;
     gotoxy(startX, startY);
     printf(FG_BRIGHT_WHITE);
     printf("                                 ");
     startY++;
     gotoxy(startX, startY);
     printf("                                 ");
     startY++;
     gotoxy(startX, startY);
     printf("        %s   %s   %s   %s   %s   %s   %s   %s        ", BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_RGB(33, 33, 33));
     startY++;
     gotoxy(startX, startY);
     printf("        %s V %s I %s C %s T %s O %s R %s Y %s        ", BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_RGB(33, 33, 33));
     startY++;
     gotoxy(startX, startY);
     printf("        %s   %s   %s   %s   %s   %s   %s   %s        ", BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_BLACK, BG_RED, BG_RGB(33, 33, 33));
     startY++;
     gotoxy(startX, startY);
     printf("                                 ");
     startY++;
     gotoxy(startX, startY);
     printf("    Played well, or it's a %s%sg&s%s1%si%sT%sch?   ", BG_BRIGHT_RED, FG_BLACK, FG_BRIGHT_WHITE ,BG_GREEN, BG_RGB(33, 33, 33), BG_BLUE, BG_RGB(33, 33, 33));
     startY++;
     gotoxy(startX, startY);
     printf("                                 ");
     startY++;
     gotoxy(startX, startY);
     printf("                                 ");
     startY++;

     printf(STYLE_RESET);
}

void renderInitScreen(state* st)
{
     clearScreen();
     renderGameArea();
     renderBanner();
     renderFruit(st);
}

void render(state* st, double deltaTime)
{
     clearSnake(st);
     updateSnake(st, deltaTime);
     renderFruit(st);
     renderSnake(st);
}