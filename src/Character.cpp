#include "Character.hpp"
#include <iostream>

namespace Sagar
{
		Character::Character(GameDataRef data) : _data(data)
		{
				character.setTexture(_data->assets.GetTexture("character"));
		}

		void Character::Draw()
		{
				_data->window.draw(character);
		}
		void Character::Update(float dt)
		{
				position += velocity * dt;
		}
		void Character::SetDirection(const sf::Vector2f& dir)
		{
				velocity = dir * speed;
		}
}
