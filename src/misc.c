#include "../include/cosmic-frontiers.h"
#include <raylib.h>

Scale get_screen_scale(int screen_width, int screen_height) {
    const float x = (float)screen_width / (float)BASE_SCREEN_WIDTH;
    const float y = (float)screen_height / (float)BASE_SCREEN_HEIGHT;
    const float uniform = (x < y) ? x : y;

    return (Scale){
        .x = x,
        .y = y,
        .uniform = uniform,
    };
}

Background* Background_create(Scale scale) {
    const int num_stars = 200;
    const float star_radius = 1;

    Circle* stars = malloc(sizeof (Circle) * num_stars);
    
    for (int i = 0; i < num_stars; i++) {
        stars[i] = (Circle){
            .center = (Vector2){ GetRandomValue(0, BASE_SCREEN_WIDTH * scale.x), GetRandomValue(0, BASE_SCREEN_HEIGHT * scale.y) },
            .radius = star_radius * scale.uniform,
            .color = WHITE,
        };
    }

    Background* bg = malloc(sizeof (Background));
    bg->stars = stars;
    bg->num_stars = num_stars;

    return bg;
}

void Background_destroy(Background* background) {
    free(background->stars);
    free(background);
}

void Background_draw(Background* background) {
    ClearBackground(BLACK);
    for (int i = 0; i < background->num_stars; i++) {
        DrawCircle(background->stars[i].center.x, background->stars[i].center.y, background->stars[i].radius, background->stars[i].color);
    }
}

GlobalState* GlobalState_create(Scale scale) {
    GlobalState* gs = malloc(sizeof (GlobalState));

    gs->root_scene = MAIN_MENU;
    gs->background = Background_create(scale);
    gs->main_menu = MainMenuState_create(scale);
    gs->game = NULL;

    gs->main_menu_is_initialized = true;
    gs->game_is_initialized = false;

    return gs;
}

void GlobalState_destroy(GlobalState* global_state) {
    Background_destroy(global_state->background);
    if (global_state->main_menu_is_initialized) MainMenuState_destroy(global_state->main_menu);
    if (global_state->game_is_initialized) GameState_destroy(global_state->game);

    free(global_state);
}