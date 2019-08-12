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

				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_0"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_1"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_2"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_3"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_4"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_5"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_6"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_7"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_8"));
				_attack_animation_frames.push_back(_data->assets.GetTexture("attack_frame_9"));

				character_sprite.setTexture(_idle_animation_frames.at(_animationIterator));
				character_sprite.setScale(0.4f,0.4f);
				character_sprite.setPosition(100,SCREEN_HEIGHT - (character_sprite.getGlobalBounds().height +10));
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

		void Character::Attack(float dt)
		{
				if(_clock.getElapsedTime().asSeconds() > ATTACK_DURATION/_attack_animation_frames.size())
				{
						if(_animationIterator < _attack_animation_frames.size() - 1)
						{
								_animationIterator ++;
						}
						else
						{
								_animationIterator = 0;
						}
						character_sprite.setTexture(_attack_animation_frames.at(_animationIterator));
						_clock.restart();
				}
		}

}
