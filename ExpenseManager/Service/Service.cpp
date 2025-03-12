#include "../Service/Service.h"
using namespace std;

// =========== Constructors/Deconstructor =============================================================================

Service::Service(Repository &repo) : Repo(repo){
    this->Repo.setSize(0);
}

Service::~Service() = default;

// ========== Getters =================================================================================================

Expense Service::readExpense(int id) {
    return this->Repo.getExpense(id);
}

Expense* Service::readAllExpenses() {
    return this->Repo.getRepo();
}

int Service::numExpenses() {
    return this->Repo.getSize();
}

// ========== Methods =================================================================================================

void Service::createExpense(int num, int total, char *type) {
    Expense exp(num, total, type);
    Repo.addExpense(exp);
}

void Service::updateExpense(int id, int num, int total, char *type) {
    Expense updatedExpense = Expense(num, total, type);
    Expense* allExpenses = readAllExpenses();
    allExpenses[id] = updatedExpense;
    this->Repo.setRepo(allExpenses, numExpenses());
}

void Service::deleteExpense(int id) {
    Expense* allExpenses = this->Repo.getRepo();
    int size = this->numExpenses() - 1;
    for (int i = id; i < size; ++i)
        allExpenses[i] = allExpenses[i + 1];
    this->Repo.setRepo(allExpenses, numExpenses());
    this->Repo.setSize(size);
}

void Service::filterByType(char *type) {
    auto* filteredExpenses = new Expense[numExpenses()];
    Expense* allExpenses = readAllExpenses();
    int k = 0;
    for (int i = 0; i < numExpenses(); ++i)
        if (strcmp(allExpenses[i].getType(), type) == 0)
            filteredExpenses[k++] = allExpenses[i];
    this->Repo.setRepo(filteredExpenses, numExpenses());
    this->Repo.setSize(k);
}

// ==

void Service::deleteExpensesByType(char* type) {
    Expense* Expenses = readAllExpenses();
    int size = numExpenses();
    for (int i = 0; i < size; ++i)
        if (strcmp(Expenses[i].getType(), type) == 0)
            deleteExpense(i);
}

int Service::sumByType(char* type){
    Expense* expenses = readAllExpenses();
    int sum=0;
    for (int i = 0; i < numExpenses(); ++i)
        if (strcmp(expenses[i].getType(), type) == 0) {
            sum += expenses[i].getTotal();
        }
    return sum;
}

void Service::filterExpensesGreaterThanVal(int val) {
    Expense* expenses = readAllExpenses();
    for (int i = 0; i < numExpenses(); ++i)
        if (expenses[i].getTotal() > val) {
            deleteExpense(i);
            i--;
        }
}
