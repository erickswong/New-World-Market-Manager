export module exceptions;

import <fstream>;
import std.filesystem;

// throw Exception;
// catch (const Exception&)

namespace exceptions {
	// Writes a crash dump to disk given an exception
	export void logCrash(const std::exception& e) {
		// Get time of crash
		auto seconds_since_epoch = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

		// Create crash dump directory
		std::stringstream dirName;
		dirName << "log/crashdump_" << seconds_since_epoch;
		std::filesystem::create_directories(dirName.str());

		// Create info.txt file
		std::ofstream file(dirName.str() + "/info.txt");

		// Write message into file
		file << e.what();
	}

	// Writes a crash dump to disk given a return code
	export void logCrash(int returnCode) {
		// Get time of crash
		auto seconds_since_epoch = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

		// Create crash dump directory
		std::stringstream dirName;
		dirName << "log/crashdump_" << seconds_since_epoch;
		std::filesystem::create_directories(dirName.str());

		// Create info.txt file
		std::ofstream file(dirName.str() + "/info.txt");

		// Write message into file
		file << "[Application Error] Application returned with return code: " << returnCode;
	}
};

class MarketManagerException : public std::exception {
	std::string message;

	protected:
		MarketManagerException() = default;

	public:
		[[nodiscard]] const char* what() const noexcept override {
			return message.c_str();
		}

		void setMessage(const std::string& message) {
			this->message = message;
		}
};

export class NotImplementedException final : public MarketManagerException {
	inline static const std::string TAG = "[Not Implemented] ";

	public:
		explicit NotImplementedException(const std::string& message) {
			setMessage(TAG + message);
		}
};

export class NotUsedException final : public MarketManagerException {
	inline static const std::string TAG = "[Not Used] ";

	public:
		explicit NotUsedException(const std::string& message) {
			setMessage(TAG + message);
		}
};

export class BadValueException final : public MarketManagerException {
	inline static const std::string TAG = "[Bad Value] ";

	public:
		explicit BadValueException(const std::string& message) {
			setMessage(TAG + message);
		}
};

export class BadJsonException final : public MarketManagerException {
	inline static const std::string TAG = "[Bad JSON] ";

	public:
		explicit BadJsonException(const std::string& message) {
			setMessage(TAG + message);
		}
		BadJsonException(const std::string& message, const std::exception& e) {
			setMessage(std::string(e.what()) + "\n" + TAG + message);
		}
};
