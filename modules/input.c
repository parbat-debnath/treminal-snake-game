#include "../includes/definition.h"
#include "../includes/state.h"
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void handleInput(state* st)
{
     if(_kbhit())
     {
          int ch = _getch();

          if(ch == 0 || ch == 224) // arrow keys
          {
               switch (_getch())
               {
               case KEY_UP:
                    
                    if(st->snake.head->dy == BOTTOM) return;
                    
                    st->snake.head->dy = UP;
                    st->snake.head->dx = 0;
                    
                    break;
                    
               case KEY_DOWN:
                    
                    if(st->snake.head->dy == UP) return;
                    
                    st->snake.head->dy = BOTTOM;
                    st->snake.head->dx = 0;
                    
                    break;
                    
               case KEY_LEFT:
               
                    if(st->snake.head->dx == RIGHT) return;
                    
                    st->snake.head->dy = 0;
                    st->snake.head->dx = LEFT;
                    
                    break;
                    
               case KEY_RIGHT:
                    
                    if(st->snake.head->dx == LEFT) return;
               
                    st->snake.head->dy = 0;
                    st->snake.head->dx = RIGHT;
                    
                    break;
               
               default:
                    break;
               }
          }
          else if(toupper(ch) == 'Q')
          {
               // code for exit
               exit(0);
          }
          else if(ch == '\r' || ch == 13) // enter
          {
               // TODO : code for rerstart
          }
          else if(ch == ' ' || ch == 32) // space
          {
               // TODO : code for pause 
          }
     }
}