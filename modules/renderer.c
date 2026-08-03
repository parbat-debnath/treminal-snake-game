#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
     char sym;
     int x, y, dx, dy;
     struct node *next;

     // dx, dy -> directions 
     // dx = +1 for right, dx = -1 for left
     // dy = +1 for bottom, dy = -1 for up
} node;


char demoGrid[10][10];
char buffer[4096];

void gotoxy(int x, int y)
{
     printf("\033[%d;%dH", y, x * 2);
}

// TODO : modify it according to new definitions
void renderGameArea(int height, int width, char *arr, int posx, int posy)
{
     
     char *p = buffer;
     p += sprintf(p, "\033[H");

     if(!arr)
     {          
          for(int i = 0; i < 20; i++)
          {
               for(int j = 0; j < 40; j++)
               {
                    *p++ = '.';
                    *p++ = ' ';
               }

               *p++ = '\n';
          }

          *p = '\0';

          height = 10;
          width = 10;

          arr = &demoGrid[0][0];
     }
     else
     {
          for(int i = 0; i < height; i++)
          {
               for(int j = 0; j < width; j++)
               {
                    *p++ = '.';
                    *p++ = ' ';
               }

               *p++ = '\n';
          }

          *p = '\0';
     }

     gotoxy(posx, posy);

     printf("%s", buffer);

}

void clearScreen()
{
     printf("\033[2J\033[H");
}

void hideCursor()
{
     printf("\033[?25l");
}

void clearSnake(node *head)
{
     if(head == NULL)
     {
          printf("Snake head is gone!");
          return;
     }

     node* tempNode = head;

     while (tempNode != NULL)
     {
          gotoxy(tempNode->x, tempNode->y);
          putchar(' ');

          tempNode = tempNode->next;
     }
     
}

void renderSnake(node *head)
{
     if(head == NULL)
     {
          printf("Snake head is gone!");
          return;
     }

     node* tempNode = head;

     while (tempNode != NULL)
     {
          gotoxy(tempNode->x, tempNode->y);
          putchar(tempNode->sym);

          tempNode = tempNode->next;
     }
}
