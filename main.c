#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

// 1. Odabir konkretnih primitivnih tipova podataka za rad s cjelobrojnim i realnim konstantama.
#define MAX_TRIES 6
#define MAX_WORD_LENGTH 20

// 3. Primjena typedef sa strukturama i unijama, po potrebi s enum tipovima podataka tamo gdje treba.
typedef struct {
    int gameOver;
    int visina;
    int sirina;
    int x;
    int y;
    int preprekaX;
    int preprekaY;
    int score;
} GameData;

// 5. Primjena ključne riječi static za globalne i lokalne varijable.
static GameData gameData;

// Funkcija za postavljanje početnih podataka igre
void setup() {
    gameData.gameOver = 0;
    gameData.visina = 20;
    gameData.sirina = 30;
    gameData.x = gameData.visina / 2;
    gameData.y = gameData.sirina / 2;
    gameData.preprekaX = 0;
    gameData.preprekaY = rand() % gameData.sirina;
    gameData.score = 0;
}

// Funkcija za crtanje stanja igre
void draw() {
    system("cls");

    for (int i = 0; i < gameData.visina; i++) {
        for (int j = 0; j < gameData.sirina; j++) {
            if (i == gameData.x && j == gameData.y)
                printf("C"); // C označava vozilo
            else if (i == gameData.preprekaX && j == gameData.preprekaY)
                printf("#"); // # označava prepreku
            else
                printf(" ");
        }
        printf("\n");
    }

    printf("Score: %d", gameData.score);
    printf("\n");

    printf("Koristite tipke A i D za skretanje vozila. Pritisnite X za izlaz iz igre.");
}

// Funkcija za unos korisničkog ulaza
void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            gameData.y--; // Skretanje u lijevo
            break;
        case 'd':
            gameData.y++; // Skretanje u desno
            break;
        case 'x':
            gameData.gameOver = 1;
            break;
        }
    }
}

// Funkcija za logiku igre
void logic() {
    if (gameData.preprekaX == gameData.visina - 1) {
        gameData.preprekaX = 0;
        gameData.preprekaY = rand() % gameData.sirina;
        gameData.score++;
    }

    gameData.preprekaX++;

    if (gameData.x == gameData.preprekaX && gameData.y == gameData.preprekaY)
        gameData.gameOver = 1;
}

int main() {
    // Postavljanje seed-a za generiranje nasumičnih brojeva
    srand(time(NULL));

    setup();
    while (!gameData.gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // Brzina igre
    }

    printf("\nGame Over! Your Score: %d\n", gameData.score);
    return 0;
}
