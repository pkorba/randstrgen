#include "randomstringgenerator.h"

std::string RandomStringGenerator::getString() const {
	std::string randomCharacterString;
	for (int i = 0; i < config.length; ++i) {
		randomCharacterString += base[randombytes_uniform(base.size())];
	}
	return randomCharacterString;
}

void RandomStringGenerator::initValues() {
	lowercaseLetters = "abcdefghijklmnopqrstuvwxyz";
	uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	numbers = "0123456789";
	specialCharacters = "#$%&@^`~.,:;\"'\\/|-<>*+!?={}[]()";
}

RandomStringGenerator::RandomStringGenerator(const Configuration config) {
	if (sodium_init() < 0) {
		exit(1);
	}
	this->config = config;
	initValues();
	if (config.lowercaseLetters) {
		base += lowercaseLetters;
	}
	if (config.uppercaseLetters) {
		base += uppercaseLetters;
	}
	if (config.numbers) {
		base += numbers;
	}
	if (config.specialCharacters) {
		base += specialCharacters;
	}
	if (base.empty()) {
		base += lowercaseLetters + uppercaseLetters + numbers;
	}
}
