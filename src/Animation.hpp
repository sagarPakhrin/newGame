#pragma once
#include <vector>
#include "DEFINATIONS.hpp"

namespace Sagar
{
		class Animation
		{
				public:
						Animation();
						~Animation(){}
						void Update(float dt);
				private:
						unsigned int _animationIterator=0;
						std::vector<sf::Texture> _animation_frames;
		}
}
