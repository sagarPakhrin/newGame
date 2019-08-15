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


				_data->assets.LoadTexture("attack_frame_0",ATTACK_SPRITE_0);
				_data->assets.LoadTexture("attack_frame_1",ATTACK_SPRITE_1);
				_data->assets.LoadTexture("attack_frame_2",ATTACK_SPRITE_2);
				_data->assets.LoadTexture("attack_frame_3",ATTACK_SPRITE_3);
				_data->assets.LoadTexture("attack_frame_4",ATTACK_SPRITE_4);
				_data->assets.LoadTexture("attack_frame_5",ATTACK_SPRITE_5);
				_data->assets.LoadTexture("attack_frame_6",ATTACK_SPRITE_6);
				_data->assets.LoadTexture("attack_frame_7",ATTACK_SPRITE_7);
				_data->assets.LoadTexture("attack_frame_8",ATTACK_SPRITE_8);
				_data->assets.LoadTexture("attack_frame_9",ATTACK_SPRITE_9);


				_data->assets.LoadTexture("run_frame_0", RUN_SPRITE_0);
				_data->assets.LoadTexture("run_frame_1", RUN_SPRITE_1);
				_data->assets.LoadTexture("run_frame_2", RUN_SPRITE_2);
				_data->assets.LoadTexture("run_frame_3", RUN_SPRITE_3);
				_data->assets.LoadTexture("run_frame_4", RUN_SPRITE_4);
				_data->assets.LoadTexture("run_frame_5", RUN_SPRITE_5);
				_data->assets.LoadTexture("run_frame_6", RUN_SPRITE_6);
				_data->assets.LoadTexture("run_frame_7", RUN_SPRITE_7);
				_data->assets.LoadTexture("run_frame_8", RUN_SPRITE_8);
				_data->assets.LoadTexture("run_frame_9", RUN_SPRITE_9);

				_data->assets.LoadTexture("jump_frame_0", JUMP_SPRITE_0);
				_data->assets.LoadTexture("jump_frame_1", JUMP_SPRITE_1);
				_data->assets.LoadTexture("jump_frame_2", JUMP_SPRITE_2);
				_data->assets.LoadTexture("jump_frame_3", JUMP_SPRITE_3);
				_data->assets.LoadTexture("jump_frame_4", JUMP_SPRITE_4);
				_data->assets.LoadTexture("jump_frame_5", JUMP_SPRITE_5);
				_data->assets.LoadTexture("jump_frame_6", JUMP_SPRITE_6);
				_data->assets.LoadTexture("jump_frame_7", JUMP_SPRITE_7);
				_data->assets.LoadTexture("jump_frame_8", JUMP_SPRITE_8);
				_data->assets.LoadTexture("jump_frame_9", JUMP_SPRITE_9);


				_data->assets.LoadTexture("slide_frame_0", SLIDE_SPRITE_0);
				_data->assets.LoadTexture("slide_frame_1", SLIDE_SPRITE_1);
				_data->assets.LoadTexture("slide_frame_2", SLIDE_SPRITE_2);
				_data->assets.LoadTexture("slide_frame_3", SLIDE_SPRITE_3);
				_data->assets.LoadTexture("slide_frame_4", SLIDE_SPRITE_4);
				_data->assets.LoadTexture("slide_frame_5", SLIDE_SPRITE_5);
				_data->assets.LoadTexture("slide_frame_6", SLIDE_SPRITE_6);
				_data->assets.LoadTexture("slide_frame_7", SLIDE_SPRITE_7);
				_data->assets.LoadTexture("slide_frame_8", SLIDE_SPRITE_8);
				_data->assets.LoadTexture("slide_frame_9", SLIDE_SPRITE_9);


				_data->assets.LoadTexture("throw_frame_0", THROW_SPRITE_0);
				_data->assets.LoadTexture("throw_frame_1", THROW_SPRITE_1);
				_data->assets.LoadTexture("throw_frame_2", THROW_SPRITE_2);
				_data->assets.LoadTexture("throw_frame_3", THROW_SPRITE_3);
				_data->assets.LoadTexture("throw_frame_4", THROW_SPRITE_4);
				_data->assets.LoadTexture("throw_frame_5", THROW_SPRITE_5);
				_data->assets.LoadTexture("throw_frame_6", THROW_SPRITE_6);
				_data->assets.LoadTexture("throw_frame_7", THROW_SPRITE_7);
				_data->assets.LoadTexture("throw_frame_8", THROW_SPRITE_8);
				_data->assets.LoadTexture("throw_frame_9", THROW_SPRITE_9);

				_data->assets.LoadTexture("ground_image", GROUND_FILE_PATH);

				if(_music.openFromFile(GAME_MUSIC))
				{
						_music.play();
				}


				_background.setTexture(this->_data->assets.GetTexture("Game Background"));
				_background.setScale(0.7,0.7);
				character = new Character(_data);
				ground1 = new Ground(_data);
		}

		void GameState::HandleInput()
		{
				sf::Event event;
				while(_data->window.pollEvent(event))
				{
						if(sf::Event::Closed == event.type)
						{
								_music.stop();
								_data->window.close();
						}
				}
		}

		void GameState::Update(float dt)
		{
				character->Update(dt);

				sf::Vector2f dirn;

				Collider groundCollider = ground1->GetCollider();
				Collider characterCollider = character->GetCollider();

				if(groundCollider.CheckCollision(characterCollider,dirn,1.0f))
						character->OnCollision(dirn);
		}

		void GameState::Draw(float dt)
		{
				_data->window.clear(sf::Color(255,255,255));
				_data->window.draw(_background);

				ground1->Draw();
				character->Draw();
				_data->window.display();
		}
}
