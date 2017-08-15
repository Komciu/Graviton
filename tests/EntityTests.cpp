#include <iostream>
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

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
