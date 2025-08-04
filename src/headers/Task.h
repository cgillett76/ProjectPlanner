#ifndef _TASK_H_
#define _TASK_H_

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <nlohmann/json.hpp>

class Task
{
private:
    std::string name;
    std::string startDateStr;
    int durationDays;
    std::string endDateStr;
    std::chrono::year_month_day startDate;
    std::chrono::year_month_day endDate;

public:
    // Constructors & Deconstructors
    Task();
    Task(std::string name, std::string startDateStr, int durationDays, std::string endDateStr);
    ~Task();

    // Method Prototypes
    friend struct nlohmann::adl_serializer<Task>;
};

// ADL serialiation for Task
namespace nlohmann
{
    template <>
    struct adl_serializer<Task>
    {
        static void to_json(nlohmann::json &j, const Task &task);
        static void from_json(const nlohmann::json &j, Task &task);
    };
}

#endif