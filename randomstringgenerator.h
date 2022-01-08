#ifndef RANDOMSTRINGGENERATOR_H
#define RANDOMSTRINGGENERATOR_H

#include <string>
#include <vector>
#include <sodium.h>

class Configuration {
public:
	bool lowercaseLetters = false;
	bool uppercaseLetters = false;
	bool numbers = false;
	bool specialCharacters = false;
	int length = 14;
};

class RandomStringGenerator {
private:
	Configuration config;
	std::string base;
	std::string lowercaseLetters;
	std::string uppercaseLetters;
	std::string numbers;
	std::string specialCharacters;
	void initValues();
public:
	RandomStringGenerator(const Configuration config);
	std::string getString() const;
};

#endif // RANDOMSTRINGGENERATOR_H
