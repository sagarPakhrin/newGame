#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINATIONS.hpp"

#include "Game.hpp"
#include "Animation.hpp"
#include "Collider.hpp"
#include "Kunai.hpp"
#include <vector>

namespace Sagar
{
		class Character
		{
				public:
						Character(GameDataRef data); 
						~Character(){}

						void Draw();
						void Update(float dt);
						void Run(float dt);
						void setDirection(const sf::Vector2f& dir);
						void setCharacterState(int character_state){this->_character_state = character_state;}
						int getCharacterState(int character_state){return (int)this->_character_state;}
						sf::Sprite getCharacterSprite(){return character_sprite;}
						sf::Vector2f GetPosition(){return this->character_sprite.getPosition();}
						void playAudio(const std::string& audio);

						const Collider GetCollider(){return Collider(this->character_sprite);}

						void Animate(float dt);
						void Attack(float dt);
						void Jump(float dt);
						void OnCollision(sf::Vector2f dirn);

				private:
						GameDataRef _data;
						sf::Sprite character_sprite;
						Animation *animation;
						float playerHealth = 100;


						unsigned int _animationIterator;
						unsigned int _character_state = IDLE_STATE;

						std::vector<sf::Texture> _idle_animation_frames;
						std::vector<sf::Texture> _attack_animation_frames;
						std::vector<sf::Texture> _run_animation_frames;
						std::vector<sf::Texture> _jump_animation_frames;
						std::vector<sf::Texture> _slide_animation_frames;
						std::vector<sf::Texture> _throw_animation_frames;
						std::vector<sf::Texture> _dead_animation_frames;

						std::vector<sf::Texture> current_animation;

						sf::Music audio;

						float speed = 930;
						sf::Vector2f velocity;
						bool canJump;
						bool faceLeft=false;
						float jumpHeight = 200;

						sf::Clock _clock;
		};
}
