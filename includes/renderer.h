#include "definition.h"
#include "state.h"

#pragma once

void renderGameArea();
void hideCursor();
void clearScreen();
void clearGameArea();
void renderSnake(state* st);
void clearSnake(state* st);
void renderFruit(state *st);
void renderScore(state* st);
void displayGameOver(state* st);