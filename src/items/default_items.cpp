module items:default_items;

import items;

import :block;
import :cloth;
import :ingot;
import :leather;
import :plank;
import :raw_resource;
import :refining_component;

namespace items::default_items {
	void setUp() {
		reset();

		addResources();
		addArmourSets();

		analyze(itemUpdateOrder());
	}

	void addResources() {
		addRawResources();
		addRefinedResources();
		addRefiningComponents();
	}

	void addArmourSets() {
		addSmelterSet();
		addWoodworkerSet();
		addWeaverSet();
		addTannerSet();
		addStonecutterSet();
	}

	void addRawResources() {
		addOres();
		addWoods();
		addFibers();
		addRawhides();
		addStones();
	}

	void addRefinedResources() {
		addIngots();
		addPlanks();
		addCloths();
		addLeathers();
		addBlocks();
	}

	void addRefiningComponents() {
		addFluxes();
		addSandpapers();
		addTannins();
		addSolvents();
		addWeaves();
	}

	void addOres() {
		const auto iron_ore = new RawResource("Iron Ore",
											  ":/MarketManager/images/items/resources/raw_resources/ores/iron_ore.png",
											  1,
											  false,
											  0.35,
											  0.3);
		const auto starmetal_ore = new RawResource("Starmetal Ore",
												   ":/MarketManager/images/items/resources/raw_resources/ores/starmetal_ore.png",
												   4,
												   false,
												   1.3,
												   1.1);
		const auto orichalcum_ore = new RawResource("Orichalcum Ore",
													":/MarketManager/images/items/resources/raw_resources/ores/orichalcum_ore.png",
													5,
													false,
													2.5,
													2.2);
		const auto silver_ore = new RawResource("Silver Ore",
												":/MarketManager/images/items/resources/raw_resources/ores/silver_ore.png",
												2,
												false,
												0.2,
												0.15);
		const auto gold_ore = new RawResource("Gold Ore",
											  ":/MarketManager/images/items/resources/raw_resources/ores/gold_ore.png",
											  3,
											  false,
											  0.4,
											  0.25);
		const auto platinum_ore = new RawResource("Platinum Ore",
												  ":/MarketManager/images/items/resources/raw_resources/ores/platinum_ore.png",
												  4,
												  false,
												  1.,
												  0.75);
		const auto cinnabar = new RawResource("Cinnabar",
											  ":/MarketManager/images/items/resources/raw_resources/ores/cinnabar.png",
											  5,
											  true,
											  15.,
											  15.);
		const auto tolvium = new RawResource("Tolvium",
											 ":/MarketManager/images/items/resources/raw_resources/ores/tolvium.png",
											 5,
											 true,
											 15.,
											 15.);

		insert("Iron Ore", iron_ore);
		insert("Starmetal Ore", starmetal_ore);
		insert("Orichalcum Ore", orichalcum_ore);
		insert("Silver Ore", silver_ore);
		insert("Gold Ore", gold_ore);
		insert("Platinum Ore", platinum_ore);
		insert("Cinnabar", cinnabar);
		insert("Tolvium", tolvium);
	}

	void addWoods() {
		const auto green_wood = new RawResource("Green Wood",
												":/MarketManager/images/items/resources/raw_resources/woods/green_wood.png",
												1,
												false,
												0.25,
												0.2);
		const auto aged_wood = new RawResource("Aged Wood",
											   ":/MarketManager/images/items/resources/raw_resources/woods/aged_wood.png",
											   2,
											   false,
											   0.25,
											   0.2);
		const auto wyrdwood = new RawResource("Wyrdwood",
											  ":/MarketManager/images/items/resources/raw_resources/woods/wyrdwood.png",
											  4,
											  false,
											  1.1,
											  0.9);
		const auto ironwood = new RawResource("Ironwood",
											  ":/MarketManager/images/items/resources/raw_resources/woods/ironwood.png",
											  5,
											  false,
											  0.75,
											  0.6);
		const auto wildwood = new RawResource("Wildwood",
											  ":/MarketManager/images/items/resources/raw_resources/woods/wildwood.png",
											  5,
											  true,
											  10.,
											  10.);
		const auto barbvine = new RawResource("Barbvine",
											  ":/MarketManager/images/items/resources/raw_resources/woods/barbvine.png",
											  5,
											  true,
											  10.,
											  10.);

		insert("Green Wood", green_wood);
		insert("Aged Wood", aged_wood);
		insert("Wyrdwood", wyrdwood);
		insert("Ironwood", ironwood);
		insert("Wildwood", wildwood);
		insert("Barbvine", barbvine);
	}

	void addFibers() {
		const auto fibers = new RawResource("Fibers",
											":/MarketManager/images/items/resources/raw_resources/fibers/fibers.png",
											1,
											false,
											0.2,
											0.15);
		const auto silk_threads = new RawResource("Silk Threads",
												  ":/MarketManager/images/items/resources/raw_resources/fibers/silk_threads.png",
												  4,
												  false,
												  0.7,
												  0.5);
		const auto wirefiber = new RawResource("Wirefiber",
											   ":/MarketManager/images/items/resources/raw_resources/fibers/wirefiber.png",
											   5,
											   false,
											   0.6,
											   0.45);
		const auto blisterweave = new RawResource("Blisterweave",
												  ":/MarketManager/images/items/resources/raw_resources/fibers/blisterweave.png",
												  5,
												  true,
												  7.5,
												  7.5);
		const auto scalecloth = new RawResource("Scalecloth",
												":/MarketManager/images/items/resources/raw_resources/fibers/scalecloth.png",
												5,
												true,
												7.5,
												7.5);

		insert("Fibers", fibers);
		insert("Silk Threads", silk_threads);
		insert("Wirefiber", wirefiber);
		insert("Blisterweave", blisterweave);
		insert("Scalecloth", scalecloth);
	}

	void addRawhides() {
		const auto rawhide = new RawResource("Rawhide",
											 ":/MarketManager/images/items/resources/raw_resources/rawhide/rawhide.png",
											 1,
											 false,
											 0.35,
											 0.3);
		const auto thick_hide = new RawResource("Thick Hide",
												":/MarketManager/images/items/resources/raw_resources/rawhide/thick_hide.png",
												4,
												false,
												0.6,
												0.55);
		const auto iron_hide = new RawResource("Iron Hide",
											   ":/MarketManager/images/items/resources/raw_resources/rawhide/iron_hide.png",
											   5,
											   false,
											   0.1,
											   0.05);
		const auto smolderhide = new RawResource("Smolderhide",
												 ":/MarketManager/images/items/resources/raw_resources/rawhide/smolderhide.png",
												 5,
												 true,
												 15.,
												 15.);
		const auto scarhide = new RawResource("Scarhide",
											  ":/MarketManager/images/items/resources/raw_resources/rawhide/scarhide.png",
											  5,
											  true,
											  15.,
											  15.);

		insert("Rawhide", rawhide);
		insert("Thick Hide", thick_hide);
		insert("Iron Hide", iron_hide);
		insert("Smolderhide", smolderhide);
		insert("Scarhide", scarhide);
	}

	void addStones() {
		const auto stone = new RawResource("Stone",
										   ":/MarketManager/images/items/resources/raw_resources/stones/stone.png",
										   1,
										   false,
										   0.2,
										   0.15);
		const auto lodestone = new RawResource("Lodestone",
											   ":/MarketManager/images/items/resources/raw_resources/stones/lodestone.png",
											   4,
											   false,
											   0.6,
											   0.5);
		const auto elemental_lodestone = new RawResource("Elemental Lodestone",
														 ":/MarketManager/images/items/resources/raw_resources/stones/elemental_lodestone.png",
														 3,
														 true,
														 0.5,
														 0.1);

		insert("Stone", stone);
		insert("Lodestone", lodestone);
		insert("Elemental Lodestone", elemental_lodestone);
	}

	void addIngots() {
		addCharcoal();
		addIronIngot();
		addSteelIngot();
		addStarmetalIngot();
		addOrichalcumIngot();
		addSilverIngot();
		addGoldIngot();
		addPlatinumIngot();
		addAsmodeum();
	}

	void addPlanks() {
		addTimber();
		addLumber();
		addWyrdwoodPlanks();
		addIronwoodPlanks();
		addGlitteringEbony();
	}

	void addCloths() {
		addLinen();
		addSateen();
		addSilk();
		addInfusedSilk();
		addPhoenixweave();
	}

	void addLeathers() {
		addCoarseLeather();
		addRuggedLeather();
		addLayeredLeather();
		addInfusedLeather();
		addRunicLeather();
	}

	void addBlocks() {
		addStoneBlock();
		addStoneBrick();
		addLodestoneBrick();
		addObsidianVoidstone();
		addRunestone();
	}

	void addCharcoal() {
		Recipe recipe1;
		Recipe recipe2;
		Recipe recipe3;
		Recipe recipe4;
		Recipe recipe5;
		Recipe recipe6;
		Recipe recipe7;
		Recipe recipe8;
		Recipe recipe9;

		recipe1.addIngredient("Green Wood", 2);
		recipe2.addIngredient("Aged Wood", 2);
		recipe3.addIngredient("Wyrdwood", 2);
		recipe4.addIngredient("Ironwood", 2);
		recipe5.addIngredient("Timber", 2);
		recipe6.addIngredient("Lumber", 2);
		recipe7.addIngredient("Wyrdwood Planks", 2);
		recipe8.addIngredient("Ironwood Planks", 2);
		recipe9.addIngredient("Glittering Ebony", 2);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);
		recipes.addRecipe(recipe4);
		recipes.addRecipe(recipe5);
		recipes.addRecipe(recipe6);
		recipes.addRecipe(recipe7);
		recipes.addRecipe(recipe8);
		recipes.addRecipe(recipe9);

		auto charcoal = new Ingot("Charcoal",
								   ":/MarketManager/images/items/resources/refined_resources/ingots/charcoal.png",
								   2,
								   false,
								   0.4,
								   0.35,
								   1.,
								   0.01,
								   recipes);

		insert("Charcoal", charcoal);
	}

	void addIronIngot() {
		Recipe recipe1;

		recipe1.addIngredient("Iron Ore", 4);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto iron_ingot = new Ingot("Iron Ingot",
										  ":/MarketManager/images/items/resources/refined_resources/ingots/iron_ingot.png",
										  2,
										  true,
										  1.2,
										  1.2,
										  1.,
										  0.01,
										  recipes);

		insert("Iron Ingot", iron_ingot);
	}

	void addSteelIngot() {
		Recipe recipe;

		recipe.addIngredient("Iron Ingot", 3);
		recipe.addIngredient("Charcoal", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Flux", 1);
		recipe2.addIngredient("Shelldust Flux", 1);
		recipe3.addIngredient("Sand Flux", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto steel_ingot = new Ingot("Steel Ingot",
										   ":/MarketManager/images/items/resources/refined_resources/ingots/steel_ingot.png",
										   3,
										   true,
										   4.5,
										   4.5,
										   0.98,
										   0.04,
										   recipes);

		insert("Steel Ingot", steel_ingot);
	}

	void addStarmetalIngot() {
		Recipe recipe;

		recipe.addIngredient("Starmetal Ore", 6);
		recipe.addIngredient("Steel Ingot", 2);
		recipe.addIngredient("Charcoal", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Flux", 1);
		recipe2.addIngredient("Shelldust Flux", 1);
		recipe3.addIngredient("Sand Flux", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto starmetal_ingot = new Ingot("Starmetal Ingot",
											   ":/MarketManager/images/items/resources/refined_resources/ingots/starmetal_ingot.png",
											   4,
											   true,
											   13.,
											   13.,
											   0.95,
											   0.07,
											   recipes);

		insert("Starmetal Ingot", starmetal_ingot);
	}

	void addOrichalcumIngot() {
		Recipe recipe;

		recipe.addIngredient("Orichalcum Ore", 8);
		recipe.addIngredient("Starmetal Ingot", 2);
		recipe.addIngredient("Charcoal", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Flux", 1);
		recipe2.addIngredient("Shelldust Flux", 1);
		recipe3.addIngredient("Sand Flux", 1);

		recipe = Recipe();

		recipe.addIngredient("Orichalcum Ore", 8);
		recipe.addIngredient("Platinum Ingot", 3);
		recipe.addIngredient("Charcoal", 2);

		Recipe recipe4 = recipe;
		Recipe recipe5 = recipe;
		Recipe recipe6 = recipe;

		recipe4.addIngredient("Obsidian Flux", 1);
		recipe5.addIngredient("Shelldust Flux", 1);
		recipe6.addIngredient("Sand Flux", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);
		recipes.addRecipe(recipe4);
		recipes.addRecipe(recipe5);
		recipes.addRecipe(recipe6);

		auto orichalcum_ingot = new Ingot("Orichalcum Ingot",
										   ":/MarketManager/images/items/resources/refined_resources/ingots/orichalcum_ingot.png",
										   5,
										   true,
										   40.,
										   40.,
										   0.93,
										   0.13,
										   recipes);

		insert("Orichalcum Ingot", orichalcum_ingot);
	}

	void addSilverIngot() {
		Recipe recipe1;

		recipe1.addIngredient("Silver Ore", 4);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto silver_ingot = new Ingot("Silver Ingot",
											":/MarketManager/images/items/resources/refined_resources/ingots/silver_ingot.png",
											2,
											true,
											0.6,
											0.6,
											0.98,
											0.01,
											recipes);

		insert("Silver Ingot", silver_ingot);
	}

	void addGoldIngot() {
		Recipe recipe;

		recipe.addIngredient("Gold Ore", 5);
		recipe.addIngredient("Silver Ingot", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Flux", 1);
		recipe2.addIngredient("Shelldust Flux", 1);
		recipe3.addIngredient("Sand Flux", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto gold_ingot = new Ingot("Gold Ingot",
										  ":/MarketManager/images/items/resources/refined_resources/ingots/gold_ingot.png",
										  3,
										  true,
										  3.75,
										  3.75,
										  0.95,
										  0.04,
										  recipes);

		insert("Gold Ingot", gold_ingot);
	}

	void addPlatinumIngot() {
		Recipe recipe;

		recipe.addIngredient("Platinum Ore", 6);
		recipe.addIngredient("Gold Ingot", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Flux", 1);
		recipe2.addIngredient("Shelldust Flux", 1);
		recipe3.addIngredient("Sand Flux", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto platinum_ingot = new Ingot("Platinum Ingot",
											  ":/MarketManager/images/items/resources/refined_resources/ingots/platinum_ingot.png",
											  4,
											  true,
											  11.,
											  11.,
											  0.93,
											  0.07,
											  recipes);

		insert("Platinum Ingot", platinum_ingot);
	}

	void addAsmodeum() {
		Recipe recipe1;

		recipe1.addIngredient("Orichalcum Ingot", 5);
		recipe1.addIngredient("Tolvium", 1);
		recipe1.addIngredient("Cinnabar", 1);
		recipe1.addIngredient("Obsidian Flux", 1);
		recipe1.addIngredient("Charcoal", 2);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto asmodeum = new Ingot("Asmodeum",
										":/MarketManager/images/items/resources/refined_resources/ingots/asmodeum.png",
										5,
										true,
										300.,
										300.,
										0.8,
										0.19,
										recipes);

		insert("Asmodeum", asmodeum);
	}

	void addTimber() {
		Recipe recipe1;

		recipe1.addIngredient("Green Wood", 4);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto timber = new Plank("Timber",
									  ":/MarketManager/images/items/resources/refined_resources/planks/timber.png",
									  2,
									  true,
									  1.,
									  1.,
									  1.,
									  0.01,
									  recipes);

		insert("Timber", timber);
	}

	void addLumber() {
		Recipe recipe;

		recipe.addIngredient("Aged Wood", 4);
		recipe.addIngredient("Timber", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Sandpaper", 1);
		recipe2.addIngredient("Fine Sandpaper", 1);
		recipe3.addIngredient("Coarse Sandpaper", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto lumber = new Plank("Lumber",
									  ":/MarketManager/images/items/resources/refined_resources/planks/lumber.png",
									  3,
									  true,
									  2.2,
									  2.2,
									  0.98,
									  0.04,
									  recipes);

		insert("Lumber", lumber);
	}

	void addWyrdwoodPlanks() {
		Recipe recipe;

		recipe.addIngredient("Wyrdwood", 6);
		recipe.addIngredient("Lumber", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Sandpaper", 1);
		recipe2.addIngredient("Fine Sandpaper", 1);
		recipe3.addIngredient("Coarse Sandpaper", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto wyrdwood_planks = new Plank("Wyrdwood Planks",
											   ":/MarketManager/images/items/resources/refined_resources/planks/wyrdwood_planks.png",
											   4,
											   true,
											   8.5,
											   8.5,
											   0.95,
											   0.07,
											   recipes);

		insert("Wyrdwood Planks", wyrdwood_planks);
	}

	void addIronwoodPlanks() {
		Recipe recipe;

		recipe.addIngredient("Ironwood", 8);
		recipe.addIngredient("Wyrdwood Planks", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Sandpaper", 1);
		recipe2.addIngredient("Fine Sandpaper", 1);
		recipe3.addIngredient("Coarse Sandpaper", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto ironwood_planks = new Plank("Ironwood Planks",
											   ":/MarketManager/images/items/resources/refined_resources/planks/ironwood_planks.png",
											   5,
											   true,
											   16.,
											   16.,
											   0.93,
											   0.13,
											   recipes);

		insert("Ironwood Planks", ironwood_planks);
	}

	void addGlitteringEbony() {
		Recipe recipe1;

		recipe1.addIngredient("Ironwood Planks", 5);
		recipe1.addIngredient("Wildwood", 1);
		recipe1.addIngredient("Barbvine", 1);
		recipe1.addIngredient("Obsidian Sandpaper", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto glittering_ebony = new Plank("Glittering Ebony",
												":/MarketManager/images/items/resources/refined_resources/planks/glittering_ebony.png",
												5,
												true,
												70.,
												70.,
												0.8,
												0.19,
												recipes);

		insert("Glittering Ebony", glittering_ebony);
	}

	void addLinen() {
		Recipe recipe1;

		recipe1.addIngredient("Fibers", 4);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto linen = new Cloth("Linen",
									 ":/MarketManager/images/items/resources/refined_resources/cloths/linen.png",
									 2,
									 true,
									 1.,
									 1.,
									 1.,
									 0.01,
									 recipes);

		insert("Linen", linen);
	}

	void addSateen() {
		Recipe recipe;

		recipe.addIngredient("Linen", 4);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Wireweave", 1);
		recipe2.addIngredient("Silkweave", 1);
		recipe3.addIngredient("Crossweave", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto sateen = new Cloth("Sateen",
									  ":/MarketManager/images/items/resources/refined_resources/cloths/sateen.png",
									  3,
									  true,
									  2.,
									  2.,
									  0.98,
									  0.04,
									  recipes);

		insert("Sateen", sateen);
	}

	void addSilk() {
		Recipe recipe;

		recipe.addIngredient("Silk Threads", 6);
		recipe.addIngredient("Sateen", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Wireweave", 1);
		recipe2.addIngredient("Silkweave", 1);
		recipe3.addIngredient("Crossweave", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto silk = new Cloth("Silk",
									":/MarketManager/images/items/resources/refined_resources/cloths/silk.png",
									4,
									true,
									5.5,
									5.5,
									0.95,
									0.07,
									recipes);

		insert("Silk", silk);
	}

	void addInfusedSilk() {
		Recipe recipe;

		recipe.addIngredient("Wirefiber", 8);
		recipe.addIngredient("Silk", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Wireweave", 1);
		recipe2.addIngredient("Silkweave", 1);
		recipe3.addIngredient("Crossweave", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto infused_silk = new Cloth("Infused Silk",
											":/MarketManager/images/items/resources/refined_resources/cloths/infused_silk.png",
											5,
											true,
											13.,
											13.,
											0.93,
											0.13,
											recipes);

		insert("Infused Silk", infused_silk);
	}

	void addPhoenixweave() {
		Recipe recipe1;

		recipe1.addIngredient("Infused Silk", 5);
		recipe1.addIngredient("Scalecloth", 1);
		recipe1.addIngredient("Blisterweave", 1);
		recipe1.addIngredient("Wireweave", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto phoenixweave = new Cloth("Phoenixweave",
											":/MarketManager/images/items/resources/refined_resources/cloths/phoenixweave.png",
											5,
											true,
											145.,
											145.,
											0.8,
											0.19,
											recipes);

		insert("Phoenixweave", phoenixweave);
	}

	void addCoarseLeather() {
		Recipe recipe1;

		recipe1.addIngredient("Rawhide", 4);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto coarse_leather = new Leather("Coarse Leather",
												":/MarketManager/images/items/resources/refined_resources/leathers/coarse_leather.png",
												2,
												true,
												1.25,
												1.25,
												1.,
												0.01,
												recipes);

		insert("Coarse Leather", coarse_leather);
	}

	void addRuggedLeather() {
		Recipe recipe;

		recipe.addIngredient("Coarse Leather", 4);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Aged Tannin", 1);
		recipe2.addIngredient("Rested Tannin", 1);
		recipe3.addIngredient("Tannin", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto rugged_leather = new Leather("Rugged Leather",
												":/MarketManager/images/items/resources/refined_resources/leathers/rugged_leather.png",
												3,
												true,
												2.1,
												2.1,
												0.98,
												0.04,
												recipes);

		insert("Rugged Leather", rugged_leather);
	}

	void addLayeredLeather() {
		Recipe recipe;

		recipe.addIngredient("Thick Hide", 6);
		recipe.addIngredient("Rugged Leather", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Aged Tannin", 1);
		recipe2.addIngredient("Rested Tannin", 1);
		recipe3.addIngredient("Tannin", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto layered_leather = new Leather("Layered Leather",
												 ":/MarketManager/images/items/resources/refined_resources/leathers/layered_leather.png",
												 4,
												 true,
												 5.5,
												 5.5,
												 0.95,
												 0.07,
												 recipes);

		insert("Layered Leather", layered_leather);
	}

	void addInfusedLeather() {
		Recipe recipe;

		recipe.addIngredient("Iron Hide", 8);
		recipe.addIngredient("Layered Leather", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Aged Tannin", 1);
		recipe2.addIngredient("Rested Tannin", 1);
		recipe3.addIngredient("Tannin", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto infused_leather = new Leather("Infused Leather",
												 ":/MarketManager/images/items/resources/refined_resources/leathers/infused_leather.png",
												 5,
												 true,
												 8.2,
												 8.2,
												 0.93,
												 0.13,
												 recipes);

		insert("Infused Leather", infused_leather);
	}

	void addRunicLeather() {
		Recipe recipe1;

		recipe1.addIngredient("Infused Leather", 5);
		recipe1.addIngredient("Smolderhide", 1);
		recipe1.addIngredient("Scarhide", 1);
		recipe1.addIngredient("Aged Tannin", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto runic_leather = new Leather("Runic Leather",
											   ":/MarketManager/images/items/resources/refined_resources/leathers/runic_leather.png",
											   5,
											   true,
											   130.,
											   130.,
											   0.8,
											   0.19,
											   recipes);

		insert("Runic Leather", runic_leather);
	}

	void addStoneBlock() {
		Recipe recipe1;

		recipe1.addIngredient("Stone", 4);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto stone_block = new Leather("Stone Block",
											 ":/MarketManager/images/items/resources/refined_resources/blocks/stone_block.png",
											 2,
											 true,
											 1.,
											 1.,
											 1.,
											 0.01,
											 recipes);

		insert("Stone Block", stone_block);
	}

	void addStoneBrick() {
		Recipe recipe;

		recipe.addIngredient("Stone Block", 4);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Sandpaper", 1);
		recipe2.addIngredient("Fine Sandpaper", 1);
		recipe3.addIngredient("Coarse Sandpaper", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto stone_brick = new Block("Stone Brick",
										   ":/MarketManager/images/items/resources/refined_resources/blocks/stone_brick.png",
										   3,
										   true,
										   2.3,
										   2.3,
										   0.98,
										   0.04,
										   recipes);

		insert("Stone Brick", stone_brick);
	}

	void addLodestoneBrick() {
		Recipe recipe;

		recipe.addIngredient("Lodestone", 6);
		recipe.addIngredient("Stone Brick", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Sandpaper", 1);
		recipe2.addIngredient("Fine Sandpaper", 1);
		recipe3.addIngredient("Coarse Sandpaper", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto lodestone_brick = new Block("Lodestone Brick",
											   ":/MarketManager/images/items/resources/refined_resources/blocks/lodestone_brick.png",
											   4,
											   true,
											   4.2,
											   4.2,
											   0.95,
											   0.07,
											   recipes);

		insert("Lodestone Brick", lodestone_brick);
	}

	void addObsidianVoidstone() {
		Recipe recipe;

		recipe.addIngredient("Lodestone Brick", 8);
		recipe.addIngredient("Lodestone", 2);

		Recipe recipe1 = recipe;
		Recipe recipe2 = recipe;
		Recipe recipe3 = recipe;

		recipe1.addIngredient("Obsidian Sandpaper", 1);
		recipe2.addIngredient("Fine Sandpaper", 1);
		recipe3.addIngredient("Coarse Sandpaper", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);
		recipes.addRecipe(recipe2);
		recipes.addRecipe(recipe3);

		const auto obsidian_voidstone = new Block("Obsidian Voidstone",
												  ":/MarketManager/images/items/resources/refined_resources/blocks/obsidian_voidstone.png",
												  5,
												  true,
												  25.,
												  25.,
												  0.93,
												  0.13,
												  recipes);

		insert("Obsidian Voidstone", obsidian_voidstone);
	}

	void addRunestone() {
		Recipe recipe1;

		recipe1.addIngredient("Obsidian Voidstone", 5);
		recipe1.addIngredient("Obsidian Sandpaper", 1);
		recipe1.addIngredient("Elemental Lodestone", 1);

		Recipes recipes;

		recipes.addRecipe(recipe1);

		const auto runestone = new Block("Runestone",
										 ":/MarketManager/images/items/resources/refined_resources/blocks/runestone.png",
										 5,
										 true,
										 64.,
										 64.,
										 0.8,
										 0.19,
										 recipes);

		insert("Runestone", runestone);
	}

	void addSmelterSet() {
		const auto smelters_headgear = new Item("Smelter's Headgear",
												":/MarketManager/images/armour_sets/smelter_set/smelters_headgear.png");
		const auto smelters_smock = new Item("Smelter's Smock",
											 ":/MarketManager/images/armour_sets/smelter_set/smelters_smock.png");
		const auto smelters_mitts = new Item("Smelter's Mitts",
											 ":/MarketManager/images/armour_sets/smelter_set/smelters_mitts.png");
		const auto smelters_pants = new Item("Smelter's Pants",
											 ":/MarketManager/images/armour_sets/smelter_set/smelters_pants.png");
		const auto smelters_shoes = new Item("Smelter's Shoes",
											 ":/MarketManager/images/armour_sets/smelter_set/smelters_shoes.png");

		insert("Smelter's Headgear", smelters_headgear);
		insert("Smelter's Smock", smelters_smock);
		insert("Smelter's Mitts", smelters_mitts);
		insert("Smelter's Pants", smelters_pants);
		insert("Smelter's Shoes", smelters_shoes);
	}

	void addWoodworkerSet() {
		const auto woodworkers_cap = new Item("Woodworker's Cap",
											  ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_cap.png");
		const auto woodworkers_shirt = new Item("Woodworker's Shirt",
												":/MarketManager/images/armour_sets/woodworker_set/woodworkers_shirt.png");
		const auto woodworkers_gloves = new Item("Woodworker's Gloves",
												 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_gloves.png");
		const auto woodworkers_pants = new Item("Woodworker's Pants",
												":/MarketManager/images/armour_sets/woodworker_set/woodworkers_pants.png");
		const auto woodworkers_shoes = new Item("Woodworker's Shoes",
												":/MarketManager/images/armour_sets/woodworker_set/woodworkers_shoes.png");

		insert("Woodworker's Cap", woodworkers_cap);
		insert("Woodworker's Shirt", woodworkers_shirt);
		insert("Woodworker's Gloves", woodworkers_gloves);
		insert("Woodworker's Pants", woodworkers_pants);
		insert("Woodworker's Shoes", woodworkers_shoes);
	}

	void addWeaverSet() {
		const auto weavers_hat = new Item("Weaver's Hat",
										  ":/MarketManager/images/armour_sets/weaver_set/weavers_hat.png");
		const auto weavers_shirt = new Item("Weaver's Shirt",
											":/MarketManager/images/armour_sets/weaver_set/weavers_shirt.png");
		const auto weavers_gloves = new Item("Weaver's Gloves",
											 ":/MarketManager/images/armour_sets/weaver_set/weavers_gloves.png");
		const auto weavers_pants = new Item("Weaver's Pants",
											":/MarketManager/images/armour_sets/weaver_set/weavers_pants.png");
		const auto weavers_shoes = new Item("Weaver's Shoes",
											":/MarketManager/images/armour_sets/weaver_set/weavers_shoes.png");

		insert("Weaver's Hat", weavers_hat);
		insert("Weaver's Shirt", weavers_shirt);
		insert("Weaver's Gloves", weavers_gloves);
		insert("Weaver's Pants", weavers_pants);
		insert("Weaver's Shoes", weavers_shoes);
	}

	void addTannerSet() {
		const auto tanner_hat = new Item("Tanner Hat",
										 ":/MarketManager/images/armour_sets/tanner_set/tanner_hat.png");
		const auto tanner_shirt = new Item("Tanner Shirt",
										   ":/MarketManager/images/armour_sets/tanner_set/tanner_shirt.png");
		const auto tanner_gloves = new Item("Tanner Gloves",
											":/MarketManager/images/armour_sets/tanner_set/tanner_gloves.png");
		const auto tanner_pants = new Item("Tanner Pants",
										   ":/MarketManager/images/armour_sets/tanner_set/tanner_pants.png");
		const auto tanner_shoes = new Item("Tanner Shoes",
										   ":/MarketManager/images/armour_sets/tanner_set/tanner_shoes.png");

		insert("Tanner Hat", tanner_hat);
		insert("Tanner Shirt", tanner_shirt);
		insert("Tanner Gloves", tanner_gloves);
		insert("Tanner Pants", tanner_pants);
		insert("Tanner Shoes", tanner_shoes);
	}

	void addStonecutterSet() {
		const auto stonecutters_hat = new Item("Stonecutter's Hat",
											   ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_hat.png");
		const auto stonecutters_shirt = new Item("Stonecutter's Shirt",
												 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_shirt.png");
		const auto stonecutters_gloves = new Item("Stonecutter's Gloves",
												  ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_gloves.png");
		const auto stonecutters_pants = new Item("Stonecutter's Pants",
												 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_pants.png");
		const auto stonecutters_shoes = new Item("Stonecutter's Shoes",
												 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_shoes.png");

		insert("Stonecutter's Hat", stonecutters_hat);
		insert("Stonecutter's Shirt", stonecutters_shirt);
		insert("Stonecutter's Gloves", stonecutters_gloves);
		insert("Stonecutter's Pants", stonecutters_pants);
		insert("Stonecutter's Shoes", stonecutters_shoes);
	}

	void addFluxes() {
		const auto sand_flux = new RefiningComponent("Sand Flux",
													 ":/MarketManager/images/items/resources/refining_components/sand_flux.png",
													 3,
													 true,
													 0.7,
													 0.7);
		const auto shelldust_flux = new RefiningComponent("Shelldust Flux",
														  ":/MarketManager/images/items/resources/refining_components/shelldust_flux.png",
														  4,
														  true,
														  0.85,
														  0.85);
		const auto obsidian_flux = new RefiningComponent("Obsidian Flux",
														 ":/MarketManager/images/items/resources/refining_components/obsidian_flux.png",
														 5,
														 false,
														 2.2,
														 1.8);

		insert("Sand Flux", sand_flux);
		insert("Shelldust Flux", shelldust_flux);
		insert("Obsidian Flux", obsidian_flux);
	}

	void addSandpapers() {
		const auto coarse_sandpaper = new RefiningComponent("Coarse Sandpaper",
															":/MarketManager/images/items/resources/refining_components/coarse_sandpaper.png",
															3,
															true,
															0.3,
															0.3);
		const auto fine_sandpaper = new RefiningComponent("Fine Sandpaper",
														  ":/MarketManager/images/items/resources/refining_components/fine_sandpaper.png",
														  4,
														  true,
														  0.2,
														  0.2);
		const auto obsidian_sandpaper = new RefiningComponent("Obsidian Sandpaper",
															  ":/MarketManager/images/items/resources/refining_components/obsidian_sandpaper.png",
															  5,
															  false,
															  0.5,
															  0.3);

		insert("Coarse Sandpaper", coarse_sandpaper);
		insert("Fine Sandpaper", fine_sandpaper);
		insert("Obsidian Sandpaper", obsidian_sandpaper);
	}

	void addWeaves() {
		const auto crossweave = new RefiningComponent("Crossweave",
													  ":/MarketManager/images/items/resources/refining_components/crossweave.png",
													  3,
													  true,
													  0.35,
													  0.35);
		const auto silkweave = new RefiningComponent("Silkweave",
													 ":/MarketManager/images/items/resources/refining_components/silkweave.png",
													 4,
													 true,
													 0.2,
													 0.2);
		const auto wireweave = new RefiningComponent("Wireweave",
													 ":/MarketManager/images/items/resources/refining_components/wireweave.png",
													 5,
													 false,
													 0.25,
													 0.15);

		insert("Crossweave", crossweave);
		insert("Silkweave", silkweave);
		insert("Wireweave", wireweave);
	}

	void addTannins() {
		const auto tannin = new RefiningComponent("Tannin",
												  ":/MarketManager/images/items/resources/refining_components/tannin.png",
												  3,
												  true,
												  0.2,
												  0.2);
		const auto rested_tannin = new RefiningComponent("Rested Tannin",
														 ":/MarketManager/images/items/resources/refining_components/rested_tannin.png",
														 4,
														 true,
														 0.2,
														 0.2);
		const auto aged_tannin = new RefiningComponent("Aged Tannin",
													   ":/MarketManager/images/items/resources/refining_components/aged_tannin.png",
													   5,
													   false,
													   0.25,
													   0.2);

		insert("Tannin", tannin);
		insert("Rested Tannin", rested_tannin);
		insert("Aged Tannin", aged_tannin);
	}

	void addSolvents() {
		const auto weak_solvent = new RefiningComponent("Weak Solvent",
														":/MarketManager/images/items/resources/refining_components/weak_solvent.png",
														3,
														true,
														0.25,
														0.25);
		const auto potent_solvent = new RefiningComponent("Potent Solvent",
														  ":/MarketManager/images/items/resources/refining_components/potent_solvent.png",
														  4,
														  true,
														  0.7,
														  0.7);
		const auto pure_solvent = new RefiningComponent("Pure Solvent",
														":/MarketManager/images/items/resources/refining_components/pure_solvent.png",
														5,
														false,
														1.,
														1.);

		insert("Weak Solvent", weak_solvent);
		insert("Potent Solvent", potent_solvent);
		insert("Pure Solvent", pure_solvent);
	}
}