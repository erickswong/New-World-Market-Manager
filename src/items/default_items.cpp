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
									  5,
									  false,
									  2.2,
									  1.8));
		addItem(new RefiningComponent("Obsidian Sandpaper",
									  5,
									  false,
									  0.5,
									  0.3));
		addItem(new RefiningComponent("Wireweave",
									  5,
									  false,
									  0.25,
									  0.15));
		addItem(new RefiningComponent("Aged Tannin",
									  5,
									  false,
									  0.25,
									  0.2));
		addItem(new RefiningComponent("Pure Solvent",
									  5,
									  false,
									  1.,
									  1.));
	}

	void addOres() {
		addItem(new RawResource("Iron Ore",
								1,
								false,
								0.35,
								0.3));
		addItem(new RawResource("Starmetal Ore",
								4,
								false,
								1.3,
								1.1));
		addItem(new RawResource("Orichalcum Ore",
								5,
								false,
								2.5,
								2.2));
		addItem(new RawResource("Silver Ore",
								2,
								false,
								0.2,
								0.15));
		addItem(new RawResource("Gold Ore",
								3,
								false,
								0.4,
								0.25));
		addItem(new RawResource("Platinum Ore",
								4,
								false,
								1.,
								0.75));
		addItem(new RawResource("Cinnabar",
								5,
								true,
								15.,
								15.));
		addItem(new RawResource("Tolvium",
								5,
								true,
								15.,
								15.));
	}

	void addWoods() {
		addItem(new RawResource("Green Wood",
								1,
								false,
								0.25,
								0.2));
		addItem(new RawResource("Aged Wood",
								2,
								false,
								0.25,
								0.2));
		addItem(new RawResource("Wyrdwood",
								4,
								false,
								1.1,
								0.9));
		addItem(new RawResource("Ironwood",
								5,
								false,
								0.75,
								0.6));
		addItem(new RawResource("Wildwood",
								5,
								true,
								10.,
								10.));
		addItem(new RawResource("Barbvine",
								5,
								true,
								10.,
								10.));
	}

	void addFibers() {
		addItem(new RawResource("Fibers",
								1,
								false,
								0.2,
								0.15));
		addItem(new RawResource("Silk Threads",
								4,
								false,
								0.7,
								0.5));
		addItem(new RawResource("Wirefiber",
								5,
								false,
								0.6,
								0.45));
		addItem(new RawResource("Blisterweave",
								5,
								true,
								7.5,
								7.5));
		addItem(new RawResource("Scalecloth",
								5,
								true,
								7.5,
								7.5));
	}

	void addRawhides() {
		addItem(new RawResource("Rawhide",
								1,
								false,
								0.35,
								0.3));
		addItem(new RawResource("Thick Hide",
								4,
								false,
								0.6,
								0.55));
		addItem(new RawResource("Iron Hide",
								5,
								false,
								0.1,
								0.05));
		addItem(new RawResource("Smolderhide",
								5,
								true,
								15.,
								15.));
		addItem(new RawResource("Scarhide",
								5,
								true,
								15.,
								15.));
	}

	void addStones() {
		addItem(new RawResource("Stone",
								1,
								false,
								0.2,
								0.15));
		addItem(new RawResource("Lodestone",
								4,
								false,
								0.6,
								0.5));
		addItem(new RawResource("Elemental Lodestone",
								3,
								false,
								0.5,
								0.1));
	}

	void addIngots() {
		addItem(new Ingot("Charcoal",
						  2,
						  false,
						  0.4,
						  0.35,
						  1.,
						  0.01));
		addItem(new Ingot("Iron Ingot",
						  2,
						  true,
						  1.2,
						  1.2,
						  1.,
						  0.01));
		addItem(new Ingot("Steel Ingot",
						  3,
						  true,
						  4.5,
						  4.5,
						  0.98,
						  0.04));
		addItem(new Ingot("Starmetal Ingot",
						  4,
						  true,
						  13.,
						  13.,
						  0.95,
						  0.07));
		addItem(new Ingot("Orichalcum Ingot",
						  5,
						  true,
						  40.,
						  40.,
						  0.93,
						  0.13));
		addItem(new Ingot("Silver Ingot",
						  2,
						  true,
						  0.6,
						  0.6,
						  0.98,
						  0.01));
		addItem(new Ingot("Gold Ingot",
						  3,
						  true,
						  3.75,
						  3.75,
						  0.95,
						  0.04));
		addItem(new Ingot("Platinum Ingot",
						  4,
						  true,
						  11.,
						  11.,
						  0.93,
						  0.07));
		addItem(new Ingot("Asmodeum",
						  5,
						  true,
						  300.,
						  300.,
						  0.8,
						  0.19));
	}

	void addPlanks() {
		addItem(new Plank("Timber",
						  2,
						  true,
						  1.,
						  1.,
						  1.,
						  0.01));
		addItem(new Plank("Lumber",
						  3,
						  true,
						  2.2,
						  2.2,
						  0.98,
						  0.04));
		addItem(new Plank("Wyrdwood Planks",
						  4,
						  true,
						  8.5,
						  8.5,
						  0.95,
						  0.07));
		addItem(new Plank("Ironwood Planks",
						  5,
						  true,
						  16.,
						  16.,
						  0.93,
						  0.13));
		addItem(new Plank("Glittering Ebony",
						  5,
						  true,
						  70.,
						  70.,
						  0.8,
						  0.19));
	}

	void addCloths() {
		addItem(new Cloth("Linen",
						  2,
						  true,
						  1.,
						  1.,
						  1.,
						  0.01));
		addItem(new Cloth("Sateen",
						  3,
						  true,
						  2.,
						  2.,
						  0.98,
						  0.04));
		addItem(new Cloth("Silk",
						  4,
						  true,
						  5.5,
						  5.5,
						  0.95,
						  0.07));
		addItem(new Cloth("Infused Silk",
						  5,
						  true,
						  13.,
						  13.,
						  0.93,
						  0.13));
		addItem(new Cloth("Phoenixweave",
						  5,
						  true,
						  145.,
						  145.,
						  0.8,
						  0.19));
	}

	void addLeathers() {
		addItem(new Leather("Coarse Leather",
							2,
							true,
							1.25,
							1.25,
							1.,
							0.01));
		addItem(new Leather("Rugged Leather",
							3,
							true,
							2.1,
							2.1,
							0.98,
							0.04));
		addItem(new Leather("Layered Leather",
							4,
							true,
							5.5,
							5.5,
							0.95,
							0.07));
		addItem(new Leather("Infused Leather",
							5,
							true,
							8.2,
							8.2,
							0.93,
							0.13));
		addItem(new Leather("Runic Leather",
							5,
							true,
							130.,
							130.,
							0.8,
							0.19));
	}

	void addBlocks() {
		addItem(new Leather("Stone Block",
							2,
							true,
							1.,
							1.,
							1.,
							0.01));
		addItem(new Block("Stone Brick",
						  3,
						  true,
						  2.3,
						  2.3,
						  0.98,
						  0.04));
		addItem(new Block("Lodestone Brick",
						  4,
						  true,
						  4.2,
						  4.2,
						  0.95,
						  0.07));
		addItem(new Block("Obsidian Voidstone",
						  5,
						  true,
						  25.,
						  25.,
						  0.93,
						  0.13));
		addItem(new Block("Runestone",
						  5,
						  true,
						  64.,
						  64.,
						  0.8,
						  0.19));
	}

	void addSmelterSet() {
		addItem(new Gear(std::string("Smelter's Headgear")));
		addItem(new Gear(std::string("Smelter's Smock")));
		addItem(new Gear(std::string("Smelter's Mitts")));
		addItem(new Gear(std::string("Smelter's Pants")));
		addItem(new Gear(std::string("Smelter's Shoes")));
	}

	void addWoodworkerSet() {
		addItem(new Gear(std::string("Woodworker's Cap")));
		addItem(new Gear(std::string("Woodworker's Shirt")));
		addItem(new Gear(std::string("Woodworker's Gloves")));
		addItem(new Gear(std::string("Woodworker's Pants")));
		addItem(new Gear(std::string("Woodworker's Shoes")));
	}

	void addWeaverSet() {
		addItem(new Gear(std::string("Weaver's Hat")));
		addItem(new Gear(std::string("Weaver's Shirt")));
		addItem(new Gear(std::string("Weaver's Gloves")));
		addItem(new Gear(std::string("Weaver's Pants")));
		addItem(new Gear(std::string("Weaver's Shoes")));
	}

	void addTannerSet() {
		addItem(new Gear(std::string("Tanner Hat")));
		addItem(new Gear(std::string("Tanner Shirt")));
		addItem(new Gear(std::string("Tanner Gloves")));
		addItem(new Gear(std::string("Tanner Pants")));
		addItem(new Gear(std::string("Tanner Shoes")));
	}

	void addStonecutterSet() {
		addItem(new Gear(std::string("Stonecutter's Hat")));
		addItem(new Gear(std::string("Stonecutter's Shirt")));
		addItem(new Gear(std::string("Stonecutter's Gloves")));
		addItem(new Gear(std::string("Stonecutter's Pants")));
		addItem(new Gear(std::string("Stonecutter's Shoes")));
	}
}
