#include "../include/cosmic-frontiers.h"
#include <stdlib.h>
#include <raylib.h>

int main(void) {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(0, 0, "Cosmic Frontiers");

    const int screen_width = GetScreenWidth();
    const int screen_height = GetScreenHeight();
    const Scale screen_scale = get_screen_scale(screen_width, screen_height);

    // gamestate is not initialized here to maximize memory efficiency
    GlobalState* global_state = GlobalState_create(screen_scale);

    SetTargetFPS(60);  

    while (!WindowShouldClose()) {

        switch (global_state->root_scene) {
            case MAIN_MENU:
            {
                MainMenuSceneState next_scene = MainMenuState_update(global_state->main_menu);
                switch (next_scene) {
                    case MAIN_MENU_NEW_GAME:
                    {
                        MainMenuState_destroy(global_state->main_menu);

                        if (!global_state->game_is_initialized) {
                            global_state->game = GameState_generate_new(screen_scale);
                            global_state->game_is_initialized = true;
                        }

                        global_state->root_scene = IN_GAME;
                    } break;
                    case MAIN_MENU_EXIT:
                    {
                        GlobalState_destroy(global_state);
                        CloseWindow();
                        return EXIT_SUCCESS;
                    } break;
                    default: {} break;
                };
            } break;
            case IN_GAME:
            {
                // TODO
            } break;
            case PAUSE_MENU:
            {
                // TODO
            } break;
        }

        BeginDrawing();
            switch (global_state->root_scene) {
                case MAIN_MENU:
                {
                    MainMenuState_draw(global_state->main_menu, global_state->background);
                } break;
                case IN_GAME:
                {
                    // TODO
                } break;
                case PAUSE_MENU:
                {
                    // TODO
                } break;
            }
        EndDrawing();
    }

    GlobalState_destroy(global_state);
    CloseWindow();
    return EXIT_SUCCESS;
}
