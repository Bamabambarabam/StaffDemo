// Copyright 2024 HSE NN
// Author: Lev Pestov

#include <iostream>
#include "Engineer.h"
#include "Employee.h"
#include "Personal.h"
#include "Interfaces.h"
#include "Project.h"

int main() {
  Project project1(1, 10000,0);
  Project project2(2, 20000,0);
  Project project3(3, 30000,0);
  Programmer programmer(2, "Programmer", 34534, 543, Positions::programmer, 0, &project1);
  Tester tester(3, "Tester", 5, 5, Positions::tester, 0, &project2);
  TeamLeader teamLeader(4, "TeamLeader", 0, 0, Positions::team_leader, 0, &project3);

  // Create a Cleaner instance
  Cleaner cleaner(5, "Cleaner", 40, 1000, Positions::cleaner, 0);

  // Test Cleaner methods
  cleaner.calc_salary(9009);
  std::cout << std::endl;
  cleaner.print_info();
  std::cout << cleaner.get_payment();
  std::cout << "---------------------" << std::endl;

  // Create a Driver instance
  Driver driver(6, "Driver", 40, 1000, Positions::driver, 0);

  // Test Driver methods
  driver.calc_salary(100);
  std::cout << std::endl;
  driver.print_info();
  std::cout << driver.get_payment();
  std::cout << "---------------------" << std::endl;

  // Test Programmer methods
  programmer.calc_salary(0);
  std::cout << std::endl;
  programmer.print_info();
  std::cout << programmer.get_payment();
  std::cout << "---------------------" << std::endl;

  // Test Tester methods
  tester.calc_salary(0);
  std::cout << std::endl;
  tester.print_info();
  std::cout << tester.get_payment();
  std::cout << "---------------------" << std::endl;

  // Test TeamLeader methods
  teamLeader.calc_salary(0);
  std::cout << std::endl;
  teamLeader.print_info();
  std::cout << teamLeader.get_payment();
  std::cout << "---------------------" << std::endl;
// Create a vector of projects
  std::vector<Project*> projects = {&project1, &project2, &project3};

  // Create a ProjectManager instance
  ProjectManager projectManager(7, "ProjectManager", 40, Positions::project_manager, projects);

  // Test ProjectManager methods
  projectManager.calc_salary(100);
  std::cout << std::endl;
  projectManager.print_info();
  std::cout << projectManager.get_payment();
  std::cout << "---------------------" << std::endl;

  // Create a SeniorManager instance
  SeniorManager seniorManager(8, "SeniorManager", 40, Positions::senior_manager, projects);

  // Test SeniorManager methods
  seniorManager.calc_salary(100);
  std::cout << std::endl;
  seniorManager.print_info();
  std::cout << seniorManager.get_payment();
  std::cout << "---------------------" << std::endl;
  return 0;
}