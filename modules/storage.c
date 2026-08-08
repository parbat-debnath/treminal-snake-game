#include "../includes/state.h"
#include "../includes/logic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* filepath = "data/game_data.bin";

bool save(state* st)
{     
     FILE* f = fopen(filepath, "wb");
     if(!f){
          perror("Couldn't open file");
          return false;
     }
     
     fwrite(&st->highScore, sizeof(int), 1, f);
     fwrite(&st->score, sizeof(int), 1, f);
     fwrite(&st->fruit, sizeof(fruit), 1, f);
     fwrite(&st->gameArea, sizeof(gameArea), 1, f);
     fwrite(&st->isGameOver, sizeof(bool), 1, f);
     fwrite(&st->isGamePaused, sizeof(bool), 1, f);
     
     int length = countNode(st->snake.head);
     
     fwrite(&length, sizeof(int), 1, f);
     
     node* tempNode = st->snake.head;
     
     while (tempNode != NULL)
     {
          fwrite(&tempNode->dx, sizeof(int), 1, f);
          fwrite(&tempNode->dy, sizeof(int), 1, f);
          fwrite(&tempNode->x, sizeof(int), 1, f);
          fwrite(&tempNode->y, sizeof(int), 1, f);
          fwrite(&tempNode->real_x, sizeof(double), 1, f);
          fwrite(&tempNode->real_y, sizeof(double), 1, f);
          fwrite(&tempNode->sym, sizeof(char), 1, f);
          fwrite(&tempNode->color[0], sizeof(char), 32, f);
          
          tempNode = tempNode->next;
     }
     
     fclose(f);
     
     return true;
}

bool load(state* st)
{
     FILE* f = fopen(filepath, "rb");
     if(!f)
     {
          perror("Couldn't open file");
          return false;
     }

     fread(&st->highScore, sizeof(int), 1, f);
     fread(&st->score, sizeof(int), 1, f);
     fread(&st->fruit, sizeof(fruit), 1, f);
     fread(&st->gameArea, sizeof(gameArea), 1, f);
     fread(&st->isGameOver, sizeof(bool), 1, f);
     fread(&st->isGamePaused, sizeof(bool), 1, f);

     int length = 0;
     
     if(!fread(&length, sizeof(int), 1, f))
     {
          fclose(f);
          return false;
     }

     st->snake.head = NULL;
     node* tail = NULL;

     for(int i = 0; i < length; i++)
     {
          node *newNode = (node*) malloc(sizeof(node));

          fread(&newNode->dx, sizeof(int), 1, f);
          fread(&newNode->dy, sizeof(int), 1, f);
          fread(&newNode->x, sizeof(int), 1, f);
          fread(&newNode->y, sizeof(int), 1, f);
          fread(&newNode->real_x, sizeof(double), 1, f);
          fread(&newNode->real_y, sizeof(double), 1, f);
          fread(&newNode->sym, sizeof(char), 1, f);
          fread(&newNode->color[0], sizeof(char), 32, f);

          if(st->snake.head == NULL)
          {
               st->snake.head = newNode;
               tail = newNode;
          }
          else
          {
               tail->next = newNode;
               tail = tail->next;
          }
          
          tail->next = NULL;
     }
     
     fclose(f);
     return true;
}