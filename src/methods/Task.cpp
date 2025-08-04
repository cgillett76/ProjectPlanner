#include "../headers/Task.h"
#include "../headers/Utilities.h"

// Constructors & Deconstructors
Task::Task()
{
}

Task::Task(std::string name, std::string startDateStr, int durationDays, std::string endDateStr)
    : name{name}, startDateStr{startDateStr}, durationDays{durationDays}, endDateStr{endDateStr}, startDate{convertDate(startDateStr)}, endDate{convertDate(endDateStr)}
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
            {"startDate", task.startDateStr},
            {"durationDays", task.durationDays},
            {"endDate", task.endDateStr}};
    }
    void adl_serializer<Task>::from_json(const nlohmann::json &j, Task &task)
    {
        try
        {
            j.at("name").get_to(task.name);
            j.at("startDate").get_to(task.startDateStr);
            j.at("durationDays").get_to(task.durationDays);
            j.at("endDate").get_to(task.endDateStr);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}