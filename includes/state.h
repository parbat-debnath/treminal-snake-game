#include "definition.h"
#include <stdbool.h>
#pragma once

typedef struct
{
     snake snake;
     int highScore, score;
     fruit fruit;
     gameArea gameArea;
     bool isGameOver;
     bool isGamePaused;
} state;

void startGame(state* st);
void restartGame(state* st);
