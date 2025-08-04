#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <chrono>
#include <nlohmann/json.hpp>

class Project
{
private:
    std::string name;
    std::string startDate;
    std::string manager;

public:
    // Constructors & Deconstructors
    Project();
    Project(std::string name, std::string startDate, std::string manager);
    ~Project();

    // Method prototypes
    friend struct nlohmann::adl_serializer<Project>;
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