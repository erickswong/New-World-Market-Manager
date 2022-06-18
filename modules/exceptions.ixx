export module exceptions;

import <exception>;
import <string>;

// throw Exception;
// catch (const Exception&)

export class NotImplementedException final : public std::exception {
	public:
		explicit NotImplementedException(const std::string& message) {
			this->message += " " + message;
		}

		[[nodiscard]] const char* what() const noexcept override {
			return message.c_str();
		}

	private:
		std::string message = "[Not Implemented]";
};

export class NotUsedException final : public std::exception {
	public:
		explicit NotUsedException(const std::string& message) {
			this->message += " " + message;
		}

		[[nodiscard]] const char* what() const noexcept override {
			return message.c_str();
		}

	private:
		std::string message = "[Not Used]";
};

export class BadValueException final : public std::exception {
	public:
		explicit BadValueException(const std::string& message) {
			this->message += " " + message;
		}

		[[nodiscard]] const char* what() const noexcept override {
			return message.c_str();
		}

	private:
		std::string message = "[Bad Value]";
};

export class BadJsonException final : public std::exception {
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

	private:
		std::string message = "[Bad JSON]";
};
