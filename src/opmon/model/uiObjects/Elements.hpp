/*
Elements.hpp
Author : Jlppc
File under licence GPL-3.0
http://opmon-game.ga
Contains the utils elements
*/
#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "../playercore/Player.hpp"

class Event;

/**
Classe définissant une carte d'un lieu en particulier
*/
class Map {
private:
  int layer1[];
  int layer2[];
  sf::Music *bg;
  //Event events;
  int w;
  int h;
  int layer3[];
  char **passArr;

  /**Le constructeur de copie ne doit pas etre utilsÃ©.
  Il est donc en privÃ©. Si tout de meme cette protection est inÃ©fficace,
  aucune definition n'est fournise de ce constructeur.*/
  Map(Map const &toCopy) = delete;

  std::vector<Event *> events;

  std::vector<int> animatedElements;
  std::vector<sf::Vector2f> elementsPos;
  std::vector<sf::Sprite> elementsSprites;
  std::vector<int> elementsCount;

public:
  Map(const int layer1[], const int layer2[], const int layer3[], int w, int h, const char *const *collisions,
      sf::Music *bg,
      std::vector<std::vector<sf::Texture> > const &animatedElements = std::vector<std::vector<sf::Texture> >(),
      std::vector<sf::Vector2f> const &elementsPos = std::vector<sf::Vector2f>());

  ~Map();

  int getH() const {
    return h;
  }

  int getW() const {
    return w;
  }

  char **getPassArr() const {
    return passArr;
  }

  const MapLayer *getLayer1() const {
    return layer1;
  }

  const MapLayer *getLayer2() const {
    return layer2;
  }

  const MapLayer *getLayer3() const {
    return layer3;
  }

  sf::Music *getBg() const {
    return bg;
  }

  void addEvent(Event *event) {
    events.push_back(event);
  }

  std::vector<Event *> getEvent(sf::Vector2i position) const;

  const std::vector<Event *> getEvents() const {
    return events;
  };

  void updateEvents(Player &player);

  void debugInfo();

  void updateElements(sf::RenderTexture &frame);
};


#endif // ELEMENTS_HPP
