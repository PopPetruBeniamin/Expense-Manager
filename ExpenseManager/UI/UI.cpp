#include <sstream>
#include <vector>
#include "UI.h"

UI::UI(Service &service) : service(service) {}

UI::~UI() = default;

void UI::addExpense(int &num, int &total, char *&type) {
    this->service.createExpense(num, total, type);
}

void UI::displayAllExpenses() {
    Expense *expenses = service.readAllExpenses();
    if (service.numExpenses())
        for (int i = 0; i < service.numExpenses(); ++i)
            std::cout << expenses[i] << std::endl;
    else
        std::cout << "No expenses!" << std::endl;
}

void UI::deleteExpensesByType(char *type) {
    service.deleteExpensesByType(type);
}

void UI::filterExpensesGreaterThanVal(int val) {
    service.filterExpensesGreaterThanVal(val);
}

int UI::sumByType(char *type) {
    return service.sumByType(type);
}

void UI::displayExpensesGreaterThanVal(int val) {
    Expense *expenses = service.readAllExpenses();
    int found = 0;
    if (service.numExpenses()) {
        for (int i = 0; i < service.numExpenses(); ++i)
            if (expenses[i].getTotal() > val) {
                std::cout << expenses[i] << std::endl;
                found++;
            }
        if (!found)
            std::cout << "No expenses greater than " << val << std::endl;
    } else {
        std::cout << "No expenses!" << std::endl;
    }
}

void UI::displayMenu() {
    std::cout << "<=== MENU ===>" << std::endl;
    std::cout << "Add expense (Ex: adauga 25 gaz 100)" << std::endl;
    std::cout << "Update expense (Ex: eliminare gaz)" << std::endl;
    std::cout << "Find expenses (Ex: listeaza > 100)" << std::endl;
    std::cout << "Statistics (Ex: sum gaz)" << std::endl;
    std::cout << "Filter expenses (Ex: filtru 100)" << std::endl << std::endl;
}

std::vector<std::string> UI::splitCommand(const std::string &command) {
    std::vector<std::string> tokens;
    std::istringstream iss(command);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

void UI::runMenu() {
    displayMenu();
    while (true) {
        std::string cmd;
        std::getline(std::cin, cmd);
        std::vector<std::string> commands = splitCommand(cmd);

        // Add
        if (commands[0] == "adauga") {
            char *type = const_cast<char *>(commands[2].c_str());
            int num = std::stoi(commands[1]);
            int total = std::stoi(commands[3]);

            addExpense(num, total, type);
            displayAllExpenses();
        }

        // Delete
        if (commands[0] == "eliminare") {

            char *type = const_cast<char *>(commands[1].c_str());
            deleteExpensesByType(type);
            displayAllExpenses();
        }

        // Display
        if (commands[0] == "listeaza") {
            int val = std::stoi(commands[2]);
            displayExpensesGreaterThanVal(val);
        }

        // Sort
        if (commands[0] == "sum") {
            char *type = const_cast<char *>(commands[1].c_str());
            std::cout << sumByType(type) << std::endl;

        }

        // Filter
        if (commands[0] == "filtru") {
            int val = std::stoi(commands[1]);
            filterExpensesGreaterThanVal(val);
            displayAllExpenses();
        }

        // Exit
        if (commands[0] == "X") {
            break;
        }
    }
}
