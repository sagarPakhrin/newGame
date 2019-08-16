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
						Animation(float switchTime);
						~Animation(){}
						void Update(sf::Sprite &sprite, std::vector<sf::Texture> &_animation_frames,bool faceLeft,float dt);
						int getIterator();
						void resetIterator(){this->_animationIterator = 0;}
				private:
						unsigned int _animationIterator=0;
						/* std::vector<sf::Texture> _animation_frames; */
						float totalTime;
						float switchTime;
		};
}
