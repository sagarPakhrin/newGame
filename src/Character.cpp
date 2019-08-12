#include "Character.hpp"
#include <iostream>

namespace Sagar
{
		Character::Character(GameDataRef data) : _data(data)
		{
				_animationIterator = 0;
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_0"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_1"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_2"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_3"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_4"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_5"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_6"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_7"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_8"));
				_idle_animation_frames.push_back(_data->assets.GetTexture("idle_frame_9"));

				character_sprite.setTexture(_idle_animation_frames.at(_animationIterator));
				character_sprite.setPosition(0,_data->window.getSize().y/3);
		}

		void Character::Draw()
		{
				_data->window.draw(character_sprite);
		}
		void Character::SetDirection(const sf::Vector2f& dir)
		{
				velocity = dir * speed;
		}

		void Character::Update(float dt)
		{
				position += velocity * dt;
		}


		void Character::Animate(float dt)
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
