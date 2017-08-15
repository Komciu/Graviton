#include "gtest/gtest.h"
#include "simulation.h"

TEST(Simulation, start)
{
	Simulation sim;
	sim.start();
}

TEST(Simulation, addEntity)
{
	Simulation sim;
	Entity ent1;
	sim.addEntity(ent1);
}
