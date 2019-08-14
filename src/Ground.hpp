#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINATIONS.hpp"

#include "Game.hpp"
#include "Animation.hpp"
#include "Collider.hpp"
#include <vector>

namespace Sagar
{
		class Ground
		{
				public:
						Ground(GameDataRef data); 
						~Ground(){}
						void Draw();
						void Update(float dt);

						const Collider GetCollider() const {return Collider(ground);}


				private:
						GameDataRef _data;
						sf::Sprite ground;
		};
}
