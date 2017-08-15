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

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
