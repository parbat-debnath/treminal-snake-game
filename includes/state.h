#include "definition.h"
#include <stdbool.h>
#pragma once

typedef struct
{
     snake snake;
     int heighScore, score;
     fruit fruit;
     gameArea gameArea;
     bool isGameOver;
     bool isGamePaused;
} state;
