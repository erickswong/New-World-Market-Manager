#include "items/default_items_initializer.h"

#include "items/resources/raw_resources/raw_resource.h"
#include "items/resources/refined_resources/blocks/block.h"
#include "items/resources/refined_resources/cloths/cloth.h"
#include "items/resources/refined_resources/ingots/ingot.h"
#include "items/resources/refined_resources/leathers/leather.h"
#include "items/resources/refined_resources/planks/plank.h"

DefaultItemsInitializer::DefaultItemsInitializer(Items* items) {
	this->items = items;
}

void DefaultItemsInitializer::initializeItems() const {
	addResources();
	addArmourSets();
}

void DefaultItemsInitializer::addResources() const {
	addRawResources();
	addRefinedResources();
	addRefiningComponents();
}

void DefaultItemsInitializer::addArmourSets() const {
	addSmelterSet();
	addWoodworkerSet();
	addWeaverSet();
	addTannerSet();
	addStonecutterSet();
}

void DefaultItemsInitializer::addRawResources() const {
	addOres();
	addWoods();
	addFibers();
	addRawhides();
	addStones();
}

void DefaultItemsInitializer::addRefinedResources() const {
	addIngots();
	addPlanks();
	addCloths();
	addLeathers();
	addBlocks();
}

void DefaultItemsInitializer::addRefiningComponents() const {
	addFluxes();
	addSandpapers();
	addTannins();
	addSolvents();
	addWeaves();
}

void DefaultItemsInitializer::addOres() const {
	auto* iron_ore = new RawResource("Iron Ore",
									 ":/MarketManager/images/items/resources/raw_resources/ores/iron_ore.png",
									 1,
									 false,
									 0.35,
									 0.3);
	auto* starmetal_ore = new RawResource("Starmetal Ore",
										  ":/MarketManager/images/items/resources/raw_resources/ores/starmetal_ore.png",
										  4,
										  false,
										  1.3,
										  1.1);
	auto* orichalcum_ore = new RawResource("Orichalcum Ore",
										   ":/MarketManager/images/items/resources/raw_resources/ores/orichalcum_ore.png",
										   5,
										   false,
										   2.5,
										   2.2);
	auto* silver_ore = new RawResource("Silver Ore",
									   ":/MarketManager/images/items/resources/raw_resources/ores/silver_ore.png",
									   2,
									   false,
									   0.2,
									   0.15);
	auto* gold_ore = new RawResource("Gold Ore",
									 ":/MarketManager/images/items/resources/raw_resources/ores/gold_ore.png",
									 3,
									 false,
									 0.4,
									 0.25);
	auto* platinum_ore = new RawResource("Platinum Ore",
										 ":/MarketManager/images/items/resources/raw_resources/ores/platinum_ore.png",
										 4,
										 false,
										 1.,
										 0.75);
	auto* cinnabar = new RawResource("Cinnabar",
									 ":/MarketManager/images/items/resources/raw_resources/ores/cinnabar.png",
									 5,
									 true,
									 15.,
									 15.);
	auto* tolvium = new RawResource("Tolvium",
									":/MarketManager/images/items/resources/raw_resources/ores/tolvium.png",
									5,
									true,
									15.,
									15.);

	items->addItem("Iron Ore", iron_ore);
	items->addItem("Starmetal Ore", starmetal_ore);
	items->addItem("Orichalcum Ore", orichalcum_ore);
	items->addItem("Silver Ore", silver_ore);
	items->addItem("Gold Ore", gold_ore);
	items->addItem("Platinum Ore", platinum_ore);
	items->addItem("Cinnabar", cinnabar);
	items->addItem("Tolvium", tolvium);
}

void DefaultItemsInitializer::addWoods() const {
	auto* green_wood = new RawResource("Green Wood",
									   ":/MarketManager/images/items/resources/raw_resources/woods/green_wood.png",
									   1,
									   false,
									   0.25,
									   0.2);
	auto* aged_wood = new RawResource("Aged Wood",
									  ":/MarketManager/images/items/resources/raw_resources/woods/aged_wood.png",
									  2,
									  false,
									  0.25,
									  0.2);
	auto* wyrdwood = new RawResource("Wyrdwood",
									 ":/MarketManager/images/items/resources/raw_resources/woods/wyrdwood.png",
									 4,
									 false,
									 1.1,
									 0.9);
	auto* ironwood = new RawResource("Ironwood",
									 ":/MarketManager/images/items/resources/raw_resources/woods/ironwood.png",
									 5,
									 false,
									 0.75,
									 0.6);
	auto* wildwood = new RawResource("Wildwood",
									 ":/MarketManager/images/items/resources/raw_resources/woods/wildwood.png",
									 5,
									 true,
									 10.,
									 10.);
	auto* barbvine = new RawResource("Barbvine",
									 ":/MarketManager/images/items/resources/raw_resources/woods/barbvine.png",
									 5,
									 true,
									 10.,
									 10.);

	items->addItem("Green Wood", green_wood);
	items->addItem("Aged Wood", aged_wood);
	items->addItem("Wyrdwood", wyrdwood);
	items->addItem("Ironwood", ironwood);
	items->addItem("Wildwood", wildwood);
	items->addItem("Barbvine", barbvine);
}

void DefaultItemsInitializer::addFibers() const {
	auto* fibers = new RawResource("Fibers",
								   ":/MarketManager/images/items/resources/raw_resources/fibers/fibers.png",
								   1,
								   false,
								   0.2,
								   0.15);
	auto* silk_threads = new RawResource("Silk Threads",
										 ":/MarketManager/images/items/resources/raw_resources/fibers/silk_threads.png",
										 4,
										 false,
										 0.7,
										 0.5);
	auto* wirefiber = new RawResource("Wirefiber",
									  ":/MarketManager/images/items/resources/raw_resources/fibers/wirefiber.png",
									  5,
									  false,
									  0.6,
									  0.45);
	auto* blisterweave = new RawResource("Blisterweave",
										 ":/MarketManager/images/items/resources/raw_resources/fibers/blisterweave.png",
										 5,
										 true,
										 7.5,
										 7.5);
	auto* scalecloth = new RawResource("Scalecloth",
									   ":/MarketManager/images/items/resources/raw_resources/fibers/scalecloth.png",
									   5,
									   true,
									   7.5,
									   7.5);
	
	items->addItem("Fibers", fibers);
	items->addItem("Silk Threads", silk_threads);
	items->addItem("Wirefiber", wirefiber);
	items->addItem("Blisterweave", blisterweave);
	items->addItem("Scalecloth", scalecloth);
}

void DefaultItemsInitializer::addRawhides() const {
	auto* rawhide = new RawResource("Rawhide",
									":/MarketManager/images/items/resources/raw_resources/rawhide/rawhide.png",
									1,
									false,
									0.35,
									0.3);
	auto* thick_hide = new RawResource("Thick Hide",
									   ":/MarketManager/images/items/resources/raw_resources/rawhide/thick_hide.png",
									   4,
									   false,
									   0.6,
									   0.55);
	auto* iron_hide = new RawResource("Iron Hide",
									  ":/MarketManager/images/items/resources/raw_resources/rawhide/iron_hide.png",
									  5,
									  false,
									  0.1,
									  0.05);
	auto* smolderhide = new RawResource("Smolderhide",
										":/MarketManager/images/items/resources/raw_resources/rawhide/smolderhide.png",
										5,
										true,
										15.,
										15.);
	auto* scarhide = new RawResource("Scarhide",
									 ":/MarketManager/images/items/resources/raw_resources/rawhide/scarhide.png",
									 5,
									 true,
									 15.,
									 15.);

	items->addItem("Rawhide", rawhide);
	items->addItem("Thick Hide", thick_hide);
	items->addItem("Iron Hide", iron_hide);
	items->addItem("Smolderhide", smolderhide);
	items->addItem("Scarhide", scarhide);
}

void DefaultItemsInitializer::addStones() const {
	auto* stone = new RawResource("Stone",
								  ":/MarketManager/images/items/resources/raw_resources/stones/stone.png",
								  1,
								  false,
								  0.2,
								  0.15);
	auto* lodestone = new RawResource("Lodestone",
									  ":/MarketManager/images/items/resources/raw_resources/stones/lodestone.png",
									  4,
									  false,
									  0.6,
									  0.5);
	auto* elemental_lodestone = new RawResource("Elemental Lodestone",
												":/MarketManager/images/items/resources/raw_resources/stones/elemental_lodestone.png",
												3,
												true,
												0.5,
												0.1);

	items->addItem("Stone", stone);
	items->addItem("Lodestone", lodestone);
	items->addItem("Elemental Lodestone", elemental_lodestone);
}

void DefaultItemsInitializer::addIngots() const {
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

void DefaultItemsInitializer::addPlanks() const {
	addTimber();
	addLumber();
	addWyrdwoodPlanks();
	addIronwoodPlanks();
	addGlitteringEbony();
}

void DefaultItemsInitializer::addCloths() const {
	addLinen();
	addSateen();
	addSilk();
	addInfusedSilk();
	addPhoenixweave();
}

void DefaultItemsInitializer::addLeathers() const {
	addCoarseLeather();
	addRuggedLeather();
	addLayeredLeather();
	addInfusedLeather();
	addRunicLeather();
}

void DefaultItemsInitializer::addBlocks() const {
	addStoneBlock();
	addStoneBrick();
	addLodestoneBrick();
	addObsidianVoidstone();
	addRunestone();
}

void DefaultItemsInitializer::addCharcoal() const {
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

	auto* charcoal = new Ingot("Charcoal",
							   ":/MarketManager/images/items/resources/refined_resources/ingots/charcoal.png",
							   2,
							   false,
							   0.4,
							   0.35,
							   1.,
							   0.01,
							   recipes);

	items->addItem("Charcoal", charcoal);
}

void DefaultItemsInitializer::addIronIngot() const {
	Recipe recipe1;

	recipe1.addIngredient("Iron Ore", 4);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* iron_ingot = new Ingot("Iron Ingot",
								 ":/MarketManager/images/items/resources/refined_resources/ingots/iron_ingot.png",
								 2,
								 true,
								 1.2,
								 1.2,
								 1.,
								 0.01,
								 recipes);

	items->addItem("Iron Ingot", iron_ingot);
}

void DefaultItemsInitializer::addSteelIngot() const {
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

	auto* steel_ingot = new Ingot("Steel Ingot",
								  ":/MarketManager/images/items/resources/refined_resources/ingots/steel_ingot.png",
								  3,
								  true,
								  4.5,
								  4.5,
								  0.98,
								  0.04,
								  recipes);

	items->addItem("Steel Ingot", steel_ingot);
}

void DefaultItemsInitializer::addStarmetalIngot() const {
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

	auto* starmetal_ingot = new Ingot("Starmetal Ingot",
									  ":/MarketManager/images/items/resources/refined_resources/ingots/starmetal_ingot.png",
									  4,
									  true,
									  13.,
									  13.,
									  0.95,
									  0.07,
									  recipes);

	items->addItem("Starmetal Ingot", starmetal_ingot);
}

void DefaultItemsInitializer::addOrichalcumIngot() const {
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

	auto* orichalcum_ingot = new Ingot("Orichalcum Ingot",
									   ":/MarketManager/images/items/resources/refined_resources/ingots/orichalcum_ingot.png",
									   5,
									   true,
									   40.,
									   40.,
									   0.93,
									   0.13,
									   recipes);

	items->addItem("Orichalcum Ingot", orichalcum_ingot);
}

void DefaultItemsInitializer::addSilverIngot() const {
	Recipe recipe1;

	recipe1.addIngredient("Silver Ore", 4);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* silver_ingot = new Ingot("Silver Ingot",
								   ":/MarketManager/images/items/resources/refined_resources/ingots/silver_ingot.png",
								   2,
								   true,
								   0.6,
								   0.6,
								   0.98,
								   0.01,
								   recipes);

	items->addItem("Silver Ingot", silver_ingot);
}

void DefaultItemsInitializer::addGoldIngot() const {
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

	auto* gold_ingot = new Ingot("Gold Ingot",
								 ":/MarketManager/images/items/resources/refined_resources/ingots/gold_ingot.png",
								 3,
								 true,
								 3.75,
								 3.75,
								 0.95,
								 0.04,
								 recipes);

	items->addItem("Gold Ingot", gold_ingot);
}

void DefaultItemsInitializer::addPlatinumIngot() const {
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

	auto* platinum_ingot = new Ingot("Platinum Ingot",
									 ":/MarketManager/images/items/resources/refined_resources/ingots/platinum_ingot.png",
									 4,
									 true,
									 11.,
									 11.,
									 0.93,
									 0.07,
									 recipes);

	items->addItem("Platinum Ingot", platinum_ingot);
}

void DefaultItemsInitializer::addAsmodeum() const {
	Recipe recipe1;

	recipe1.addIngredient("Orichalcum Ingot", 5);
	recipe1.addIngredient("Tolvium", 1);
	recipe1.addIngredient("Cinnabar", 1);
	recipe1.addIngredient("Obsidian Flux", 1);
	recipe1.addIngredient("Charcoal", 2);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* asmodeum = new Ingot("Asmodeum",
							   ":/MarketManager/images/items/resources/refined_resources/ingots/asmodeum.png",
							   5,
							   true,
							   300.,
							   300.,
							   0.8,
							   0.19,
							   recipes);

	items->addItem("Asmodeum", asmodeum);
}

void DefaultItemsInitializer::addTimber() const {
	Recipe recipe1;

	recipe1.addIngredient("Green Wood", 4);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* timber = new Plank("Timber",
		":/MarketManager/images/items/resources/refined_resources/planks/timber.png",
		2,
		true,
		1.,
		1.,
		1.,
		0.01,
		recipes);

	items->addItem("Timber", timber);
}

void DefaultItemsInitializer::addLumber() const {
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

	auto* lumber = new Plank("Lumber",
		":/MarketManager/images/items/resources/refined_resources/planks/lumber.png",
		3,
		true,
		2.2,
		2.2,
		0.98,
		0.04,
		recipes);

	items->addItem("Lumber", lumber);
}

void DefaultItemsInitializer::addWyrdwoodPlanks() const {
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

	auto* wyrdwood_planks = new Plank("Wyrdwood Planks",
		":/MarketManager/images/items/resources/refined_resources/planks/wyrdwood_planks.png",
		4,
		true,
		8.5,
		8.5,
		0.95,
		0.07,
		recipes);

	items->addItem("Wyrdwood Planks", wyrdwood_planks);
}

void DefaultItemsInitializer::addIronwoodPlanks() const {
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

	auto* ironwood_planks = new Plank("Ironwood Planks",
		":/MarketManager/images/items/resources/refined_resources/planks/ironwood_planks.png",
		5,
		true,
		16.,
		16.,
		0.93,
		0.13,
		recipes);

	items->addItem("Ironwood Planks", ironwood_planks);
}

void DefaultItemsInitializer::addGlitteringEbony() const {
	Recipe recipe1;

	recipe1.addIngredient("Ironwood Planks", 5);
	recipe1.addIngredient("Wildwood", 1);
	recipe1.addIngredient("Barbvine", 1);
	recipe1.addIngredient("Obsidian Sandpaper", 1);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* glittering_ebony = new Plank("Glittering Ebony",
		":/MarketManager/images/items/resources/refined_resources/planks/glittering_ebony.png",
		5,
		true,
		70.,
		70.,
		0.8,
		0.19,
		recipes);

	items->addItem("Glittering Ebony", glittering_ebony);
}

void DefaultItemsInitializer::addLinen() const {
	Recipe recipe1;

	recipe1.addIngredient("Fibers", 4);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* linen = new Cloth("Linen",
		":/MarketManager/images/items/resources/refined_resources/cloths/linen.png",
		2,
		true,
		1.,
		1.,
		1.,
		0.01,
		recipes);

	items->addItem("Linen", linen);
}

void DefaultItemsInitializer::addSateen() const {
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

	auto* sateen = new Cloth("Sateen",
		":/MarketManager/images/items/resources/refined_resources/cloths/sateen.png",
		3,
		true,
		2.,
		2.,
		0.98,
		0.04,
		recipes);

	items->addItem("Sateen", sateen);
}

void DefaultItemsInitializer::addSilk() const {
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

	auto* silk = new Cloth("Silk",
		":/MarketManager/images/items/resources/refined_resources/cloths/silk.png",
		4,
		true,
		5.5,
		5.5,
		0.95,
		0.07,
		recipes);

	items->addItem("Silk", silk);
}

void DefaultItemsInitializer::addInfusedSilk() const {
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

	auto* infused_silk = new Cloth("Infused Silk",
		":/MarketManager/images/items/resources/refined_resources/cloths/infused_silk.png",
		5,
		true,
		13.,
		13.,
		0.93,
		0.13,
		recipes);

	items->addItem("Infused Silk", infused_silk);
}

void DefaultItemsInitializer::addPhoenixweave() const {
	Recipe recipe1;

	recipe1.addIngredient("Infused Silk", 5);
	recipe1.addIngredient("Scalecloth", 1);
	recipe1.addIngredient("Blisterweave", 1);
	recipe1.addIngredient("Wireweave", 1);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* phoenixweave = new Cloth("Phoenixweave",
		":/MarketManager/images/items/resources/refined_resources/cloths/phoenixweave.png",
		5,
		true,
		145.,
		145.,
		0.8,
		0.19,
		recipes);

	items->addItem("Phoenixweave", phoenixweave);
}

void DefaultItemsInitializer::addCoarseLeather() const {
	Recipe recipe1;

	recipe1.addIngredient("Rawhide", 4);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* coarse_leather = new Leather("Coarse Leather",
		":/MarketManager/images/items/resources/refined_resources/leathers/coarse_leather.png",
		2,
		true,
		1.25,
		1.25,
		1.,
		0.01,
		recipes);

	items->addItem("Coarse Leather", coarse_leather);
}

void DefaultItemsInitializer::addRuggedLeather() const {
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

	auto* rugged_leather = new Leather("Rugged Leather",
		":/MarketManager/images/items/resources/refined_resources/leathers/rugged_leather.png",
		3,
		true,
		2.1,
		2.1,
		0.98,
		0.04,
		recipes);

	items->addItem("Rugged Leather", rugged_leather);
}

void DefaultItemsInitializer::addLayeredLeather() const {
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

	auto* layered_leather = new Leather("Layered Leather",
		":/MarketManager/images/items/resources/refined_resources/leathers/layered_leather.png",
		4,
		true,
		5.5,
		5.5,
		0.95,
		0.07,
		recipes);

	items->addItem("Layered Leather", layered_leather);
}

void DefaultItemsInitializer::addInfusedLeather() const {
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

	auto* infused_leather = new Leather("Infused Leather",
		":/MarketManager/images/items/resources/refined_resources/leathers/infused_leather.png",
		5,
		true,
		8.2,
		8.2,
		0.93,
		0.13,
		recipes);

	items->addItem("Infused Leather", infused_leather);
}

void DefaultItemsInitializer::addRunicLeather() const {
	Recipe recipe1;

	recipe1.addIngredient("Infused Leather", 5);
	recipe1.addIngredient("Smolderhide", 1);
	recipe1.addIngredient("Scarhide", 1);
	recipe1.addIngredient("Aged Tannin", 1);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* runic_leather = new Leather("Runic Leather",
		":/MarketManager/images/items/resources/refined_resources/leathers/runic_leather.png",
		5,
		true,
		130.,
		130.,
		0.8,
		0.19,
		recipes);

	items->addItem("Runic Leather", runic_leather);
}

void DefaultItemsInitializer::addStoneBlock() const {
	Recipe recipe1;

	recipe1.addIngredient("Stone", 4);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* stone_block = new Leather("Stone Block",
		":/MarketManager/images/items/resources/refined_resources/blocks/stone_block.png",
		2,
		true,
		1.,
		1.,
		1.,
		0.01,
		recipes);

	items->addItem("Stone Block", stone_block);
}

void DefaultItemsInitializer::addStoneBrick() const {
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

	auto* stone_brick = new Block("Stone Brick",
		":/MarketManager/images/items/resources/refined_resources/blocks/stone_brick.png",
		3,
		true,
		2.3,
		2.3,
		0.98,
		0.04,
		recipes);

	items->addItem("Stone Brick", stone_brick);
}

void DefaultItemsInitializer::addLodestoneBrick() const {
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

	auto* lodestone_brick = new Block("Lodestone Brick",
		":/MarketManager/images/items/resources/refined_resources/blocks/lodestone_brick.png",
		4,
		true,
		4.2,
		4.2,
		0.95,
		0.07,
		recipes);

	items->addItem("Lodestone Brick", lodestone_brick);
}

void DefaultItemsInitializer::addObsidianVoidstone() const {
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

	auto* obsidian_voidstone = new Block("Obsidian Voidstone",
		":/MarketManager/images/items/resources/refined_resources/blocks/obsidian_voidstone.png",
		5,
		true,
		25.,
		25.,
		0.93,
		0.13,
		recipes);

	items->addItem("Obsidian Voidstone", obsidian_voidstone);
}

void DefaultItemsInitializer::addRunestone() const {
	Recipe recipe1;

	recipe1.addIngredient("Obsidian Voidstone", 5);
	recipe1.addIngredient("Obsidian Sandpaper", 1);
	recipe1.addIngredient("Elemental Lodestone", 1);

	Recipes recipes;

	recipes.addRecipe(recipe1);

	auto* runestone = new Block("Runestone",
		":/MarketManager/images/items/resources/refined_resources/blocks/runestone.png",
		5,
		true,
		64.,
		64.,
		0.8,
		0.19,
		recipes);

	items->addItem("Runestone", runestone);
}

void DefaultItemsInitializer::addSmelterSet() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addWoodworkerSet() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addWeaverSet() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addTannerSet() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addStonecutterSet() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addFluxes() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addSandpapers() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addWeaves() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addTannins() const {
	// TODO: Implement
}

void DefaultItemsInitializer::addSolvents() const {
	// TODO: Implement
}
