#include "Kunai.hpp"
namespace Sagar
{
		Kunai::Kunai(sf::Texture& texture)
		{
				kunai.setTexture(texture);
				kunai.setScale(0.6,0.6);
		}
		void Kunai::Update(float dt)
		{
				kunai.move(kunaiSpeed * dt,0);
		}
		void Kunai::Draw(sf::RenderWindow& window)
		{
				window.draw(kunai);
		}
}
