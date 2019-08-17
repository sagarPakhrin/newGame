#pragma once
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <vector>

namespace Sagar
{
		class Enemy
		{
				public:
				public:
						Enemy(GameDataRef data);
						void Draw();
						void Update(float dt);
						void Die();
						sf::Sprite getEnemySprite(){return this->enemyCharacter;}
				private:
						GameDataRef _data;
						Animation *animation;
						unsigned int animation_iterator = 0;
						sf::Sprite enemyCharacter;
						std::vector<sf::Texture> _running_enemy_frames;
						std::vector<sf::Texture> current_animation;
						bool die = false;
		};
}
