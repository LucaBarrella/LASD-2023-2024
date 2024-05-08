
#include "../vector/vector.hpp"

/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // Include the header file for rand()

// #include "../zlasdtest/container/container.hpp"
// #include "../zlasdtest/list/list.hpp"
// #include "../zlasdtest/container/dictionary.hpp"
// #include "../zlasdtest/container/linear.hpp"
// #include "../zlasdtest//container/mappable.hpp"
// #include "../zlasdtest/container/testable.hpp"
// #include "../zlasdtest/container/traversable.hpp"
// #include "../zlasdtest/vector/vector.hpp"
// #include "../zlasdtest/stack/stack.hpp"
// #include "../zlasdtest/queue/queue.hpp"
// #include "../zlasdtest/list/list.hpp"

// #include "../zlasdtest/test.hpp"


#include "../list/list.hpp"
#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/queue.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"

//Global variables

uint numberOfTests = 0;
uint numberOfErrors = 0;
bool expectedResult = true;


// My test:
#include "../zmytest/container/container.hpp"
#include "../zmytest/container/dictionary.hpp"
#include "../zmytest/container/linear.hpp"
#include "../zmytest/container/mappable.hpp"
#include "../zmytest/container/testable.hpp"
#include "../zmytest/container/traversable.hpp"
#include "../zmytest/vector/vector.hpp"
#include "../zmytest/stack/stack.hpp"
#include "../zmytest/queue/queue.hpp"
#include "../zmytest/list/list.hpp"


using namespace std;

/* ************************************************************************** */
void vectorTest();
void listTest();
void stackTest();
void queueTest();
void mytest();

void mytest() {

  int StructureSelector = 0;
  std::cout << "\nSelect the structure to test:\n" << std::endl;
  std::cout << "1. Vector\n2. List\n3. Stack\n4. Queue\n5. For All\n0. Exit" << std::endl;
  std::cin >> StructureSelector;
  switch (StructureSelector)
  {
  case 0:
    std::cout << "Exiting..." << std::endl;
    exit(0);
    break;
  case 1:
    vectorTest();
    break;
  case 2:
    listTest();
    break;
  case 3:
    stackTest();
    break;
  case 4:
    queueTest();
    break;
  case 5:
    vectorTest();
    listTest();
    stackTest();
    queueTest();
    break;
  default:
    std::cout << "Invalid input" << std::endl;
    break;
  }
  std::cout << "\nNumber of tests: " << numberOfTests << std::endl;
  std::cout << "Number of errors: " << numberOfErrors << std::endl;
  numberOfErrors == 0 ? std::cout << "\n\nAll tests passed!" << std::endl : std::cout << "\n\nSome tests failed!" << std::endl;
}


void vectorTest(){

  lasd::SortableVector<int> v1;
  Empty(numberOfTests, numberOfErrors, v1, expectedResult);
  int newSize = rand() % 1000000;
  v1.Resize(newSize);
  Size(numberOfTests, numberOfErrors, v1, expectedResult, newSize);

  // Fill the vector with random numbers
  for (int i = 0; i < v1.Size(); i++)
  {
    v1[i] = rand() % 1000;
  }
  TestSort(numberOfTests, numberOfErrors, v1);
  lasd::SortableVector<int> v2; v2 = v1;
  EqualLinear(numberOfTests, numberOfErrors, v1, v2, expectedResult);

  SetFront(numberOfTests, numberOfErrors, v1, expectedResult, rand() % 1000);
  GetFront(numberOfTests, numberOfErrors, v1, expectedResult, v1[0]);
  SetBack(numberOfTests, numberOfErrors, v1, expectedResult, rand() % 1000);
  GetBack(numberOfTests, numberOfErrors, v1, expectedResult, v1[v1.Size() - 1]);
  v1[rand() % v1.Size()]= 123456789;
  Exists(numberOfTests, numberOfErrors, v1, expectedResult, 123456789);
  lasd::SortableVector<int> v3(std::move(v2));
  expectedResult = false;
  EqualLinear(numberOfTests, numberOfErrors, v2, v3, expectedResult);

  for (int i = 1; i < v1.Size(); i++)
  {
    v1[i] = v1[i - 1];
  }

  lasd::SortableVector<int> v4; v4 = v1;
  v4.Clear();
  if (v4.Empty())
  {
    std::cout << "Vector cleared successfully" << std::endl;
    std::cout << "Infact Size is: " << v4.Size() << std::endl;
  }
  else
  {
    std::cout << "Vector not cleared" << std::endl;
  }

  std::cout << "int Vector test completed" << std::endl;
  std::cout << "--------------------------------" << std::endl;
  std::cout << "double Vector test starting" << std::endl;


  lasd::SortableVector<double> v5;
  expectedResult = true;
  Empty(numberOfTests, numberOfErrors, v5, expectedResult);
  newSize = rand() % 1000000;
  v5.Resize(newSize);
  Size(numberOfTests, numberOfErrors, v5, expectedResult, newSize);
  // Fill the vector with random numbers
  for (int i = 0; i < v5.Size(); i++)
  {
    v5[i] = static_cast<double>(rand()) / RAND_MAX;
  }
  TestSort(numberOfTests, numberOfErrors, v5);
  lasd::SortableVector<double> v6; v6 = v5;
  EqualLinear(numberOfTests, numberOfErrors, v5, v6, expectedResult);
  SetFront(numberOfTests, numberOfErrors, v5, expectedResult, static_cast<double>(rand()) / RAND_MAX);
  GetFront(numberOfTests, numberOfErrors, v5, expectedResult, v5[0]);
  SetBack(numberOfTests, numberOfErrors, v5, expectedResult, static_cast<double>(rand()) / RAND_MAX);
  GetBack(numberOfTests, numberOfErrors, v5, expectedResult, v5[v5.Size() - 1]);
  v5[rand() % v5.Size()] = 0.123456789;
  Exists(numberOfTests, numberOfErrors, v5, expectedResult, 0.123456789);
  lasd::SortableVector<double> v7(std::move(v6));
  expectedResult = false;
  EqualLinear(numberOfTests, numberOfErrors, v6, v7, expectedResult);
  for (int i = 1; i < v5.Size(); i++)
  {
    v5[i] = v5[i - 1];
  }
  lasd::SortableVector<double> v8; v8 = v5;
  v8.Clear();
  if (v8.Empty())
  {
    std::cout << "Vector cleared successfully" << std::endl;
    std::cout << "Infact Size is: " << v8.Size() << std::endl;
  }
  else
  {
    std::cout << "Vector not cleared" << std::endl;
  }

  std::cout << "double Vector test completed" << std::endl;
  std::cout << "--------------------------------" << std::endl;
  std::cout << "string Vector test starting" << std::endl;

  lasd::SortableVector<std::string> v9;
  expectedResult = true;
  Empty(numberOfTests, numberOfErrors, v9, expectedResult);
  newSize = rand() % 1000000;
  v9.Resize(newSize);
  Size(numberOfTests, numberOfErrors, v9, expectedResult, newSize);
  // Fill the vector with random strings
  for (int i = 0; i < v9.Size(); i++)
  {
    v9[i] = "String" + std::to_string(i);
  }
  TestSort(numberOfTests, numberOfErrors, v9);
  lasd::SortableVector<std::string> v10; v10 = v9;
  EqualLinear(numberOfTests, numberOfErrors, v9, v10, expectedResult);
  SetAt(numberOfTests, numberOfErrors, v9, expectedResult, 0, string("NewFront"));
  GetFront(numberOfTests, numberOfErrors, v9, expectedResult, v9[0]);
  SetAt(numberOfTests, numberOfErrors, v9, expectedResult, 1, string("NewBack"));
  GetBack(numberOfTests, numberOfErrors, v9, expectedResult, v9[v9.Size() - 1]);
  v9[rand() % v9.Size()] = "ModifiedString";
  Exists(numberOfTests, numberOfErrors, v9, expectedResult, string ("ModifiedString"));
  lasd::SortableVector<std::string> v11(std::move(v10));
  expectedResult = false;
  EqualLinear(numberOfTests, numberOfErrors, v10, v11, expectedResult);
  for (int i = 1; i < v9.Size(); i++)
  {
    v9[i] = v9[i - 1];
  }
  lasd::SortableVector<std::string> v12; v12 = v9;
  v12.Clear();
  if (v12.Empty())
  {
    std::cout << "Vector cleared successfully" << std::endl;
    std::cout << "Infact Size is: " << v12.Size() << std::endl;
  }
  else
  {
    std::cout << "Vector not cleared" << std::endl;
  }

  std::cout << "string Vector test completed" << std::endl;
  std::cout << "--------------------------------" << std::endl;
}

void listTest(){
  expectedResult = true;
  std::cout << "int List test starting" << std::endl;
  std::cout << "--------------------------------" << std::endl;
  std::cout << "Transforming vector into list" << std::endl;
  lasd::SortableVector<int> v1(10);
  for (int i = 0; i < v1.Size(); i++)
  {
    v1[i] = rand() % 1000;
  }
  lasd::List<int> l1(v1);
  EqualLinear(numberOfTests, numberOfErrors, v1, l1, expectedResult);
  std::cout << "Transforming list into vector" << std::endl;
  lasd::SortableVector<int> v2(l1);
  EqualLinear(numberOfTests, numberOfErrors, l1, v2, expectedResult);
  TransformListToVector(numberOfTests, numberOfErrors, l1, true);
  TransformVectorToList(numberOfTests, numberOfErrors, v1, true);
  lasd::List<int> l2;
  Empty(numberOfTests, numberOfErrors, l2, expectedResult);
  Size(numberOfTests, numberOfErrors, l2, expectedResult, 0);
  lasd::List<int> l3(l1);
  EqualList(numberOfTests, numberOfErrors, l1, l3, expectedResult);
  lasd::List<int> l4(std::move(l3));
  expectedResult = false;
  EqualList(numberOfTests, numberOfErrors, l3, l4, expectedResult);
  lasd::List<int> l5;
  Clear(numberOfTests, numberOfErrors, l5, false);
  l5.Clear();
  Clear(numberOfTests, numberOfErrors, l5, true);

  lasd::List<int> l6;
  InsertAtFront(numberOfTests, numberOfErrors, l6, true, rand() % 1000);
  lasd::List<int> l7;
  InsertAtBack(numberOfTests, numberOfErrors, l7, true, rand() % 1000);
  RemoveFromFront(numberOfTests, numberOfErrors, l6, true);
  ExistsAfterInsertBack(numberOfTests, numberOfErrors, l6, true, rand() % 1000);
  std:: cout << l7.Front()<< std::endl;
  //todo other tests for list


}
void stackTest(){
  lasd::StackVec<int> s1;
  Empty(numberOfTests, numberOfErrors, s1, true);
  Size(numberOfTests, numberOfErrors, s1, true, 0);
  int casualNumber = rand() % 1000;
  Top(numberOfTests, numberOfErrors, s1, false, casualNumber);
  TopNPop(numberOfTests, numberOfErrors, s1, false, casualNumber);
  PushC(numberOfTests, numberOfErrors, s1, casualNumber);
  Top(numberOfTests, numberOfErrors, s1, true, casualNumber);
  TopNPop(numberOfTests, numberOfErrors, s1, true, casualNumber);
  Top(numberOfTests, numberOfErrors, s1, false, casualNumber);
  PushM(numberOfTests, numberOfErrors, s1, casualNumber);
  Top(numberOfTests, numberOfErrors, s1, true, casualNumber);
  lasd::StackVec<int> s2; s2 = s1;
  EqualStack(numberOfTests, numberOfErrors, s1, s2, true);
  lasd::StackLst<int> s3;
  Empty(numberOfTests, numberOfErrors, s3, true);
  Size(numberOfTests, numberOfErrors, s3, true, 0);
  Top(numberOfTests, numberOfErrors, s3, false, casualNumber);
  TopNPop(numberOfTests, numberOfErrors, s3, false, casualNumber);
  PushC(numberOfTests, numberOfErrors, s3, casualNumber);
  Top(numberOfTests, numberOfErrors, s3, true, casualNumber);
  TopNPop(numberOfTests, numberOfErrors, s3, true, casualNumber);
  Top(numberOfTests, numberOfErrors, s3, false, casualNumber);
  PushM(numberOfTests, numberOfErrors, s3, casualNumber);
  Top(numberOfTests, numberOfErrors, s3, true, casualNumber);
  lasd::StackLst<int> s4; s4 = s3;
  EqualStack(numberOfTests, numberOfErrors, s3, s4, true);
  lasd::StackVec<int> s5; s5 = std::move(s2);
  lasd::StackLst<int> s6; s6 = std::move(s4);
  EqualStack(numberOfTests, numberOfErrors, s2, s5, false);
  EqualStack(numberOfTests, numberOfErrors, s4, s6, false);
  s5.Clear();
  s6.Clear();
  Empty(numberOfTests, numberOfErrors, s5, true);
  Empty(numberOfTests, numberOfErrors, s6, true);
  std::cout << "Stack test completed" << std::endl;
}

void queueTest(){
  int casualNumber = rand() % 1000;
  lasd::QueueVec<int> q1;
  Empty(numberOfTests, numberOfErrors, q1, true);
  Size(numberOfTests, numberOfErrors, q1, true, 0);
  Head(numberOfTests, numberOfErrors, q1, false, casualNumber);
  HeadNDequeue(numberOfTests, numberOfErrors, q1, false, casualNumber);
  Dequeue(numberOfTests, numberOfErrors, q1, false);
  EnqueueC(numberOfTests, numberOfErrors, q1, casualNumber);
  Head(numberOfTests, numberOfErrors, q1, true, casualNumber);
  HeadNDequeue(numberOfTests, numberOfErrors, q1, true, casualNumber);
  EnqueueM(numberOfTests, numberOfErrors, q1, casualNumber);
  Dequeue(numberOfTests, numberOfErrors, q1, true);
  lasd::QueueVec<int> q2; q2 = q1;
  EqualQueue(numberOfTests, numberOfErrors, q1, q2, true);
  lasd::QueueLst<int> q3;
  Empty(numberOfTests, numberOfErrors, q3, true);
  Size(numberOfTests, numberOfErrors, q3, true, 0);
  Head(numberOfTests, numberOfErrors, q3, false, casualNumber);
  HeadNDequeue(numberOfTests, numberOfErrors, q3, false, casualNumber);
  Dequeue(numberOfTests, numberOfErrors, q3, false);
  EnqueueC(numberOfTests, numberOfErrors, q3, casualNumber);
  Head(numberOfTests, numberOfErrors, q3, true, casualNumber);
  HeadNDequeue(numberOfTests, numberOfErrors, q3, true, casualNumber);
  EnqueueM(numberOfTests, numberOfErrors, q3, casualNumber);
  Dequeue(numberOfTests, numberOfErrors, q3, true);
  EnqueueC(numberOfTests, numberOfErrors, q3, casualNumber);
  EnqueueM(numberOfTests, numberOfErrors, q3, casualNumber+1);
  lasd::QueueLst<int> q4; q4 = q3;
  EqualQueue(numberOfTests, numberOfErrors, q3, q4, true);
  lasd::QueueVec<int> q5;
  EnqueueC(numberOfTests, numberOfErrors, q5, casualNumber);
  EnqueueM(numberOfTests, numberOfErrors, q5, casualNumber+1);
  lasd::QueueVec<int> q6; q6 = std::move(q5);
  NonEqualQueue(numberOfTests, numberOfErrors, q5, q6, true);
  lasd::QueueLst<int> q7;
  EnqueueC(numberOfTests, numberOfErrors, q7, casualNumber);
  EnqueueM(numberOfTests, numberOfErrors, q7, casualNumber+1);
  lasd::QueueLst<int> q8; q8 = std::move(q7);
  NonEqualQueue(numberOfTests, numberOfErrors, q7, q8, true);
  q6.Clear();
  q8.Clear();
  Empty(numberOfTests, numberOfErrors, q6, true);
  Empty(numberOfTests, numberOfErrors, q8, true);
  std::cout << "Queue test completed" << std::endl;
}