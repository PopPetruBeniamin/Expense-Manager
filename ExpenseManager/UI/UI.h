#ifndef LAB07BUN_UI_H
#define LAB07BUN_UI_H

#include "../Service/Service.h"
#include <vector>
#include <stack>

class UI {
private:
    Service& service;
public:
    explicit UI(Service& service);
    ~UI();

    void addExpense(int& num, int& total, char*& type);
    void displayAllExpenses();

    void deleteExpensesByType(char* type);
    int sumByType(char* type);
    void displayExpensesGreaterThanVal(int val);
    void filterExpensesGreaterThanVal(int val);

    static void displayMenu();
    void runMenu();
    static std::vector<std::string> splitCommand(const std::string& command);
};



#endif //LAB07BUN_UI_H
