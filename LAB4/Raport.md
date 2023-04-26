This program simulates round based fighting game. It could serve as a combat extension to my previous program - interactive story adventure game.
Entity is a base class for inheritance structure. It represents every object created in game. Its child classes are player, enemy and weapon.
Player represents user, there is only one player in the course of the game.
Weapon represents weapon which player can use to defeat enemies.
Enemy represents enemy to be defeated by a player using a weapon.
Program uses factory design pattern. Class entityfactory serves as a factory for all classes that inherit from entity. 
Class game operates the whole gameplay. It stores pointer to a player, list of pointers to enemies and list of pointers to weapons.
I used shared pointers to be able to get to elements in weapon or enemies list without having to delete the element from the list. (With unique pointer I would have to move pointer to another which would empty the list).
After creating enemies and weapons using entityfactory in main the gameplay begins. You must choose appropriate weapon for each enemy, then fighting is simulated. This is reapeated until there are no more enemies.