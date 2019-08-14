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
						void Animate();
						~Character(){}
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
						std::vector<sf::Texture> _slide_animation_frames;
						std::vector<sf::Texture> _throw_animation_frames;

						std::vector<sf::Texture> current_animation;

						sf::Music sword_slash;

						float speed = 330;

						sf::Clock _clock;
		};
}
