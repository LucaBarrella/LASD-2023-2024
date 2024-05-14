
// #include "..."
#include <iostream>

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

#include "../zmytest/test.hpp"

using namespace lasd;
using namespace std;

/* ************************************************************************** */

void mytest() {
  
  //TEST FUNZIONI/COMBINAZIONI NON TESTATE DAL PROF

  myDictionary(); //! Errore ma è un errore di esecuzione, non di compilazione che non permette di arrivare alla fine del test.
  // myLinear();
  // myMappable(); //! Errori ma compila correttamente ed arriva alla fine del test.
  // myTraversable();

  //TEST CASI PARTICOLARI

  // mySortableVector();
  myList();
}

void myDictionary() {
  uint mytestnum = 0;
  uint mytesterr = 0;

  List<int> lst1;

  InsertC(mytestnum, mytesterr, lst1, true, 1);
  InsertC(mytestnum, mytesterr, lst1, true, 2);
  InsertC(mytestnum, mytesterr, lst1, false, 1);

  InsertM(mytestnum, mytesterr, lst1, true, 3);
  InsertM(mytestnum, mytesterr, lst1, true, 4);
  InsertM(mytestnum, mytesterr, lst1, false, 3);

  Remove(mytestnum, mytesterr, lst1, false, 5);
  Remove(mytestnum, mytesterr, lst1, true, 4);
  Remove(mytestnum, mytesterr, lst1, true, 2);
  Remove(mytestnum, mytesterr, lst1, true, 1);
  //lst1 contiene 3

  Vector<int> toinsert(3);
  SetAt(mytestnum, mytesterr, toinsert, true, 0, 1);
  SetAt(mytestnum, mytesterr, toinsert, true, 1, 2);
  SetAt(mytestnum, mytesterr, toinsert, true, 2, 3);
  //FIXME SI PIANTA QUI, STO STRONZO:

  InsertAllC(mytestnum, mytesterr, lst1, false, toinsert);
  //lst1 contiene 1 2 3

  SetAt(mytestnum, mytesterr, toinsert, true, 0, 4);
  SetAt(mytestnum, mytesterr, toinsert, true, 1, 5);
  SetAt(mytestnum, mytesterr, toinsert, true, 2, 6);
  InsertAllC(mytestnum, mytesterr, lst1, true, toinsert);
  
  Vector<int> toinsert2 = toinsert;
  Vector<int> toinsert3 = toinsert;
  SetAt(mytestnum, mytesterr, toinsert2, true, 2, 3);
  lst1.Clear();
  InsertAllM(mytestnum, mytesterr, lst1, true, move(toinsert));
  InsertAllM(mytestnum, mytesterr, lst1, false, move(toinsert2));
  //lst1 contiene 4 5 6 3
  
  std::cout << "SI PIANTA QUI, STO STRONZO! 2" << std::endl;
  Size(mytestnum, mytesterr, lst1, true, 4);
  RemoveAll(mytestnum, mytesterr, lst1, true, toinsert3);
  SetAt(mytestnum, mytesterr, toinsert3, true, 2, 3);
  RemoveAll(mytestnum, mytesterr, lst1, false, toinsert3);
  Empty(mytestnum, mytesterr, lst1, true);

  InsertSomeC(mytestnum, mytesterr, lst1, true, toinsert3);
  InsertSomeC(mytestnum, mytesterr, lst1, false, toinsert3);
  Vector<int> toinsert4(2);
  SetAt(mytestnum, mytesterr, toinsert4, true, 0, 1);
  SetAt(mytestnum, mytesterr, toinsert4, true, 1, 2);

  std::cout << "SI PIANTA QUI, STO STRONZO! 3" << std::endl;
  RemoveSome(mytestnum, mytesterr, lst1, false, toinsert4);
  SetAt(mytestnum, mytesterr, toinsert4, true, 0, 5);
  RemoveSome(mytestnum, mytesterr, lst1, true, toinsert4);
  //lst1 contiene 4 3

  InsertSomeM(mytestnum, mytesterr, lst1, true, move(toinsert3));
  SetAt(mytestnum, mytesterr, toinsert4, true, 1, 4);
  InsertSomeM(mytestnum, mytesterr, lst1, false, move(toinsert4));
  Size(mytestnum, mytesterr, lst1, true, 3);
  
  cout << endl << "End of functions inherited from Dictionary in List Test! (Errors/Tests: " << mytesterr << "/" << mytestnum << ")" << endl << endl;
}

void myLinear() {
  uint mytestnum = 0;
  uint mytesterr = 0;
  
  Vector<int> vec;
  List<int> lst;

  EqualLinear(mytestnum, mytesterr, vec, lst, true);
  NonEqualLinear(mytestnum, mytesterr, vec, lst, false);
  EqualLinear(mytestnum, mytesterr, lst, vec, true);
  NonEqualLinear(mytestnum, mytesterr, lst, vec, false);

  Vector<int> vec2 = vec;
  List<int> lst2 = lst;
  EqualLinear(mytestnum, mytesterr, vec, vec2, true);
  EqualLinear(mytestnum, mytesterr, lst, lst2, true);

  vec.Resize(3);
  SetAt(mytestnum, mytesterr, vec, true, 0, 1);
  SetAt(mytestnum, mytesterr, vec, true, 1, 2);
  SetAt(mytestnum, mytesterr, vec, true, 2, 3);
  InsertAtBack(mytestnum, mytesterr, lst, true, 1);
  InsertAtBack(mytestnum, mytesterr, lst, true, 2);
  EqualLinear(mytestnum, mytesterr, vec, lst, false);

  InsertAtBack(mytestnum, mytesterr, lst, true, 3);
  EqualLinear(mytestnum, mytesterr, vec, lst, true);
  InsertAtBack(mytestnum, mytesterr, lst, true, 3);
  vec.Resize(4);
  EqualLinear(mytestnum, mytesterr, vec, lst, false);

  vec.Clear();
  SetAt(mytestnum, mytesterr, vec, false, 0, 1);
  SetFront(mytestnum, mytesterr, vec, false, 0);
  GetFront(mytestnum, mytesterr, vec, false, 0);

  lst.Clear();
  GetFront(mytestnum, mytesterr, lst, false, 0);
  SetFront(mytestnum, mytesterr, lst, false, 0);
  InsertAtFront(mytestnum, mytesterr, lst, true, 0);
  GetFront(mytestnum, mytesterr, lst, true, 0);

  cout << endl << "End of functions from Linear Test! (Errors/Tests: " << mytesterr << "/" << mytestnum << ")" << endl << endl;
}

void myMappable() {
  
  uint mytestnum = 0;
  uint mytesterr = 0;
  
  Vector<int> vec;
  List<int> lst;

  MapPreOrder(mytestnum, mytesterr, vec, true, &MapIncrement<int>);
  MapPreOrder(mytestnum, mytesterr, lst, true, &MapIncrement<int>);
  MapPostOrder(mytestnum, mytesterr, vec, true, &MapIncrement<int>);
  MapPostOrder(mytestnum, mytesterr, lst, true, &MapIncrement<int>);

  vec.Resize(3);
  SetAt(mytestnum, mytesterr, vec, true, 0, 1);
  SetAt(mytestnum, mytesterr, vec, true, 1, 2);
  SetAt(mytestnum, mytesterr, vec, true, 2, 3);
  InsertAtBack(mytestnum, mytesterr, lst, true, 1);
  InsertAtBack(mytestnum, mytesterr, lst, true, 2);
  InsertAtBack(mytestnum, mytesterr, lst, true, 3);

  MapPreOrder(mytestnum, mytesterr, vec, true, &MapIncrement<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  MapPreOrder(mytestnum, mytesterr, vec, true, &MapDecrement<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  Exists(mytestnum, mytesterr, vec, false, 4);

  MapPreOrder(mytestnum, mytesterr, vec, true, &MapDouble<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  MapPreOrder(mytestnum, mytesterr, vec, true, &MapHalf<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  MapPreOrder(mytestnum, mytesterr, vec, true, &MapInvert<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);

  MapPreOrder(mytestnum, mytesterr, lst, true, &MapIncrement<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  MapPreOrder(mytestnum, mytesterr, lst, true, &MapDecrement<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  Exists(mytestnum, mytesterr, lst, false, 4);

  MapPreOrder(mytestnum, mytesterr, lst, true, &MapDouble<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  MapPreOrder(mytestnum, mytesterr, lst, true, &MapHalf<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  
  EqualLinear(mytestnum, mytesterr, vec, lst, false);
  MapPreOrder(mytestnum, mytesterr, lst, true, &MapInvert<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  EqualLinear(mytestnum, mytesterr, vec, lst, true);

  MapPostOrder(mytestnum, mytesterr, vec, true, &MapDecrement<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  MapPostOrder(mytestnum, mytesterr, vec, true, &MapIncrement<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  Exists(mytestnum, mytesterr, vec, false, -4);

  MapPostOrder(mytestnum, mytesterr, vec, true, &MapDouble<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  MapPostOrder(mytestnum, mytesterr, vec, true, &MapHalf<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  MapPostOrder(mytestnum, mytesterr, vec, true, &MapInvert<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);

  MapPostOrder(mytestnum, mytesterr, lst, true, &MapDecrement<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  MapPostOrder(mytestnum, mytesterr, lst, true, &MapIncrement<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  Exists(mytestnum, mytesterr, lst, false, -4);

  MapPostOrder(mytestnum, mytesterr, lst, true, &MapDouble<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  MapPostOrder(mytestnum, mytesterr, lst, true, &MapHalf<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  
  EqualLinear(mytestnum, mytesterr, vec, lst, false);
  MapPostOrder(mytestnum, mytesterr, lst, true, &MapInvert<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  EqualLinear(mytestnum, mytesterr, vec, lst, true);
  
  MapPreOrder(mytestnum, mytesterr, lst, true, &MapParityInvert<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  MapPostOrder(mytestnum, mytesterr, lst, true, &MapParityInvert<int>);
  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  
  MapPreOrder(mytestnum, mytesterr, vec, true, &MapParityInvert<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  MapPostOrder(mytestnum, mytesterr, vec, true, &MapParityInvert<int>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);

  Vector<string> vec2(2);
  List<string> lst2;
  SetAt(mytestnum, mytesterr, vec2, true, 0, string("A"));
  SetAt(mytestnum, mytesterr, vec2, true, 1, string(""));
  InsertAtBack(mytestnum, mytesterr, lst2, true, string(""));
  InsertAtBack(mytestnum, mytesterr, lst2, true, string("A"));
  
  MapPostOrder(mytestnum, mytesterr, vec2, true, [](string & str) { MapStringNonEmptyAppend(str, string("!")); });
  TraversePreOrder(mytestnum, mytesterr, vec2, true, &TraversePrint<string>);
  MapPostOrder(mytestnum, mytesterr, lst2, true, [](string & str) { MapStringNonEmptyAppend(str, string("!")); });
  TraversePreOrder(mytestnum, mytesterr, lst2, true, &TraversePrint<string>);

  cout << endl << "End of functions from Mappable Test! (Errors/Tests: " << mytesterr << "/" << mytestnum << ")" << endl << endl;
}

void myTraversable() {
  uint mytestnum = 0;
  uint mytesterr = 0;
  
  Vector<int> vec(3);
  List<int> lst;
  
  SetAt(mytestnum, mytesterr, vec, true, 0, 1);
  SetAt(mytestnum, mytesterr, vec, true, 1, 2);
  SetAt(mytestnum, mytesterr, vec, true, 2, 3);
  InsertAtBack(mytestnum, mytesterr, lst, true, 1);
  InsertAtBack(mytestnum, mytesterr, lst, true, 2);

  TraversePostOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  TraversePostOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  
  FoldPreOrder(mytestnum, mytesterr, vec, true, &FoldParity, 0, 0);
  FoldPreOrder(mytestnum, mytesterr, lst, true, &FoldParity, 0, 1);
  FoldPostOrder(mytestnum, mytesterr, vec, true, &FoldParity, 0, 0);
  FoldPostOrder(mytestnum, mytesterr, lst, true, &FoldParity, 0, 1);
  TraversePostOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  TraversePostOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);

  vec.Clear();
  lst.Clear();
  FoldPostOrder(mytestnum, mytesterr, vec, true, &FoldParity, 0, 0);
  FoldPostOrder(mytestnum, mytesterr, lst, true, &FoldParity, 0, 0);
  TraversePostOrder(mytestnum, mytesterr, vec, true, &TraversePrint<int>);
  TraversePostOrder(mytestnum, mytesterr, lst, true, &TraversePrint<int>);
  
  cout << endl << "End of functions from Traversable Test! (Errors/Tests: " << mytesterr << "/" << mytestnum << ")" << endl << endl;
}

void mySortableVector() {

  uint mytestnum = 0;
  uint mytesterr = 0;

  SortableVector<int> vec;
  Empty(mytestnum, mytesterr, vec, true);
  Exists(mytestnum, mytesterr, vec, false, 0);
  SetFront(mytestnum, mytesterr, vec, false, 0);
  GetFront(mytestnum, mytesterr, vec, false, 0);
  SetBack(mytestnum, mytesterr, vec, false, 0);
  GetBack(mytestnum, mytesterr, vec, false, 0);
  vec.Sort();

  List<int> lst;
  for (ulong i = 0; i < 10; i++) {
    lst.InsertAtBack(i);
  }
  vec.Resize(10);
  for (ulong i = 0; i < vec.Size(); i++) {
    vec[i] = i;
  }

  SortableVector<int> sortablevec = SortableVector<int>(lst);
  SortableVector<int> othersortable = SortableVector<int>(std::move(vec));
  EqualVector(mytestnum, mytesterr, sortablevec, othersortable, true);
  
  List<int> otherlst = List<int>(sortablevec);
  EqualLinear(mytestnum, mytesterr, sortablevec, otherlst, true);

  cout << endl << "End of functions from SortableVector Test! (Errors/Tests: " << mytesterr << "/" << mytestnum << ")" << endl << endl;
}

void myList() {

  uint mytestnum = 0;
  uint mytesterr = 0;

  List<int> lst;
  Remove(mytestnum, mytesterr, lst, false, 0);
  Remove(mytestnum, mytesterr, lst, false, 0);
  Empty(mytestnum, mytesterr, lst, true);
  Size(mytestnum, mytesterr, lst, true, 0);

  List<int> coplst = lst;
  EqualLinear(mytestnum, mytesterr, lst, coplst, true);
  EqualList(mytestnum, mytesterr, lst, coplst, true);

  InsertAtBack(mytestnum, mytesterr, lst, true, 1);
  coplst = lst;
  EqualLinear(mytestnum, mytesterr, lst, coplst, true);
  EqualList(mytestnum, mytesterr, lst, coplst, true);

  List<int> movlst = move(lst);
  EqualLinear(mytestnum, mytesterr, lst, movlst, false);
  EqualList(mytestnum, mytesterr, lst, movlst, false);

  List<int> copconstrlst(coplst);
  EqualLinear(mytestnum, mytesterr, coplst, copconstrlst, true);
  EqualList(mytestnum, mytesterr, coplst, copconstrlst, true);

  List<int> movconstrlst(std::move(copconstrlst));
  EqualLinear(mytestnum, mytesterr, movconstrlst, copconstrlst, false);
  EqualList(mytestnum, mytesterr, movconstrlst, copconstrlst, false);
  Size(mytestnum, mytesterr, copconstrlst, true, 0);
  EqualLinear(mytestnum, mytesterr, movconstrlst, coplst, true);
  EqualList(mytestnum, mytesterr, movconstrlst, coplst, true);

  cout << endl << "End of functions from List Test! (Errors/Tests: " << mytesterr << "/" << mytestnum << ")" << endl << endl;
}

void myStackVec() {

  uint mytestnum = 0;
  uint mytesterr = 0;
  
  StackVec<string> stack;
  string prima = "prima", seconda = "seconda", terza = "terza";
  Size(mytestnum, mytesterr, stack, true, 0);
  Empty(mytestnum, mytesterr, stack, true);

  PushM(mytestnum, mytesterr, stack, prima);
  Size(mytestnum, mytesterr, stack, true, 1);
  Empty(mytestnum, mytesterr, stack, false);
  PushC(mytestnum, mytesterr, stack, seconda);
  PushM(mytestnum, mytesterr, stack, terza);
  Size(mytestnum, mytesterr, stack, true, 3);
  Empty(mytestnum, mytesterr, stack, false);
  
  StackVec<string> copstack(stack);
  Vector<string> vec(stack.Size());
  List<string> lst = List<string>();
  StackLst<string> support = StackLst<string>();
  for (unsigned long i = 3; i > 0; --i)
  {
    vec[i-1] = stack.TopNPop();
    lst.InsertAtFront(vec[i-1]);
    support.Push(vec[i-1]);
  }

  TraversePreOrder(mytestnum, mytesterr, lst, true, &TraversePrint<string>);
  TraversePreOrder(mytestnum, mytesterr, vec, true, &TraversePrint<string>);

  for (unsigned long i = 0; i < 3; i++)
  {
    stack.Push(support.TopNPop());
  }

  StackVec<string> travvecconstrstack(vec);
  StackVec<string> travlstconstrstack(lst);
  StackVec<string> mapconstrstack(std::move(vec));

  StackVec<string> copstk;
  copstk = stack;
  
  stack.Pop();
  string second = stack.Top();
  TopNPop(mytestnum, mytesterr, stack, true, second);
  TopNPop(mytestnum, mytesterr, stack, true, prima);

  stack.Push(prima);
  stack.Push(seconda);
  stack.Push(terza);

  EqualStack(mytestnum, mytesterr, copstack, stack, true);
  EqualStack(mytestnum, mytesterr, travvecconstrstack, stack, true);
  EqualStack(mytestnum, mytesterr, travlstconstrstack, stack, true);
  EqualStack(mytestnum, mytesterr, mapconstrstack, stack, true);
  EqualStack(mytestnum, mytesterr, copstack, stack, true);

  StackVec<string> stk;
  Pop(mytestnum, mytesterr, stk, false);
  Size(mytestnum, mytesterr, stk, true, 0);
  PushC(mytestnum, mytesterr, stk, string("uno"));
  Size(mytestnum, mytesterr, stk, true, 1);
  TopNPop(mytestnum, mytesterr, stk, true, string("uno"));
  Size(mytestnum, mytesterr, stk, true, 0);

  cout << endl << "End of functions from StackVec Test! (Errors/Tests: " << mytesterr << "/" << mytestnum << ")" << endl << endl; 
}