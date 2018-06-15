#pragma once 

#include <memory.h>
#include <string.h>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Sonar
{
  struct GameData
  {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
  };

  typedef std::shared_ptr<GameData> GameDataRef;

  class Game
  {
    public:
      Game(int width, int height, std::string title);

    private:
      const float dt = 1.0f/60.0f; // frame rate updates at 60Hz
      sf::Clock _clock; // Handle frame rate

      GameDataRef _data = std::make_shared<GameData> ( );

      void Run( );


  };
}