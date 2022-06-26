module recipe_book:default_recipe_book;

import recipe_book;

namespace recipe_book::default_recipe_book {
	void setUp() {
		reset();

		addRefinedResources();
	}

	void addRefinedResources() {
		addIngots();
		addPlanks();
		addCloths();
		addLeathers();
		addBlocks();
	}

	void addIngots() {
		addRecipe(
			Recipe("Charcoal")
			.addIngredient("Green Wood", 2)
		);
		addRecipe(
			Recipe("Charcoal")
			.addIngredient("Aged Wood", 2)
		);
		addRecipe(
			Recipe("Charcoal")
			.addIngredient("Wyrdwood", 2)
		);
		addRecipe(
			Recipe("Charcoal")
			.addIngredient("Ironwood", 2)
		);
		addRecipe(
			Recipe("Iron Ingot")
			.addIngredient("Iron Ore", 4)
		);
		addRecipe(
			Recipe("Steel Ingot")
			.addIngredient("Iron Ingot", 3)
			.addIngredient("Charcoal", 2)
			.addIngredient("Obsidian Flux", 1)
		);
		addRecipe(
			Recipe("Starmetal Ingot")
			.addIngredient("Starmetal Ore", 6)
			.addIngredient("Steel Ingot", 2)
			.addIngredient("Charcoal", 2)
			.addIngredient("Obsidian Flux", 1)
		);
		addRecipe(
			Recipe("Orichalcum Ingot")
			.addIngredient("Orichalcum Ore", 8)
			.addIngredient("Starmetal Ingot", 2)
			.addIngredient("Charcoal", 2)
			.addIngredient("Obsidian Flux", 1)
		);
		addRecipe(
			Recipe("Orichalcum Ingot")
			.addIngredient("Orichalcum Ore", 8)
			.addIngredient("Platinum Ingot", 3)
			.addIngredient("Charcoal", 2)
			.addIngredient("Obsidian Flux", 1)
		);
		addRecipe(
			Recipe("Silver Ingot")
			.addIngredient("Silver Ore", 4)
		);
		addRecipe(
			Recipe("Gold Ingot")
			.addIngredient("Gold Ore", 5)
			.addIngredient("Silver Ingot", 2)
			.addIngredient("Obsidian Flux", 1)
		);
		addRecipe(
			Recipe("Platinum Ingot")
			.addIngredient("Platinum Ore", 6)
			.addIngredient("Gold Ingot", 2)
			.addIngredient("Obsidian Flux", 1)
		);
		addRecipe(
			Recipe("Asmodeum")
			.addIngredient("Orichalcum Ingot", 5)
			.addIngredient("Tolvium", 1)
			.addIngredient("Cinnabar", 1)
			.addIngredient("Obsidian Flux", 1)
			.addIngredient("Charcoal", 2)
		);
	}

	void addPlanks() {
		addRecipe(
			Recipe("Timber")
			.addIngredient("Green Wood", 4)
		);
		addRecipe(
			Recipe("Lumber")
			.addIngredient("Aged Wood", 4)
			.addIngredient("Timber", 2)
			.addIngredient("Obsidian Sandpaper", 1)
		);
		addRecipe(
			Recipe("Wyrdwood Planks")
			.addIngredient("Wyrdwood", 6)
			.addIngredient("Lumber", 2)
			.addIngredient("Obsidian Sandpaper", 1)
		);
		addRecipe(
			Recipe("Ironwood Planks")
			.addIngredient("Ironwood", 8)
			.addIngredient("Wyrdwood Planks", 2)
			.addIngredient("Obsidian Sandpaper", 1)
		);
		addRecipe(
			Recipe("Glittering Ebony")
			.addIngredient("Ironwood Planks", 5)
			.addIngredient("Wildwood", 1)
			.addIngredient("Barbvine", 1)
			.addIngredient("Obsidian Sandpaper", 1)
		);
	}

	void addCloths() {
		addRecipe(
			Recipe("Linen")
			.addIngredient("Fibers", 4)
		);
		addRecipe(
			Recipe("Sateen")
			.addIngredient("Linen", 4)
			.addIngredient("Wireweave", 1)
		);
		addRecipe(
			Recipe("Silk")
			.addIngredient("Silk Threads", 6)
			.addIngredient("Sateen", 2)
			.addIngredient("Wireweave", 1)
		);
		addRecipe(
			Recipe("Infused Silk")
			.addIngredient("Wirefiber", 8)
			.addIngredient("Silk", 2)
			.addIngredient("Wireweave", 1)
		);
		addRecipe(
			Recipe("Phoenixweave")
			.addIngredient("Infused Silk", 5)
			.addIngredient("Scalecloth", 1)
			.addIngredient("Blisterweave", 1)
			.addIngredient("Wireweave", 1)
		);
	}

	void addLeathers() {
		addRecipe(
			Recipe("Coarse Leather")
			.addIngredient("Rawhide", 4)
		);
		addRecipe(
			Recipe("Rugged Leather")
			.addIngredient("Coarse Leather", 4)
			.addIngredient("Aged Tannin", 1)
		);
		addRecipe(
			Recipe("Layered Leather")
			.addIngredient("Thick Hide", 6)
			.addIngredient("Rugged Leather", 2)
			.addIngredient("Aged Tannin", 1)
		);
		addRecipe(
			Recipe("Infused Leather")
			.addIngredient("Iron Hide", 8)
			.addIngredient("Layered Leather", 2)
			.addIngredient("Aged Tannin", 1)
		);
		addRecipe(
			Recipe("Runic Leather")
			.addIngredient("Infused Leather", 5)
			.addIngredient("Smolderhide", 1)
			.addIngredient("Scarhide", 1)
			.addIngredient("Aged Tannin", 1)
		);
	}

	void addBlocks() {
		addRecipe(
			Recipe("Stone Block")
			.addIngredient("Stone", 4)
		);
		addRecipe(
			Recipe("Stone Brick")
			.addIngredient("Stone Block", 4)
			.addIngredient("Obsidian Sandpaper", 1)
		);
		addRecipe(
			Recipe("Lodestone Brick")
			.addIngredient("Lodestone", 6)
			.addIngredient("Stone Brick", 2)
			.addIngredient("Obsidian Sandpaper", 1)
		);
		addRecipe(
			Recipe("Obsidian Voidstone")
			.addIngredient("Lodestone Brick", 8)
			.addIngredient("Lodestone", 2)
			.addIngredient("Obsidian Sandpaper", 1)
		);
		addRecipe(
			Recipe("Runestone")
			.addIngredient("Obsidian Voidstone", 5)
			.addIngredient("Obsidian Sandpaper", 1)
			.addIngredient("Elemental Lodestone", 1)
		);
	}
}
