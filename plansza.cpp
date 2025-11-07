#include "plansza.h"
#include <iostream>

Plansza::Plansza()
{
	_linie[0].setSize(sf::Vector2f(300.f, 2.f));
	_linie[1].setSize(sf::Vector2f(300.f, 2.f));
	_linie[2].setSize(sf::Vector2f(2.f, 300.f));
	_linie[3].setSize(sf::Vector2f(2.f, 300.f));

	_linie[0].setPosition(sf::Vector2f(450.f, 349.f));
	_linie[1].setPosition(sf::Vector2f(450.f, 449.f));
	_linie[2].setPosition(sf::Vector2f(549.f, 250.f));
	_linie[3].setPosition(sf::Vector2f(649.f, 250.f));


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			_plansza[i][j] = 0;

			_pola[i][j].setSize(sf::Vector2f(100.f, 100.f));
			_pola[i][j].setPosition(sf::Vector2f(450.f + j * 100.f, 250.f + i * 100.f));
		}
	}
}

void Plansza::rysujPlansze(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(_linie[i]);
	}

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		window.draw(_pola[i][j]);
	//	}
	//}
}

int* Plansza::obslugaKlikniec(sf::RenderWindow& window, const bool& tura)
{
	sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	int indeksy[2] = { 3, 3 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sf::FloatRect bounds = _pola[i][j].getGlobalBounds();

			if (bounds.contains(mouse))
			{
				indeksy[0] = j;
				indeksy[1] = i;

				return indeksy;
			}
		}
	}

	return indeksy;
}

bool Plansza::czyPoleZapelnione(const int& x, const int& y)
{
	if (_plansza[x][y] == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int Plansza::getPole(const int& x, const int& y)
{
	return _plansza[x][y];
}


void Plansza::setPole(const int& x, const int& y, const bool& tura)
{
	if (_plansza[x][y] == 0)
	{
		if (!tura)
		{
			_plansza[x][y] = 1;
		}
		else if (tura)
		{
			_plansza[x][y] = 2;
		}
	}
}

bool Plansza::czyWygrana()
{
	
	for (int i = 0; i < 3; i++)
	{
		if (_plansza[i][0] == _plansza[i][1] && _plansza[i][1] == _plansza[i][2] && _plansza[i][0] != 0)
		{
			return true;
		}
		else if (_plansza[0][i] == _plansza[1][i] && _plansza[1][i] == _plansza[2][i] && _plansza[0][i] != 0)
		{
			return true;
		}
	}

	if (_plansza[0][0] == _plansza[1][1] && _plansza[1][1] == _plansza[2][2] && _plansza[0][0] != 0)
	{
		return true;
	}
	else if (_plansza[0][2] == _plansza[1][1] && _plansza[1][1] == _plansza[2][0] && _plansza[0][2] != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
