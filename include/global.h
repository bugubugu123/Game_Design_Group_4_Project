#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include "config.h"
#include "logicSystem.h"
#include "entityCreator.h"

namespace global_internal{ //this namespace is not supposed to use outside the file
  class GameEngine { //used to store some information for run-time
    public:
      GameEngine(){}
      LogicSystem *logicSystem;
      EntityCreator *entityCreator;
      constants::GameState gameState;
      int mainMenuState;
      int levelMenuState;
      int optionsMenuState;
  };
}


class Global {

    static Global *singleton;

  public:
    Config config;
    global_internal::GameEngine gameEngine;
    static Global *getSingleton(){return singleton;}
    static void init(){singleton = new Global();}
};

static Global *global(){
  return Global::getSingleton();
}

#endif
