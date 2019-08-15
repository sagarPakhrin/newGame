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

				sf::Vector2f thisPosition = this->GetPosition();
				sf::Vector2f thisHalfSize = this->GetHalfSize();

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
}
