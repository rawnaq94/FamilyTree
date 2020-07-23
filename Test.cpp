
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>
using namespace std;

using namespace family;

Tree *test_tree()
{
    Tree *T  = new Tree("Amnon"); // root
       CHECK_NOTHROW(T->addFather("Amnon", "Almog")); 
       CHECK_NOTHROW(T->addMother("Amnon", "Shani"));
       CHECK_NOTHROW(T->addFather("Almog", "Gal"));
       CHECK_NOTHROW(T->addMother("Almog", "Mitar"));
       CHECK_NOTHROW(T->addFather("Gal", "Adam"));
       CHECK_NOTHROW(T->addMother("Gal", "Mirav"));
       CHECK_NOTHROW(T->addFather("Adam", "Yaakov"));
       CHECK_NOTHROW(T->addFather("Mitar", "Yoni"));
       CHECK_NOTHROW(T->addFather("Shani", "Riza"));
       CHECK_NOTHROW(T->addFather("Mirav", "David"));
       CHECK_NOTHROW(T->addFather("Yoni", "Danial"));
       CHECK_NOTHROW(T->addMother("Yoni", "Miream"));
                return T
 }
 
 
 
 
 TEST_CASE("add father") 
 {
   Tree t("Noam");
      CHECK_NOTHROW(t.addFather("Noam", "Serg"));
      CHECK_NOTHROW(t.addFather("Serg", "Morag"));
      CHECK_NOTHROW(t.addFather("Morag", "Asaf"));
      CHECK_THROWS(t.addFather("Noam", "Serg"));   // error - he is have father
      CHECK_THROWS(t.addFather("Morag", "Amir"));  // error - he is have father
      CHECK_THROWS(t.addFather("Serg", "Ronza")); // error - he is have father
      CHECK(t.find("father") == "Serg");
      CHECK(t.find("grandfather") == "Morag");
      CHECK(t.find("great-grandfather") == "Asaf");
  }
  
  
  
  TEST_CASE("add mother")
  {
    Tree t("Orna");
      CHECK_NOTHROW(t.addMother("Orna", "Marina"));
      CHECK_NOTHROW(t.addMother("Marina", "Almoget"));
      CHECK_NOTHROW(t.addMother("Almoget", "Ronit"));
      CHECK_THROWS(t.addMother("Orna", "Orit")); // error - she is have mather
      CHECK_THROWS(t.addMother("Marina", "Orit")); // error - she is have mather
      CHECK_THROWS(t.addMother("Almoget", "Orit")); // error - she is have mather
      CHECK(t.find("mother") == "Marina"); 
      CHECK(t.find("grandmother") == "Almoget");
      CHECK(t.find("great-grandmother") == "Ronit");
   }
      
    

TEST_CASE("relation")
{
    Tree *T;
    CHECK_NOTHROW(T = test_tree());    
    CHECK(T->relation("Amnon") == "me");
    CHECK(T->relation("Yaakov") == "great-great-grandfather");
    CHECK(T->relation("Gal") == "grandfather");
    CHECK(T->relation("Adam") == "great-grandfather");
    CHECK(T->relation("Almog") == "father");
    CHECK(T->relation("Riza") == "grandfather");
    CHECK(T->relation("Mirav") == "great-grandmother");
    CHECK(T->relation("Mitar") == "grandmother");
    CHECK(T->relation("Yoni") == "great-grandfather");
    CHECK(T->relation("David") == "great-great-grandfather");
    CHECK(T->relation("Danial") == "great-great-grandfather");
    CHECK(T->relation("Shani") == "mother");
    CHECK(T->relation("Miream") == "great-great-grandmother"); 

    delete T;
}
    



TEST_CASE("find") 
{
    Tree *T;
    CHECK_NOTHROW(T = test_tree());   
    CHECK(T->find("me") == "Amnon"); 
    CHECK(T->find("father") == "Almog"); 
    CHECK(T->find("mother") == "Shani"); 
    CHECK(T->find("grandmother") == "Mitar");
    CHECK(T->find("great-grandmother") == "Mirav");
    CHECK(T->find("great-great-grandmother") == "Miream"); 
    string grandfather;
    CHECK_NOTHROW(grandfather = T->find("grandfather"));      // find grandfather
    CHECK((grandfather == "Gal" || grandfather == "Riza"));  //check grandfather
    string great_grandfather;
    CHECK_NOTHROW(great_grandfather = T->find("great-grandfather"));   // find great grandfather
    CHECK((great_grandfather == "Adam" || great_grandfather == "Yoni"));  //check great grandfather
    string great_great_grandfather;
    CHECK_NOTHROW(great_great_grandfather = T->find("great-great-grandfather")); // find great great grandfather
    CHECK((great_great_grandfather == "Terah" || great_great_grandfather == "Haran" || great_great_grandfather == "Nahor"));  // check great great grandfather
      
     delete T;
}



TEST_CASE("display")
{
    Tree *T;
    CHECK_NOTHROW(T = test_tree());
    CHECK_NOTHROW(T->display());  
     /*
        display family tree of Amnon: rhite >> father - left >> mother
                       Miream    Danial    David      Yaakov
                               Yoni   Mirav   Adam
                      Riza   Mitar       Gal    
                  shani        Almog
                         Amnon   
     */
        
      delete T; 
 }
   
   
  
 TEST_CASE("remove function")
 {
    Tree *T;
    CHECK_NOTHROW(T = test_tree());
    CHECK_THROWS(T->remove("Ronu")); // error - not found
    CHECK_THROWS(T->remove("Dani")); // error - not found
    CHECK_THROWS(T->remove("Amnon")); // The tree root must not be erased
    CHECK_NOTHROW(T->remove("Yoni"));
    CHECK_NOTHROW(T->remove("David));
    CHECK(T->relation("Yoni") == "unrelated"); // has been deleted
    CHECK(T->relation("David") == "unrelated"); // has been deleted
    CHECK_THROWS(T->remove("Yoni")); // already removed 
    CHECK_THROWS(T->remove("David")); // already removed
    
     delete T;
  }
    
  
  
  




    
     
    
    
    
    
    
  
  
      
      
      
   
   
   
   
   
   
   
   
   
   
   
   
 
 
       
