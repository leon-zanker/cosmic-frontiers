#include "../include/cosmic-frontiers.h"

GameState* GameState_generate_new(Scale scale) {
    GameState* game = malloc(sizeof (GameState));

    // TODO: initialize game

    return game;
}

void GameState_destroy(GameState* game) {
    // TODO: uninitialize game
    free(game);
}