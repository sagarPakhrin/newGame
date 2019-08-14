#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINATIONS.hpp"

#include "Game.hpp"
#include "Animation.hpp"
#include <vector>

namespace Sagar
{
		class Ground
		{
				public:
						Ground(GameDataRef data); 
						void Draw();
						void Update(float dt);
						~Ground(){}
				private:
						GameDataRef _data;
						sf::Sprite ground;
		};
}
