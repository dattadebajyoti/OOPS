/*
    This is an implementation to showcase how to make a virtual constructor like behavior   
    to find out what objects need to be created at runtime
*/

#include <iostream>
using namespace std;

//Library starts
class Base
{
  public:
  //Function used to behave like virtual constructor
  static Base *Create(int id);
  Base()
  {}
  ~Base()
  {}
  
  //implement depends on the consumer of Base
  virtual void ShowAction() = 0;
};

class Derived1: public Base
{
    public:
    Derived1()
    {
        cout<<"Derived1 obj created"<<endl;
    }
    ~Derived1()
    {
        cout<<"Derived1 obj destroyed"<<endl;
    }
    void ShowAction()
    {
        cout<<"Action from Derived1"<<endl;
    }
};

class Derived2: public Base
{
    public:
    Derived2()
    {
        cout<<"Derived2 obj created"<<endl;
    }
    ~Derived2()
    {
        cout<<"Derived2 obj destroyed"<<endl;
    }
    void ShowAction()
    {
        cout<<"Action from Derived2"<<endl;
    }
};

//Decoupling the implementation to create an object by delagting the task to Create(), which evaluates it at runtime
Base *Base::Create(int id)
{
    if(id == 1)
    {
        return new Derived1;
    }
    else
    {
        return new Derived2;
    }
}

//Library ends


//The consumer of the library 
class User
{
    Base *pBase;
    public:
    User():pBase(nullptr)
    {
        int ip;
        cout<<"enter input id"<<endl;
        cin>>ip;
        pBase = Base::Create(ip);
    }
    ~User()
    {
        if(pBase)
        {
            delete pBase;
        }
        pBase = nullptr;
    }
    void Action()
    {
        pBase->ShowAction();
    }
};



int main() {
	User *user = new User();
	user->Action();
	return 0;
}
