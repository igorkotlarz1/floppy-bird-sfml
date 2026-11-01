#ifndef GAME_H
#define GAME_H

#include <vector>
#include <queue>
#include <sstream>
#include <memory>

// Game objects
#include "Bird.h"
#include "Pipe.h"
#include "MovingPipe.h"
#include "PipeFactory.h"
#include "Invincibility.h"
#include "Definitions.h"
#include "GameState.h"

// GUI
#include "Menu.h"
#include "MainMenu.h"
#include "GameOverMenu.h"
#include "PauseMenu.h"
#include "GamePlayMenu.h"

#include "TextureManager.h"

class Game
{
private:
	TextureManager textureManager;

	// Game state
	GameState currentState;

	// Menus
	Menu* currentMenu;

	MainMenu mainMenu;
	GamePlayMenu playingMenu;
	PauseMenu pauseMenu;
	GameOverMenu gameOver;

	// Window
	RenderWindow* window;
	VideoMode videoMode;

	Event event;

	// Game objects
	Bird bird;
	std::vector<std::unique_ptr<Pipe>> pipes;
	std::vector<std::unique_ptr<PowerUp>> powerUps;

	// Pipes
	PipeFactory pipeFactory;
	float baseSpeed, baseDistance;
	float movingPipeSpeed, movingPipeRange;

	Time pipeSpawnTimer, pipeSpawnInterval;
	Time pupSpawnTimer, pupSpawnInterval;

	// Textures
	Sprite backgroundSprite, groundSprite;

	// Text
	Text scoreText, loadingText;
	Font font;

	// Score
	unsigned int score;

	// Initialisation
	void initWindow();
	void initText();
	void loadTextures();
	void initAssets();
	void initVariables();

	bool texturesLoaded();

	// Event handling
	void pollEvents();

	// Per-state update helpers
	void spawnPipes(Time& dt);
	void updatePipes(Time& dt);
	void checkCollisions();
	void handleStates();
	void updateScore();
	void restartGame();

	void spawnPowerUp(Time& dt);
	void updatePowerUp(Time& dt);
	void renderPowerUp();

	// Rendering helpers
	void renderPipes();
	void renderScore();

	void saveScreenshoot();

	// Non-copyable singleton
	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;

	Game();

public:
	static Game& getInstance();

	virtual ~Game();

	// Main update entry point
	void update(Time& dt);

	// Main render entry point
	void render();

	const bool isRunning() const;
};

#endif
