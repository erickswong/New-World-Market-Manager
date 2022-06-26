module items:default_items;

import items;

import :block;
import :cloth;
import :gear;
import :ingot;
import :leather;
import :plank;
import :raw_resource;
import :refining_component;

namespace items::default_items {
	void setUp() {
		reset();

		addResources();
		addGears();

		update(itemUpdateOrder());
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
		addItem(new RefiningComponent("Obsidian Flux",
									  ":/MarketManager/images/items/resources/refining_components/obsidian_flux.png",
									  5,
									  false,
									  2.2,
									  1.8));
		addItem(new RefiningComponent("Obsidian Sandpaper",
									  ":/MarketManager/images/items/resources/refining_components/obsidian_sandpaper.png",
									  5,
									  false,
									  0.5,
									  0.3));
		addItem(new RefiningComponent("Wireweave",
									  ":/MarketManager/images/items/resources/refining_components/wireweave.png",
									  5,
									  false,
									  0.25,
									  0.15));
		addItem(new RefiningComponent("Aged Tannin",
									  ":/MarketManager/images/items/resources/refining_components/aged_tannin.png",
									  5,
									  false,
									  0.25,
									  0.2));
		addItem(new RefiningComponent("Pure Solvent",
									  ":/MarketManager/images/items/resources/refining_components/pure_solvent.png",
									  5,
									  false,
									  1.,
									  1.));
	}

	void addOres() {
		addItem(new RawResource("Iron Ore",
								":/MarketManager/images/items/resources/raw_resources/ores/iron_ore.png",
								1,
								false,
								0.35,
								0.3));
		addItem(new RawResource("Starmetal Ore",
								":/MarketManager/images/items/resources/raw_resources/ores/starmetal_ore.png",
								4,
								false,
								1.3,
								1.1));
		addItem(new RawResource("Orichalcum Ore",
								":/MarketManager/images/items/resources/raw_resources/ores/orichalcum_ore.png",
								5,
								false,
								2.5,
								2.2));
		addItem(new RawResource("Silver Ore",
								":/MarketManager/images/items/resources/raw_resources/ores/silver_ore.png",
								2,
								false,
								0.2,
								0.15));
		addItem(new RawResource("Gold Ore",
								":/MarketManager/images/items/resources/raw_resources/ores/gold_ore.png",
								3,
								false,
								0.4,
								0.25));
		addItem(new RawResource("Platinum Ore",
								":/MarketManager/images/items/resources/raw_resources/ores/platinum_ore.png",
								4,
								false,
								1.,
								0.75));
		addItem(new RawResource("Cinnabar",
								":/MarketManager/images/items/resources/raw_resources/ores/cinnabar.png",
								5,
								true,
								15.,
								15.));
		addItem(new RawResource("Tolvium",
								":/MarketManager/images/items/resources/raw_resources/ores/tolvium.png",
								5,
								true,
								15.,
								15.));
	}

	void addWoods() {
		addItem(new RawResource("Green Wood",
								":/MarketManager/images/items/resources/raw_resources/woods/green_wood.png",
								1,
								false,
								0.25,
								0.2));
		addItem(new RawResource("Aged Wood",
								":/MarketManager/images/items/resources/raw_resources/woods/aged_wood.png",
								2,
								false,
								0.25,
								0.2));
		addItem(new RawResource("Wyrdwood",
								":/MarketManager/images/items/resources/raw_resources/woods/wyrdwood.png",
								4,
								false,
								1.1,
								0.9));
		addItem(new RawResource("Ironwood",
								":/MarketManager/images/items/resources/raw_resources/woods/ironwood.png",
								5,
								false,
								0.75,
								0.6));
		addItem(new RawResource("Wildwood",
								":/MarketManager/images/items/resources/raw_resources/woods/wildwood.png",
								5,
								true,
								10.,
								10.));
		addItem(new RawResource("Barbvine",
								":/MarketManager/images/items/resources/raw_resources/woods/barbvine.png",
								5,
								true,
								10.,
								10.));
	}

	void addFibers() {
		addItem(new RawResource("Fibers",
								":/MarketManager/images/items/resources/raw_resources/fibers/fibers.png",
								1,
								false,
								0.2,
								0.15));
		addItem(new RawResource("Silk Threads",
								":/MarketManager/images/items/resources/raw_resources/fibers/silk_threads.png",
								4,
								false,
								0.7,
								0.5));
		addItem(new RawResource("Wirefiber",
								":/MarketManager/images/items/resources/raw_resources/fibers/wirefiber.png",
								5,
								false,
								0.6,
								0.45));
		addItem(new RawResource("Blisterweave",
								":/MarketManager/images/items/resources/raw_resources/fibers/blisterweave.png",
								5,
								true,
								7.5,
								7.5));
		addItem(new RawResource("Scalecloth",
								":/MarketManager/images/items/resources/raw_resources/fibers/scalecloth.png",
								5,
								true,
								7.5,
								7.5));
	}

	void addRawhides() {
		addItem(new RawResource("Rawhide",
								":/MarketManager/images/items/resources/raw_resources/rawhide/rawhide.png",
								1,
								false,
								0.35,
								0.3));
		addItem(new RawResource("Thick Hide",
								":/MarketManager/images/items/resources/raw_resources/rawhide/thick_hide.png",
								4,
								false,
								0.6,
								0.55));
		addItem(new RawResource("Iron Hide",
								":/MarketManager/images/items/resources/raw_resources/rawhide/iron_hide.png",
								5,
								false,
								0.1,
								0.05));
		addItem(new RawResource("Smolderhide",
								":/MarketManager/images/items/resources/raw_resources/rawhide/smolderhide.png",
								5,
								true,
								15.,
								15.));
		addItem(new RawResource("Scarhide",
								":/MarketManager/images/items/resources/raw_resources/rawhide/scarhide.png",
								5,
								true,
								15.,
								15.));
	}

	void addStones() {
		addItem(new RawResource("Stone",
								":/MarketManager/images/items/resources/raw_resources/stones/stone.png",
								1,
								false,
								0.2,
								0.15));
		addItem(new RawResource("Lodestone",
								":/MarketManager/images/items/resources/raw_resources/stones/lodestone.png",
								4,
								false,
								0.6,
								0.5));
		addItem(new RawResource("Elemental Lodestone",
								":/MarketManager/images/items/resources/raw_resources/stones/elemental_lodestone.png",
								3,
								false,
								0.5,
								0.1));
	}

	void addIngots() {
		addItem(new Ingot("Charcoal",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/charcoal.png",
						  2,
						  false,
						  0.4,
						  0.35,
						  1.,
						  0.01));
		addItem(new Ingot("Iron Ingot",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/iron_ingot.png",
						  2,
						  true,
						  1.2,
						  1.2,
						  1.,
						  0.01));
		addItem(new Ingot("Steel Ingot",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/steel_ingot.png",
						  3,
						  true,
						  4.5,
						  4.5,
						  0.98,
						  0.04));
		addItem(new Ingot("Starmetal Ingot",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/starmetal_ingot.png",
						  4,
						  true,
						  13.,
						  13.,
						  0.95,
						  0.07));
		addItem(new Ingot("Orichalcum Ingot",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/orichalcum_ingot.png",
						  5,
						  true,
						  40.,
						  40.,
						  0.93,
						  0.13));
		addItem(new Ingot("Silver Ingot",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/silver_ingot.png",
						  2,
						  true,
						  0.6,
						  0.6,
						  0.98,
						  0.01));
		addItem(new Ingot("Gold Ingot",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/gold_ingot.png",
						  3,
						  true,
						  3.75,
						  3.75,
						  0.95,
						  0.04));
		addItem(new Ingot("Platinum Ingot",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/platinum_ingot.png",
						  4,
						  true,
						  11.,
						  11.,
						  0.93,
						  0.07));
		addItem(new Ingot("Asmodeum",
						  ":/MarketManager/images/items/resources/refined_resources/ingots/asmodeum.png",
						  5,
						  true,
						  300.,
						  300.,
						  0.8,
						  0.19));
	}

	void addPlanks() {
		addItem(new Plank("Timber",
						  ":/MarketManager/images/items/resources/refined_resources/planks/timber.png",
						  2,
						  true,
						  1.,
						  1.,
						  1.,
						  0.01));
		addItem(new Plank("Lumber",
						  ":/MarketManager/images/items/resources/refined_resources/planks/lumber.png",
						  3,
						  true,
						  2.2,
						  2.2,
						  0.98,
						  0.04));
		addItem(new Plank("Wyrdwood Planks",
						  ":/MarketManager/images/items/resources/refined_resources/planks/wyrdwood_planks.png",
						  4,
						  true,
						  8.5,
						  8.5,
						  0.95,
						  0.07));
		addItem(new Plank("Ironwood Planks",
						  ":/MarketManager/images/items/resources/refined_resources/planks/ironwood_planks.png",
						  5,
						  true,
						  16.,
						  16.,
						  0.93,
						  0.13));
		addItem(new Plank("Glittering Ebony",
						  ":/MarketManager/images/items/resources/refined_resources/planks/glittering_ebony.png",
						  5,
						  true,
						  70.,
						  70.,
						  0.8,
						  0.19));
	}

	void addCloths() {
		addItem(new Cloth("Linen",
						  ":/MarketManager/images/items/resources/refined_resources/cloths/linen.png",
						  2,
						  true,
						  1.,
						  1.,
						  1.,
						  0.01));
		addItem(new Cloth("Sateen",
						  ":/MarketManager/images/items/resources/refined_resources/cloths/sateen.png",
						  3,
						  true,
						  2.,
						  2.,
						  0.98,
						  0.04));
		addItem(new Cloth("Silk",
						  ":/MarketManager/images/items/resources/refined_resources/cloths/silk.png",
						  4,
						  true,
						  5.5,
						  5.5,
						  0.95,
						  0.07));
		addItem(new Cloth("Infused Silk",
						  ":/MarketManager/images/items/resources/refined_resources/cloths/infused_silk.png",
						  5,
						  true,
						  13.,
						  13.,
						  0.93,
						  0.13));
		addItem(new Cloth("Phoenixweave",
						  ":/MarketManager/images/items/resources/refined_resources/cloths/phoenixweave.png",
						  5,
						  true,
						  145.,
						  145.,
						  0.8,
						  0.19));
	}

	void addLeathers() {
		addItem(new Leather("Coarse Leather",
							":/MarketManager/images/items/resources/refined_resources/leathers/coarse_leather.png",
							2,
							true,
							1.25,
							1.25,
							1.,
							0.01));
		addItem(new Leather("Rugged Leather",
							":/MarketManager/images/items/resources/refined_resources/leathers/rugged_leather.png",
							3,
							true,
							2.1,
							2.1,
							0.98,
							0.04));
		addItem(new Leather("Layered Leather",
							":/MarketManager/images/items/resources/refined_resources/leathers/layered_leather.png",
							4,
							true,
							5.5,
							5.5,
							0.95,
							0.07));
		addItem(new Leather("Infused Leather",
							":/MarketManager/images/items/resources/refined_resources/leathers/infused_leather.png",
							5,
							true,
							8.2,
							8.2,
							0.93,
							0.13));
		addItem(new Leather("Runic Leather",
							":/MarketManager/images/items/resources/refined_resources/leathers/runic_leather.png",
							5,
							true,
							130.,
							130.,
							0.8,
							0.19));
	}

	void addBlocks() {
		addItem(new Leather("Stone Block",
							":/MarketManager/images/items/resources/refined_resources/blocks/stone_block.png",
							2,
							true,
							1.,
							1.,
							1.,
							0.01));
		addItem(new Block("Stone Brick",
						  ":/MarketManager/images/items/resources/refined_resources/blocks/stone_brick.png",
						  3,
						  true,
						  2.3,
						  2.3,
						  0.98,
						  0.04));
		addItem(new Block("Lodestone Brick",
						  ":/MarketManager/images/items/resources/refined_resources/blocks/lodestone_brick.png",
						  4,
						  true,
						  4.2,
						  4.2,
						  0.95,
						  0.07));
		addItem(new Block("Obsidian Voidstone",
						  ":/MarketManager/images/items/resources/refined_resources/blocks/obsidian_voidstone.png",
						  5,
						  true,
						  25.,
						  25.,
						  0.93,
						  0.13));
		addItem(new Block("Runestone",
						  ":/MarketManager/images/items/resources/refined_resources/blocks/runestone.png",
						  5,
						  true,
						  64.,
						  64.,
						  0.8,
						  0.19));
	}

	void addSmelterSet() {
		addItem(new Gear("Smelter's Headgear",
						 ":/MarketManager/images/armour_sets/smelter_set/smelters_headgear.png"));
		addItem(new Gear("Smelter's Smock",
						 ":/MarketManager/images/armour_sets/smelter_set/smelters_smock.png"));
		addItem(new Gear("Smelter's Mitts",
						 ":/MarketManager/images/armour_sets/smelter_set/smelters_mitts.png"));
		addItem(new Gear("Smelter's Pants",
						 ":/MarketManager/images/armour_sets/smelter_set/smelters_pants.png"));
		addItem(new Gear("Smelter's Shoes",
						 ":/MarketManager/images/armour_sets/smelter_set/smelters_shoes.png"));
	}

	void addWoodworkerSet() {
		addItem(new Gear("Woodworker's Cap",
						 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_cap.png"));
		addItem(new Gear("Woodworker's Shirt",
						 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_shirt.png"));
		addItem(new Gear("Woodworker's Gloves",
						 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_gloves.png"));
		addItem(new Gear("Woodworker's Pants",
						 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_pants.png"));
		addItem(new Gear("Woodworker's Shoes",
						 ":/MarketManager/images/armour_sets/woodworker_set/woodworkers_shoes.png"));
	}

	void addWeaverSet() {
		addItem(new Gear("Weaver's Hat",
						 ":/MarketManager/images/armour_sets/weaver_set/weavers_hat.png"));
		addItem(new Gear("Weaver's Shirt",
						 ":/MarketManager/images/armour_sets/weaver_set/weavers_shirt.png"));
		addItem(new Gear("Weaver's Gloves",
						 ":/MarketManager/images/armour_sets/weaver_set/weavers_gloves.png"));
		addItem(new Gear("Weaver's Pants",
						 ":/MarketManager/images/armour_sets/weaver_set/weavers_pants.png"));
		addItem(new Gear("Weaver's Shoes",
						 ":/MarketManager/images/armour_sets/weaver_set/weavers_shoes.png"));
	}

	void addTannerSet() {
		addItem(new Gear("Tanner Hat",
						 ":/MarketManager/images/armour_sets/tanner_set/tanner_hat.png"));
		addItem(new Gear("Tanner Shirt",
						 ":/MarketManager/images/armour_sets/tanner_set/tanner_shirt.png"));
		addItem(new Gear("Tanner Gloves",
						 ":/MarketManager/images/armour_sets/tanner_set/tanner_gloves.png"));
		addItem(new Gear("Tanner Pants",
						 ":/MarketManager/images/armour_sets/tanner_set/tanner_pants.png"));
		addItem(new Gear("Tanner Shoes",
						 ":/MarketManager/images/armour_sets/tanner_set/tanner_shoes.png"));
	}

	void addStonecutterSet() {
		addItem(new Gear("Stonecutter's Hat",
						 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_hat.png"));
		addItem(new Gear("Stonecutter's Shirt",
						 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_shirt.png"));
		addItem(new Gear("Stonecutter's Gloves",
						 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_gloves.png"));
		addItem(new Gear("Stonecutter's Pants",
						 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_pants.png"));
		addItem(new Gear("Stonecutter's Shoes",
						 ":/MarketManager/images/armour_sets/stonecutter_set/stonecutters_shoes.png"));
	}
}
