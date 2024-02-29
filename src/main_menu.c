#include "../include/cosmic-frontiers.h"

MainMenuState* MainMenuState_create(Scale scale) {
    MainMenuState* main_menu = malloc(sizeof (MainMenuState));

    // TODO: initialize main menu

    return main_menu;
}

void MainMenuState_destroy(MainMenuState* main_menu) {
    // TODO: uninitialize main menu

    free(main_menu);
}

MainMenuSceneState MainMenuState_update(MainMenuState* main_menu) {
    // detect mouse hovers, clicks etc.

    return MAIN_MENU_SAME;
}

void MainMenuState_draw(MainMenuState* main_menu, Background* background) {
    Background_draw(background);

    // TODO: draw menu items
}