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

				enemyCharacter.setScale(0.3,0.3);
				enemyCharacter.setOrigin(enemyCharacter.getTexture()->getSize().x/2,enemyCharacter.getTexture()->getSize().y/2);
				enemyCharacter.setPosition(_data->window.getSize().x-100,_data->window.getSize().y-100);

				animation = new Animation(0.1);
		}
		void Enemy::Update(float dt)
		{
				current_animation = _running_enemy_frames;
				animation->Update(enemyCharacter,current_animation,false,dt);
		}
		void Enemy::Draw()
		{
				_data->window.draw(enemyCharacter);
		}

}
