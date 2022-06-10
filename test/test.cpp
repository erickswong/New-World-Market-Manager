#include <gtest/gtest.h>

import recipes;

TEST(TestCaseName, TestName) {
	Recipe recipe;
	recipe.addIngredient("Ingredient 1", 1);

	EXPECT_EQ(1, recipe.get().size());
}