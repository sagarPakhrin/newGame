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
						~Enemy();
						void Draw();
						void Update(float dt);
						void Die();
						sf::Sprite getEnemySprite(){return this->enemyCharacter;}
				private:
						GameDataRef _data;
						Animation *animation;
						unsigned int animation_iterator = 0;
						sf::Sprite enemyCharacter;
						sf::Clock clock;
						std::vector<sf::Texture> _running_enemy_frames;
						std::vector<sf::Texture> current_animation;
						bool die = false;
						bool turnRight = false;
						float totalTime = 0;
						float enemySpeed = 980.0f;
						sf::Vector2f velocity= {0.0f,0.0f};
		};
}
