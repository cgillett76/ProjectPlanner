#include "../headers/Project.h"
#include <nlohmann/json.hpp>
#include <iostream>

// Constructors & Deconstructors
Project::Project()
{
}

Project::Project(std::string name, std::string startDate, std::string manager)
    : name{name}, startDate{startDate}, manager{manager}
{
}

Project::Project(std::string name, std::string startDate, std::string manager, std::vector<Task> tasks)
    : name{name}, startDate{startDate}, manager{manager}, tasks{tasks}
{
}

Project::~Project()
{
}

// Methods

// ADL serialization in same namespace as Project
namespace nlohmann
{
    void adl_serializer<Project>::to_json(nlohmann::json &j, const Project &project)
    {
        j = json{
            {"name", project.name},
            {"startDate", project.startDate},
            {"manager", project.manager},
            {"tasks", project.tasks}};
    }
    void adl_serializer<Project>::from_json(const nlohmann::json &j, Project &project)
    {
        try
        {
            j.at("name").get_to(project.name);
            j.at("startDate").get_to(project.startDate);
            j.at("manager").get_to(project.manager);
            j.at("tasks").get_to(project.tasks);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}