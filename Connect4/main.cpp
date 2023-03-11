#include "gameplay.cpp"
#include <array>
#include <iostream>
using namespace std;

int main() {
    const int rows = 6;
    const int cols = 7;
    int slots[cols];
    char** Arr = new char*;
    char player = 'a';
    int gameRoll = 0;

    Display display;
    do {
        Gameplay* game = new Gameplay(rows, cols);
        display.clrScr();
        Arr = game->InitializeTable(Arr);
        game->InitializeSlots(slots);
        display.welcomeScreen();
        while (!game->gameOver(player)) {
            gameRoll++;
            player = gameRoll % 2 ? 'R' : 'B';
            display.clrScr();
            display.viewTable(Arr, rows, cols);
            display.getInput(player, slots, cols);
            game->getSlot(Arr, player, slots);
        }
        delete game;
        display.viewTable(Arr, rows, cols);
    } while (display.replayScreen() != 'x');
    display.clrScr();
    cout<<display.endScreen();
}
