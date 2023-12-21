#include "Parser.h"

const int HELP_ARG_NUM = 2;
const int DEFAULT_ARG_NUM = 5;
const int PARSE_POS = 3;

std::pair<std::string, std::vector<std::string>> Parser::parseArgs(int argc, char** argv) {
	if (argc == HELP_ARG_NUM) {
		if (argv[1][0] == '-' && argv[1][1] == 'h') {
			return std::pair<std::string, std::vector<std::string>>{"help", std::vector<std::string>{"help"}};
		}
		else {
			throw std::runtime_error("Error while parsing arguments: wrong arguments!");
		}
	}
	if (argc < DEFAULT_ARG_NUM) {
		throw std::runtime_error("Error while parsing arguments: too few arguments!");
	}

	std::pair<std::string, std::vector<std::string>> res;

	if (argv[1][0] != '-' && argv[1][1] != 'c') {
		throw std::runtime_error("Error while parsing arguments: wrong arguments!");
	}

	res.first = argv[2];
	for (Size i = PARSE_POS; i < argc; ++i) {
		res.second.emplace_back(argv[i]);
	}

	return res;
}
