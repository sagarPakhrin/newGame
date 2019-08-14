#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "DEFINATIONS.hpp"

namespace Sagar
{
		class Animation
		{
				public:
						/* Animation(sf::Sprite* sprite,std::vector _animation_frames); */
						Animation(){}
						~Animation(){}
						void Update(sf::Sprite &sprite, std::vector<sf::Texture> _animation_frames,sf::Clock _clock, float dt);
				private:
						unsigned int _animationIterator=0;
						/* std::vector<sf::Texture> _animation_frames; */
		};
}
