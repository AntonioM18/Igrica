// main.c
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "game.h"

int main() {
    srand(time(NULL));
    GameData game;

    setup(&game);

    while (1) {
        draw(&game);
        input(&game);
        logic(&game);
        Sleep(game.speed);
    }

    return 0;
}

