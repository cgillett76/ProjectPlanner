#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "headers/Project.h"
#include "headers/Task.h"
#include "headers/Utilities.h"
#include <nlohmann/json.hpp>
#include <nlohmann/json-schema.hpp>

int main()
{
	// Project *gensis = new Project{"Genesis", "04-08-2025", "Chris Gillett"};
	Project gensis{"Genesis", "04-08-2025", "Chris Gillett"};

	gensis.createProjectTask("First task", "04-08-2025", 5);
	gensis.createProjectTask("Second task", "12-08-2025", 5);
	gensis.createProjectTask("Third task", "20-08-2025", 5);

	nlohmann::json gensisJson = gensis;

	std::cout << gensisJson.dump(4) << std::endl;

	// delete gensis;

	return 0;
}
