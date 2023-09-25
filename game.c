// game.c
#include "game.h"

void logic(GameData* game) {
    for (int i = 0; i < game->prepreke; i++) {
        if (game->obstacles[i].y == 0) {
            game->obstacles[i].y = game->visina - 1;
            game->obstacles[i].x = rand() % game->visina;
            (game->score)++;
        }
        else {
            game->obstacles[i].y--;
        }
    }

    if (game->score % SPEED_INCREASE_INTERVAL == 0 && game->prepreke < MAX_OBSTACLES) {
        (game->prepreke)++;
        (game->speed) -= 10;
    }

    // Provjera da li se score povećao za 5 i povećanje broja prepreka
    if (game->score % 5 == 0 && game->score > 0 && game->score / 5 > game->brojPrepreka) {
        game->brojPrepreka++;
    }
}

