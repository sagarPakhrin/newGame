#pragma once
namespace Sagar
{
		class Collider{
				public:
						Collider(sf::Sprite &player);
						~Collider(){};

						void Move(float dx,float dy){player.move(dx,dy);}
						bool CheckCollision(Collider& other, sf::Vector2f& dirn, float push);
						sf::Vector2f GetPosition(){return player.getPosition();}
						sf::Vector2f GetHalfSize(){return static_cast<sf::Vector2f>(player.getTexture()->getSize());}
				private:
						sf::Sprite player;
		};
}
