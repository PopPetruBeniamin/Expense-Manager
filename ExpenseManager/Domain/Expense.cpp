#include "Expense.h"
#include <cstring>

// ========== Constructors/Deconstructor ==============================================================================

Expense::Expense() {
    this->num = 0;
    this->total = 0;
    this->type = nullptr;
}

Expense::Expense(int num, int total, char *type) {
    this->num = num;
    this->total = total;

    this->type = new char[strlen(type) + 1];
    strcpy_s(this->type, strlen(type) + 1, type);
}

Expense::Expense(const Expense &exp) {
    this->num = exp.num;
    this->total = exp.total;

    this->type = new char[strlen(exp.type) + 1];
    strcpy_s(this->type, strlen(exp.type) + 1, exp.type);
}

Expense::~Expense() {
    delete[] type;
}

// ========== Getters/Setters =========================================================================================

int Expense::getNum() const {
    return this->num;
}

int Expense::getTotal() const {
    return this->total;
}

char *Expense::getType() const{
    return this->type;
}

void Expense::setNum(int newNum) {
    this->num = newNum;
}

void Expense::setTotal(int newTotal) {
    this->total = newTotal;
}

void Expense::setType(char *newType) {
    this->type = new char[strlen(newType) + 1];
    strcpy_s(this->type, strlen(newType) + 1, newType);
}

// ========== Operators ===============================================================================================

Expense& Expense::operator=(const Expense &e) {
    if (this != &e){
        this->setType(e.getType());
        this->setTotal(e.getTotal());
        this->setNum(e.getNum());
    }
    return *this;
}

bool Expense::operator==(const Expense &e) {
    return ((this->num == e.getNum()) && (this->total == e.getTotal()) && (strcmp(this->type, e.getType())) == 0);
}

std::ostream& operator<<(std::ostream& os, Expense& expense){
    os << "Apartment number: " << expense.getNum() << ", total amount: " << expense.getTotal();
    os << ", type: " << expense.getType();
    return os;
}
