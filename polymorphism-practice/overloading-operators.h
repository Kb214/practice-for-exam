#pragma once
#include <iostream>

class Add{
private:
int val; 

public:
//constructor for v and giving it value of zero
Add(int v = 0);

                    //adding the left hand and right hand
friend Add operator+(const Add& lhs, const Add& rhs);

//on the right hand side you have your operator and on the left you have what you want
friend std::ostream& operator<<(std::ostream& os, const Add& a);


};
