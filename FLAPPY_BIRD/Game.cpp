#include "Game.h"

void Game::initWindow()
{
    videoMode.width = WIN_WIDTH;
    videoMode.height = WIN_HEIGHT;

	window = new RenderWindow(videoMode, "Flappy Bird", Style::Titlebar | Style::Close ); 

    window->setFramerateLimit(90);
}

void Game::initTextures()
{
    //Inicjalizacja tekstur tla  
    if (!backgroundTexture.loadFromFile(R"(Textures\backgrounds\piwko1.jpg)"))
        std::cout << "ERROR: failed to load background file in Game::initTextures()" << std::endl;

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(BG_SCALE_W, BG_SCALE_H);
    backgroundSprite.setPosition(0.0f, 0.0f);
    
    //Inicjalizacja tekstur podloza
    if (!groundTexture.loadFromFile(R"(Textures\ground\base.png)"))
        std::cout << "ERROR: failed to load ground file in Game::initTextures()" << std::endl;

    groundTexture.setRepeated(true);
    groundSprite.setTexture(groundTexture);

    groundSprite.setTextureRect(IntRect(0, 0, WIN_WIDTH, GROUND_HEIGHT));
    groundSprite.setPosition(0.f, WIN_HEIGHT-GROUND_HEIGHT);
}

void Game::initVariables()
{
    currentMenu = &mainMenu;

    pipeSpawnTimer = Time::Zero;
    pipeSpawnInterval = seconds(3.f);

    pupSpawnTimer = Time::Zero;
    pupSpawnInterval = seconds(5.f);

    difficulty = Difficulty::EASY;
}

void Game::initText()
{
    if (!font.loadFromFile(FONT_SCORE))
        std::cout << "Unable to load SCORE FONT!" << std::endl;

    scoreText.setFont(font);
    scoreText.setCharacterSize(72);
    scoreText.setFillColor(Color::White);
    scoreText.setOutlineColor(Color::Black);
    scoreText.setOutlineThickness(3.f);
    scoreText.setString("0");

    //Wycentrowanie napisu
    auto scoreBounds = scoreText.getGlobalBounds();
    scoreText.setOrigin(scoreBounds.left + scoreBounds.width / 2.f, scoreBounds.top + scoreBounds.height / 2.f);
    scoreText.setPosition(WIN_WIDTH / 2.f, 60.f);

}

Game::Game(): window(nullptr), score(0), currentState(GameState::MENU)
{
	initWindow();
    initTextures();    
    initText();
    initVariables();     
}

Game& Game::getInstance()
{
    static Game instance;
    return instance;
}

Game::~Game()
{
	delete window;
}

const bool Game::isRunning() const
{
	return window->isOpen();
}

void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            case Event::Closed:
            {
                window->close();
                break;
            }
            case Event::KeyPressed:
            {
                if (event.key.code == Keyboard::Escape)
                    window->close();
                if (event.key.code == Keyboard::F12)
                    saveScreenshoot();
                break;
            }
        }
    }
}

void Game::spawnPipes(Time& dt)
{
    pipeSpawnTimer += dt;
    if (pipeSpawnTimer >= pipeSpawnInterval)
    {        
        //zastosowanie wzorca fabryki obiektow
        pipes.push_back(pipeFactory.createPipe(score, difficulty));
        pipeSpawnTimer = Time::Zero;
    }
}

void Game::updatePipes(Time& dt)
{
    //aktualizowanie stanu
    for (const auto& pipe : pipes)   
        pipe->update(dt);
    
    pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [](const std::unique_ptr<Pipe>& pipe)
        {   return pipe->isOutside();   }), pipes.end());
   
}

void Game::checkCollisions()
{   
    //Zmniejszenie hitboxu ptaka bo rotacja zaburza poprawne wykrywanie kolizji z rurami i podlozem
    auto birdBounds = bird.getBounds();
    birdBounds.left += birdBounds.width * 0.1f;
    birdBounds.top += birdBounds.height * 0.1f;
    birdBounds.width *= 0.75f;
    birdBounds.height *= 0.75f;

    if (birdBounds.top <= 0.f || birdBounds.top + birdBounds.height >= WIN_HEIGHT - GROUND_HEIGHT - 5)
    {
        bird.freeze();
        currentState = GameState::GAME_OVER;
        std::cout << "KOLIZJA\n";
    }  
    
    if (!pipes.empty())    
    {
        if (!bird.getInvincibility() && (birdBounds.intersects(pipes[0]->getBottomBounds()) ||
            birdBounds.intersects(pipes[0]->getTopBounds()))) 
        {
            bird.freeze();
            currentState = GameState::GAME_OVER;
            std::cout << "KOLIZJA\n";
        }
    }

    if(!powerUps.empty())
    {
        auto& pup = powerUps[0];
        if (birdBounds.intersects(pup->getBounds()))
        {
            pup->activate();
            pup->apply(bird);
        }
    }

}

void Game::handleStates()
{
    switch (currentState)
    {
    case GameState::PLAYING:
        currentMenu = &playingMenu;
        break;
    case GameState::MENU:
        currentMenu = &mainMenu;
        break;
    case GameState::PAUSE:
        currentMenu = &pauseMenu;
        break;
    case GameState::GAME_OVER:
        currentMenu = &gameOver;
        break;
    }
}

void Game::update(Time& dt)
{
    pollEvents();   
    handleStates();

    currentMenu->update(window);
    switch (currentState) 
    {
    case GameState::MENU :
        if (mainMenu.start())
        {
            currentState = GameState::PLAYING;
            restartGame();
        }
        break;
    case GameState::PLAYING :
        spawnPipes(dt);
        spawnPowerUp(dt);
        bird.update(dt);
        updatePipes(dt);
        checkCollisions();
        updatePowerUp(dt);
        updateScore();      

        if (playingMenu.pause())
        {
            currentState = GameState::PAUSE;           
            bird.freeze();
        }
        break;
    case GameState::PAUSE :
        if (pauseMenu.resume())
        {
            currentState = GameState::PLAYING;
            bird.unfreeze();
        }
        else if (pauseMenu.menu())
        {
            currentState = GameState::MENU;           
        }
        break;
    case GameState::GAME_OVER :
        if (gameOver.restart())
        {
            restartGame();
            currentState = GameState::PLAYING;
        }
        else if (gameOver.menu())
        {           
            currentState = GameState::MENU;
        }
        else if (gameOver.exit())
            window->close();
        break;
     }
}

void Game::updateScore()
{
    if (pipes.empty())
    {
        scoreText.setString("0");
        return;
    }
        
    const auto& pipe = pipes[0];
    if (!pipe->isPassed() && bird.getLeftEdge() > pipe->getRightEdge())
    {
        score++;
        pipe->setPassed();
    }
    //std::cout << "Punkty: " << score << std::endl;
    std::stringstream sos;
    sos << score;
    scoreText.setString(sos.str()); 
}

void Game::restartGame()
{
    bird.reset();
    pipes.clear();
    powerUps.clear();
    score = 0;
    currentState = GameState::PLAYING;
    currentMenu = &playingMenu;

    pupSpawnTimer = Time::Zero;
}

void Game::spawnPowerUp(Time& dt)
{
    pupSpawnTimer += dt;
    if (pupSpawnTimer > pupSpawnInterval)
    {
        float posY = PipeFactory::randomIntGenerator(250,550);
        powerUps.push_back(std::make_unique<Invincibility>(Vector2f(WIN_WIDTH - 50, posY)));
        pupSpawnTimer = Time::Zero;
    }
}

void Game::updatePowerUp(Time& dt)
{
    for (auto& pup : powerUps)   
        pup->update(dt);

    powerUps.erase(std::remove_if(powerUps.begin(), powerUps.end(), [](const std::unique_ptr<PowerUp>& pup)
        {   return pup->isOutside();   }), powerUps.end());
}

void Game::renderPowerUp()
{
    for (const auto& pup : powerUps)
        pup->render(window);
}

void Game::render()
{
    window->clear();
    window->draw(backgroundSprite);   

    switch (currentState)
    {
    case GameState::MENU:
        break;
    case GameState::PLAYING:
        bird.render(window);   
        renderPowerUp();
        renderPipes(); 
        renderScore();
        break; 
    case GameState::PAUSE:
        bird.render(window);
        renderPowerUp();
        renderPipes();       
        break;
    case GameState::GAME_OVER:
        // stany PLAYING, PAUSE I GAME_OVER maja taka sama sekwnecje renderowania, wiec kod w switchu zostaje pusty bez break;
        bird.render(window);
        renderPipes();
        renderScore();
        break;
    }  
    window->draw(groundSprite);
    //kazdy stan dokonuje renderu
    currentMenu->render(window);
    window->display();
}

void Game::renderScore()
{
    window->draw(scoreText);
}

void Game::renderPipes()
{
    for (const auto& pipe : pipes)
        pipe->render(window);
}

void Game::saveScreenshoot()
{
    Texture tempTexture;
    tempTexture.create(window->getSize().x, window->getSize().y);
    tempTexture.update(*window);

    Image screenshot = tempTexture.copyToImage();
    screenshot.saveToFile("screenshot.png");   
}






