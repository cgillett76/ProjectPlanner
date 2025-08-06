#include "../headers/Project.h"
#include "../headers/Utilities.h"

// Constructors & Deconstructors
Project::Project()
{
}

Project::Project(std::string name, std::string startDate, std::string manager)
    : name{name}, startDate{convertDate(startDate)}, manager{manager}, startDateStr{startDate}
{
}

Project::Project(std::string name, std::string startDate, std::string manager, std::vector<Task> tasks)
    : name{name}, startDate{convertDate(startDate)}, manager{manager}, tasks{tasks}
{
}

Project::~Project()
{
}

// Methods
void Project::createProjectTask(std::string name, std::string startDate, int duration)
{
    Task task{name, startDate, duration};
    this->tasks.push_back(task);
}

void Project::createProjectTask(std::string name, std::string startDate, int duration, std::string endDate)
{
    Task task{name, startDate, duration, endDate};
    this->tasks.push_back(task);
}

// ADL serialization in same namespace as Project
namespace nlohmann
{
    void adl_serializer<Project>::to_json(nlohmann::json &j, const Project &project)
    {
        j = json{
            {"name", project.name},
            {"startDate", project.startDateStr},
            {"manager", project.manager},
            {"tasks", project.tasks}};
    }
    void adl_serializer<Project>::from_json(const nlohmann::json &j, Project &project)
    {
        try
        {

            j.at("name").get_to(project.name);
            // j.at("startDate").get_to(project.startDate);
            j.at("startDate").get_to(project.startDateStr);
            j.at("manager").get_to(project.manager);
            j.at("tasks").get_to(project.tasks);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}