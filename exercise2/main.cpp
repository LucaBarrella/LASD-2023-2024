
#include "zlasdtest/test.hpp"

#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2024" << std::endl;
    std::cout << "\nSelect a test to run:\n\n1) Simple Test\n2) My Test\n3) Full Test\n\n0) To get out of the program\n\n" << std::endl;
    int choice;
    std::cout << "I choose the test: ";
    std::cin >> choice;
    while (1){
        switch (choice){
            case 0:
                return 0;
            case 1:
                lasdtest();
                break;
            case 2:
                mytest();
                break;
            case 3:
                //fulltest();
                break;
            default:
                std::cout << "Invalid choice, please choose again: ";
                std::cin >> choice;
                continue;
        }
        break;
    }


    return 0;
}
