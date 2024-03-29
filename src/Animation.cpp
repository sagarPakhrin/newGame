#include "Animation.hpp"

namespace Sagar
{
		Animation::Animation(float switchTime)
		{
				this->switchTime = switchTime;
		}
		void Animation::Update(sf::Sprite &sprite, std::vector<sf::Texture> &_animation_frames,bool faceLeft,float dt)
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
				if(faceLeft)
				{
						/* sprite.setScale(-abs(sprite.getScale().x),sprite.getScale().y); */
				}
				/* else */
				/* { */
				/* 		sprite.setScale(abs(sprite.getScale().x),sprite.getScale().y); */

				/* } */
				sprite.setTexture(_animation_frames.at(_animationIterator));

		}

		int Animation::getIterator()
		{
				return static_cast<int>(_animationIterator);
		}
}
