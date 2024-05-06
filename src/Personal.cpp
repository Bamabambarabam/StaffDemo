#include "Personal.h"

Personal::Personal(int id, std::string name, int workTime, int salary, Positions position, int payment)
    : Employee(id, std::move(name), workTime, position, payment), salary(salary) {}

int Personal::calc_base_salary(int salary, int work_time_salary) {
  return salary * work_time_salary;
}

int Personal::calc_bonus_salary(int bonus) {
  return bonus;
}

void Personal::print_info() {
  std::cout << "Personal: " << name << ", Position: " << enum_print[position] << ", Salary: " << payment << std::endl;
}

Driver::Driver(int id, std::string name, int workTime, int salary, Positions position, int payment)
    : Personal(id, std::move(name), workTime, salary, position, payment) {}

int Driver::calc_bonus_salary(int night_hours) {
  return night_hours * 10;
}
void Driver::calc_salary(int bonus_hours) {
  payment = calc_base_salary(salary, work_time) + calc_bonus_salary(bonus_hours);
}

Cleaner::Cleaner(int id, std::string name, int workTime, int salary, Positions position, int payment)
    : Personal(id, std::move(name), workTime, salary, position, payment) {}

void Cleaner::calc_salary(int bonus) {
  payment = calc_base_salary(salary, work_time);
}