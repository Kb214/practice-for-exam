#include <iostream>
#include <memory>

int main(){
    //raw pointers

    /* you are allocating data to the heap with "new" keyword*/
    int* p = new int(5);

    /* you print the integer out by dereference it*/
    std::cout << "Raw pointer: " << *p << "\n";

    /*you always need to delete your pointer to clean it up
    so there won't be any memory leaks
        memory leaks - program loses address of allocated memory before returning it to OS
                        also eats up free memory and makes machine crash.*/
    delete p;
    p = nullptr;


    //smart pointers
    /* cleans themselves up, you have three pointers: */

        //unique - exlusive ownership
            /*CANNOT be copied*/

    std::unique_ptr<int> u = std::make_unique<int>(8);
    std::cout << "Smart Unique Pointer: " << *u << '\n';

    //can also do

    auto ptr{std::make_unique<int>(7)};
    std::cout << "Using another way to make a pointer: " << *ptr << '\n';


        //shared - shared ownership and ref-counted
    
    std::shared_ptr<int> s = std::make_shared<int>(9); //reference count 1
    std::cout << "Smart Shared Pointer: " << *s << '\n';

    //can also do

    auto ptr1{std::make_shared<int>(3)}; //reference count 2


        //weak - not ref-counted no ownership
    
    std::weak_ptr<int> w = s;
    /*cannot print it out because it doesn't store raw ptr internally.
     avoids giving access to any memory address so we cannot dereference it because it is an expire
     object.
     "weak pointer is an OBSERVER" */

    // std::cout << "Smart Weak Pointer: " << *w << "\n";
    std::cout << "Smart Weak Pointer cannot be printed because it's doesn't own anything, it is an OBSERVER.\n";

    if(auto locked = w.lock()){
        std::cout << "getting the weak pointer using lock:" << *locked << '\n';
    }


    //MOVE SEMANTICS - transferring resource instead of copying
        //changing l values to r values
            // l = named object can take address
            // r = Temporary value can be destroyed
        //std::move();
    //EX:
    std::unique_ptr<int> movedptr{std::move(u)};
    std::cout << "Moved Unique pointer: " << *movedptr << '\n';


    //DANGLING POINTERS
        //where you pointer to deleted memory
        //set point to null after deleting. like I did above with the raw pointer.

    

    return 0;

}