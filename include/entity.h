#ifndef _ENTITY_H_
#define _ENTITY_H_


#include "allComponents.h"
#include <map>
#include <SFML/Graphics.hpp>
class Entity
{
public:
  Entity(int id);
  ~Entity();

  int getID(){return id;}
  bool hasComponent(constants::ComponentType type);
  void addComponent(Component* c);
  void removeComponent(constants::ComponentType type); //eventually enum
  void removeAllComponents();
  Component* getComponent(constants::ComponentType type);
  bool getComponent(constants::ComponentType type, Component * &component); //safer implementation of Component* getComponent();

  void setXY(sf::Vector2f Newxy);
  sf::Vector2f getXY(){return xy;}

  void move(float time);
  void receiveInput(constants::Input input, void *extra_data = NULL);

  sf::FloatRect* getBoundingBox(){return boundingBox;}
  void setBoundingBox(sf::FloatRect *bb){delete boundingBox; boundingBox = bb;}

private:
  std::map<constants::ComponentType, Component*> componentMap;
  int id;
  sf::Vector2f xy;
  sf::FloatRect *boundingBox;

};

#endif
