### Round-Based Fighting Game Program
This program simulates a round-based fighting game. It could serve as a combat extension to my previous program - an interactive story adventure game.

### Entity Class
Entity is a base class for inheritance structure. It represents every object created in the game. Its child classes are Player, Enemy, and Weapon.

- Player represents the user. There is only one player in the course of the game.
- Weapon represents the weapon which the player can use to defeat enemies.
- Enemy represents the enemy to be defeated by a player using a weapon.

### Factory Design Pattern
The program uses the factory design pattern. The EntityFactory serves as a factory for all classes that inherit from Entity.

### Game Class
The Game class operates the whole gameplay. It stores a pointer to a player, a list of pointers to enemies, and a list of pointers to weapons.

I used shared pointers to be able to get to elements in the weapon or enemies list without having to delete the element from the list. (With a unique pointer, I would have to move the pointer to another variable, which would empty the list).

After creating enemies and weapons using EntityFactory in the main function, the gameplay begins. You must choose an appropriate weapon for each enemy, and then the fighting is simulated. This is repeated until there are no more enemies.