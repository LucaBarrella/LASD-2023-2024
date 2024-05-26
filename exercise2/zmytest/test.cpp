
// #include "..."
#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../stack/stack.hpp"
#include "../queue/queue.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"


#include "../zlasdtest/container/container.hpp"
#include "../zlasdtest/container/dictionary.hpp"
#include "../zlasdtest/container/linear.hpp"
#include "../zlasdtest/container/mappable.hpp"
#include "../zlasdtest/container/testable.hpp"
#include "../zlasdtest/container/traversable.hpp"
#include "../zlasdtest/vector/vector.hpp"
#include "../zlasdtest/list/list.hpp"
#include "../zlasdtest/stack/stack.hpp"
#include "../zlasdtest/queue/queue.hpp"
#include "../zlasdtest/iterator/iterator.hpp"
#include "../zlasdtest/binarytree/binarytree.hpp"
#include "../zlasdtest/bst/bst.hpp"
/* ************************************************************************** */

#include <iostream>
unsigned long numTestexecuted = 0;
unsigned long numError = 0;

using namespace std;

/* ************************************************************************** */
//!NOTE(05/26/2024) I had forgotten to add the test for the first library, so I added it here.

//todo add the test for the first library:
void traversableTest();
void dictionaryTest();
void mappableTest();
void linearTest();
void vectorTest();
void listTest();
void stackVecTest();
void queueVecTest();
void stackLstTest();
void queueLstTest();
//test for the second library
void iteratorTest();
void binaryTreeLinkedTest();
void binaryTreeVectorTest();
void binarySearchTreeLinkedTest();

namespace lucaTest{
  void mytest() {
    // ...
    srand(time(0));
    cout << "Hello, World!" << endl;

    //!NOTE(05/26/2024) I had forgotten to add the test for the first library, so I added it here.
    //! test for the first library:

    traversableTest();
    dictionaryTest();
    mappableTest();
    linearTest();
    vectorTest();
    listTest();
    stackVecTest();
    queueVecTest();
    stackLstTest();
    queueLstTest();

    //! test for the second library:

    iteratorTest();
    binaryTreeLinkedTest();
    binaryTreeVectorTest();
    binarySearchTreeLinkedTest();

    std::cout << "\n\n\nI'm happy to see ya!\n\n\n" << std::endl;

    if (numError == 0) {
      std::cout << "All tests passed!\n" << std::endl;
    } else {
      std::cout << "Some tests failed!\n " <<  numTestexecuted << "/ " << numError << " errors found.\n" << std::endl;
    }
  }
}

/* ************************************************************************** */
  void traversableTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::Vector<int> v1(16);
    lasd::List<int> l1;

    SetAt(testnum, testerr, v1, true, 0, 1);
    SetAt(testnum, testerr, v1, true, 1, 2);
    SetAt(testnum, testerr, v1, true, 2, 3);
    SetAt(testnum, testerr, v1, true, 3, 4);
    SetAt(testnum, testerr, v1, true, 4, 5);
    InsertAtBack(testnum, testerr, l1, true, 1);
    InsertAtBack(testnum, testerr, l1, true, 2);
    InsertAtBack(testnum, testerr, l1, true, 3);
    Traverse(testnum, testerr, v1, true, &TraversePrint<int>);
    TraversePreOrder(testnum, testerr, v1, true, &TraversePrint<int>);
    TraversePostOrder(testnum, testerr, v1, true, &TraversePrint<int>);
    Fold(testnum, testerr, v1, true, &FoldAdd<int>, 0, 15);
    FoldPreOrder(testnum, testerr, v1, true, &FoldAdd<int>, 0, 15);
    FoldPostOrder(testnum, testerr, v1, true, &FoldAdd<int>, 0, 15);

    v1.Clear();
    l1.Clear();
    Empty(testnum, testerr, v1, true);
    Empty(testnum, testerr, l1, true);
    Size(testnum, testerr, v1, true, 0);
    Size(testnum, testerr, l1, true, 0);
    Traverse(testnum, testerr, v1, true, &TraversePrint<int>);
    TraversePreOrder(testnum, testerr, v1, true, &TraversePrint<int>);
    TraversePostOrder(testnum, testerr, v1, true, &TraversePrint<int>);
    Fold(testnum, testerr, v1, true, &FoldAdd<int>, 0, 0);
    FoldPreOrder(testnum, testerr, v1, true, &FoldAdd<int>, 0, 0);
    FoldPostOrder(testnum, testerr, v1, true, &FoldAdd<int>, 0, 0);
  } 

  void dictionaryTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::List<int> l1;

    InsertC(testnum, testerr, l1, true, 1);
    InsertC(testnum, testerr, l1, true, 2);
    InsertC(testnum, testerr, l1, true, 3);
    InsertC(testnum, testerr, l1, false, 3);
    InsertC(testnum, testerr, l1, false, 2);
    InsertC(testnum, testerr, l1, false, 1);
    Remove(testnum, testerr, l1, true, 1);
    Remove(testnum, testerr, l1, true, 2);
    Remove(testnum, testerr, l1, true, 3);
    Remove(testnum, testerr, l1, false, 3);
    Remove(testnum, testerr, l1, false, 2);
    Remove(testnum, testerr, l1, false, 1);
    InsertAtFront(testnum, testerr, l1, true, 1);
    InsertAtFront(testnum, testerr, l1, true, 2);
    InsertAtFront(testnum, testerr, l1, true, 3);
    InsertAtBack(testnum, testerr, l1, true, 4);
    InsertAtBack(testnum, testerr, l1, true, 5);
    InsertAtBack(testnum, testerr, l1, true, 6);
    Size(testnum, testerr, l1, true, 6);
    lasd::Vector<int> v1(3);
    SetAt(testnum, testerr, v1, true, 0, 1);
    SetAt(testnum, testerr, v1, true, 1, 2);
    SetAt(testnum, testerr, v1, true, 2, 3);
    InsertAllC(testnum, testerr, l1, false, v1);
    RemoveAll(testnum, testerr, l1, true, v1);
    Exists(testnum, testerr, l1, false, 1);
    Exists(testnum, testerr, l1, false, 2);
    Exists(testnum, testerr, l1, false, 3);
    Exists(testnum, testerr, l1, true, 4);
    InsertAllC(testnum, testerr, l1, true, v1);
    l1.Clear();
    InsertSomeC(testnum, testerr, l1, true, v1);
    Remove(testnum, testerr, l1, true, 1);
    Remove(testnum, testerr, l1, true, 2);
    Remove(testnum, testerr, l1, true, 3);
    Remove(testnum, testerr, l1, false, 3);
    InsertAllC(testnum, testerr, l1, true, v1);
    RemoveSome(testnum, testerr, l1, true, v1);
  }

  void mappableTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::Vector<int> v1(10);
    lasd::List<int> l1;

    MapPreOrder(testnum, testerr, v1, true, &MapIncrement<int>);
    MapPreOrder(testnum, testerr, l1, true, &MapIncrement<int>);
    MapPostOrder(testnum, testerr, v1, true, &MapIncrement<int>);
    MapPostOrder(testnum, testerr, l1, true, &MapIncrement<int>);

    v1.Resize(16);
    Size(testnum, testerr, v1, true, 16);
    SetAt(testnum, testerr, v1, true, 0, 1);
    SetAt(testnum, testerr, v1, true, 1, 2);
    SetAt(testnum, testerr, v1, true, 2, 3);
    SetAt(testnum, testerr, v1, true, 3, 4);
    SetAt(testnum, testerr, v1, true, 4, 5);
    Map(testnum, testerr, v1, true, &MapIncrement<int>);
    MapPreOrder(testnum, testerr, v1, true, &MapIncrement<int>);
    MapPostOrder(testnum, testerr, v1, true, &MapIncrement<int>);
    v1.Clear();
    Size(testnum, testerr, v1, true, 0);
    Empty(testnum, testerr, v1, true);
    for (ulong i = 0; i < 16; i++) { 
      l1.InsertAtBack(i + 1);
    }
    Map(testnum, testerr, l1, true, &MapIncrement<int>);
    MapPreOrder(testnum, testerr, l1, true, &MapIncrement<int>);
    MapPostOrder(testnum, testerr, l1, true, &MapIncrement<int>);


    //todo aggiungere altri test appena possibile
  }

  void linearTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::Vector<int> v1;
    lasd::List<int> l1;

    v1.Resize(16);
    EqualLinear(testnum, testerr, v1, l1, false);

    l1.Clear();
    v1.Clear();
    v1.Resize(16);
    
    for (ulong i = 0; i < v1.Size(); i++) {
      v1[i] = i + 1;
    }

    for (ulong i = 0; i < v1.Size(); i++) { 
      l1.InsertAtBack(v1[i]);
    }

    EqualLinear(testnum, testerr, v1, l1, true);
    GetFront(testnum, testerr, v1, true, 1);
    GetFront(testnum, testerr, l1, true, 1);
    GetBack(testnum, testerr, v1, true, 16);
    GetBack(testnum, testerr, l1, true, 16);
    InsertAtFront(testnum, testerr, l1, true, 0);
    InsertAtBack(testnum, testerr, l1, true, 17);
    Exists(testnum, testerr, l1, true, 0);
    Exists(testnum, testerr, l1, true, 17);
    FrontNRemove(testnum, testerr, l1, true, 0);
    Remove(testnum, testerr, l1, true, 17);
    Exists(testnum, testerr, l1, false, 0);
    Exists(testnum, testerr, l1, false, 17);
  }

  void vectorTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::Vector<int> v1(16);
    lasd::Vector<int> v2(16);
    lasd::Vector<int> v3(16);

    for (ulong i = 0; i < v1.Size(); i++) { 
      v1[i] = i + 1;
    }

    for (ulong i = 0; i < v2.Size(); i++) { 
      v2[i] = i + 1;
    }

    for (ulong i = 0; i < v3.Size(); i++) { 
      v3[i] = i + 2;
    }

    lasd::Vector<int> v4(v1);
    lasd::Vector<int> v5(std::move(v1));

    Size(testnum, testerr, v1, true, 0);
    Size(testnum, testerr, v2, true, 16);
    Size(testnum, testerr, v3, true, 16);
    Size(testnum, testerr, v4, true, 16);
    Size(testnum, testerr, v5, true, 16);
    Empty(testnum, testerr, v1, true);
    Empty(testnum, testerr, v2, false);
    Empty(testnum, testerr, v3, false);
    Empty(testnum, testerr, v4, false);
    Empty(testnum, testerr, v5, false);
    GetFront(testnum, testerr, v2, true, 1);
    GetBack(testnum, testerr, v2, true, 16);
    SetAt(testnum, testerr, v2, true, 0, 0);
    SetAt(testnum, testerr, v2, true, 15, 17);
    GetAt(testnum, testerr, v2, true, 0, 0);
    GetAt(testnum, testerr, v2, true, 15, 17);

    EqualLinear(testnum, testerr, v2, v3, false);
    EqualLinear(testnum, testerr, v2, v4, false);

    v1 = v2;
    EqualLinear(testnum, testerr, v1, v2, true);
    v1 = std::move(v2);
    EqualLinear(testnum, testerr, v1, v2, true);

    lasd::SortableVector<int> sv1;

    Empty(testnum, testerr, sv1, true);
    Size(testnum, testerr, sv1, true, 0);
    sv1 = v1;
    Size(testnum, testerr, sv1, true, 16);
    sv1.Sort();
    EqualLinear(testnum, testerr, sv1, v1, true);

    sv1.Resize(0);
    Empty(testnum, testerr, sv1, true);
    lasd::List<int> l1;
    for (ulong i = 16; i > 0; --i) { 
      l1.InsertAtBack(i);
    }
    lasd::SortableVector<int> sv2(l1);
    lasd::SortableVector<int> sv3(16);
    for (ulong i = 0; i < sv3.Size(); i++) { 
      sv3[i] = i + 1;
    }
    EqualLinear(testnum, testerr, sv2, sv3, false);
    sv2.Sort();
    EqualLinear(testnum, testerr, sv2, sv3, true);

  }

  void listTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::List<int> l1;
    lasd::List<int> l2{l1};
    EqualLinear(testnum, testerr, l1, l2, true);
    lasd::List<int> l3{std::move(l1)};
    EqualLinear(testnum, testerr, l1, l3, true);

    Remove(testnum, testerr, l1, false, 1);
    Remove(testnum, testerr, l1, false, 2);
    for (ulong i = 0; i < 16; i++) { 
      l1.InsertAtBack(i + 1);
    }
    Remove(testnum, testerr, l1, true, 1);
    Remove(testnum, testerr, l1, true, 2);
    Remove(testnum, testerr, l1, true, 3);
    l1.Clear();
    Empty(testnum, testerr, l1, true);
    InsertAtFront(testnum, testerr, l1, true, 1);
    InsertAtFront(testnum, testerr, l1, true, 2);
    InsertAtFront(testnum, testerr, l1, true, 3);
    InsertAtBack(testnum, testerr, l1, true, 4);
    InsertAtBack(testnum, testerr, l1, true, 5);
    Exists(testnum, testerr, l1, true, 1);
    Exists(testnum, testerr, l1, true, 2);
    Exists(testnum, testerr, l1, true, 3);
    Exists(testnum, testerr, l1, true, 4);
    Exists(testnum, testerr, l1, true, 5);
    Exists(testnum, testerr, l1, false, 6);
    FrontNRemove(testnum, testerr, l1, true, 3);
    FrontNRemove(testnum, testerr, l1, true, 2);
    Remove(testnum, testerr, l1, true, 4);
    Exists(testnum, testerr, l1, true, 5);
    l1.Clear();
    for (ulong i = 0; i < 16; i++) { 
      l1.InsertAtBack(i + 1);
    }
    Remove(testnum, testerr, l1, true, 8);
    Exists(testnum, testerr, l1, false, 8);
    Exists(testnum, testerr, l1, true, 9);
    Exists(testnum, testerr, l1, true, 7);

  }

  void stackVecTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::StackVec<string> s1;
    string str2 = "Hello";
    string str3 = "World";
    string str4 = "!";
    string str5 = "I'm";
    string str6 = "Luca";
    string str7 = "!";
    Size(testnum, testerr, s1, true, 0);
    Empty(testnum, testerr, s1, true);

    PushM(testnum, testerr, s1, str2);
    Size(testnum, testerr, s1, true, 1);
    PushM(testnum, testerr, s1, str3);
    Size(testnum, testerr, s1, true, 2);
    PushM(testnum, testerr, s1, str4);
    Size(testnum, testerr, s1, true, 3);
    PushC(testnum, testerr, s1, str5);
    Size(testnum, testerr, s1, true, 4);
    PushC(testnum, testerr, s1, str6);
    PushC(testnum, testerr, s1, str7);
    Size(testnum, testerr, s1, true, 6);
    Empty(testnum, testerr, s1, false);

    Pop(testnum, testerr, s1, true);
    Size(testnum, testerr, s1, true, 5);
    Top(testnum, testerr, s1, true, str6);
    Pop(testnum, testerr, s1, true);
    Size(testnum, testerr, s1, true, 4);
    TopNPop(testnum, testerr, s1, true, str5);
    Size(testnum, testerr, s1, true, 3);

    lasd::StackVec<string> s2(s1);
    EqualStack(testnum, testerr, s1, s2, true);
    lasd::StackVec<string> s3(std::move(s1));
    EqualStack(testnum, testerr, s1, s3, false);
    lasd::StackVec<string> s4;
    s4 = s2;
    EqualStack(testnum, testerr, s2, s4, true);
    lasd::StackVec<string> s5;
    s5 = std::move(s2);
    EqualStack(testnum, testerr, s2, s5, false);

  }

  void queueVecTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::QueueVec<string> q1;
    string str2 = "Hello";
    string str3 = "World";
    string str4 = "!";
    string str5 = "I'm";
    string str6 = "Luca";
    string str7 = "!";
    Size(testnum, testerr, q1, true, 0);
    Empty(testnum, testerr, q1, true);
    Dequeue(testnum, testerr, q1, false);
    EnqueueM(testnum, testerr, q1, str2);
    Size(testnum, testerr, q1, true, 1);
    EnqueueM(testnum, testerr, q1, str3);
    Size(testnum, testerr, q1, true, 2);
    EnqueueM(testnum, testerr, q1, str4);
    Size(testnum, testerr, q1, true, 3);
    EnqueueC(testnum, testerr, q1, str5);
    Size(testnum, testerr, q1, true, 4);
    EnqueueC(testnum, testerr, q1, str6);
    EnqueueC(testnum, testerr, q1, str7);
    Size(testnum, testerr, q1, true, 6);
    
    Head(testnum, testerr, q1, true, str2);
    Dequeue(testnum, testerr, q1, true);
    Size(testnum, testerr, q1, true, 5);
    HeadNDequeue(testnum, testerr, q1, true, str3);
    Size(testnum, testerr, q1, true, 4);
    lasd::QueueVec<string> q2(q1);
    EqualQueue(testnum, testerr, q1, q2, true);
    lasd::QueueVec<string> q3(std::move(q1));
    EqualQueue(testnum, testerr, q1, q3, false);

    lasd::List<string> l1;
    lasd::Vector<string> v1(16);
    for (ulong i = 0; i < 16; i++) { 
      l1.InsertAtBack(to_string(i + 1));
    }
    for (ulong i = 0; i < 16; i++) { 
      v1[i] = to_string(i + 1);
    }
    lasd::QueueVec<string> q4(l1);
    lasd::QueueVec<string> q5(v1);
    EqualQueue(testnum, testerr, q4, q5, true);
    q5 = std::move(l1);
    EqualQueue(testnum, testerr, q4, q5, true);
    lasd::QueueVec<string> q6{std::move(v1)};
    EqualQueue(testnum, testerr, q4, q6, true);

  }

  void stackLstTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::StackLst<string> s1;
    string str2 = "Hello";
    string str3 = "World";
    string str4 = "!";
    string str5 = "I'm";
    string str6 = "Luca";
    string str7 = "!";
    Size(testnum, testerr, s1, true, 0);
    Empty(testnum, testerr, s1, true);

    PushM(testnum, testerr, s1, str2);
    Size(testnum, testerr, s1, true, 1);
    PushM(testnum, testerr, s1, str3);
    Size(testnum, testerr, s1, true, 2);
    PushM(testnum, testerr, s1, str4);
    Size(testnum, testerr, s1, true, 3);
    PushC(testnum, testerr, s1, str5);
    Size(testnum, testerr, s1, true, 4);
    PushC(testnum, testerr, s1, str6);
    PushC(testnum, testerr, s1, str7);
    Size(testnum, testerr, s1, true, 6);
    Empty(testnum, testerr, s1, false);

    Pop(testnum, testerr, s1, true);
    Size(testnum, testerr, s1, true, 5);
    Top(testnum, testerr, s1, true, str6);
    Pop(testnum, testerr, s1, true);
    Size(testnum, testerr, s1, true, 4);
    TopNPop(testnum, testerr, s1, true, str5);
    Size(testnum, testerr, s1, true, 3);

    lasd::StackLst<string> s2(s1);
    EqualStack(testnum, testerr, s1, s2, true);
    lasd::StackLst<string> s3(std::move(s1));
    EqualStack(testnum, testerr, s1, s3, false);
    lasd::StackLst<string> s4;
    s4 = s2;
    EqualStack(testnum, testerr, s2, s4, true);
  }

  void queueLstTest(){
    unsigned int testnum = 0;
    unsigned int testerr = 0;

    lasd::QueueLst<string> q1;
    string str2 = "Hello";
    string str3 = "World";
    string str4 = "!";
    string str5 = "I'm";
    string str6 = "Luca";
    string str7 = "!";
    Size(testnum, testerr, q1, true, 0);
    Empty(testnum, testerr, q1, true);
    Dequeue(testnum, testerr, q1, false);
    EnqueueM(testnum, testerr, q1, str2);
    Size(testnum, testerr, q1, true, 1);
    EnqueueM(testnum, testerr, q1, str3);
    Size(testnum, testerr, q1, true, 2);
    EnqueueM(testnum, testerr, q1, str4);
    Size(testnum, testerr, q1, true, 3);
    EnqueueC(testnum, testerr, q1, str5);
    Size(testnum, testerr, q1, true, 4);
    EnqueueC(testnum, testerr, q1, str6);
    EnqueueC(testnum, testerr, q1, str7);

    lasd:: QueueLst<string> q2(q1);
    EqualQueue(testnum, testerr, q1, q2, true);
    lasd:: QueueLst<string> q3(std::move(q2));
    EqualQueue(testnum, testerr, q1, q3, true);
    HeadNDequeue(testnum, testerr, q1, true, str2);
    Size(testnum, testerr, q1, true, 5);
    Head(testnum, testerr, q1, true, str3);
    Dequeue(testnum, testerr, q1, true);
    Size(testnum, testerr, q1, true, 4);

    lasd::List<string> l1;
    lasd::Vector<string> v1(16);
    for (ulong i = 0; i < 16; i++) { 
      l1.InsertAtBack(to_string(i + 1));
    }
    for (ulong i = 0; i < 16; i++) { 
      v1[i] = to_string(i + 1);
    }
    lasd::QueueLst<string> q4(l1);
    lasd::QueueLst<string> q5(v1);
    EqualQueue(testnum, testerr, q4, q5, true);
    q5 = std::move(l1);
    EqualQueue(testnum, testerr, q4, q5, true);
    q5 = v1;
    EqualQueue(testnum, testerr, q4, q5, true);
    lasd::QueueLst<string> q6{std::move(v1)};
    EqualQueue(testnum, testerr, q4, q6, true);
    lasd::QueueLst<int> q7;
    EnqueueC(testnum, testerr, q7, 1);
    EnqueueC(testnum, testerr, q7, 2);
    HeadNDequeue(testnum, testerr, q7, true, 1);
    HeadNDequeue(testnum, testerr, q7, true, 2);
    while (!q7.Empty()) {
      Dequeue(testnum, testerr, q7, true);
    }
    Dequeue(testnum, testerr, q7, false);
    Head(testnum, testerr, q7, false, 1);
    EnqueueC(testnum, testerr, q7, 1);
    Head(testnum, testerr, q7, true, 1);
    HeadNDequeue(testnum, testerr, q7, true, 1);
  }

  void iteratorTest() {
    std::cout << "Testing iterator" << std::endl;

    //! Vector and List Declaration
    lasd::Vector <int> v1 (16);
    lasd::List <int> l1;
    


    //! Fill Vector and List
    for (ulong i = 0; i < v1.Size(); i++) { 
      // v1[i] = rand() % 100;
      v1[i] = i + 1;
    }
    for (ulong i = 0; i < v1.Size(); i++) { 
      l1.InsertAtBack(v1[i]);
    }
    
    
    lasd::BinaryTreeVec<int> btvec(v1);
    lasd::BinaryTreeLnk<int> btlnk(l1);

    

    unsigned int testnum = 0;
    unsigned int testerr = 0;

    try {
      Empty(testnum, testerr, btvec, false);
      Empty(testnum, testerr, btlnk, false);
      Size(testnum, testerr, btvec, true, 16);
      Size(testnum, testerr, btlnk, true, 16);
      Traverse(testnum, testerr, btvec, true, &TraversePrint<int>);
      TraversePreOrder(testnum, testerr, btvec, true, &TraversePrint<int>);
      TraversePostOrder(testnum, testerr, btvec, true, &TraversePrint<int>);
      TraverseInOrder(testnum, testerr, btvec, true, &TraversePrint<int>);
      TraverseBreadth(testnum, testerr, btvec, true, &TraversePrint<int>);
      Fold(testnum, testerr, btvec, true, &FoldAdd<int>, 0, 136);
      FoldPreOrder(testnum, testerr, btvec, true, &FoldAdd<int>, 0, 136);
      FoldPostOrder(testnum, testerr, btvec, true, &FoldAdd<int>, 0, 136);
      FoldInOrder(testnum, testerr, btvec, true, &FoldAdd<int>, 0, 136);
      FoldBreadth(testnum, testerr, btvec, true, &FoldAdd<int>, 0, 136);
      EqualBT(testnum, testerr, btvec, btlnk);
      btvec.Clear();
      btlnk.Clear();
      Empty(testnum, testerr, btvec, true);
      Empty(testnum, testerr, btlnk, true);
      Size(testnum, testerr, btvec, true, 0);
      Size(testnum, testerr, btlnk, true, 0);
      EqualBT(testnum, testerr, btvec, btlnk);

      // Ora testo gli iteratori


      // Test l'iteratore con btvec vuoto
      lasd::BTPreOrderIterator<int> itr1(btvec);

      std::cout << "Dimensione di btvec: " << btvec.Size() << std::endl;

      Terminated(testnum, testerr, itr1, true);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr1, true, static_cast<int>(i));
        ++itr1;
      }

      // Test l'iteratore con btlnk vuoto
      lasd::BTPreOrderIterator<int> itr2(btlnk);

      Terminated(testnum, testerr, itr2, true);

      std::cout << "Dimensione di btlnk: " << btlnk.Size() << std::endl;

      for(long unsigned int i = 1; i <= btlnk.Size(); ++i) {
        GetItrValue(testnum, testerr, itr2, true, static_cast<int>(i));
        ++itr2;
      }

      //! Test l'iteratore con btvec pieno PreOrder
      btvec = v1;
      lasd::BTPreOrderIterator<int> itr3(btvec);

      std::cout << "Dimensione di btvec: " << btvec.Size() << std::endl;

      std::cout << "PreOrderIterator vec: " << std::endl;

      lasd::Vector<int> expectedValues(16);
      long unsigned int valuesPreorder[] = {1, 2, 4, 8, 16, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
      long unsigned int valuesInorder[] = {16, 8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
      long unsigned int valuesPostorder[] = {16, 8, 9, 4, 10, 11, 5, 2, 12, 13, 6, 14, 15, 7, 3, 1};
      long unsigned int valuesBreadth[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

      for(long unsigned int i = 0; i < sizeof(valuesPreorder)/sizeof(valuesPreorder[0]); ++i) expectedValues[i] = valuesPreorder[i];

      Terminated(testnum, testerr, itr3, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr3, true, expectedValues[i-1]);
        ++itr3;
      }

      Terminated(testnum, testerr, itr3, true);

      itr3.Reset();

      Terminated(testnum, testerr, itr3, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr3, true, expectedValues[i-1]);
        ++itr3;
      }

      std::cout << "PreOrderIterator lst: " << std::endl;


      //! Test l'iteratore con btlnk pieno PreOrder
      btlnk = l1;
      lasd::BTPreOrderIterator<int> itr4(btlnk);

      std::cout << "Dimensione di btlnk: " << btlnk.Size() << std::endl;
      
      for(long unsigned int i = 0; i < sizeof(valuesPreorder)/sizeof(valuesPreorder[0]); ++i) expectedValues[i] = valuesPreorder[i];

      Terminated(testnum, testerr, itr4, false);

      for(long unsigned int i = 1; i <= btlnk.Size(); ++i) {
        GetItrValue(testnum, testerr, itr4, true, expectedValues[i-1]);
        ++itr4;
      }

      Terminated(testnum, testerr, itr4, true);

      itr4.Reset();

      Terminated(testnum, testerr, itr4, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr4, true, expectedValues[i-1]);
        ++itr4;
      }

      std::cout << "PostOrderIterator vec: " << std::endl;

      //! Test l'iteratore con btvec pieno InOrder

      lasd::BTInOrderIterator<int> itr5(btvec);

      for(long unsigned int i = 0; i < sizeof(valuesInorder)/sizeof(valuesInorder[0]); ++i) expectedValues[i] = valuesInorder[i];
      
      Terminated(testnum, testerr, itr5, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr5, true, expectedValues[i-1]);
        ++itr5;
      }

      Terminated(testnum, testerr, itr5, true);

      itr5.Reset();

      Terminated(testnum, testerr, itr5, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr5, true, expectedValues[i-1]);
        ++itr5;
      }

      //! Test l'iteratore con btlnk pieno InOrder

      std::cout << "PostOrderIterator lst: " << std::endl;

      lasd::BTInOrderIterator<int> itr6(btlnk);

      Terminated(testnum, testerr, itr6, false);

      for(long unsigned int i = 1; i <= btlnk.Size(); ++i) {
        GetItrValue(testnum, testerr, itr6, true, expectedValues[i-1]);
        ++itr6;
      }

      Terminated(testnum, testerr, itr6, true);

      //! Test l'iteratore con btvec pieno PostOrder

      std::cout << "InOrderIterator vec: " << std::endl;

      lasd::BTPostOrderIterator<int> itr7(btvec);
      for(long unsigned int i = 0; i < sizeof(valuesPostorder)/sizeof(valuesPostorder[0]); ++i) expectedValues[i] = valuesPostorder[i];

      Terminated(testnum, testerr, itr7, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr7, true, expectedValues[i-1]);
        ++itr7;
      }

      Terminated(testnum, testerr, itr7, true);

      itr7.Reset();

      Terminated(testnum, testerr, itr7, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr7, true, expectedValues[i-1]);
        ++itr7;
      }

      //! Test l'iteratore con btlnk pieno PostOrder

      std::cout << "InOrderIterator lst: " << std::endl;

      lasd::BTPostOrderIterator<int> itr8(btlnk);

      Terminated(testnum, testerr, itr8, false);

      for(long unsigned int i = 1; i <= btlnk.Size(); ++i) {
        GetItrValue(testnum, testerr, itr8, true, expectedValues[i-1]);
        ++itr8;
      }

      Terminated(testnum, testerr, itr8, true);

      itr8.Reset();

      Terminated(testnum, testerr, itr8, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr8, true, expectedValues[i-1]);
        ++itr8;
      }

      Terminated(testnum, testerr, itr8, true);

      //! Test l'iteratore con btvec pieno Breadth

      std::cout << "BreadthIterator vec: " << std::endl;

      lasd::BTBreadthIterator<int> itr9(btvec);
      for(long unsigned int i = 0; i < sizeof(valuesBreadth)/sizeof(valuesBreadth[0]); ++i) expectedValues[i] = valuesBreadth[i];
      Terminated(testnum, testerr, itr9, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr9, true, expectedValues[i-1]);
        ++itr9;
      }

      Terminated(testnum, testerr, itr9, true);

      itr9.Reset();

      Terminated(testnum, testerr, itr9, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr9, true, expectedValues[i-1]);
        ++itr9;
      }

      //! Test l'iteratore con btlnk pieno Breadth

      std::cout << "BreadthIterator lst: " << std::endl;

      lasd::BTBreadthIterator<int> itr10(btlnk);
      Terminated(testnum, testerr, itr10, false);

      for(long unsigned int i = 1; i <= btlnk.Size(); ++i) {
        GetItrValue(testnum, testerr, itr10, true, expectedValues[i-1]);
        ++itr10;
      }

      Terminated(testnum, testerr, itr10, true);

      itr10.Reset();

      Terminated(testnum, testerr, itr10, false);

      for(long unsigned int i = 1; i <= btvec.Size(); ++i) {
        GetItrValue(testnum, testerr, itr10, true, expectedValues[i-1]);
        ++itr10;
      }

      Terminated(testnum, testerr, itr10, true);


      //Todo Se ho genio (e sopratutto tempo) faccio qualche altro test.

      lasd::BTBreadthIterator<int> itr11(itr10);
      if (itr11 == itr10){ std::cout << "Correct!" << std::endl;}
      else if (itr11 != itr10){std::cout << "Error!" << std::endl;}

      lasd::BTBreadthIterator<int> itr12(std::move(itr11));

      lasd::BTBreadthIterator<int> itr13(btlnk);
      itr13 = itr12;
      if (itr13 == itr12) {std::cout << "Correct!" << std::endl;}
      else if (itr13 != itr12) {std::cout << "Error!" << std::endl;} 

      //Todo Se ho genio (e sopratutto tempo) faccio qualche altro test.

      lasd::BTBreadthIterator<int> itr14(itr13);
      itr14.Reset();
      itr14.Reset();
      itr14.Reset();
      Terminated(testnum, testerr, itr14, false);
      lasd::BinaryTreeLnk<int> btlnk2;
      lasd::BTPreOrderIterator<int> itr15(btlnk2);
      Terminated(testnum, testerr, itr15, true);
      btlnk2 = l1;
      itr15.Reset();
      GetItrValue(testnum, testerr, itr15, false, 1);
      GetItrValue(testnum, testerr, itr15, false, 2);
      GetItrValue(testnum, testerr, itr15, false, 3);
      GetItrValue(testnum, testerr, itr15, false, 4);
  
      







    } catch (...) {
      numTestexecuted++; numError++;
      cout << endl << "Unmanaged error! " << endl;
    }
    std::cout << "End of BinaryTree<int> Test! (Errors/Tests: " << numError << "/" << numTestexecuted << ")" << endl;
    testnum += numTestexecuted;
    testerr += numError;
  }

  void binaryTreeLinkedTest(){
    lasd::List<int> l1;
    for (ulong i = 0; i < 16; i++) { 
      l1.InsertAtBack(i + 1);
    }
    lasd::BinaryTreeLnk<int> btlnk(l1);

    unsigned int testnum = 0;
    unsigned int testerr = 0;

    try {

      lasd::BinaryTreeLnk<int> btlnk2(std::move(btlnk));
      NonEqualBT(testnum, testerr, btlnk, btlnk2);
      Empty(testnum, testerr, btlnk, true);

      lasd::BinaryTreeLnk<int> btlnk(btlnk2);
      Empty(testnum, testerr, btlnk, false);
      Size(testnum, testerr, btlnk, true, 16);
      EqualBT(testnum, testerr, btlnk, btlnk2);

      lasd::BinaryTreeLnk<int> btlnk3;
      NonEqualBT(testnum, testerr, btlnk3, btlnk);
      btlnk3 = std::move(btlnk2);
      NonEqualBT(testnum, testerr, btlnk2, btlnk3);

      lasd::BinaryTreeLnk<int> btlnk4;
      lasd::BinaryTreeLnk<int> btlnk5;
      EqualBT(testnum, testerr, btlnk4, btlnk5);
      btlnk4 = btlnk5;
      TraverseBreadth(testnum, testerr, btlnk4, true, &TraversePrint<int>);
      btlnk4 = std::move(btlnk5);
      EqualBT(testnum, testerr, btlnk4, btlnk5);
      lasd::BinaryTreeLnk<int> btlnk6;
      lasd::BinaryTreeLnk<int> btlnk7(std::move(btlnk6));
      EqualBT(testnum, testerr, btlnk6, btlnk7);
      btlnk7 = std::move(btlnk6);
      EqualBT(testnum, testerr, btlnk6, btlnk7);

      Traverse(testnum, testerr, btlnk6, true, &TraversePrint<int>);
      TraversePreOrder(testnum, testerr, btlnk6, true, &TraversePrint<int>);
      TraversePostOrder(testnum, testerr, btlnk6, true, &TraversePrint<int>);
      TraverseInOrder(testnum, testerr, btlnk6, true, &TraversePrint<int>);
      TraverseBreadth(testnum, testerr, btlnk6, true, &TraversePrint<int>);
      Fold(testnum, testerr, btlnk6, true, &FoldAdd<int>, 0, 0);



      // todo spostastare in btvec
      lasd::BinaryTreeVec<int> btvec;
      btvec = btlnk6;
      EqualBT(testnum, testerr, btvec, btlnk6);
      Traverse(testnum, testerr, btvec, true, &TraversePrint<int>);

      



      //todo Testare exists e vedere se modifica i dati.


      //todo Exists
      //todo Chiamo ogni funzione almeno una volta
      //todo in bst per esempio prende in input minimo, massimo ecc. e controlla che sia giusto
      //todo E chiamo quel test su un bst vuoto, uno degenere e uno random

      Empty(testnum, testerr, btlnk7, true);
      Size(testnum, testerr, btlnk7, true, 0);
      Exists(testnum, testerr, btlnk7, false, 1);
      btlnk7 = l1;
      Exists(testnum, testerr, btlnk7, true, 1);
      Exists(testnum, testerr, btlnk7, true, 16);
      Exists(testnum, testerr, btlnk7, false, 17);
      Exists(testnum, testerr, btlnk7, false, 0);
      Exists(testnum, testerr, btlnk7, false, -1);
      Exists(testnum, testerr, btlnk7, false, 100);
      Exists(testnum, testerr, btlnk7, true, 8);
      Exists(testnum, testerr, btlnk7, false, 104);
      btlnk7.Root().LeftChild().LeftChild().Element() = int(104);
      Exists(testnum, testerr, btlnk7, true, 104);


      if (!btlnk7.Root().LeftChild().LeftChild().IsLeaf()) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      testnum++;

      lasd::Vector<int> vectLeaf(1);
      vectLeaf[0] = 104;
      lasd::BinaryTreeLnk<int> btlnk8;
      btlnk8 = vectLeaf;
      Exists(testnum, testerr, btlnk8, true, 104);
      Exists(testnum, testerr, btlnk8, false, 105);
      if (btlnk8.Root().Element() == 104) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (!btlnk8.Root().HasLeftChild()) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (!btlnk8.Root().HasRightChild()) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (btlnk8.Root().IsLeaf()) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      testnum+=4;
      lasd::Vector<int> vec2(2);
      vec2[0] = 104;
      vec2[1] = 105;
      btlnk8 = vec2;
      Exists(testnum, testerr, btlnk8, true, 104);
      Exists(testnum, testerr, btlnk8, true, 105);
      Exists(testnum, testerr, btlnk8, false, 106);
      if (btlnk8.Root().Element() == 104) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (btlnk8.Root().LeftChild().Element() == 105) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      testnum+=2;

      //analog test Double

      lasd::BinaryTreeLnk<double> btlnk9;
      lasd::List<double> l2;
      for (double i = 0; i < 16; i++) { 
        l2.InsertAtBack(i + 1.5);
      }
      btlnk9 = l2;
      Exists(testnum, testerr, btlnk9, true, 1.5);
      Exists(testnum, testerr, btlnk9, true, 16.5);
      Exists(testnum, testerr, btlnk9, false, 17.5);
      Exists(testnum, testerr, btlnk9, false, 0.5);
      Exists(testnum, testerr, btlnk9, false, -1.5);
      Exists(testnum, testerr, btlnk9, false, 100.5);
      Exists(testnum, testerr, btlnk9, true, 8.5);
      Exists(testnum, testerr, btlnk9, false, 104.5);
      btlnk9.Root().LeftChild().LeftChild().Element() = double(104.5);
      Exists(testnum, testerr, btlnk9, true, 104.5);
      lasd::Vector<double> vectLeaf2(1);
      vectLeaf2[0] = 104.5;
      lasd::BinaryTreeLnk<double> btlnk10;
      btlnk10 = vectLeaf2;
      Exists(testnum, testerr, btlnk10, true, 104.5);
      Exists(testnum, testerr, btlnk10, false, 105.5);
      if (btlnk10.Root().Element() == 104.5) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (!btlnk10.Root().HasLeftChild()) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (!btlnk10.Root().HasRightChild()) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (btlnk10.Root().IsLeaf()) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}

      testnum+=4;

      // test string
      lasd::BinaryTreeLnk<std::string> btlnk11;
      lasd::List<std::string> l3;
      for (ulong i = 0; i < 16; i++) { 
        l3.InsertAtBack(std::to_string(i + 1));
      }
      btlnk11 = l3;
      // Exists(testnum, testerr, btlnk11, true, "1");
      

      
    } catch (...) {
      numTestexecuted++; numError++;
      cout << endl << "Unmanaged error! " << endl;
    }
  }
  
  void binaryTreeVectorTest(){
    lasd::Vector<int> v1(16);
    for (ulong i = 0; i < v1.Size(); i++) { 
      v1[i] = i + 1;
    }
    std::cout << "Testing BinaryTreeVec<int>" << std::endl;
    unsigned int testnum = 0;
    unsigned int testerr = 0;
    lasd::BinaryTreeVec<int> btvec1;

    try
    {
      Empty(testnum, testerr, btvec1, true);
      Size(testnum, testerr, btvec1, true, 0);
      btvec1 = v1;
      Empty(testnum, testerr, btvec1, false);
      Size(testnum, testerr, btvec1, true, 16);
      lasd::BinaryTreeVec<int> btvec2(btvec1);
      EqualBT(testnum, testerr, btvec1, btvec2);
      lasd::BinaryTreeVec<int> btvec3(std::move(btvec2));
      NonEqualBT(testnum, testerr, btvec1, btvec2);
      EqualBT(testnum, testerr, btvec1, btvec3);
      lasd::BinaryTreeVec<int> btvec4;
      lasd::BinaryTreeVec<int> btvec5;
      EqualBT(testnum, testerr, btvec4, btvec5);
      btvec4 = btvec5;
      Traverse(testnum, testerr, btvec4, true, &TraversePrint<int>);
      TraversePreOrder(testnum, testerr, btvec4, true, &TraversePrint<int>);
      TraverseInOrder(testnum, testerr, btvec4, true, &TraversePrint<int>);
      TraversePostOrder(testnum, testerr, btvec4, true, &TraversePrint<int>);
      TraverseBreadth(testnum, testerr, btvec4, true, &TraversePrint<int>);
      btvec4 = std::move(btvec5);
      EqualBT(testnum, testerr, btvec4, btvec5);
      lasd::BinaryTreeVec<int> btvec6 (v1);
      Exists(testnum, testerr, btvec6, true, 1);
      Exists(testnum, testerr, btvec6, true, 16);
      Exists(testnum, testerr, btvec6, false, 17);
      Exists(testnum, testerr, btvec6, false, 0);
      Exists(testnum, testerr, btvec6, false, -1);
      Exists(testnum, testerr, btvec6, true, 8);
      lasd::BinaryTreeVec<int> btvec7;
      Empty(testnum, testerr, btvec7, true);
      Size(testnum, testerr, btvec7, true, 0);
      Exists(testnum, testerr, btvec7, false, 1);
      Exists(testnum, testerr, btvec7, false, 0);
      Fold(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 0);
      FoldPreOrder(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 0);
      FoldInOrder(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 0);
      FoldBreadth(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 0);
      btvec7 = v1;
      Fold(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 136);
      FoldPreOrder(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 136);
      FoldInOrder(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 136);
      FoldPostOrder(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 136);
      FoldBreadth(testnum, testerr, btvec7, true, &FoldAdd<int>, 0, 136);

      if (btvec7.Root().Element() == 1) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (btvec7.Root().LeftChild().Element() == 2) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (btvec7.Root().RightChild().Element() == 3) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      if (!btvec7.Root().LeftChild().LeftChild().IsLeaf()) {std::cout << "Correct!" << std::endl;}
      else {std::cout << "Error!" << std::endl;}
      testnum+=4;

      lasd::BinaryTreeVec<int> btvec8 (v1);
      lasd::BinaryTreeVec<int> btvec9 (v1);
      EqualBT(testnum, testerr, btvec8, btvec9);
      btvec8.Clear();
      NonEqualBT(testnum, testerr, btvec8, btvec9);
      btvec8 = v1;
      EqualBT(testnum, testerr, btvec8, btvec9);
      btvec8 = std::move(btvec9);
      EqualBT(testnum, testerr, btvec8, btvec9); //! Perché nel move assigment io faccio lo swap dei dati, quindi i due oggetti sono uguali

      lasd::BinaryTreeVec<int> btvec10 (btvec8);
      EqualBT(testnum, testerr, btvec8, btvec10);
      btvec8 = std::move(btvec10);
      EqualBT(testnum, testerr, btvec8, btvec10);


      //todo inserire altri test se ho tempo e voglia 

      

    } catch (...) {
      numTestexecuted++; numError++;
      cout << endl << "Unmanaged error! " << endl;
    }
    
    
  }
  
  void binarySearchTreeLinkedTest(){
    //todo Fare ora!

    lasd::BST<int> bst;
    unsigned int testnum = 0;
    unsigned int testerr = 0;
    Empty(testnum, testerr, bst, true);
    Size(testnum, testerr, bst, true, 0);
    Min(testnum, testerr, bst, false, 0);
    Max(testnum, testerr, bst, false, 0);
    for (int i = 0; i < 16; i++) {
      bst.Insert(i + 1);
    }
    for (int i = 0; i < 16; i++) {
      Exists(testnum, testerr, bst, true, i + 1);
    }
    Exists(testnum, testerr, bst, false, 0);
    Exists(testnum, testerr, bst, false, 17);
    Min(testnum, testerr, bst, true, 1);
    Max(testnum, testerr, bst, true, 16);
    Size(testnum, testerr, bst, true, 16);
    Fold(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    FoldPreOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    FoldInOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    FoldPostOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    FoldBreadth(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    Traverse(testnum, testerr, bst, true, &TraversePrint<int>);
    TraversePreOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraverseInOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraversePostOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst, true, &TraversePrint<int>);
    for (int i = 0; i < 16; i++) {
      bst.Remove(i + 1);
    }
    Empty(testnum, testerr, bst, true);
    Size(testnum, testerr, bst, true, 0);
    Min(testnum, testerr, bst, false, 0);
    Max(testnum, testerr, bst, false, 0);
    Fold(testnum, testerr, bst, true, &FoldAdd<int>, 0, 0);
    FoldPreOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 0);
    FoldInOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 0);
    FoldPostOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 0);
    FoldBreadth(testnum, testerr, bst, true, &FoldAdd<int>, 0, 0);
    Traverse(testnum, testerr, bst, true, &TraversePrint<int>);
    TraversePreOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraverseInOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraversePostOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst, true, &TraversePrint<int>);
    Exists(testnum, testerr, bst, false, 0);
    Exists(testnum, testerr, bst, false, 1);
    Exists(testnum, testerr, bst, false, 16);
    RemoveMin(testnum, testerr, bst, false);
    RemoveMax(testnum, testerr, bst, false);
    InsertC(testnum, testerr, bst, true, 1);
    InsertC(testnum, testerr, bst, true, 16);
    RemoveMin(testnum, testerr, bst, true);
    RemoveMax(testnum, testerr, bst, true);

    lasd::BST<int> bst2;
    MaxNRemove(testnum, testerr, bst2, false, 0);
    MinNRemove(testnum, testerr, bst2, false, 0);

    bst.Clear();
    Empty(testnum, testerr, bst, true);
    Size(testnum, testerr, bst, true, 0);
    Min(testnum, testerr, bst, false, 0);
    Max(testnum, testerr, bst, false, 0);
    for (int i = 0; i < 16; i++) {
      bst.Insert(i + 1);
    }
    for (int i = 0; i < 16; i++) {
      Exists(testnum, testerr, bst, true, i + 1);
    }
    Exists(testnum, testerr, bst, false, 0);
    Exists(testnum, testerr, bst, false, 17);
    Min(testnum, testerr, bst, true, 1);
    Max(testnum, testerr, bst, true, 16);
    Size(testnum, testerr, bst, true, 16);
    Fold(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    FoldPreOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    FoldInOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    FoldPostOrder(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    FoldBreadth(testnum, testerr, bst, true, &FoldAdd<int>, 0, 136);
    Traverse(testnum, testerr, bst, true, &TraversePrint<int>);
    TraversePreOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraverseInOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraversePostOrder(testnum, testerr, bst, true, &TraversePrint<int>);
    TraverseBreadth(testnum, testerr, bst, true, &TraversePrint<int>);
    for (int i = 0; i < 16; i++) {
      bst.Remove(i + 1);
    }

    lasd::BST<int> bst3;

    // Additional tests
    // Test inserting duplicate elements
    bst3.Insert(5);
    bst3.Insert(5);
    Exists(testnum, testerr, bst3, true, 5);
    Size(testnum, testerr, bst3, true, 1);

    // Test removing non-existent elements
    bst3.Remove(10);
    Exists(testnum, testerr, bst3, false, 10);
    Size(testnum, testerr, bst3, true, 1);

    // Test removing root element
    bst3.Remove(5);
    Exists(testnum, testerr, bst3, false, 5);
    Size(testnum, testerr, bst3, true, 0);

    // Test inserting elements in descending order
    for (int i = 16; i > 0; i--) {
      bst3.Insert(i);
    }
    for (int i = 1; i <= 16; i++) {
      Exists(testnum, testerr, bst3, true, i);
    }
    Size(testnum, testerr, bst3, true, 16);

    // Test removing elements in descending order
    for (int i = 16; i > 0; i--) {
      bst3.Remove(i);
    }
    for (int i = 1; i <= 16; i++) {
      Exists(testnum, testerr, bst3, false, i);
    }
    Size(testnum, testerr, bst3, true, 0);

    // Test inserting elements in random order
    std::vector<int> elements = {5, 2, 8, 1, 4, 7, 10, 3, 6, 9};
    for (const auto& element : elements) {
      bst3.Insert(element);
    }
    for (const auto& element : elements) {
      Exists(testnum, testerr, bst3, true, element);
    }
    Size(testnum, testerr, bst3, true, elements.size());

    // Test removing elements in random order
    for (const auto& element : elements) {
      bst3.Remove(element);
    }
    for (const auto& element : elements) {
      Exists(testnum, testerr, bst3, false, element);
    }
    Size(testnum, testerr, bst3, true, 0);

    // Test inserting elements in ascending order
    for (int i = 1; i <= 16; i++) {
      bst3.Insert(i);
    }
    for (int i = 1; i <= 16; i++) {
      Exists(testnum, testerr, bst3, true, i);
    }
    Size(testnum, testerr, bst3, true, 16);

    // Test removing elements in ascending order
    for (int i = 1; i <= 16; i++) {
      bst3.Remove(i);
    }
    for (int i = 1; i <= 16; i++) {
      Exists(testnum, testerr, bst3, false, i);
    }
    Size(testnum, testerr, bst3, true, 0);

    // Other tests:

    lasd::BST<int> bst5;
    bst5.Insert(5);
    bst5.Insert(3);
    bst5.Insert(8);
    HasLeftChild<int>(testnum, testerr, bst5.Root(), true);  
    HasRightChild<int>(testnum, testerr, bst5.Root(), true);
    HasLeftChild<int>(testnum, testerr, bst5.Root().LeftChild(), false);
    HasRightChild<int>(testnum, testerr, bst5.Root().RightChild(), false);
    bst5.Insert(2);
    HasLeftChild<int>(testnum, testerr, bst5.Root().LeftChild(), true);
    bst5.Insert(4);
    HasRightChild<int>(testnum, testerr, bst5.Root().LeftChild(), true);
    bst5.Insert(7);
    HasLeftChild<int>(testnum, testerr, bst5.Root().RightChild(), true);
    bst5.Insert(9);
    HasRightChild<int>(testnum, testerr, bst5.Root().RightChild(), true);
    Min(testnum, testerr, bst5, false, 12);
    Max(testnum, testerr, bst5, false, 4);
    Min(testnum, testerr, bst5, true, 2);
    Max(testnum, testerr, bst5, true, 9);
    RemoveMin(testnum, testerr, bst5, true);
    Exists(testnum, testerr, bst5, false, 2);
    RemoveMax(testnum, testerr, bst5, true);
    Exists(testnum, testerr, bst5, false, 9);
    RemoveMin(testnum, testerr, bst5, true);
    Exists(testnum, testerr, bst5, false, 3);
    RemoveMax(testnum, testerr, bst5, true);
    Exists(testnum, testerr, bst5, false, 8);
    RemoveMin(testnum, testerr, bst5, true);
    Exists(testnum, testerr, bst5, false, 4);
    RemoveMax(testnum, testerr, bst5, true);
    Exists(testnum, testerr, bst5, false, 7);
    bst5.Clear();
    bst.Insert(5);
    bst.Insert(3);
    Exists(testnum, testerr, bst, true, 3);
    Exists(testnum, testerr, bst, true, 5);
    Predecessor(testnum, testerr, bst, true, 5, 3);
    PredecessorNRemove(testnum, testerr, bst, true, 5, 3);
    Exists(testnum, testerr, bst, false, 3);
    Root(testnum, testerr, bst, true, 5);
    bst.Clear();
    bst.Insert(5);
    bst.Insert(3);
    bst.Insert(8);
    Successor(testnum, testerr, bst, true, 5, 8);
    SuccessorNRemove(testnum, testerr, bst, true, 5, 8);
    Exists(testnum, testerr, bst, false, 8);
    Root(testnum, testerr, bst, true, 5);
    Max(testnum, testerr, bst, true, 5);
  }