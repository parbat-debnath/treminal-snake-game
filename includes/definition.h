#pragma once

typedef struct node {
     int dx, dy;
     char sym;
     int x, y;
     char* color;
     node* next;
} node;

typedef struct {
     int x, y;
     char sym;
     char* color;
     int score;
} fruit;

typedef struct {
     node* head;
} snake;

typedef struct gameArea
{
     int x, y;
     int height, width;
};


#define HEIGHT 40
#define WIDTH 20
#define FPS 60
#define speed 3 // cells per seconds
#define LEFT -1
#define RIGHT 1
#define TOP -1
#define BOTTOM 1