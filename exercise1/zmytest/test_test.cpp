#include <iostream>
#include <stdexcept>
#include "lasd/Vector.hpp"

void mytest() {
  std::cout << "Test di capacità e dimensione:" << std::endl;
  std::cout << "Test di accesso agli elementi:" << std::endl;
  std::cout << "Test di inserimento degli elementi:" << std::endl;
  std::cout << "Test di rimozione degli elementi:" << std::endl;
  std::cout << "Test di modifica degli elementi:" << std::endl;
  std::cout << "Test di copia degli elementi:" << std::endl;
  std::cout << "Test di assegnazione degli elementi:" << std::endl;
  std::cout << "Test di resize della struttura:" << std::endl;
  std::cout << "Test di clear della struttura:" << std::endl;
  std::cout << "Test di confronto degli elementi:" << std::endl;
  std::cout << "Test di performance:" << std::endl;

  uint numberOfTests = 0;
  uint numberOfErrors = 0;

  try {
    lasd::SortableVector<int> vector(0); // This is an empty vector
    Empty(numberOfTests, numberOfErrors, vector, true); // Fix the variable name
    vector.Resize(10);
    std::cout << "Size: " << vector.Size() << std::endl;
    vector.Resize(0);
    std::cout << "Size: " << vector.Size() << std::endl;
    Size(numberOfTests, numberOfErrors, vector, true, 0); // Fix the variable name
  } 
  catch (std::length_error &e) {
    numberOfErrors++;
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // lasd::SortableVector<double> vec1;
  // lasd::SortableVector<string> vec2;

  // Test di capacità e dimensione:
  // Add your tests here

  // Test di accesso agli elementi:
  // Add your tests here

  // Test di inserimento degli elementi:
  // Add your tests here

  // Test di rimozione degli elementi:
  // Add your tests here

  // Test di modifica degli elementi:
  // Add your tests here

  // Test di copia degli elementi:
  // Add your tests here

  // Test di assegnazione degli elementi:
  // Add your tests here

  // Test di resize della struttura:
  // Add your tests here

  // Test di clear della struttura:
  // Add your tests here

  // Test di confronto degli elementi:
  // Add your tests here

  // Test di performance:
  // Add your tests here
}