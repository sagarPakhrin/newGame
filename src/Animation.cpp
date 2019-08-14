#include "Animation.hpp"

namespace Sagar
{
		Animation::Animation(float switchTime)
		{
				this->switchTime = switchTime;
		}
		void Animation::Update(sf::Sprite &sprite, std::vector<sf::Texture> &_animation_frames,sf::Clock &_clock,bool faceLeft,float dt)
		{
				totalTime += dt;
				if(totalTime >= switchTime)
				{
						totalTime -=switchTime;
						_animationIterator ++;
						if(_animationIterator < _animation_frames.size() - 1)
						{
								_animationIterator ++;
						}
						else
						{
								_animationIterator = 0;
						}
				}
				sprite.setTexture(_animation_frames.at(_animationIterator));

				/* if(faceLeft) */
		}
}
