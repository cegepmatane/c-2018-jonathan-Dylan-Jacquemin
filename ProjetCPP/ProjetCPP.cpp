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

	World* world = new World();

	// SFML components
	sf::RenderWindow window(sf::VideoMode(1600, 900), "C++ Project");
	
	sf::Font* font = new sf::Font();
	font->loadFromFile("./data/ressources/fonts/Roboto-Regular.ttf");

	// SFML Textures
	sf::Texture* grassTexture = new sf::Texture();
	if (!grassTexture->loadFromFile("data/ressources/textures/grass.jpg")) {
		cout << "Load failed for grass.jpg" << endl;
		system("pause");
	}
	sf::Texture* characterTexture = new sf::Texture();
	if (!characterTexture->loadFromFile("data/ressources/textures/" + world->currentCharacter->getPath())) {
		cout << "Load failed for character texture" << endl;
		system("pause");
	}
	sf::Texture* weaponTexture = new sf::Texture();
	if (!weaponTexture->loadFromFile("data/ressources/textures/" + world->currentCharacter->weapon->getPath())) {
		cout << "Load failed for the weapon texture" << endl;
		system("pause");
	}
	sf::Texture* banditTexture = new sf::Texture();
	if (!banditTexture->loadFromFile("data/ressources/textures/bandit.png")) {
		cout << "Load failed for bandit.png" << endl;
		system("pause");
	}

	// SFML Sprites
	sf::Sprite* grassSprite = new sf::Sprite(*grassTexture);
	sf::Sprite* characterSprite = new sf::Sprite(*characterTexture);
	sf::Sprite* weaponSprite = new sf::Sprite(*weaponTexture);
	sf::Sprite* banditSprite = new sf::Sprite(*banditTexture);

	// Texture rescaling
	sf::Vector2f targetSize(100.0f, 100.0f);

	grassSprite->setScale(
		targetSize.x / grassSprite->getLocalBounds().width,
		targetSize.y / grassSprite->getLocalBounds().height
	);

	characterSprite->setPosition(1200.0f, 400.0f);
	characterSprite->setScale(0.143f, 0.143f);

	weaponSprite->setScale(0.125f, 0.125f);

	banditSprite->setScale(0.143f, 0.143f);
	banditSprite->setPosition(200.0f, 400.0f);

	// Vectors used for moving textures sprites
	sf::Vector2f* upMoveVector2f = new sf::Vector2f(0, -100);
	sf::Vector2f* leftMoveVector2f = new sf::Vector2f(-100, 0);
	sf::Vector2f* downMoveVector2f = new sf::Vector2f(0, 100);
	sf::Vector2f* rightMoveVector2f = new sf::Vector2f(100, 0);

	int frames = 0;
	int key;
	bool gameIsRunning = true;
	int currentPlayingTime = 0;
	int waitCount = 0;
	bool isPlayingAction = false;
	Character* ennemy = world->ennemy;


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

					// Changing textures of the character and his/her weapon
					if (!characterTexture->loadFromFile("data/ressources/textures/" + world->currentCharacter->getPath())) {
						cout << "Load failed for current character image" << endl;
						system("pause");
					}
					characterSprite->setTexture(*characterTexture);

					if (!weaponTexture->loadFromFile("data/ressources/textures/" + world->currentCharacter->weapon->getPath())) {
						cout << "Load failed for bow.png " << endl;
						system("pause");
					}
					weaponSprite->setTexture(*weaponTexture);

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
						world->currentCharacter->usePotion();
						cout << "You now have " << world->currentCharacter->hitPoints << "HP" << endl;
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
			if (world->gameTurn != 0) {
				ennemy->useWeapon(*(world->currentCharacter));
				cout << "You take " << ennemy->weapon->damageAmmount << "DMG." << endl;
			}
			world->gameTurn++;
			waitCount = 15;
			isPlayingAction = false;
			cout << "Turn " << world->gameTurn << ". You now have 15sec to play your turn.\n" << endl;
		}

		window.clear();

		// Display the grass background
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				grassSprite->setPosition(i*100.0f, j*100.0f);
				window.draw(*grassSprite);
			}
		}

		// Display sprites
		window.draw(*characterSprite);
		weaponSprite->setPosition(1500.0f, 800.0f);
		window.draw(*weaponSprite);
		window.draw(*banditSprite);

		// Display current turn number
		sf::Text* turn = new sf::Text("Turn : " + to_string(world->gameTurn), *font, 20);
		turn->setPosition(1400.0f, 15.0f);
		window.draw(*turn);

		// Display timer
		sf::Text* time = new sf::Text("Time : " + to_string(currentPlayingTime), *font, 20);
		time->setPosition(1500.0f, 15.0f);
		window.draw(*time);

		// Display current hitpoints
		sf::Text* myHitPoints = new sf::Text("HP : " + to_string(world->currentCharacter->hitPoints), *font, 20);
		myHitPoints->setPosition(1300.0f, 15.0f);
		window.draw(*myHitPoints);

		// Display ennemy hitpoints
		sf::Text* ennemyHitPoints = new sf::Text("Ennemy HP : " + to_string(ennemy->hitPoints), *font, 20);
		ennemyHitPoints->setPosition(50.0f, 15.0f);
		window.draw(*ennemyHitPoints);

		window.display();

		if (currentPlayingTime != frames / 120) {
			currentPlayingTime = frames / 120;
			waitCount--;
		}
	}
	world->saveState();

	return 0;
}