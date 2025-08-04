#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "headers/Project.h"
#include "headers/Task.h"
#include <nlohmann/json.hpp>
#include <nlohmann/json-schema.hpp>

int main()
{
	std::vector<Task> gensisTasks;

	Task *firstTask = new Task{"First task", "04-08-2025", 5, "09-08-2025"};
	Task *secondTask = new Task{"Second task", "12-08-2025", 5, "17-08-2025"};

	gensisTasks.push_back(*firstTask);
	gensisTasks.push_back(*secondTask);

	Project *gensis = new Project{"Genesis", "04-08-2025", "Chris Gillett", gensisTasks};

	nlohmann::json gensisJson = *gensis;

	std::cout << gensisJson.dump(4) << std::endl;

	return 0;
}