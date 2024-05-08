
#ifndef VECTORTEST_HPP
#define VECTORTEST_HPP

#include "../../vector/vector.hpp"

/* ************************************************************************** */

//Function to test the Vector class

template <typename Data>
void EqualVector(unsigned int &testnum, unsigned int &testerr,
                 const lasd::Vector<Data> &vec1, const lasd::Vector<Data> &vec2,
                 bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two vectors are "
              << ((tst = (vec1 == vec2)) ? "" : "not ") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void NonEqualVector(unsigned int &testnum, unsigned int &testerr,
                    const lasd::Vector<Data> &vec1,
                    const lasd::Vector<Data> &vec2, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two vectors are "
              << ((tst = (vec1 != vec2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}


//! Implemented by me:

template <typename Data>
void TestVectorTraversableConstructor(unsigned int &testnum, unsigned int &testerr, const lasd::TraversableContainer<Data>& container) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing vector constructor with TraversableContainer: ";
    lasd::Vector<Data> vec(container); // Constructor with TraversableContainer
    std::cout << ((tst = (vec.Size() == container.Size())) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestVectorMappableConstructor(unsigned int &testnum, unsigned int &testerr, lasd::MappableContainer<Data>& container) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing vector constructor with MappableContainer: ";
    lasd::Vector<Data> vec(std::move(container)); // Constructor with MappableContainer
    std::cout << ((tst = (vec.Size() == container.Size())) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestVectorConstructors(unsigned int &testnum, unsigned int &testerr) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing vector constructors: ";
    lasd::Vector<Data> vec1(5); // Constructor with size
    lasd::Vector<Data> vec2(vec1); // Copy constructor
    lasd::Vector<Data> vec3(std::move(vec2)); // Move constructor
    std::cout << ((tst = (vec1.Size() == 5 && vec2.Size() == 0 && vec3.Size() == 5)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestVectorAssignments(unsigned int &testnum, unsigned int &testerr) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing vector assignments: ";
    lasd::Vector<Data> vec1(5); // Constructor with size
    lasd::Vector<Data> vec2 = vec1; // Copy assignment
    lasd::Vector<Data> vec3 = std::move(vec2); // Move assignment
    std::cout << ((tst = (vec1.Size() == 5 && vec2.Size() == 0 && vec3.Size() == 5)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestVectorClear(unsigned int &testnum, unsigned int &testerr, lasd::Vector<Data> &vec) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Clearing the vector: ";
    vec.Clear();
    std::cout << ((tst = (vec.Size() == 0)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestVectorResize(unsigned int &testnum, unsigned int &testerr, lasd::Vector<Data> &vec, unsigned long newSize) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Resizing the vector: ";
    vec.Resize(newSize);
    std::cout << ((tst = (vec.Size() == newSize)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestVectorOperatorIndex(unsigned int &testnum, unsigned int &testerr, lasd::Vector<Data> &vec, unsigned long index, const Data& expectedValue) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing vector operator[]: ";
    std::cout << ((tst = (vec[index] == expectedValue)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestVectorFront(unsigned int &testnum, unsigned int &testerr, lasd::Vector<Data> &vec, const Data& expectedValue) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing vector Front(): ";
    std::cout << ((tst = (vec.Front() == expectedValue)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestVectorBack(unsigned int &testnum, unsigned int &testerr, lasd::Vector<Data> &vec, const Data& expectedValue) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing vector Back(): ";
    std::cout << ((tst = (vec.Back() == expectedValue)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}


//! SortableVector
template <typename Data>
void TestSortableVectorTraversableConstructor(unsigned int &testnum, unsigned int &testerr, const lasd::TraversableContainer<Data>& container) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing SortableVector constructor with TraversableContainer: ";
    lasd::SortableVector<Data> vec(container); // Constructor with TraversableContainer
    std::cout << ((tst = (vec.Size() == container.Size())) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestSortableVectorMappableConstructor(unsigned int &testnum, unsigned int &testerr, lasd::MappableContainer<Data>& container) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing SortableVector constructor with MappableContainer: ";
    lasd::SortableVector<Data> vec(std::move(container)); // Constructor with MappableContainer
    std::cout << ((tst = (vec.Size() == container.Size())) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestSortableVectorConstructors(unsigned int &testnum, unsigned int &testerr) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing SortableVector constructors: ";
    lasd::SortableVector<Data> vec1(5); // Constructor with size
    lasd::SortableVector<Data> vec2(vec1); // Copy constructor
    lasd::SortableVector<Data> vec3(std::move(vec2)); // Move constructor
    std::cout << ((tst = (vec1.Size() == 5 && vec2.Size() == 0 && vec3.Size() == 5)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TestSortableVectorAssignments(unsigned int &testnum, unsigned int &testerr) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Testing SortableVector assignments: ";
    lasd::SortableVector<Data> vec1(5); // Constructor with size
    lasd::SortableVector<Data> vec2 = vec1; // Copy assignment
    lasd::SortableVector<Data> vec3 = std::move(vec2); // Move assignment
    std::cout << ((tst = (vec1.Size() == 5 && vec2.Size() == 0 && vec3.Size() == 5)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}



/* ************************************************************************** */

#endif
