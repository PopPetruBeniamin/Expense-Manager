#ifndef LAB07BUN_REPO_H
#define LAB07BUN_REPO_H

#include "../Domain/Expense.h"

using namespace std;

class Repository{
private:
    Expense* Repo;
    int numExpenses;
public:
    // Constructors/Deconstructor
    Repository();
    Repository(const Repository& Repo);
    ~Repository();

    // Getters/Setters
    [[nodiscard]] int getSize() const;
    Expense* getRepo();
    Expense getExpense(int pos);
    void setSize(int newSize);
    void setRepo(const Expense* newRepo, int size);

    // Methods
    void addExpense(Expense &e);

    // Operators
    Repository& operator=(Repository repo);
};

#endif //LAB07BUN_REPO_H
