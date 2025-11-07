#pragma once

#include <SFML/Graphics.hpp>

#include "plansza.h"

class Gracz
{
	public:

		Gracz(const int& x, const int& y, const bool& tura, Plansza& plansza);

		void rysujGracza(sf::RenderWindow& window);

	protected:

		bool _typGracza;

		sf::CircleShape _kolko;

		sf::RectangleShape _krzyzyk[2];
};
