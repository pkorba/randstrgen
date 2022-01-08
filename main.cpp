#include <iostream>
#include <map>
#include <string>
#include <exception>
#include "randomstringgenerator.h"

enum Commands {
	lowercase,
	uppercase,
	numbers,
	special,
	length,
	help
};

int main(int argc, char **argv) {
	std::map<std::string, Commands> commands;
	commands["--lowercase"] = Commands::lowercase;
	commands["-L"] = Commands::lowercase;
	commands["--uppercase"] = Commands::uppercase;
	commands["-U"] = Commands::uppercase;
	commands["--numbers"] = Commands::numbers;
	commands["-n"] = Commands::numbers;
	commands["--special"] = Commands::special;
	commands["-s"] = Commands::special;
	commands["--length"] = Commands::length;
	commands["-l"] = Commands::length;
	commands["-h"] = Commands::help;
	commands["--help"] = Commands::help;
	Configuration config;
	for (int i = 1; i < argc; ++i) {
		if (commands.find(argv[i]) != commands.end()) {
			switch (commands[argv[i]]) {
				case lowercase:
					config.lowercaseLetters = true;
					break;
				case uppercase:
					config.uppercaseLetters = true;
					break;
				case numbers:
					config.numbers = true;
					break;
				case special:
					config.specialCharacters = true;
					break;
				case length:
				{
					int length;
					if (argc <= i + 1) {
						std::cerr << "No value for 'length' parameter provided." << std::endl;
						exit(1);
					}
					else {
						try {
							// konwersja na int
							length = std::stoi(argv[i + 1]);
						}
						catch (std::invalid_argument) {
							std::cerr << "Invalid value '" + std::string(argv[i + 1])
									+ "' provided for 'length' parameter." << std::endl;
							exit(1);
						}
						catch (std::out_of_range) {
							std::cerr << "Value '" + std::string(argv[i + 1])
									+ "' is out of range for 'length' parameter." << std::endl;
							exit(1);
						}
					}
					config.length = length;
					++i;
					break;
				}
				case help:
				{
					std::cout << "randstrgen - generates random strings"
							  << "\nUsage:"
							  << "\n\trandstrgen [OPTIONS]"
							  << "\nOptions:"
							  << "\n\t-h,	--help		show this descrition and terminate"
							  << "\n\t-l,	--length	define desired length of string"
							  << "\n\t-L,	--lowercase	use lowercase letters a-z"
							  << "\n\t-n,	--numbers	use numbers 0-9"
							  << "\n\t-s,	--special	use special characters"
							  << "\n\t-U,	--uppercase	use uppercase letters A-Z"
							  << "\n\t"
							  << std::endl;
					exit(0);
					break;
				}
			}
		}
		else {
			std::cerr << "Invalid '" + std::string(argv[i]) + "' parameter." << std::endl;
			exit(1);
		}
	}
	RandomStringGenerator rsg(config);
	std::cout << rsg.getString() << std::endl;
	return 0;
}
