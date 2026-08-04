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
                    
                    st->snake.head->dy = UP;
                    st->snake.head->dx = 0;
                    
                    break;

               case KEY_DOWN:
                    
                    st->snake.head->dy = BOTTOM;
                    st->snake.head->dx = 0;
                    
                    break;

               case KEY_LEFT:
                    
                    st->snake.head->dy = 0;
                    st->snake.head->dx = LEFT;
                    
                    break;
                    
               case KEY_RIGHT:
                    
                    st->snake.head->dy = 0;
                    st->snake.head->dx = RIGHT;
                    
                    break;
               
               default:
                    break;
               }
          }
     }
}