export module exceptions;

import <exception>;

// throw Exception();
// catch (const Exception&)

export struct NotImplementedException final : std::exception {
	[[nodiscard]] const char* what() const noexcept override {
		return "Not Implemented";
	}
};

export struct NotUsedException final : std::exception {
	[[nodiscard]] const char* what() const noexcept override {
		return "Not Used";
	}
};

export struct BadJsonException final : std::exception {
	BadJsonException() = default;
	explicit BadJsonException(const char* message)
		: message(message) {
	}

	[[nodiscard]] const char* what() const noexcept override {
		return message;
	}

	private:
		const char* message = "Bad JSON";
};
