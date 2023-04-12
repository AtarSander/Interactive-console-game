1. Created config_chapters method in Game class, which loads chapter names from config file and sets up game object for playing. It enables easy and fast development of new chapters.
2. Created save_game method, which saves current chapter, player's health, name and time played to save file for future continuation using load_game method.
3. Created main menu chapter with new game, load game and quit options.
4. Created player's death (game over) handling.
5. Created playtime clock, which is shown after the game is over.
6. Implemented item class which represent items that can be found and used during the game. Each item has a name, type and a number of uses after which it disappears from player's inventory.
7. Implemented items usage into player class with algorithm library functions.
8. Implemented ingame scenarios in game class where player's inventory is searched for needed type item. If player has said type's item new outcome is enabled.
9. Corrected catching errors in game.cpp to catch specific error instead of std::exception.
10. Added tests for new functionalities.
11. Moved seeds to separate directory for cleanliness.
12. Other minor improvements.