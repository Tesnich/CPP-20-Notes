#include <iostream>
#include "Circle.h"

int main(int argc, char **argv){

    //Polymorphism

    //Polymorphism is the practice of managing multiple derived objects through references
    //or pointers to their base forms. One big benefit is it allows us to create arrays 
    //to hold different derived types and call their individually implemented functionalities
    //through the same call!

    //Think of a base class called 'Shape' and several other classes derived from it called
    //'Circle' or 'Square'. If Shape implements a 'DrawShape()' method and the derived classes also
    //do so, we can store whatever derived class we want in a pointer to Shape and call that method!

    //Polymorphism can be achieved with both references & and pointers!
    
    //  HOWEVER! THIS IS NOT THE DEFAULT BEHAVIOR OF INHERITANCE!

    //Run the section below to see how traditional inheritance works with STATIC BINDING.
    //Shape is a parent of Oval, and Oval is a parent of the Circle class. Each has its own
    //custom DrawShape() method implemented.

    Shape shape{};
    Oval oval(5.0,10.0);
    Circle circle(7);

    Shape* ptrShape{&shape};
    ptrShape->DrawShape(); //The base class <Shape> has no drawable method.

    ptrShape = &oval;
    ptrShape->DrawShape(); //The base class <Shape> has no drawable method.

    ptrShape = &circle;
    ptrShape->DrawShape(); //The base class <Shape> has no drawable method.

    //as you can see, despite the fact that all the derived classes are storable in a ptr to Shape
    //by default, does not mean polymorphism works by default. All calls to DrawShape() are executed
    //on the base class using standard inheritance. This is called STATIC BINDING. The pointer type
    //is used by the compiler to resolve the call DrawShape() staticaly. 

    //The same goes for references...

    Shape& shapeRefShape{shape};
    Shape& shapeRefOval{oval};
    Shape& shapeRefCircle{circle};

    shapeRefShape.DrawShape(); //The base class <Shape> has no drawable method.
    shapeRefOval.DrawShape(); //The base class <Shape> has no drawable method.
    shapeRefCircle.DrawShape(); //The base class <Shape> has no drawable method.

    //  Same result as above. In static binding the reference (or pointer) type is used as
    //  the floor to determine what members are called. Because it is a 'Shape&' reference,
    //  when we initialize it with the Derived class 'Oval' we are basically creating a reference
    //  to the shape object that lives inside of that oval object. So ofcourse when we make a call
    //  to DrawShape(), it is going to find the Shape class' method first. (This is very similar
    //  to how copy constructors work with inheritance hierarchies. We provide the derieved object
    //  to the constructor of the base object and it strips away all aspects of the derived to call
    //  Base(Base)! )

    //  As a matter of fact, it is important to note that when managing a derived class in terms of its
    //  base, that you lose access to the derived members. The below call is illegal, the reference 
    //  only has perspective of the members defined in the Shape class.

    //  Illegal!
    //shapeRefCircle.CircleOnlyMethod(); 

    

    return 0;
}