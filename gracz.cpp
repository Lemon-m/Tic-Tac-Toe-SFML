#include "gracz.h"

Gracz::Gracz(const int& x, const int& y, const bool& tura, Plansza &plansza)
{
	_typGracza = tura;

	if (!tura) // kolko
	{
		_kolko.setRadius(35.f);
		_kolko.setFillColor(sf::Color::Transparent);
		_kolko.setOutlineThickness(6.f);
		_kolko.setOutlineColor(sf::Color::Blue);
		_kolko.setOrigin(sf::Vector2f(_kolko.getRadius(), _kolko.getRadius()));
		_kolko.setPosition(sf::Vector2f(500.f + 100.f * x, 300.f + 100.f * y));
	}
	else if (tura) // krzyzyk
	{
		_krzyzyk[0].setSize(sf::Vector2f(113.f, 6.f));
		_krzyzyk[0].setOrigin(sf::Vector2f(56.5f, 3.f));
		_krzyzyk[0].rotate(45.f);
		_krzyzyk[0].setPosition(sf::Vector2f(500.f + 100.f * x, 300.f + 100.f * y));
		_krzyzyk[0].setFillColor(sf::Color::Red);
		_krzyzyk[1].setSize(sf::Vector2f(113.f, 6.f));
		_krzyzyk[1].setOrigin(sf::Vector2f(56.5f, 3.f));
		_krzyzyk[1].rotate(135.f);
		_krzyzyk[1].setPosition(sf::Vector2f(500.f + 100.f * x, 300.f + 100.f * y));
		_krzyzyk[1].setFillColor(sf::Color::Red);
	}

	plansza.setPole(x, y, tura);
}

void Gracz::rysujGracza(sf::RenderWindow& window)
{
	if (!_typGracza)
	{
		window.draw(_kolko);
	}
	else if (_typGracza)
	{
		window.draw(_krzyzyk[0]);
		window.draw(_krzyzyk[1]);
	}
}