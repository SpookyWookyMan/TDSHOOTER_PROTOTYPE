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

    //initiate resources here
    res_mgr::addFont("res/fonts/arial.ttf", "Arial");
    res_mgr::addFont("res/fonts/m12.ttf", "M12");
    res_mgr::addTexture("res/textures/ui/in_game_cursor.png", "InGameCursor");

    inGameCursor.setTexture(res_mgr::getTexture("InGameCursor"));

    sf::Vector2f cBounds = sf::Vector2f(inGameCursor.getLocalBounds().width, inGameCursor.getLocalBounds().height);
    inGameCursor.setOrigin(cBounds.x / 2, cBounds.y / 2);

    player.start();
    player.projectileMgr = &projectileMgr;

    npcmgr.instantiate(sf::Vector2f(600.0f, 200.0f), 100000);

    TileMgr::start();
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
    player.draw(window);
    projectileMgr.draw(window);
    npcmgr.draw(window);
    gui::PopUpTextMgr::draw(window);
    window->draw(inGameCursor);
    TileMgr::draw(window);
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
    npcmgr.update(deltaTime, projectileMgr.getProjectiles(), player.getRect().getPosition(), window);
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