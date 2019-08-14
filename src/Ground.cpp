#include "Ground.hpp"
#include <iostream>
#include "Animation.hpp"

namespace Sagar
{
		Ground::Ground(GameDataRef data) : _data(data)
		{
				ground.setTexture(_data->assets.GetTexture("ground_image"));
				ground.setPosition(_data->window.getSize().x/2,_data->window.getSize().y - (ground.getTexture()->getSize().y)/2);
				ground.setOrigin(ground.getTexture()->getSize().x/2,ground.getTexture()->getSize().y/2);
		}

		void Ground::Draw()
		{
				_data->window.draw(ground);
		}
		const sf::Sprite Character::&GetSprite() const
		{
				return ground;
		}

}
