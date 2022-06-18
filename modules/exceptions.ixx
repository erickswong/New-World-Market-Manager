export module exceptions;

import <exception>;
import <string>;

// throw Exception;
// catch (const Exception&)

export class NotImplementedException final : std::exception {
	std::string message = "[Not Implemented]";

	public:

	explicit NotImplementedException(const std::string& message) {
		this->message += " " + message;
	}

	[[nodiscard]] const char* what() const noexcept override {
		return message.c_str();
	}
};

export class NotUsedException final : std::exception {
	std::string message = "[Not Used]";

	public:

	explicit NotUsedException(const std::string& message) {
		this->message += " " + message;
	}

	[[nodiscard]] const char* what() const noexcept override {
		return message.c_str();
	}
};

export class BadValueException final : std::exception {
	std::string message = "[Bad Value]";

	public:

	explicit BadValueException(const std::string& message) {
		this->message += " " + message;
	}

	[[nodiscard]] const char* what() const noexcept override {
		return message.c_str();
	}
};

export class BadJsonException final : std::exception {
	std::string message = "[Bad JSON]";

	public:

	explicit BadJsonException(const std::string& message) {
		this->message += " " + message;
	}
	BadJsonException(const std::string& message, const std::exception& e) {
		this->message += " " + message + "\n" + e.what();
	}

	[[nodiscard]] const char* what() const noexcept override {
		return message.c_str();
	}
};
