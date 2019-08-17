#include "Enemy.hpp"
namespace Sagar
{
		Enemy::Enemy(GameDataRef data):_data(data)
		{
				_running_enemy_frames.push_back(_data->assets.GetTexture("enemy_running_frame_0"));
				_running_enemy_frames.push_back(_data->assets.GetTexture("enemy_running_frame_1"));
				_running_enemy_frames.push_back(_data->assets.GetTexture("enemy_running_frame_2"));
				_running_enemy_frames.push_back(_data->assets.GetTexture("enemy_running_frame_3"));
				_running_enemy_frames.push_back(_data->assets.GetTexture("enemy_running_frame_4"));
				_running_enemy_frames.push_back(_data->assets.GetTexture("enemy_running_frame_5"));
				_running_enemy_frames.push_back(_data->assets.GetTexture("enemy_running_frame_6"));
				_running_enemy_frames.push_back(_data->assets.GetTexture("enemy_running_frame_7"));

				enemyCharacter.setTexture(_running_enemy_frames.at(animation_iterator));

				enemyCharacter.setScale(-0.3f,0.3f);
				enemyCharacter.setOrigin(enemyCharacter.getTexture()->getSize().x/2,enemyCharacter.getTexture()->getSize().y/2);
				enemyCharacter.setPosition(_data->window.getSize().x-100,_data->window.getSize().y-100);

				animation = new Animation(0.1);
		}
		void Enemy::Update(float dt)
		{
				float time = clock.restart().asSeconds();
				velocity.x = 0;
				velocity.x -=enemySpeed * dt;
				totalTime +=time;
				if(totalTime > 3)
				{
						turnRight = !turnRight;
						totalTime = 0;
						enemyCharacter.setScale(-enemyCharacter.getScale().x,enemyCharacter.getScale().y);
				}

				if(!turnRight)
						enemyCharacter.move(velocity*dt);
				else
						enemyCharacter.move(-velocity*dt);


				if(die){
						enemyCharacter.setPosition(_data->window.getSize().x+1000,_data->window.getSize().y+1000);
				}
				current_animation = _running_enemy_frames;
				animation->Update(enemyCharacter,current_animation,false,dt);
		}
		void Enemy::Draw()
		{
				_data->window.draw(enemyCharacter);
		}
		void Enemy::Die()
		{
				die = true;
		}
}
