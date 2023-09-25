// game.h
#ifndef GAME_H
#define GAME_H

#define MAX_OBSTACLES 5
#define INITIAL_SPEED 100
#define SPEED_INCREASE_INTERVAL 10

typedef struct {
    int x;
    int y;
} Obstacle;

typedef struct {
    int visina;
    int sirina;
    int x;
    int y;
    int score;
    int speed;
    int prepreke;
    int brojPrepreka;  // Novi član za praćenje broja prepreka
    Obstacle obstacles[MAX_OBSTACLES];
} GameData;

void setup(GameData* game);
void draw(const GameData* game);
void input(GameData* game);
void logic(GameData* game);

#endif // GAME_H




