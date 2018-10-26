#include <filesystem>

#include "conio.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "World.h"


#if __cplusplus < 201703L // If the version of C++ is less than 17
namespace fs = std::experimental::filesystem;
#else
namespace fs = std::filesystem;
#endif

using namespace std;

int main() {
	fs::create_directory("./data");
	
	cout << "To quit the game, press on ESC key. \n" << endl;
	cout << "|====| Welcome to the battleground ! |====|" << endl;

	// SFML components
	sf::RenderWindow window(sf::VideoMode(1600, 1000), "C++ Project");

	sf::Font* font = new sf::Font();
	font->loadFromFile("./data/ressources/fonts/Roboto-Regular.ttf");

	// SFML Textures
	sf::Texture* grassTexture = new sf::Texture();
	if (!grassTexture->loadFromFile("data/ressources/textures/grass.jpg")) {
		cout << "Load failed for grass.jpg " << endl;
		system("pause");
	}

	sf::Texture* characterTexture = new sf::Texture();
	if (!characterTexture->loadFromFile("data/ressources/textures/archer.png")) {
		cout << "Load failed for grass.jpg " << endl;
		system("pause");
	}

	sf::Texture* weaponTexture;

	// SFML Sprites
	sf::Sprite* grassSprite = new sf::Sprite(*grassTexture);
	sf::Sprite* characterSprite = new sf::Sprite(*characterTexture);

	// 100px x 100px texture rescaling
	sf::Vector2f targetSize(100.0f, 100.0f);

	grassSprite->setScale(
		targetSize.x / grassSprite->getLocalBounds().width,
		targetSize.y / grassSprite->getLocalBounds().height
	);

	characterSprite->setScale(0.1f, 0.1f);

	// Vectors used for moving textures sprites
	sf::Vector2f* upMoveVector2f = new sf::Vector2f(0, -100);
	sf::Vector2f* leftMoveVector2f = new sf::Vector2f(-100, 0);
	sf::Vector2f* downMoveVector2f = new sf::Vector2f(0, 100);
	sf::Vector2f* rightMoveVector2f = new sf::Vector2f(100, 0);

	World* world = new World();

	int frames = 0;
	int key;
	bool gameIsRunning = true;
	int currentPlayingTime = 0;
	int waitCount = 0;
	bool isPlayingAction = false;
	Character* ennemy = world->charactersList.at(3);


	while (gameIsRunning && window.isOpen()) {
		this_thread::sleep_for(chrono::milliseconds(1000 / 120)); // 120 fps

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();


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
					characterSprite->move(*upMoveVector2f);
					waitCount = 0;
					break;
				// LEFT
				case 113:
					cout << "move left" << endl;
					characterSprite->move(*leftMoveVector2f);
					waitCount = 0;
					break;
				// DOWN
				case 115:
					cout << "move down" << endl;
					characterSprite->move(*downMoveVector2f);
					waitCount = 0;
					break;
				// RIGHT
				case 100:
					cout << "move right" << endl;
					characterSprite->move(*rightMoveVector2f);
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
						<< world->currentCharacter->weapon->damageAmmount << endl;
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

		window.clear();

		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				grassSprite->setPosition(i*100.0f, j*100.0f);
				window.draw(*grassSprite);
			}
		}

		sf::Text* turn = new sf::Text("Turn : " + to_string(world->gameTurn), *font, 20);
		turn->setPosition(1400.0f, 15.0f);
		window.draw(*turn);

		sf::Text* time = new sf::Text("Time : " + to_string(currentPlayingTime), *font, 20);
		time->setPosition(1500.0f, 15.0f);
		window.draw(*time);

		window.draw(*characterSprite);

		window.display();

		if (currentPlayingTime != frames / 120) {
			currentPlayingTime = frames / 120;
			waitCount--;
		}

	}

	world->saveState();

	return 0;
}