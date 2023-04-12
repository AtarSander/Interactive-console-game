1. Created config_chapters method in Game class, which loads chapter names from config file and sets up game object for playing. It enables easy and fast development of new chapters.
2. Created main menu chapter with new game, load game and quit options.
3. Created save_game method, which saves current chapter, player's health, name and time played to save file for future continuation using load_game method.
4. Created player's death (game over) handling.
5. Created playtime clock, which is shown after the game is over.
6. Implemented item class which represent items that can be found and used during the game.
7. Implemented items usage into player class with algorithm library functions.
8. Corrected catching in game.cpp to catch specific error instead of std::exception.