#include "gtest/gtest.h"
#include "entity.h"
#include <cmath>
#include <iostream>

using namespace std;

TEST(Entity, CreateEntity)
{
	Entity ent;
}

TEST(Entity, getPos)
{
	Entity ent;
	ASSERT_EQ(0, ent.getPos().x);
	ASSERT_EQ(0, ent.getPos().y);
	ASSERT_EQ(0, ent.getPos().z);
}

TEST(Entity, getPosChangedInitialPos)
{
	Entity ent({1, 2, 3});
	ASSERT_EQ(1, ent.getPos().x);
	ASSERT_EQ(2, ent.getPos().y);
	ASSERT_EQ(3, ent.getPos().z);
}

TEST(Entity, getVelocity)
{
	Entity ent;
	ent.setVelocity({1, 2, 3});
	ASSERT_EQ(1, ent.getVelocity().x);
	ASSERT_EQ(2, ent.getVelocity().y);
	ASSERT_EQ(3, ent.getVelocity().z);
}

TEST(Entity, getAcceleration)
{
	Entity ent;
	ent.setAcceleration({1, 2, 3});
	ASSERT_EQ(1, ent.getAcceleration().x);
	ASSERT_EQ(2, ent.getAcceleration().y);
	ASSERT_EQ(3, ent.getAcceleration().z);
}

TEST(Entity, updateWithNoAcceleration)
{
	Entity ent;
	ent.setVelocity({1, 0, 0});
	double frameDuration = 1; //1s , 0.001 == 1ms
	ent.setFrameDuration(frameDuration);
	ent.update();
	ASSERT_NEAR(1, ent.getPos().x, 0.01);
}

TEST(Entity, updateWithAcceleration)
{
	Entity ent;
	ent.setAcceleration({1, 0, 0});
	double frameDuration = 1; //1s , 0.001 == 1ms
	ent.setFrameDuration(frameDuration);
	ent.update();
	ASSERT_NEAR(0.5, ent.getPos().x, 0.01);
}

TEST(Entity, updateLoop)
{
	Entity ent;
	ent.setVelocity({1, 0, 0});
	for(int i = 0; i < 10; i++)
	{
		ent.update();
	}
	ASSERT_NEAR(0.01, ent.getPos().x, 0.001);
}

TEST(Entity, update_checkAllAxes)
{
	Entity ent;
	ent.setVelocity({1, 1, 1});
	ent.setFrameDuration(1);
	ent.update();
	ASSERT_NEAR(1, ent.getPos().x, 0.001);
	ASSERT_NEAR(1, ent.getPos().y, 0.001);
	ASSERT_NEAR(1, ent.getPos().z, 0.001);
}

TEST(Entity, getDistanceBetweenEntities1D)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 0, 0});
	ASSERT_EQ(1, ent1.getDistanceTo(ent2));
}

TEST(Entity, getDistanceBetweenEntities2D)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 1, 0});
ASSERT_NEAR(1.42, ent1.getDistanceTo(ent2), 0.01);
}

TEST(Entity, getDistanceBetweenEntities3D)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 1, 1});
	ASSERT_NEAR(1.73, ent1.getDistanceTo(ent2), 0.01);
}

TEST(Entity, getVersorTowardsTarget)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 1, 0});
	Entity ent3({2, 1, 0});
	Entity ent4({1, 1, 1});
	ASSERT_NEAR(ent1.getVersorTowards(ent2).x, 0.707, 0.01);
	ASSERT_NEAR(ent1.getVersorTowards(ent2).y, 0.707, 0.01);
	ASSERT_NEAR(ent1.getVersorTowards(ent2).z, 0, 0.01);
	ASSERT_NEAR(ent2.getVersorTowards(ent1).x, -0.707, 0.01);
	ASSERT_NEAR(ent2.getVersorTowards(ent1).y, -0.707, 0.01);
	ASSERT_NEAR(ent2.getVersorTowards(ent1).z, 0, 0.01);
	ASSERT_NEAR(ent1.getVersorTowards(ent3).x, 2/sqrt(5), 0.01);
	ASSERT_NEAR(ent1.getVersorTowards(ent3).y, 1/sqrt(5), 0.01);
	ASSERT_NEAR(ent1.getVersorTowards(ent3).z, 0, 0.01);
	ASSERT_NEAR(ent1.getVersorTowards(ent4).x, 1/sqrt(3), 0.01);
	ASSERT_NEAR(ent1.getVersorTowards(ent4).y, 1/sqrt(3), 0.01);
	ASSERT_NEAR(ent1.getVersorTowards(ent4).z, 1/sqrt(3), 0.01);
}

TEST(Entity, getForcesInfluencingEntity)
{
	Entity ent1;
	ent1.addForce({1, 0, 0}); //WHY DOES THAT WORK AND (1, 0, 0) does not?!
	ASSERT_EQ(ent1.getOutputForce(), Vector3D(1, 0, 0));
	ent1.addForce({-0.5, 0, 1});
	ASSERT_EQ(ent1.getOutputForce(), Vector3D(0.5, 0, 1));
}

TEST(Entity, calcForceToAnotherEntity)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 0, 0});
	double G = 10;
	double r = ent1.getDistanceTo(ent2);
	double force12 = G * ent1.getMass() * ent2.getMass() / r*r;
	Vector3D forceVector = ent1.getVersorTowards(ent2) * force12;
	ent1.addForce(forceVector);
	ASSERT_EQ(ent1.getOutputForce(), Vector3D(10, 0, 0));
}

TEST(Entity, calcForceToAnotherEntityIn3D)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 1, 1});
	double G = 1;
	double r = ent1.getDistanceTo(ent2);
	double force12 = G * ent1.getMass() * ent2.getMass() / r*r;
	Vector3D forceVector = ent1.getVersorTowards(ent2) * force12;
	ent1.addForce(forceVector);
	ASSERT_NEAR(ent1.getOutputForce().x, sqrt(3)/(sqrt(3)*sqrt(3)), 0.01);
	ASSERT_NEAR(ent1.getOutputForce().y, sqrt(3)/(sqrt(3)*sqrt(3)), 0.01);
	ASSERT_NEAR(ent1.getOutputForce().z, sqrt(3)/(sqrt(3)*sqrt(3)), 0.01);
}

TEST(Entity, simpleUpdateBasedOnForceApplied)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 0, 0});
	double G = 1;
	double r = ent1.getDistanceTo(ent2);
	double force12 = G * ent1.getMass() * ent2.getMass() / r*r;
	Vector3D forceVector = ent1.getVersorTowards(ent2) * force12;
	ent1.addForce(forceVector);
	ent1.setFrameDuration(1);
	ent1.update();
	ASSERT_EQ(ent1.getPos(), Vector3D(0.5, 0, 0));
}
