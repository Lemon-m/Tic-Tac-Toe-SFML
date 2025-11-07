#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "plansza.h"
#include "gracz.h"

int main()
{
    sf::Font arial;

    if (!arial.loadFromFile("arial.ttf"))
    {
        std::cerr << "Couldn't load font\n";
        return -1;
    }

    Plansza plansza;

    sf::Event event;

    std::vector<Gracz> symbole;

    bool tura = true;

    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Kó³ko i krzy¿yk");

    sf::Text text;
    text.setFont(arial);
    text.setCharacterSize(72);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                std::cout << "X: " << plansza.obslugaKlikniec(window, tura)[0] << " Y: " << plansza.obslugaKlikniec(window, tura)[1] << "\n";

                if (!plansza.czyPoleZapelnione(plansza.obslugaKlikniec(window, tura)[0], plansza.obslugaKlikniec(window, tura)[1]) && !plansza.czyWygrana())
                {
                    symbole.push_back(Gracz(plansza.obslugaKlikniec(window, tura)[0], plansza.obslugaKlikniec(window, tura)[1], tura, plansza));
                    if (plansza.czyWygrana())
                    {
                        if (!tura)
                        {
                            text.setString("Wygrana kolka");
                            sf::Vector2f textCenter(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
                            text.setOrigin(textCenter);
                            text.setPosition(sf::Vector2f(600.f, 125.f));
                        }
                        else if (tura)
                        {
                            text.setString("Wygrana krzyzyka");
                            sf::Vector2f textCenter(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
                            text.setOrigin(textCenter);
                            text.setPosition(sf::Vector2f(600.f, 125.f));
                        }

                    }
                    tura = !tura;
                }
            }
        }

        window.clear();
        plansza.rysujPlansze(window);
        for (int i = 0; i < symbole.size(); i++)
        {
            symbole[i].rysujGracza(window);
        }
        window.draw(text);
        window.display();
    }
}