#pragma once

#include <SFML/Graphics.hpp>


class Plansza
{
	public:

		Plansza();

		void rysujPlansze(sf::RenderWindow& window);

		int* obslugaKlikniec(sf::RenderWindow& window, const bool& tura);

		bool czyPoleZapelnione(const int& x, const int& y);

		int getPole(const int& x, const int& y);

		void setPole(const int& x, const int& y, const bool& tura);

		bool czyWygrana();

	protected:

		int _plansza[3][3]; // 1 - kolko | 2 - krzyzyk

		sf::RectangleShape _linie[4];

		sf::RectangleShape _pola[3][3];
};