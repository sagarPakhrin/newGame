#include <SFML/Graphics.hpp>
#include "Collider.hpp"

/* delte this */ 
#include <iostream>

namespace Sagar
{
		Collider::Collider(sf::Sprite& player):player(player)
		{
		}
		bool Collider::CheckCollision(Collider& other, sf::Vector2f& dirn, float push)
		{
				/* GetPosition is my own function */
				sf::Vector2f otherPosition = other.GetPosition();

				/* GetHalfSize is my own function */
				sf::Vector2f otherHalfSize = other.GetHalfSize();

				sf::Vector2f thisPosition = GetPosition();
				sf::Vector2f thisHalfSize = GetHalfSize();

				float deltaX = otherPosition.x - thisPosition.x;
				float deltaY = otherPosition.y - thisPosition.y;

				float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
				float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

				if(intersectX < 0.0f && intersectY < 0.0f)
				{
						push = std::min(std::max(push, 0.0f),1.0f);

						if(intersectX > intersectY)
						{
								if(deltaX > 0.0f)
								{
										Move(intersectX * (1.0f - push),0.0f);
										other.Move(-intersectX * push,0.0f);

										dirn.x = 1.0f;
										dirn.y = 0.0f;
								}
								else
								{
										Move(-intersectX * (1.0f - push),0.0f);
										other.Move(intersectX * push,0.0f);

										dirn.x = -1.0f;
										dirn.y = 0.0f;
								}
						}
						else
						{
								if(deltaY > 0.0f)
								{
										Move(0.0f,intersectY * (1.0f - push));
										other.Move(0.0f,-intersectY * push);

										dirn.x = 0.0f;
										dirn.y = 1.0f;
								}
								else
								{
										Move(0.0f,-intersectY * (1.0f - push));
										other.Move(0.0f,intersectY * push);

										dirn.x = 0.0f;
										dirn.y = -1.0f;
								}
						}

						return true;
				}

				return false;
		}
		sf::Vector2f Collider::GetHalfSize()
		{
				sf::Vector2f size;
				size.x = static_cast<float>(player.getTexture()->getSize().x/2.0f);
				size.y = static_cast<float>(player.getTexture()->getSize().y/2.0f);
				return size;
		}


		sf::Vector2f Collider::GetCharacterHalfSize()
		{
				sf::Vector2f size;
				size.x = static_cast<float>(player.getTexture()->getSize().x*0.3f/2.0f);
				size.y = static_cast<float>(player.getTexture()->getSize().y*0.3f/2.0f);
				return size;
		}



		bool Collider::MyCollisionDetectoer(sf::Sprite sprite1, sf::Sprite sprite2)
		{
				sf::Rect<float> rect1 = sprite1.getGlobalBounds();
				sf::Rect<float> rect2 = sprite2.getGlobalBounds();
				if(rect1.intersects(rect2))
						return true;
				return false;
		}
}
