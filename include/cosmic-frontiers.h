#pragma once

/*

    TODO:

    - flexible ui element structs
    - main menu buttons
    - custom fonts

*/

#include <raylib.h>
#include <stdlib.h>


#define BASE_SCREEN_WIDTH 1920
#define BASE_SCREEN_HEIGHT 1080


typedef struct {
    float x;
    float y;
    float uniform;
} Scale;

Scale get_screen_scale(int screen_width, int screen_height);


typedef struct {
    Vector2 center;
    float radius;
    Color color;
} Circle;


typedef enum {
    MAIN_MENU,  // TODO: implement
    IN_GAME,    // TODO: implement
    PAUSE_MENU, // TODO: implement
} RootSceneState;


typedef struct {
    Circle* stars;
    size_t num_stars;
} Background;

Background* Background_create(Scale scale);
void Background_destroy(Background* background);
void Background_draw(Background* background);


typedef enum {
    MAIN_MENU_SAME,
    MAIN_MENU_NEW_GAME,
    MAIN_MENU_EXIT,
} MainMenuSceneState;


typedef struct {
} MainMenuState;

MainMenuState* MainMenuState_create(Scale scale);
void MainMenuState_destroy(MainMenuState* main_menu);
MainMenuSceneState MainMenuState_update(MainMenuState* main_menu);
void MainMenuState_draw(MainMenuState* main_menu, Background* background);


typedef struct {
} GameState;

GameState* GameState_generate_new(Scale scale);
void GameState_destroy(GameState* game);


typedef struct {
    RootSceneState root_scene;
    Background* background;
    MainMenuState* main_menu;
    GameState* game;

    bool main_menu_is_initialized;
    bool game_is_initialized;
} GlobalState;

GlobalState* GlobalState_create(Scale scale);
void GlobalState_destroy(GlobalState* global_state);