
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
void iteratorTest();
void binaryTreeLinkedTest();
void binaryTreeVectorTest();
void binarySearchTreeLinkedTest();

void mytest() {
  // ...
  srand(time(0));
  cout << "Hello, World!" << endl;

  iteratorTest();
  binaryTreeLinkedTest();
  binaryTreeVectorTest();
  binarySearchTreeLinkedTest();

  std::cout << "\n\n\nI'm happy to see ya!\n\n\n" << std::endl;

  if (numError == 0) {
    std::cout << "All tests passed!\n" << std::endl;
  } else {
    std::cout << "Some tests failed!\n" << std::endl;
  }
}

/* ************************************************************************** */

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
      btvec8 = std::move(btvec8);
      EqualBT(testnum, testerr, btvec8, btvec10);


      //todo inserire altri test se ho tempo e voglia 

      

    } catch (...) {
      numTestexecuted++; numError++;
      cout << endl << "Unmanaged error! " << endl;
    }
    
    
  }
  void binarySearchTreeLinkedTest(){
    //todo Fare ora!

  }
