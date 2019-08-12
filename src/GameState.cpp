#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINATIONS.hpp"
#include <iostream>

namespace Sagar
{
		GameState::GameState(GameDataRef data): _data(data)
		{

		}

		void GameState::Init()
		{
				_data->assets.LoadTexture("Game Background",GAME_BACKGROUND_FILE_PATH);
				_data->assets.LoadTexture("idle_frame_0",IDLE_SPRITE_0);
				_data->assets.LoadTexture("idle_frame_1",IDLE_SPRITE_1);
				_data->assets.LoadTexture("idle_frame_2",IDLE_SPRITE_2);
				_data->assets.LoadTexture("idle_frame_3",IDLE_SPRITE_3);
				_data->assets.LoadTexture("idle_frame_4",IDLE_SPRITE_4);
				_data->assets.LoadTexture("idle_frame_5",IDLE_SPRITE_5);
				_data->assets.LoadTexture("idle_frame_6",IDLE_SPRITE_6);
				_data->assets.LoadTexture("idle_frame_7",IDLE_SPRITE_7);
				_data->assets.LoadTexture("idle_frame_8",IDLE_SPRITE_8);
				_data->assets.LoadTexture("idle_frame_9",IDLE_SPRITE_9);

				character = new Character(_data);
		}

		void GameState::HandleInput()
		{
				sf::Event event;
				while(_data->window.pollEvent(event))
				{
						if(sf::Event::Closed == event.type)
						{
								_data->window.close();
						}
				}
		}


		void GameState::Update(float dt)
		{
				character->Animate(dt);
				character->Update(dt);
		}

		void GameState::Draw(float dt)
		{
				_data->window.clear(sf::Color(255,255,255));
				_data->window.draw(_background);

				character->Draw();
				_data->window.display();
		}
}
