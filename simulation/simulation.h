#pragma once

#include "common.h"
#include "entity.h"
#include <vector>

class Simulation
{
public:
  Simulation();
  void start();
  void addEntity(Entity ent);

private:
  std::vector<Entity> entities;
};
