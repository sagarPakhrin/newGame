#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace Sagar
{
		class Kunai
		{
				public:
						Kunai(sf::Texture);
						~Kunai(){}
						void Draw();
						void Update(float dt);

				private:
						sf::Sprite player;
		};
}
