#include "Tests.h"
#include "../Domain/Expense.h"
#include "../Repository/Repo.h"
#include "../Service/Service.h"
#include <cassert>
#include <cstring>
#include <iostream>

// ========== TEST ENTITY =============================================================================================

void testExpense() {
    Expense e1;
    assert (e1.getNum() == 0);
    assert (e1.getTotal() == 0);
    assert (e1.getType() == nullptr);

    Expense e2(13, 278, (char *) "mancare");
    assert (e2.getNum() == 13);
    assert (e2.getTotal() == 278);
    assert (strcmp(e2.getType(), "mancare") == 0);

    Expense e3(e2);
    assert (e3.getNum() == 13);
    assert (e3.getTotal() == 278);
    assert (strcmp(e3.getType(), "mancare") == 0);

    e3.setNum(28);
    e3.setTotal(199);
    e3.setType((char *) "altele");
    assert (e3.getNum() == 28);
    assert (e3.getTotal() == 199);
    assert (strcmp(e3.getType(), "altele") == 0);
}

// ========== TEST REPO ===============================================================================================

void testRepository() {
    Repository repo;

    Expense e1 = Expense(5, 37, (char *) "mancare");
    Expense e2 = Expense(6, 51, (char *) "altele");
    repo.addExpense(e1);
    repo.addExpense(e2);
    assert (repo.getSize() == 2);

    Expense *exp = repo.getRepo();
    assert (exp[0].getTotal() == e1.getTotal());
    assert (exp[1].getNum() == e2.getNum());
}

void testService() {
    Repository repo;
    Service service(repo);

    service.createExpense(13, 190, (char *) "mancare");
    service.createExpense(28, 21, (char *) "altele");
    assert (service.numExpenses() == 2);

    service.updateExpense(0, 13, 210, (char *) "mancare");
    assert (service.readExpense(0).getTotal() == 210);

    service.deleteExpense(0);
    assert (service.numExpenses() == 1);
    assert (service.readExpense(0).getNum() == 28);
    service.deleteExpense(0);
    assert (service.numExpenses() == 0);

    service.createExpense(20, 81, (char *) "altele");
    service.createExpense(21, 90, (char *) "altele");
    int sum = service.sumByType((char *) "altele");
    assert (sum == 171);

    service.createExpense(25, 70, (char *) "water");
    service.createExpense(27, 210, (char *) "gas");
    assert(service.numExpenses() == 4);
    assert(service.readExpense(1).getNum() == 21);

    Expense exp1 = service.readExpense(0);
    Expense exp2 = service.readExpense(1);
    assert(exp1.getTotal() == 81);
    assert(exp2.getTotal() == 90);

    service.deleteExpense(3);
    service.deleteExpense(2);
    service.deleteExpense(1);
    service.deleteExpense(0);
    assert (service.numExpenses() == 0);
}

// ========== TEST ALL ================================================================================================

void testFunctions() {
    testExpense();
    testRepository();
    testService();
    std::cout << "All tests ran successfully !" << std::endl << std::endl;
}
