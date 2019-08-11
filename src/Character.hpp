#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINATIONS.hpp"

#include "Game.hpp"
#include <vector>

namespace Sagar
{
		class Character
		{
				public:
						Character(GameDataRef data); 
						void Draw();
						void Update(float dt);
						void SetDirection(const sf::Vector2f& dir);
				private:
						GameDataRef _data;
						sf::Sprite character;

						static constexpr float speed = 10.0f;

						sf::Vector2f position;
						sf::Vector2f velocity = {0.0f,0.0f};
						sf::Clock _clock;
		};
}
