#include "Animation.hpp"

namespace Sagar
{
		void Animation::Update(sf::Sprite &sprite, std::vector<sf::Texture> &_animation_frames,sf::Clock &_clock, float dt)
		{
				if(_clock.getElapsedTime().asSeconds() > CHARACTER_ANIMATION_DURATION/_animation_frames.size())
				{
						if(_animationIterator < _animation_frames.size() - 1)
						{
								_animationIterator ++;
						}
						else
						{
								_animationIterator = 0;
						}
						sprite.setTexture(_animation_frames.at(_animationIterator));
						_clock.restart();
				}
		}
}
