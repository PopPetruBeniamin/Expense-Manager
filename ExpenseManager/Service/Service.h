#ifndef LAB07BUN_SERVICE_H
#define LAB07BUN_SERVICE_H

#include "../Domain/Expense.h"
#include "../Repository/Repo.h"

class Service {
private:
    Repository& Repo;
public:
    // Constructor/Deconstructor
    explicit Service(Repository &repo);
    ~Service();

    // Getters
    Expense readExpense(int );
    Expense* readAllExpenses();
    int numExpenses();

    // Methods
    void createExpense(int num, int total, char* type);
    void updateExpense(int id, int num, int total, char* type);
    void deleteExpense(int id);

    void filterByType(char* type);
    void deleteExpensesByType(char* type);
    int sumByType(char* type);
    void filterExpensesGreaterThanVal(int val);
};
#endif //LAB07BUN_SERVICE_H
