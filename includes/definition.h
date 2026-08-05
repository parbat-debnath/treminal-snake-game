#pragma once

typedef struct node {
     int dx, dy;
     char sym;
     double real_x, real_y;
     int x, y;
     char* color;
     struct node* next;
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

typedef struct 
{
     int x, y;
     int height, width;
} gameArea;

#define BOX_START_X 23
#define BOX_START_Y 5
#define HEIGHT 30
#define WIDTH 30
#define FPS 60
#define SPEED 7 // cells per seconds

#define LEFT -1
#define RIGHT 1
#define UP -1
#define BOTTOM 1

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77