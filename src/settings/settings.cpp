module settings;

import exceptions;
import std.core;
import std.filesystem;

namespace settings {
    void setUp() {
        try {
            // Open file for reading
            std::ifstream file("data/settings.json");
            Json::Reader reader;
            Json::Value json_value;

            // Read file into json_value
            if (!reader.parse(file, json_value)) {
                throw BadJsonException("Unable to parse settings.json");
            }

            // Set members to values from json
            fromJson(json_value);
        } catch (const std::exception&) {
            // Reset members to default values
            reset();

            // TODO: alert that creating settings from json was unsuccessful with message e.what()
        }
    }

    void reset() noexcept {
        fort_bonuses::reset();
        standing_bonuses::reset();
        taxes::reset();
        trade_skills::reset();
    }

    void fromJson(const Json::Value& json_value) {
        try {
            fort_bonuses::fromJson(json_value["fort_bonuses"]);
            standing_bonuses::fromJson(json_value["standing_bonuses"]);
            taxes::fromJson(json_value["taxes"]);
            trade_skills::fromJson(json_value["trade_skills"]);
        } catch (const std::exception& e) {
            throw BadJsonException("settings is malformed", e);
        }
    }

    Json::Value toJson() {
        Json::Value json_value;

        json_value["fort_bonuses"]     = fort_bonuses::toJson();
        json_value["standing_bonuses"] = standing_bonuses::toJson();
        json_value["taxes"]            = taxes::toJson();
        json_value["trade_skills"]     = trade_skills::toJson();

        return json_value;
    }

    void writeToDisk() {
        // Create data directory if missing
        std::filesystem::create_directory("data");

        // Create settings.json file
        std::ofstream file("data/settings.json");

        // Write json into file
        Json::StyledWriter styled_writer;
        file << styled_writer.write(toJson());
    }

    double smeltingYieldBonus() {
        return trade_skills::smeltingYieldBonus() + armour_sets::smeltingYieldBonus() + fort_bonuses::yieldBonus();
    }

    double woodworkingYieldBonus() {
        return trade_skills::woodworkingYieldBonus() + armour_sets::woodworkingYieldBonus() + fort_bonuses::yieldBonus();
    }

    double leatherworkingYieldBonus() {
        return trade_skills::leatherworkingYieldBonus() + armour_sets::leatherworkingYieldBonus() + fort_bonuses::yieldBonus();
    }

    double weavingYieldBonus() {
        return trade_skills::weavingYieldBonus() + armour_sets::weavingYieldBonus() + fort_bonuses::yieldBonus();
    }

    double stonecuttingYieldBonus() {
        return trade_skills::stonecuttingYieldBonus() + armour_sets::stonecuttingYieldBonus() + fort_bonuses::yieldBonus();
    }
}
