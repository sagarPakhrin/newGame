#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINATIONS.hpp"
#include <iostream>

namespace Sagar
{
		SplashState::SplashState(GameDataRef data): _data(data)
		{

		}

		void SplashState::Init()
		{
				_data->assets.LoadTexture("Splash State Background",SPLASH_SCENE_BACKGROUND_FILEPATH);
				_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
				_background.setOrigin(_background.getGlobalBounds().width/2.0f,_background.getGlobalBounds().height/2.0f);
				_background.setPosition(_data->window.getSize().x/2,_data->window.getSize().y/2);
		}

		void SplashState::HandleInput()
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


		void SplashState::Update(float dt)
		{
				if( _clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME )
				{
						_data->machine.AddState(StateRef (new MainMenuState(_data)), true);
				}
		}

		void SplashState::Draw(float dt)
		{
				_data->window.clear(sf::Color(0,0,0));
				_data->window.draw(_background);
				_data->window.display();
		}

}
