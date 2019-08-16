#include "Character.hpp"
#include <cmath>
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

				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_0"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_1"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_2"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_3"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_4"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_5"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_6"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_7"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_8"));
				_slide_animation_frames.push_back(_data->assets.GetTexture("slide_frame_9"));

				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_0"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_1"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_2"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_3"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_4"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_5"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_6"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_7"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_8"));
				_throw_animation_frames.push_back(_data->assets.GetTexture("throw_frame_9"));

				character_sprite.setTexture(_attack_animation_frames.at(_animationIterator));
				character_sprite.setPosition(100,_data->window.getSize().y - (character_sprite.getTexture()->getSize().x * 0.3)/2 - 2000);
				character_sprite.setScale(0.3,0.3);
				character_sprite.setOrigin(character_sprite.getTexture()->getSize().x/2,character_sprite.getTexture()->getSize().y/2);
				current_animation = _idle_animation_frames;
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
				velocity.x = 0.0f;


				if(_character_state == IDLE_STATE)
				{
						current_animation = _idle_animation_frames;
				}
				else if(_character_state == THROW_STATE)
				{
						current_animation = _throw_animation_frames;
						if(animation->getIterator()>=(int)current_animation.size()-2)
						{
								_character_state = IDLE_STATE;
						}
				}
				else if(_character_state == SLIDE_STATE)
				{
						current_animation = _slide_animation_frames;
						character_sprite.setPosition(character_sprite.getPosition().x,_data->window.getSize().y + 20);
						character_sprite.move(20,0);
						if(animation->getIterator()>=(int)current_animation.size()-2)
						{
								_character_state = IDLE_STATE;
						}
				}
				else if(_character_state == ATTACK_STATE)
				{
						playAudio();
						current_animation = _attack_animation_frames;
						if(animation->getIterator()>=(int)current_animation.size()-2)
						{
								_character_state = IDLE_STATE;
						}
				}

				else if(_character_state == JUMPING_STATE && canJump)
				{
						canJump = false;
						velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
						// square root 2.0f * gravity * jumpheight;
						current_animation = _jump_animation_frames;

				}
				else if(_character_state == RUNNING_RIGHT_STATE)
				{
						velocity.x +=speed * dt;
						current_animation = _run_animation_frames;

				}
				else if(_character_state == RUNNING_LEFT_STATE)
				{
						velocity.x -=speed * dt;
						current_animation = _run_animation_frames;
				}

				if(_character_state == RUNNING_LEFT_STATE || _character_state == RUNNING_RIGHT_STATE)
				{
						if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
						{
								_character_state = IDLE_STATE;
						}
				}

				animation->Update(character_sprite,current_animation,false,dt);



				/* setting gravity */
				velocity.y +=981.0f * dt;
				character_sprite.move(velocity*dt);

				/* check if boundry crossed */
				if(character_sprite.getPosition().x <= (character_sprite.getTexture()->getSize().x*0.3)/2)
				{
						character_sprite.setPosition((character_sprite.getTexture()->getSize().x*0.3)/2,character_sprite.getPosition().y);
				}
				if(character_sprite.getPosition().x >= _data->window.getSize().x - (character_sprite.getTexture()->getSize().x*0.3)/2)
				{
						character_sprite.setPosition(_data->window.getSize().x - (character_sprite.getTexture()->getSize().x*0.3)/2,character_sprite.getPosition().y);
				}
				if(character_sprite.getPosition().y >= _data->window.getSize().y - 100)
				{
						character_sprite.setPosition(character_sprite.getPosition().x ,_data->window.getSize().y -100);
						canJump = true;
				}
		}

		void Character::OnCollision(sf::Vector2f dirn)
		{
				if(dirn.x < 0.0f)
				{
						/* collosion on left */
						velocity.x = 0.0f;
				}
				else if(dirn.x > 0.0f)
				{
						velocity.x = 0.0f;
				}
				if(dirn.y > 0.0f)
				{
						/* collision on the Bottom */
						velocity.y = 0.0f;
						canJump = true;
				}
				else if (dirn.y > 0.0f)
				{
						/* collision on the top */
						velocity.y = 0.0f;
				}
		}

		void Character::playAudio()
		{
				if(sword_slash.openFromFile(SWORD_SLASH))
						sword_slash.play();
		}
}
