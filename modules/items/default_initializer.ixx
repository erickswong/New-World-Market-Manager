export module items:default_initializer;

import items;

export class DefaultInitializer {
	public:
		explicit DefaultInitializer(Items* items);

		void init() const;

	private:
		Items* items;

		void addResources() const;
		void addArmourSets() const;

		void addRawResources() const;
		void addRefinedResources() const;
		void addRefiningComponents() const;

		void addOres() const;
		void addWoods() const;
		void addFibers() const;
		void addRawhides() const;
		void addStones() const;

		void addIngots() const;
		void addPlanks() const;
		void addCloths() const;
		void addLeathers() const;
		void addBlocks() const;

		void addCharcoal() const;
		void addIronIngot() const;
		void addSteelIngot() const;
		void addStarmetalIngot() const;
		void addOrichalcumIngot() const;
		void addSilverIngot() const;
		void addGoldIngot() const;
		void addPlatinumIngot() const;
		void addAsmodeum() const;

		void addTimber() const;
		void addLumber() const;
		void addWyrdwoodPlanks() const;
		void addIronwoodPlanks() const;
		void addGlitteringEbony() const;

		void addLinen() const;
		void addSateen() const;
		void addSilk() const;
		void addInfusedSilk() const;
		void addPhoenixweave() const;

		void addCoarseLeather() const;
		void addRuggedLeather() const;
		void addLayeredLeather() const;
		void addInfusedLeather() const;
		void addRunicLeather() const;

		void addStoneBlock() const;
		void addStoneBrick() const;
		void addLodestoneBrick() const;
		void addObsidianVoidstone() const;
		void addRunestone() const;

		void addSmelterSet() const;
		void addWoodworkerSet() const;
		void addWeaverSet() const;
		void addTannerSet() const;
		void addStonecutterSet() const;

		void addFluxes() const;
		void addSandpapers() const;
		void addWeaves() const;
		void addTannins() const;
		void addSolvents() const;
};
