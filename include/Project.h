#pragma once
#ifndef STAFFDEMO_INCLUDE_PROJECT_H_
#define STAFFDEMO_INCLUDE_PROJECT_H_

#include "Employee.h"
#include "Interfaces.h"
#include <vector>

class Project {
 public:
  Project() = default;
  Project(int id, int budget);
  int get_budget() const;
  int get_id() const;
  void set_budget(int budget);
 private:
  int id;
  int budget;
};


class ProjectManager : public Employee, public Project_Budget, public Project, public Heading {
 public:
  ProjectManager(int id, std::string name, int workTime, Positions position, std::vector<Project*>& projects);
  ~ProjectManager() override = default;
  int calc_budget_part() override;
  int calc_pro_additions(int bonus) override;
  void calc_salary(int bonus) override;
  void print_info() override;
 private:
  std::vector<Project*> projects;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, int workTime, Positions position, std::vector<Project*>& projects);
  ~SeniorManager() override = default;
  int calc_budget_part() override;
  int calc_pro_additions(int bonus) override;
  void calc_salary(int bonus) override;
  void print_info() override;
 private:
  std::vector<Project*> projects;
};

#endif //STAFFDEMO_INCLUDE_PROJECT_H_
