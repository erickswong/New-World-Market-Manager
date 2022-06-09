#include <gtest/gtest.h>

#include "recipes/recipe.h"

TEST(TestCaseName, TestName) {
	Recipe recipe;
	recipe.addIngredient("Ingredient 1", 1);

	EXPECT_EQ(1, recipe.get().size());
}