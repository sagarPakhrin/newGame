#pragma once
namespace Sagar
{
		class Collider{
				public:
						Collider(sf::Sprite& player);
						~Collider(){};

						void Move(float dx,float dy){player.move(dx,dy);}
						bool CheckCollision(Collider& other, sf::Vector2f& dirn, float push);
						bool MyCollisionDetectoer(sf::Sprite sprite1, sf::Sprite sprite2);
						sf::Vector2f GetPosition(){return player.getPosition();}
						sf::Vector2f GetHalfSize();
						sf::Vector2f GetCharacterHalfSize();
				private:
						sf::Sprite player;
		};
}
