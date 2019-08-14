#include "Character.hpp"
#include <iostream>
#include "Animation.hpp"

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

				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_0"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_1"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_2"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_3"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_4"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_5"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_6"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_7"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_8"));
				_run_animation_frames.push_back(_data->assets.GetTexture("run_frame_9"));

				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_0"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_1"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_2"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_3"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_4"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_5"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_6"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_7"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_8"));
				_jump_animation_frames.push_back(_data->assets.GetTexture("jump_frame_9"));

				character_sprite.setTexture(_attack_animation_frames.at(_animationIterator));
				/* character_sprite.setPosition(100,_data->window.getSize().y-150); */
				character_sprite.setPosition(100,_data->window.getSize().y-150);
				character_sprite.setScale(0.3,0.3);
				animation = new Animation(0.1);
		}

		void Character::Draw()
		{
				_data->window.draw(character_sprite);
		}

		/************************************
		 *************UPDATE METHOD ********
		 ************************************/

		void Character::Update(float dt)
		{
				sf::Vector2f movement(0.0f,0.0f);

				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
						movement.x +=speed * dt;
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
						movement.x -=speed * dt;
				}

				animation->Update(character_sprite,_idle_animation_frames,_clock,false,dt);
				character_sprite.move(movement);
		}
		void Character::playAudio()
		{
				if(sword_slash.openFromFile(SWORD_SLASH))
						sword_slash.play();
		}
}
