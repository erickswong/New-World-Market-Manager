module image_map;

import exceptions;
import std.core;
import std.filesystem;

import :default_image_map;

namespace image_map {
    void setUp() {
		try {
			// Open file for reading
			std::ifstream file("data/image_map.json");
			Json::Reader reader;
			Json::Value json_value;

			// Read file into json_value
			if (!reader.parse(file, json_value)) {
				throw BadJsonException("Unable to parse image_map.json");
			}

			// Set members to values from json
			fromJson(json_value);
		} catch (const std::exception&) {
			// Reset members to default values
			default_image_map::setUp();

			// TODO: alert that creating image_map from json was unsuccessful with message e.what()
		}
    }

    void image_map::reset() noexcept {
		image_map.clear();
    }

    void fromJson(const Json::Value& json_value) {
		try {
			reset();

			for (const std::string& image_name : json_value.getMemberNames()) {
                addImage(image_name, json_value[image_name].asString());
			}
		} catch (const std::exception& e) {
			throw BadJsonException("image_map is malformed", e);
		}
    }

    Json::Value toJson() {
		Json::Value json_value;

		for (const auto& [image_name, image_path] : image_map) {
			json_value[image_name] = image_path;
		}

		return json_value;
    }

    void writeToDisk() {
		// Create data directory if missing
		std::filesystem::create_directory("data");

		// Create image_map.json file
		std::ofstream file("data/image_map.json");

		// Write json into file
		Json::StyledWriter styled_writer;
		file << styled_writer.write(toJson());
    }

    void addImage(const std::string& image_name, const std::string& image_path) {
		if (!image_map.insert({ image_name, image_path }).second) {
			throw BadValueException("Unable to add duplicate image \"" + image_name + "\"");
		}
    }

    std::string getPath(const std::string& image_name) {
        try {
            return image_map.at(image_name);
        } catch (const std::out_of_range&) {
            return PLACEHOLDER;
        }
    }
}
