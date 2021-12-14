#include "program.h"

//TODO:
// Create UI class for UI manipulation
// Create manager of managers so that this class is clean
//

Program::Program() :
	win_name ("SFML Application"),
	window (NULL)
{
}
Program::Program(const std::string& win_name) :
	win_name(win_name),
	window  (NULL)
{
}
Program::~Program()
{
}

void Program::open(void) 
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), win_name);
    window->setMouseCursorVisible(false);

    srand(time(NULL));

    LOG("Testing ", "this");

    //initiate resources here
    res_mgr::addFont("res/fonts/arial.ttf", "Arial");
    res_mgr::addFont("res/fonts/m12.ttf", "M12");
    res_mgr::addTexture("res/textures/ui/in_game_cursor.png", "InGameCursor");

    inGameCursor.setTexture(res_mgr::getTexture("InGameCursor"));

    sf::Vector2f cBounds = sf::Vector2f(inGameCursor.getLocalBounds().width, inGameCursor.getLocalBounds().height);
    inGameCursor.setOrigin(cBounds.x / 2, cBounds.y / 2);

    player.start();
    player.projectileMgr = &projectileMgr;
    npcmgr.projectileManager = &projectileMgr;

    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT * 0.11f), 300, 50);                  //TEST: Small spawns
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH - WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT * 0.11f), 300, 50);   //TEST: Small spawns   
    //                                                                                                         
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT / 2.0f), 300, 50);                   //TEST: Small spawns
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH - WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT / 2.0f), 300, 50);    //TEST: Small spawns
    //                                                                                                         
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT / 4.0f), 300, 50);                   //TEST: Small spawns
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH - WINDOW_WIDTH * 0.07f, WINDOW_HEIGHT / 4.0f), 300, 50);    //TEST: Small spawns
    //                                                                                                         
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 4.0f), 300, 50);                    //TEST: Small spawns
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH - WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 4.0f), 300, 50);     //TEST: Small spawns
    //
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.14f, WINDOW_HEIGHT / 4.0f + WINDOW_HEIGHT * 0.11f), 600, 75);
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH - (WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.14f), WINDOW_HEIGHT / 4.0f + WINDOW_HEIGHT * 0.11f), 600, 75);
    //
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.28f, WINDOW_HEIGHT / 4.0f + WINDOW_HEIGHT * 0.27f), 600, 75);
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH - (WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.28f), WINDOW_HEIGHT / 4.0f + WINDOW_HEIGHT * 0.27f), 600, 75);
    //
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH / 2 - WINDOW_WIDTH * 0.11f, WINDOW_HEIGHT / 4.0f - WINDOW_HEIGHT * 0.07f), 1200, 100);
    //npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH / 2 + WINDOW_WIDTH * 0.11f, WINDOW_HEIGHT / 4.0f - WINDOW_HEIGHT * 0.07f), 1200, 100);

    npcmgr.instantiate(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4.0f - WINDOW_HEIGHT * 0.07f), 1200, 125);

    //TileMgr::start();

    //build ui here
    //b.setText("Text");
}
void Program::events(sf::Event& evt)
{
    if (evt.type == sf::Event::Closed)
        window->close();
    player.events(evt);
}
void Program::draw(void)
{
    window->clear(sf::Color(27, 38, 102));
    //Draw things here ==============================
    //b.draw(window);
    
    //TileMgr::drawDecor(window);

    player.draw(window);
    npcmgr.draw(window);

    //TileMgr::drawCol(window);

    projectileMgr.draw(window);
    player.drawGui(window);
    gui::PopUpTextMgr::draw(window);
    window->draw(inGameCursor);
    //===============================================
    window->display();
}

void Program::update(void)
{
    float deltaTime = deltaClock.restart().asSeconds();

    inGameCursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));

    //b.update(window);
    gui::PopUpTextMgr::update(window, deltaTime);

    player.update(window, deltaTime);
    projectileMgr.update(deltaTime);
    npcmgr.update(deltaTime, projectileMgr.getProjectiles(), player.pos, window, &player.getBounds());
}
void Program::run(void) 
{
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
            this->events(event);
        this->update();
        this->draw();
    }
}