#include <filesystem>

#include "conio.h"
#include <thread>
#include <chrono>
#include <iostream>

#include "World.h"


#if __cplusplus < 201703L // If the version of C++ is less than 17
namespace fs = std::experimental::filesystem;
#else
namespace fs = std::filesystem;
#endif

using namespace std;

int main() {
	fs::create_directory("./data");
	
	// Game Loop
	cout << "To quit the game, press on ESC key. \n" << endl;
	cout << "|====| Welcome to the battleground ! |====|" << endl;

	World* world = new World();

	int frames = 0;
	int key;
	bool gameIsRunning = true;
	int currentPlayingTime = 0;
	int waitCount = 0;
	bool isPlayingAction = false;
	Character* ennemy = world->charactersList.at(3);


	while (gameIsRunning) {
		this_thread::sleep_for(chrono::milliseconds(1000 / 120)); // 120 fps

		if (waitCount != 0) {
			if (_kbhit()) {
				key = _getch();
				//cout << "key pressed : " << key << " frame n." << frames << endl;

				switch (key) {
				// case "ESCAPE", to quit the game
				case 27:
					gameIsRunning = false;
					break;

				// UP
				case 122:
					cout << "move up" << endl;
					waitCount = 0;
					break;
				// LEFT
				case 113:
					cout << "move left" << endl;
					waitCount = 0;
					break;
				// DOWN
				case 115:
					cout << "move down" << endl;
					waitCount = 0;
					break;
				// RIGHT
				case 100:
					cout << "move right" << endl;
					waitCount = 0;
					break;

				// case "SPACE"
				case 32:
					cout << "Swaping the caracter..." << endl;
					world->nextCharacter();
					cout << "You currently are playing " << world->currentCharacter->name
						<< " (" << world->currentCharacter->hitPoints << "HP) \n" << endl;					
					waitCount = 0;
					break;

				case 't':
					cout << "Current time :" << currentPlayingTime << endl;
					break;

				// case 'ENTER'
				case 13:
					cout << "|==| Interaction Menu |==|" << endl;
					cout << "HP : " << world->currentCharacter->hitPoints << " | DMG : "
						<< world->currentCharacter->weapon.damageAmmount << endl;
					cout << "Press :" << endl;
					cout << " - 'a' to unleash your ultimate" << endl;
					cout << " - 'e' to do a simple attack" << endl;
					cout << " - 'p' to use a potion \n" << endl;
					isPlayingAction = true;
					break;
				}

				// In case the player has chosen to interact (with 'ENTER') in this turn
				if (isPlayingAction) {
					switch (key) {
					// 'A' then 'a', or 'Q' then 'q' in QWERTY
					case 65:
					case 97:
						world->currentCharacter->pressA(world);
						isPlayingAction = false;
						waitCount = 0;
						break;

					// 'E' then 'e'
					case 69:
					case 101:
						world->currentCharacter->pressE(world);
						isPlayingAction = false;
						waitCount = 0;
						break;

					// 'P' then 'p'
					case 80:
					case 112:
						// TODO : define a baseHP attribute and a method to usePotion in std::Character
						world->currentCharacter->hitPoints = world->currentCharacter->hitPoints + 5;
						cout << "You used a potion. You now have " << world->currentCharacter->hitPoints << "HP" << endl;
						isPlayingAction = false;
						waitCount = 0;
						break;

					}
				}
			}
			while (_kbhit())
				_getch();
			//cout << "frames " << frames << endl;
			frames++;
		}
		else {
			// NEW TURN
			world->gameTurn++;
			waitCount = 15;
			isPlayingAction = false;
			cout << "Turn " << world->gameTurn << ". You now have 15sec to play your turn.\n" << endl;
			// TODO make the ennemy attack
		}

		if (currentPlayingTime != frames / 120) {
			currentPlayingTime = frames / 120;
			waitCount--;
		}

	}

	world->save();

	return 0;
}