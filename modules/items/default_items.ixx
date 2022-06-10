export module items:default_items;

import items;

namespace default_items {
	Items* items;

	// Perform default initialization for items
	export void init(Items* items);

	void addResources();
	void addArmourSets();

	void addRawResources();
	void addRefinedResources();
	void addRefiningComponents();

	void addOres();
	void addWoods();
	void addFibers();
	void addRawhides();
	void addStones();

	void addIngots();
	void addPlanks();
	void addCloths();
	void addLeathers();
	void addBlocks();

	void addCharcoal();
	void addIronIngot();
	void addSteelIngot();
	void addStarmetalIngot();
	void addOrichalcumIngot();
	void addSilverIngot();
	void addGoldIngot();
	void addPlatinumIngot();
	void addAsmodeum();

	void addTimber();
	void addLumber();
	void addWyrdwoodPlanks();
	void addIronwoodPlanks();
	void addGlitteringEbony();

	void addLinen();
	void addSateen();
	void addSilk();
	void addInfusedSilk();
	void addPhoenixweave();

	void addCoarseLeather();
	void addRuggedLeather();
	void addLayeredLeather();
	void addInfusedLeather();
	void addRunicLeather();

	void addStoneBlock();
	void addStoneBrick();
	void addLodestoneBrick();
	void addObsidianVoidstone();
	void addRunestone();

	void addSmelterSet();
	void addWoodworkerSet();
	void addWeaverSet();
	void addTannerSet();
	void addStonecutterSet();

	void addFluxes();
	void addSandpapers();
	void addWeaves();
	void addTannins();
	void addSolvents();
};
