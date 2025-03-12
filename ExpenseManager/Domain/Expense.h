#ifndef LAB07BUN_EXPENSE_H
#define LAB07BUN_EXPENSE_H

#include <cstring>
#include <iostream>

class Expense{
private:
    int num;
    int total;
    char* type;
public:
    // Constructors, Deconstructor
    Expense();
    Expense(int num, int total, char *type);
    Expense(const Expense &exp);
    ~Expense();

    // Getters, Setters
    [[nodiscard]] int getNum() const;
    [[nodiscard]] int getTotal() const;
    [[nodiscard]] char* getType() const;
    void setNum(int newNum);
    void setTotal(int newTotal);
    void setType(char *newType);

    // Operators
    Expense& operator=(const Expense& e);
    bool operator==(const Expense &e);
    friend std::ostream& operator<<(std::ostream& os, Expense& expense);
};

#endif //LAB07BUN_EXPENSE_H
