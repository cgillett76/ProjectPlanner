#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <string>
#include <vector>
#include <chrono>
#include <nlohmann/json.hpp>
#include "Task.h"
#include "Utilities.h"

class Project
{
private:
    std::string name;
    std::chrono::year_month_day startDate;
    std::string manager;
    std::string startDateStr;
    std::vector<Task> tasks;

public:
    // Constructors & Deconstructors
    Project();
    Project(std::string name, std::string startDate, std::string manager);
    Project(std::string name, std::string startDate, std::string manager, std::vector<Task> tasks);
    ~Project();

    // Method prototypes
    friend struct nlohmann::adl_serializer<Project>;
    void createProjectTask(std::string name, std::string startDate, int duration);
    void createProjectTask(std::string name, std::string startDate, int duration, std::string endDate);
};

// ADL serialiation
namespace nlohmann
{
    template <>
    struct adl_serializer<Project>
    {
        static void to_json(nlohmann::json &j, const Project &project);
        static void from_json(const nlohmann::json &j, Project &project);
    };
}

#endif