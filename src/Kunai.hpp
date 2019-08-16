#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace Sagar
{
		class Kunai
		{
				public:
						Kunai(sf::Texture& texture);
						~Kunai(){}
						void Draw(sf::RenderWindow& window);
						void Update(float dt);
						void SetPosition(sf::Vector2f position){kunai.setPosition(position);}
						sf::Sprite getKunaiSprite(){return this->kunai;}
				private:
						sf::Sprite kunai;
						float kunaiSpeed = 980.0f;
		};
}
