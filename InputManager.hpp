#pragma once 

#include <SFML/Graphics.hpp>

namespace Sonar
{
  class InputManager
  {
    public:
      InputManager( ) { }
      ~InputManager( ) { }

      // Check if a sprite is clicked on the actual window that the event occurs
      bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

      // Get mouse position on window
      sf::Vector2i GetMousePosition(sf::RenderWindow &window);
  };
}