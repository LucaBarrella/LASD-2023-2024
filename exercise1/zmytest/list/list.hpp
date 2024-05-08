
#ifndef LISTTEST_HPP
#define LISTTEST_HPP

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

template <typename Data>
void InsertAtFront(unsigned int &testnum, unsigned int &testerr,
                   lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insert at the front of the list the value \"" << val
              << "\": ";
    lst.InsertAtFront(val);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void RemoveFromFront(unsigned int &testnum, unsigned int &testerr,
                     lasd::List<Data> &lst, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Remove from the list of \"" << lst.Front() << "\": ";
    lst.RemoveFromFront();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::length_error &exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void FrontNRemove(unsigned int &testnum, unsigned int &testerr,
                  lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") FrontNRemove from the list of \"" << lst.Front() << "\": ";
    std::cout << ((tst = ((lst.FrontNRemove() == val) == chk)) ? "Correct"
                                                               : "Error")
              << "!" << std::endl;
  } catch (std::length_error &exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error")
              << "!" << std::endl;
  } catch (std::exception &exc) {
    tst = false;
    std::cout << std::endl
              << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void InsertAtBack(unsigned int &testnum, unsigned int &testerr,
                  lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insert at the back of the list the value \"" << val
              << "\": ";
    lst.InsertAtBack(val);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void EqualList(unsigned int &testnum, unsigned int &testerr,
               const lasd::List<Data> &lst1, const lasd::List<Data> &lst2,
               bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two lists are "
              << ((tst = (lst1 == lst2)) ? "" : "not ") << "equal: ";
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
void NonEqualList(unsigned int &testnum, unsigned int &testerr,
                  const lasd::List<Data> &lst1, const lasd::List<Data> &lst2,
                  bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two lists are "
              << ((tst = (lst1 != lst2)) ? "not " : "") << "equal: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

//! Implemented by me

template <typename Data>
void Clear(unsigned int &testnum, unsigned int &testerr,
           lasd::List<Data> &lst, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Clear the list: ";
    lst.Clear();
    std::cout << ((tst = (lst.Size() == 0)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void Size(unsigned int &testnum, unsigned int &testerr,
           lasd::List<Data> &lst, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Size of the list: ";
    std::cout << ((tst = (lst.Size() == 0)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void SizeAfterInsert(unsigned int &testnum, unsigned int &testerr,
           lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insert at the front of the list the value \"" << val
              << "\": ";
    lst.InsertAtFront(val);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << " " << testnum << " (" << testerr
              << ") Size of the list: ";
    std::cout << ((tst = (lst.Size() == 1)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void SizeAfterRemove(unsigned int &testnum, unsigned int &testerr,
           lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Remove from the list of \"" << lst.Front() << "\": ";
    lst.RemoveFromFront();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << " " << testnum << " (" << testerr
              << ") Size of the list: ";
    std::cout << ((tst = (lst.Size() == 0)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void SizeAfterInsertBack(unsigned int &testnum, unsigned int &testerr,
           lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insert at the back of the list the value \"" << val
              << "\": ";
    lst.InsertAtBack(val);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << " " << testnum << " (" << testerr
              << ") Size of the list: ";
    std::cout << ((tst = (lst.Size() == 1)) ? "Correct" : "Error") << "!"
              << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void Exists(unsigned int &testnum, unsigned int &testerr,
       lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
  std::cout << " " << testnum << " (" << testerr
        << ") Exists for the value \"" << val
        << "\": ";
  bool exists = false;
  for (unsigned int i = 0; i < lst.Size(); ++i) {
    if (lst[i] == val) {
      exists = true;
      break;
    }
  }
  std::cout << ((tst = exists) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
  std::cout << "\"" << exc.what()
        << "\": " << ((tst = chk) ? "Correct" : "Error") << "!"
        << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void ExistsAfterInsert(unsigned int &testnum, unsigned int &testerr,
           lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insert at the front of the list the value \"" << val
              << "\": ";
    lst.InsertAtFront(val);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << " " << testnum << " (" << testerr
              << ") Exists for the value \"" << val
              << "\": ";
    std::cout << ((tst = lst.Exists(val)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void ExistsAfterRemove(unsigned int &testnum, unsigned int &testerr,
           lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Remove from the list of \"" << lst.Front() << "\": ";
    lst.RemoveFromFront();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << " " << testnum << " (" << testerr
              << ") Exists for the value \"" << val
              << "\": ";
    std::cout << ((tst = !lst.Exists(val)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void ExistsAfterInsertBack(unsigned int &testnum, unsigned int &testerr,
           lasd::List<Data> &lst, bool chk, const Data &val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr
              << ") Insert at the back of the list the value \"" << val
              << "\": ";
    lst.InsertAtBack(val);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << " " << testnum << " (" << testerr
              << ") Exists for the value \"" << val
              << "\": ";
    std::cout << ((tst = lst.Exists(val)) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
    std::cout << "\"" << exc.what()
              << "\": " << ((tst = chk) ? "Correct" : "Error") << "!"
              << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TransformVectorToList(unsigned int &testnum, unsigned int &testerr,
               const lasd::Vector<Data> &vec, bool chk) {
  bool tst;
  testnum++;
  try {
  std::cout << " " << testnum << " (" << testerr
        << ") Transform vector to list: ";
  lasd::List<Data> lst(vec);
  std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
  std::cout << "\"" << exc.what()
        << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
        << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

template <typename Data>
void TransformListToVector(unsigned int &testnum, unsigned int &testerr,
         const lasd::List<Data> &lst, bool chk) {
  bool tst;
  testnum++;
  try {
  std::cout << " " << testnum << " (" << testerr
        << ") Transform list to vector: ";
  lasd::Vector<Data> vec(lst);
  std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch (std::exception &exc) {
  std::cout << "\"" << exc.what()
        << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!"
        << std::endl;
  }
  testerr += (1 - (unsigned int)tst);
}

/* ************************************************************************** */

#endif
