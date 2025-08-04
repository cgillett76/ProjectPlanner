#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "headers/Project.h"
#include <nlohmann/json.hpp>
#include <nlohmann/json-schema.hpp>

int main()
{

	Project *gensis = new Project{"Genesis", "04-08-2025", "Chris Gillett"};

	nlohmann::json gensisJson = *gensis;

	std::cout << gensisJson.dump(4) << std::endl;

	return 0;
}