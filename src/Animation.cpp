#include "Animation.hpp"

namespace Sagar
{
		void Animation::Update(sf::Sprite &sprite, std::vector<sf::Texture> _animation_frames, float dt)
		{
				if(_clock.getElapsedTime().asSeconds() > CHARACTER_ANIMATION_DURATION/_idle_animation_frames.size())
				{
						if(_animationIterator < _idle_animation_frames.size() - 1)
						{
								_animationIterator ++;
						}
						else
						{
								_animationIterator = 0;
						}
						character_sprite.setTexture(_idle_animation_frames.at(_animationIterator));
						_clock.restart();
				}
		}
}
