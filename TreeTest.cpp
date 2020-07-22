/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using namespace std;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree; 
  ariel::Tree bigtree;	 
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

   .CHECK_OK    (bigtree.insert(12))
   .CHECK_OK    (bigtree.insert(5))
   .CHECK_OK    (bigtree.insert(14))
   .CHECK_EQUAL (bigtree.contains(12), true)
   .CHECK_OK    (bigtree.remove(12))
   .CHECK_EQUAL (bigtree.contains(12), false)
   .CHECK_OK    (bigtree.insert(22))
   .CHECK_OK    (bigtree.insert(2))
   .CHECK_OK    (bigtree.insert(15))
   .CHECK_OK    (bigtree.insert(20))
   .CHECK_OK    (bigtree.insert(6))
   .CHECK_OK    (bigtree.insert(1))
   .CHECK_OK    (bigtree.insert(4))
   .CHECK_OK    (bigtree.insert(40))
   .CHECK_OK    (bigtree.insert(11))
   .CHECK_OK    (bigtree.insert(8))
   .CHECK_OK    (bigtree.insert(7))
   .CHECK_OK    (bigtree.insert(60))
   .CHECK_OK    (bigtree.insert(33))
   .CHECK_OK    (bigtree.insert(25))
   .CHECK_OK    (bigtree.insert(18))
   .CHECK_OK    (bigtree.insert(0))
   .CHECK_THROWS(bigtree.insert(60))
   .CHECK_EQUAL (bigtree.left(1),0)
   .CHECK_EQUAL(bigtree.right(22),40)
   .CHECK_THROWS (bigtree.left(6))
   .CHECK_EQUAL (bigtree.left(8),7)
   .CHECK_EQUAL (bigtree.parent(40),22)
   .CHECK_EQUAL (bigtree.parent(11),6)
   .CHECK_EQUAL (bigtree.parent(25),33)
   .CHECK_OK    (bigtree.remove(15))
   .CHECK_OK    (bigtree.remove(11))
   .CHECK_EQUAL (bigtree.size(),16)	
   .CHECK_OK    (bigtree.remove(33))
   .CHECK_OK    (bigtree.remove(0))
   .CHECK_OK    (bigtree.remove(18))
   .CHECK_EQUAL (bigtree.size(),13)	
   .CHECK_EQUAL (bigtree.contains(20), true)
   .CHECK_EQUAL (bigtree.contains(2), true)
   .CHECK_EQUAL (bigtree.contains(11), false)
   .CHECK_EQUAL (bigtree.contains(33), false)
   .CHECK_EQUAL (bigtree.contains(8), true)
   


  .print();

  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
return 0;

}
