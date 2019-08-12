#include "Character.hpp"
#include <iostream>

namespace Sagar
{
		Character::Character(GameDataRef data) : _data(data)
		{
				character.setTexture(_data->assets.GetTexture("character"));
				character.setPosition(0,_data->window.getSize().y/3);
		}

		void Character::Draw()
		{
				_data->window.draw(character);
		}
		void Character::SetDirection(const sf::Vector2f& dir)
		{
				velocity = dir * speed;
		}

		void Character::Update(float dt)
		{
				position += velocity * dt;
		}

}
