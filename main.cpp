#include "Tests/Tests.h"
#include "Service/Service.h"
#include "UserInterface/UserInterface.h"
#include "Repository/RepoFile.h"

int main() {
    test_all();
    RepoInFile repo;
    Service service;
    service.set_repository("fisier");
    UserInterface user_interface(repo, service);
    user_interface.show_menu();
    return 0;
}
