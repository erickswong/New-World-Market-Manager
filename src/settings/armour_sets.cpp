module settings:armour_sets;

import items;

using items::RefiningGear;

namespace settings::armour_sets {
    double smeltingYieldBonus() {
        return
            items::getItem<RefiningGear>("Smelter's Headgear")->yieldBonus() +
            items::getItem<RefiningGear>("Smelter's Smock")->yieldBonus() +
            items::getItem<RefiningGear>("Smelter's Mitts")->yieldBonus() +
            items::getItem<RefiningGear>("Smelter's Pants")->yieldBonus() +
            items::getItem<RefiningGear>("Smelter's Shoes")->yieldBonus();
    }

    double woodworkingYieldBonus() {
        return
            items::getItem<RefiningGear>("Woodworker's Cap")->yieldBonus() +
            items::getItem<RefiningGear>("Woodworker's Shirt")->yieldBonus() +
            items::getItem<RefiningGear>("Woodworker's Gloves")->yieldBonus() +
            items::getItem<RefiningGear>("Woodworker's Pants")->yieldBonus() +
            items::getItem<RefiningGear>("Woodworker's Shoes")->yieldBonus();
    }

    double weavingYieldBonus() {
        return
            items::getItem<RefiningGear>("Weaver's Hat")->yieldBonus() +
            items::getItem<RefiningGear>("Weaver's Shirt")->yieldBonus() +
            items::getItem<RefiningGear>("Weaver's Gloves")->yieldBonus() +
            items::getItem<RefiningGear>("Weaver's Pants")->yieldBonus() +
            items::getItem<RefiningGear>("Weaver's Shoes")->yieldBonus();
    }

    double leatherworkingYieldBonus() {
        return
            items::getItem<RefiningGear>("Tanner Hat")->yieldBonus() +
            items::getItem<RefiningGear>("Tanner Shirt")->yieldBonus() +
            items::getItem<RefiningGear>("Tanner Gloves")->yieldBonus() +
            items::getItem<RefiningGear>("Tanner Pants")->yieldBonus() +
            items::getItem<RefiningGear>("Tanner Shoes")->yieldBonus();
    }

    double stonecuttingYieldBonus() {
        return
            items::getItem<RefiningGear>("Stonecutter's Hat")->yieldBonus() +
            items::getItem<RefiningGear>("Stonecutter's Shirt")->yieldBonus() +
            items::getItem<RefiningGear>("Stonecutter's Gloves")->yieldBonus() +
            items::getItem<RefiningGear>("Stonecutter's Pants")->yieldBonus() +
            items::getItem<RefiningGear>("Stonecutter's Shoes")->yieldBonus();
    }
}
