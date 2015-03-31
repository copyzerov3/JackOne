#include "Game.h"
#include "LoadingScreen.h"
#include "MainMenuScreen.h"
Game::Game()
{

}

Game::~Game()
{
	delete m_screen;
	m_screen = NULL;

	delete manager;
	manager = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

}

bool Game::Init()
{
	manager = new Managers();
	if (!manager->Init())
	{
		return false;
	}
	m_screen = new MainMenuScreen(manager);
	m_screen->Init();
	fpsTimer.start();
	countedFrames = 0;

	return true;
}
bool Game::Leave()
{
	return m_screen->GetLeave();
}
void Game::Update()
{
	//for calculating frame rate
	capTimer.start();
	//Process all inputs
	manager->GetInputManager()->Process();
	//Update the screen
	m_screen->Update();
	//if there is supposed to be a screen transition
	Screen* temp = m_screen->GetNextScreen();
	//if there is a screem
	if (temp != nullptr)
	{
		//delete the old screen
		delete m_screen;
		//Set it to NULL for good measure.
		m_screen = NULL;
		//Set Our screen pointer to the new screen.
		m_screen = temp;
		//Set temp to NULL because I am paranoid.
		temp = NULL;
		//Init the new screen
		m_screen->Init();
	}
	
	//Clear the screen
	manager->GetGraphicsManager()->startDraw();
	//Have the current Screen Draw
	m_screen->Draw();
	//Present the screen to the user
	manager->GetGraphicsManager()->endDraw();
	//increase the frames;
	++countedFrames;
	//if the frame went by to quickly then wait until its fit its time
	int frameTicks = capTimer.getTicks();
	if (frameTicks < SCREEN_TICKS_PER_FRAME)
	{
		SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
	}
}

