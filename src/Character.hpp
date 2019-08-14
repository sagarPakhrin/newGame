#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINATIONS.hpp"

#include "Game.hpp"
#include "Animation.hpp"
#include <vector>

namespace Sagar
{
		class Character
		{
				public:
						Character(GameDataRef data); 
						void Draw();
						void Update(float dt);
						void Run(float dt);
						void setDirection(const sf::Vector2f& dir);
						void setCharacterState(int character_state);
						void playAudio();

						void Animate(float dt);
						void Attack(float dt);
						void Jump(float dt);
						void Tap();
				private:
						GameDataRef _data;
						sf::Sprite character_sprite;
						Animation *animation;


						unsigned int _animationIterator;
						unsigned int _character_state = IDLE_STATE;

						std::vector<sf::Texture> _idle_animation_frames;
						std::vector<sf::Texture> _attack_animation_frames;
						std::vector<sf::Texture> _run_animation_frames;
						std::vector<sf::Texture> _jump_animation_frames;

						sf::Music sword_slash;

						/* static constexpr float speed = 2.0f; */
						sf::Vector2f speed = {30.0f,30.0f};
						sf::Vector2f direction = {1.0f,1.0f};
						/* sf::Vector2f position; */
						sf::Vector2f velocity = {0.0f,100.0f};
						/* unsigned float mass = 50.f; */
						float gravity = 350.0f;
						float falling_speed = 350.0f;
						float jump_duration = 0.25f;
						sf::Clock _jumpClock;

						sf::Clock _clock;
		};
}
