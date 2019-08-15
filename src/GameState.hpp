#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Character.hpp"
#include "Ground.hpp"
#include "Collider.hpp"
namespace Sagar
{
		class GameState: public State
		{
				public:
						GameState(GameDataRef data);
						void Init();
						void HandleInput();
						void Update(float dt);
						void Draw(float dt);

				private:
						GameDataRef _data;
						sf::Clock _clock;
						sf::Sprite _background;

						sf::Music _music;

						Character *character;
						Ground *ground1;

		};
}
