
#include "Nested.h"

Outer::~Outer(){}
Outer::Outer(int integerVal, double doubleVal)
    :integerVal_(integerVal), doubleVal_(doubleVal) {}

void Outer::DoSomething(){
    Inner inner(integerVal_ * doubleVal_);
    std::cout << "Created inner object with value : " << inner.doubleVal() << std::endl;
}

//When establishing the scope for a class within a class you need to use the outer class name as well
Outer::Inner::~Inner() {}

Outer::Inner::Inner(double doubleVal)
    :doubleVal_(doubleVal) {}

double Outer::Inner::doubleVal(){
    return doubleVal_;
}
