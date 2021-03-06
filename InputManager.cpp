#include "InputManager.hpp"

namespace Sonar
{
  // Check if a sprite is clicked on the actual window that the event occurs
  bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
  {
    if( sf::Mouse::isButtonPressed(button))
    {
      sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
      
      if (tempRect.contains(sf::Mouse::getPosition(window)))
      {
        return true;
      }
    }

  }

  // Get mouse position on window
  sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
  {
    return sf::Mouse::getPosition(window);
  }
}