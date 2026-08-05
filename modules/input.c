#include "../includes/definition.h"
#include "../includes/state.h"
#include <conio.h>

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
     }
}