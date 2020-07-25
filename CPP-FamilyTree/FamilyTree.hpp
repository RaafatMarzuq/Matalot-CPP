#include <string>
#include <string.h>

using namespace std;

namespace family
{
class Node
{
public:
    string name;
    Node *mom;
    Node *dad;
    string relation;
    
    Node(string n)
    {
        name = n;
        mom = nullptr;
        dad = nullptr;
    }
      ~Node(){
        if(mom != nullptr) delete mom;
        if(dad != nullptr) delete dad;
    }

};

class Tree
{
public:
    Node *root;

    Tree(string n)
    {
        root = new Node(n);
    }
  
    Tree &addFather(string, string);
    Tree &addMother(string, string);
    string relation(string);
    string find(string);
    void display();
    void remove(string);
    Node *search(Node *root, string name);
    string findDad(Node *root, string name,string *relation);
    string findMom(Node *root,string name, string *relation);
    string get_name(string r,Node * root);
    Node *leafDelete(struct Node* root);
    bool ifNodeExists( Node* node, string key); 
     
};
} // namespace family