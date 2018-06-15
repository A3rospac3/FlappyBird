#include "Game.hpp"

namespace Sonar
{
  Game::Game( int width, int height, std::string title)
  {
     // or Close and Title bar, this means we have clsoe and tile bar on the window
    _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

    this->Run( );
  }

  void Game::Run()
  {
    float newTime, frameTime, interpolation;
    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (this->_data->window.isOpen())
    {
      this->_data->machine.ProcessStateChanges(); // Process the change that occur
      newTime = this->_clock.getElapsedTime().asMicroseconds(); 
      frameTime = newTime - currentTime; // How long it took between frames

      if (frameTime > 0.25f)
      {
        frameTime = 0.25f; // restrict frametime for smooth game play
      }
      currentTime = newTime;
      accumulator +=frameTime;

      while(accumulator > dt)
      {
        this->_data->machine.GetActiveState()->HandleInout();
        this->_data->machine.GetActiveState()->Update(dt);

        accumulator -=dt;
      }

      interpolation = accumulator / dt;
      this->_data->machine.GetActiveState()->Draw(interpolation);
    }
  }
}