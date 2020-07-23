#ifndef _FamilyTree_
#define _FamilyTree_

#include <iostream>
#include <string>


using namespace std;
namespace family
{
    enum Type{
        root_type, father_type, mother_type
    };

    class Tree
    {
        const string _name;
        const Type _type;
        Tree *_father, *_mother;

    
    Tree *findNode(const string &);
    public:
        Tree(string name, Type type = root_type): 
            _name(name), 
            _father(nullptr), 
            _mother(nullptr), 
            _type(type) { };
            
        Tree &addFather(const string &,const string &);   //add father of 'son'.
	      Tree &addMother(const string &,const string &);  // add mother of 'son'.
        string relation(const string &) const; // return relation - if not found return unrelated.
        void display(size_t tabs = 0) const; // presentation.
        string find(const string &) const; // the name of a person whith this relation. 
        bool remove(const string &); // delet parents.
      
      ~Tree()
      {
            if(_father != nullptr)
                delete _father;
            if(_mother != nullptr)
                delete _mother;
      };
    };
};

#endif
