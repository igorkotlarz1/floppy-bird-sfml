#ifndef GAME_H
#define GAME_H

#include <vector>
#include <queue>
#include <sstream>
#include <memory>

//obiekty growe
#include "Bird.h"
#include "Pipe.h"
#include "MovingPipe.h"
#include "PipeFactory.h"
#include "Invincibility.h"
#include "Definitions.h"
#include "Button.h"
#include "GameState.h"

//interfejsy GUI
#include "Menu.h"
#include "MainMenu.h"
#include "GameOverMenu.h"
#include "PauseMenu.h"
#include "GamePlayMenu.h"

//#include "PathValidator.h"
#include "TextureManager.h"

class Game
{
private:
	//Stan gry
	GameState currentState;
	Difficulty difficulty;

	//Zarzadzanie menu
	Menu* currentMenu;

	MainMenu mainMenu;
	GamePlayMenu playingMenu;
	PauseMenu pauseMenu;
	GameOverMenu gameOver;	

	//Zmienne okna
	RenderWindow* window;
	VideoMode videoMode;

	Event event;

	//Obiekty growe
	Bird bird;
	std::vector<std::unique_ptr<Pipe>> pipes;	
	std::vector<std::unique_ptr<PowerUp>> powerUps;

	//zarzadzanie rurami
	PipeFactory pipeFactory;
	float baseSpeed, baseDistance;
	float movingPipeSpeed, movingPipeRange;

	Time pipeSpawnTimer, pipeSpawnInterval;

	Time pupSpawnTimer, pupSpawnInterval;
	
	//Textury
	TextureManager textureManager;

	Texture backgroundTexture, groundTexture;
	Sprite backgroundSprite, groundSprite;

	//Tekst
	Text scoreText, loadingText;
	Font font;

	//punkty
	unsigned int score;

	//Metody inicjalizujace
	void initWindow();
	void initText();
	void loadTextures();
	void initSprites();
	void initVariables();

	bool texturesLoaded();

	//przechwytywanie zdazen
	void pollEvents();

	//metody pomocnicze do aktualizacji stanow gry
	void spawnPipes(Time& dt);
	void updatePipes(Time& dt);
	void checkCollisions();
	void handleStates();
	void updateScore();
	void restartGame();

	void spawnPowerUp(Time& dt);
	void updatePowerUp(Time& dt);
	void renderPowerUp();

	//metody pomocnicze do renderu
	void renderPipes();
	void renderScore();

	void saveScreenshoot();

	//Zablokowanie kopiwoania - implementacja SINGLETONA
	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;

	Game();

public:
	static Game& getInstance();
	
	virtual ~Game();
	
	//glowna metoda do aktualizacji
	void update(Time& dt);

	//glowna metoda do renderu na ekran
	void render();

	const bool isRunning() const;
};

#endif