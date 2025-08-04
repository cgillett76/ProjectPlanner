#include "../headers/Task.h"

// Constructors & Deconstructors
Task::Task()
{
}

Task::Task(std::string name, std::string startDate, int durationDays, std::string endDate)
    : name{name}, startDate{startDate}, durationDays{durationDays}, endDate{endDate}
{
}

Task::~Task()
{
}

// Methods

// ADL serialization in same namespace as Task
namespace nlohmann
{
    void adl_serializer<Task>::to_json(nlohmann::json &j, const Task &task)
    {
        j = json{
            {"name", task.name},
            {"startDate", task.startDate},
            {"durationDays", task.durationDays},
            {"endDate", task.endDate}};
    }
    void adl_serializer<Task>::from_json(const nlohmann::json &j, Task &task)
    {
        try
        {
            j.at("name").get_to(task.name);
            j.at("startDate").get_to(task.startDate);
            j.at("durationDays").get_to(task.durationDays);
            j.at("endDate").get_to(task.endDate);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}