#include <vector>
#include "Repo.h"

// ========== Constructors/Deconstructor ==============================================================================

Repository::Repository() {
    this->numExpenses = 0;
    this->Repo = new Expense[1];
}

Repository::Repository(const Repository &rep) {
    this->numExpenses = rep.getSize();
    this->Repo = new Expense[this->numExpenses];
    for (int i = 0; i < this->numExpenses; i++)
        this->Repo[i] = Repo[i];
}

Repository::~Repository() = default;

// ========== Getters/Setters =========================================================================================

int Repository::getSize() const {
    return this->numExpenses;
}

Expense *Repository::getRepo() {
    return this->Repo;
}

Expense Repository::getExpense(int pos) {
    return this->Repo[pos];
}

void Repository::setSize(int newSize) {
    this->numExpenses = newSize;
}

void Repository::setRepo(const Expense* newRepo, int size) {
    if (Repo != nullptr) {
        Repo = nullptr;
        numExpenses = 0;
    }

    Repo = new Expense[size];

    for (int i = 0; i < size; ++i)
        Repo[i] = newRepo[i];

    numExpenses = size;
}

// ========== Methods =================================================================================================

void Repository::addExpense(Expense &exp) {
    this->Repo[this->numExpenses++] = exp;
}

// ========== Operators ===============================================================================================

Repository& Repository::operator=(Repository repo){
    this->Repo = repo.getRepo();
    this->setSize(repo.getSize());
    return *this;
}
