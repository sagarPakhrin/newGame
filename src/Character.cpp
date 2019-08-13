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
				character_sprite.setPosition(100,SCREEN_HEIGHT - character_sprite.getGlobalBounds().height/4);
				character_sprite.setScale(0.3,0.3);
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
				if(_character_state==1)
				{
						Character::Attack(dt);
				}
				else if(_character_state==2)
				{
						Character::Run(dt);
				}
				else if(_character_state==3)
				{
						Character::Jump(dt);
				}
				else if (_character_state == 0)
				{
						Character::Animate(dt);
				}

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
								_character_state = 0;
						}
						character_sprite.setTexture(_attack_animation_frames.at(_animationIterator));
						_clock.restart();
				}
		}

		void Character::Jump(float dt)
		{
				if(_clock.getElapsedTime().asSeconds() > ATTACK_DURATION/_attack_animation_frames.size())
				{
						/* sf::Vector2f dir = {direction.x,direction.y}; */
						character_sprite.move(0,-100);
						if(_animationIterator < _jump_animation_frames.size() - 1)
						{
								_animationIterator ++;
						}
						else
						{
								_character_state = 0;
						}

						character_sprite.setTexture(_jump_animation_frames.at(_animationIterator));
						_clock.restart();
				}
		}

		void Character::Run(float dt)
		{
				if(_clock.getElapsedTime().asSeconds() > ATTACK_DURATION/_attack_animation_frames.size())
				{
						sf::Vector2f pos = character_sprite.getPosition();

						/******************** Setting Character Boundry *********************/
						if(pos.x >(SCREEN_WIDTH - character_sprite.getGlobalBounds().width/2 -50))
						{
								character_sprite.setPosition(SCREEN_WIDTH-character_sprite.getGlobalBounds().width/2-50,pos.y);
						}
						else if(pos.x <50)
						{
								character_sprite.setPosition(50,pos.y);
						}

						character_sprite.move(speed.x*direction.x,0);

						/* Set Animation */
						if(_animationIterator < _run_animation_frames.size() - 1)
						{
								_animationIterator ++;
						}
						else
						{
								_animationIterator=0;
						}
						if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
						{
								_character_state=2;
						}
						else
						{
								_character_state = 0;
						}
						character_sprite.setTexture(_run_animation_frames.at(_animationIterator));
						_clock.restart();
				}
		}

		void Character::setCharacterState(const int character_state)
		{
				/* to update the character state */ 
				this->_character_state=character_state;
		}

		void Character::setDirection(const sf::Vector2f& dir)
		{
				direction = dir;
		}

		void Character::playAudio()
		{
				if(sword_slash.openFromFile(SWORD_SLASH))
				{
						sword_slash.play();
				}
		}

}
