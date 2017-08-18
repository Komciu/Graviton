#include "gtest/gtest.h"
#include "entity.h"

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

TEST(Entity, getVectorTowardsTarget)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 1, 0});
	ASSERT_TRUE(ent1.getVectorTowardsTarget(ent2) == Vector3D(1, 1, 0));
	ASSERT_TRUE(ent2.getVectorTowardsTarget(ent1) == Vector3D(-1, -1, 0));
}

/*
TEST(Entity, calcForceToAnotherEntity)
{
	Entity ent1({0, 0, 0});
	Entity ent2({1, 1, 0});
	double G = 9.8;
	double r = ent1.getDistanceTo(ent2);
	double force12 = G * ent1.getMass() * ent2.getMass() / r*r;
	ent1.addForce()
	ASSERT_NEAR(ent1.addForce)
}
*/
