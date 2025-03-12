#include "Tests/Tests.h"
#include "Repository/Repo.h"
#include "Service/Service.h"
#include "UI/UI.h"

int main() {
    testFunctions();

    Repository repo;
    Service serv(repo);
    UI ui(serv);

    ui.runMenu();

    return 0;
}
// 3