#include "Kunai.hpp"
namespace Sagar
{
		Kunai::Kunai(sf::Texture tex)
		{
				kunai.setTexture(tex);
		}
		void Kunai::Update(float dt)
		{

		}
		void Kunai::Draw()
		{
				_data->window.draw(kunai);
		}
}
