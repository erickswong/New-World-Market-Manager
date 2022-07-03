export module image_map;

import "json/json.h";
import <unordered_map>;

namespace image_map {
    std::string PLACEHOLDER = ":/MarketManager/images/placeholder.png";

    std::unordered_map<std::string, std::string> image_map; // Maps the image_name to its image_path

    // Set up image_map
    export void setUp();
	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(const Json::Value& json_value);
	// Returns a json representing image_map
	export [[nodiscard]] Json::Value toJson();
	// Writes a json representing this namespace to disk
	export void writeToDisk();

	// Adds an image
	export void addImage(const std::string& image_name, const std::string& image_path);

    // Gets the image_path with the given image_name. If no such image_name exists, a default image_path is returned.
    export [[nodiscard]] std::string getPath(const std::string& image_name);
};
