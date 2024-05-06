#pragma once
#ifndef STAFFDEMO_INCLUDE_ENGINEER_H_
#define STAFFDEMO_INCLUDE_ENGINEER_H_

#include <iostream>
#include "Personal.h"
#include "Interfaces.h"

class Project;


class Engineer : public Personal, public Project_Budget {
 public:
  Engineer(int id, std::string name, int work_time, int salary, Positions position, int payment, Project* project);
  virtual ~Engineer() = default;
  int calc_budget_part() override;
  void calc_salary(int bonus) override;
  void print_info() override;
 protected:
  Project* project;
};


class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, int work_time, Positions position, int payment, Project* project);
  ~Programmer() override = default;
  void calc_salary(int bonus) override;
  int calc_pro_additions(int bonus) override;
  void print_info() override;
};


class Tester : public Engineer {
 public:
  Tester(int id, std::string name, int work_time, int salary, Positions position, int payment, Project* project);
  ~Tester() override = default;
  void calc_salary(int bonus) override;
  int calc_pro_additions(int bugs) override;
  void print_info() override;
};


class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string name, int work_time, int salary, Positions position, int payment, Project* project);
  ~TeamLeader() override = default;
  void calc_salary(int bonus) override;
  int calc_Heads() override;
  void print_info() override;
};

#endif //STAFFDEMO_INCLUDE_ENGINEER_H_
