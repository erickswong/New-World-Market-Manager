module image_map:default_image_map;

import image_map;

namespace image_map::default_image_map {
	void setUp() {
		reset();

		addResources();
		addGears();
	}

	void addResources() {
		addRawResources();
		addRefinedResources();
		addRefiningComponents();
	}

	void addGears() {
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
		addImage("Obsidian Flux",
				 ":/MarketManager/images/items/resources/refining_components/obsidian_flux.png");
		addImage("Obsidian Sandpaper",
				 ":/MarketManager/images/items/resources/refining_components/obsidian_sandpaper.png");
		addImage("Wireweave",
				 ":/MarketManager/images/items/resources/refining_components/wireweave.png");
		addImage("Aged Tannin",
				 ":/MarketManager/images/items/resources/refining_components/aged_tannin.png");
		addImage("Pure Solvent",
				 ":/MarketManager/images/items/resources/refining_components/pure_solvent.png");
	}

	void addOres() {
		addImage("Iron Ore",
				 ":/MarketManager/images/items/resources/raw_resources/ores/iron_ore.png");
		addImage("Starmetal Ore",
				 ":/MarketManager/images/items/resources/raw_resources/ores/starmetal_ore.png");
		addImage("Orichalcum Ore",
				 ":/MarketManager/images/items/resources/raw_resources/ores/orichalcum_ore.png");
		addImage("Silver Ore",
				 ":/MarketManager/images/items/resources/raw_resources/ores/silver_ore.png");
		addImage("Gold Ore",
				 ":/MarketManager/images/items/resources/raw_resources/ores/gold_ore.png");
		addImage("Platinum Ore",
				 ":/MarketManager/images/items/resources/raw_resources/ores/platinum_ore.png");
		addImage("Cinnabar",
				 ":/MarketManager/images/items/resources/raw_resources/ores/cinnabar.png");
		addImage("Tolvium",
				 ":/MarketManager/images/items/resources/raw_resources/ores/tolvium.png");
	};

	void addWoods() {
		addImage("Green Wood",
				 ":/MarketManager/images/items/resources/raw_resources/woods/green_wood.png");
		addImage("Aged Wood",
				 ":/MarketManager/images/items/resources/raw_resources/woods/aged_wood.png");
		addImage("Wyrdwood",
				 ":/MarketManager/images/items/resources/raw_resources/woods/wyrdwood.png");
		addImage("Ironwood",
				 ":/MarketManager/images/items/resources/raw_resources/woods/ironwood.png");
		addImage("Wildwood",
				 ":/MarketManager/images/items/resources/raw_resources/woods/wildwood.png");
		addImage("Barbvine",
				 ":/MarketManager/images/items/resources/raw_resources/woods/barbvine.png");
	}

	void addFibers() {
		addImage("Fibers",
				 ":/MarketManager/images/items/resources/raw_resources/fibers/fibers.png");
		addImage("Silk Threads",
				 ":/MarketManager/images/items/resources/raw_resources/fibers/silk_threads.png");
		addImage("Wirefiber",
				 ":/MarketManager/images/items/resources/raw_resources/fibers/wirefiber.png");
		addImage("Blisterweave",
				 ":/MarketManager/images/items/resources/raw_resources/fibers/blisterweave.png");
		addImage("Scalecloth",
				 ":/MarketManager/images/items/resources/raw_resources/fibers/scalecloth.png");
	}

	void addRawhides() {
		addImage("Rawhide",
				 ":/MarketManager/images/items/resources/raw_resources/rawhide/rawhide.png");
		addImage("Thick Hide",
				 ":/MarketManager/images/items/resources/raw_resources/rawhide/thick_hide.png");
		addImage("Iron Hide",
				 ":/MarketManager/images/items/resources/raw_resources/rawhide/iron_hide.png");
		addImage("Smolderhide",
				 ":/MarketManager/images/items/resources/raw_resources/rawhide/smolderhide.png");
		addImage("Scarhide",
				 ":/MarketManager/images/items/resources/raw_resources/rawhide/scarhide.png");
	}

	void addStones() {
		addImage("Stone",
				 ":/MarketManager/images/items/resources/raw_resources/stones/stone.png");
		addImage("Lodestone",
				 ":/MarketManager/images/items/resources/raw_resources/stones/lodestone.png");
		addImage("Elemental Lodestone",
				 ":/MarketManager/images/items/resources/raw_resources/stones/elemental_lodestone.png");
	}

	void addIngots() {
		addImage("Charcoal",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/charcoal.png");
		addImage("Iron Ingot",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/iron_ingot.png");
		addImage("Steel Ingot",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/steel_ingot.png");
		addImage("Starmetal Ingot",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/starmetal_ingot.png");
		addImage("Orichalcum Ingot",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/orichalcum_ingot.png");
		addImage("Silver Ingot",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/silver_ingot.png");
		addImage("Gold Ingot",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/gold_ingot.png");
		addImage("Platinum Ingot",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/platinum_ingot.png");
		addImage("Asmodeum",
				 ":/MarketManager/images/items/resources/refined_resources/ingots/asmodeum.png");
	}

	void addPlanks() {
		addImage("Timber",
				 ":/MarketManager/images/items/resources/refined_resources/planks/timber.png");
		addImage("Lumber",
				 ":/MarketManager/images/items/resources/refined_resources/planks/lumber.png");
		addImage("Wyrdwood Planks",
				 ":/MarketManager/images/items/resources/refined_resources/planks/wyrdwood_planks.png");
		addImage("Ironwood Planks",
				 ":/MarketManager/images/items/resources/refined_resources/planks/ironwood_planks.png");
		addImage("Glittering Ebony",
				 ":/MarketManager/images/items/resources/refined_resources/planks/glittering_ebony.png");
	}

	void addCloths() {
		addImage("Linen",
				 ":/MarketManager/images/items/resources/refined_resources/cloths/linen.png");
		addImage("Sateen",
				 ":/MarketManager/images/items/resources/refined_resources/cloths/sateen.png");
		addImage("Silk",
				 ":/MarketManager/images/items/resources/refined_resources/cloths/silk.png");
		addImage("Infused Silk",
				 ":/MarketManager/images/items/resources/refined_resources/cloths/infused_silk.png");
		addImage("Phoenixweave",
				 ":/MarketManager/images/items/resources/refined_resources/cloths/phoenixweave.png");
	}

	void addLeathers() {
		addImage("Coarse Leather",
				 ":/MarketManager/images/items/resources/refined_resources/leathers/coarse_leather.png");
		addImage("Rugged Leather",
				 ":/MarketManager/images/items/resources/refined_resources/leathers/rugged_leather.png");
		addImage("Layered Leather",
				 ":/MarketManager/images/items/resources/refined_resources/leathers/layered_leather.png");
		addImage("Infused Leather",
				 ":/MarketManager/images/items/resources/refined_resources/leathers/infused_leather.png");
		addImage("Runic Leather",
				 ":/MarketManager/images/items/resources/refined_resources/leathers/runic_leather.png");
	}

	void addBlocks() {
		addImage("Stone Block",
				 ":/MarketManager/images/items/resources/refined_resources/blocks/stone_block.png");
		addImage("Stone Brick",
				 ":/MarketManager/images/items/resources/refined_resources/blocks/stone_brick.png");
		addImage("Lodestone Brick",
				 ":/MarketManager/images/items/resources/refined_resources/blocks/lodestone_brick.png");
		addImage("Obsidian Voidstone",
				 ":/MarketManager/images/items/resources/refined_resources/blocks/obsidian_voidstone.png");
		addImage("Runestone",
				 ":/MarketManager/images/items/resources/refined_resources/blocks/runestone.png");
	}

	void addSmelterSet() {
		addImage("Smelter's Headgear",
				 ":/MarketManager/images/armour_sets/smelter_set/smelters_headgear.png");
		addImage("Smelter's Smock",
				 ":/MarketManager/images/armour_sets/smelter_set/smelters_smock.png");
		addImage("Smelter's Mitts",
				 ":/MarketManager/images/armour_sets/smelter_set/smelters_mitts.png");
		addImage("Smelter's Pants",
				 ":/MarketManager/images/armour_sets/smelter_set/smelters_pants.png");
		addImage("Smelter's Shoes",
				 ":/MarketManager/images/armour_sets/smelter_set/smelters_shoes.png");
	}

	void addWoodworkerSet() {
		addImage("Woodworker's Cap",
				 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_cap.png");
		addImage("Woodworker's Shirt",
				 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_shirt.png");
		addImage("Woodworker's Gloves",
				 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_gloves.png");
		addImage("Woodworker's Pants",
				 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_pants.png");
		addImage("Woodworker's Shoes",
				 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_shoes.png");
	}

	void addWeaverSet() {
		addImage("Weaver's Hat",
				 ":/MarketManager/images/armour_sets/weaver_set/weavers_hat.png");
		addImage("Weaver's Shirt",
				 ":/MarketManager/images/armour_sets/weaver_set/weavers_shirt.png");
		addImage("Weaver's Gloves",
				 ":/MarketManager/images/armour_sets/weaver_set/weavers_gloves.png");
		addImage("Weaver's Pants",
				 ":/MarketManager/images/armour_sets/weaver_set/weavers_pants.png");
		addImage("Weaver's Shoes",
				 ":/MarketManager/images/armour_sets/weaver_set/weavers_shoes.png");
	}

	void addTannerSet() {
		addImage("Tanner Hat",
				 ":/MarketManager/images/armour_sets/tanner_set/tanner_hat.png");
		addImage("Tanner Shirt",
				 ":/MarketManager/images/armour_sets/tanner_set/tanner_shirt.png");
		addImage("Tanner Gloves",
				 ":/MarketManager/images/armour_sets/tanner_set/tanner_gloves.png");
		addImage("Tanner Pants",
				 ":/MarketManager/images/armour_sets/tanner_set/tanner_pants.png");
		addImage("Tanner Shoes",
				 ":/MarketManager/images/armour_sets/tanner_set/tanner_shoes.png");
	}

	void addStonecutterSet() {
		addImage("Stonecutter's Hat",
				 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_hat.png");
		addImage("Stonecutter's Shirt",
				 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_shirt.png");
		addImage("Stonecutter's Gloves",
				 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_gloves.png");
		addImage("Stonecutter's Pants",
				 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_pants.png");
		addImage("Stonecutter's Shoes",
				 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_shoes.png");
	}
}