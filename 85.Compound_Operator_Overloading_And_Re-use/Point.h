#ifndef POINT_H
#define POINT_H

#include <iostream>

namespace Geometry {
    class Point {
        friend std::ostream& operator<< (std::ostream& os, const Point& point);
        private :
            double x_{}, y_{};
        public :
            Point();
            Point(double x, double y);

            //I am fairly confused why the overloads work below. I wrote the definition
            //for these in such a way that they access the private members of pointB...

            //Could it be that by default arithmetic opperators have friend access to any
            //instance of the class?

            //implementing below to test...
            void DisplayInputParameterPrivateVars (const Point& pointB){
                std::cout<< "pointB data : (" << pointB.x_ <<"," <<pointB.y_ <<")" <<std::endl;
            } //what the what, why is this working???

            //ok, so for the future me... instances of the same class have complete access to one anothers
            //private members! Thats wild. How did that not come up before now?

            //  https://www.quora.com/Why-are-objects-able-to-access-private-members-of-other-objects-of-the-same-class
    
            Point& operator+= (const Point& pointB);
            Point operator+ (const Point& pointB) const;

            //In implementing the above I had a little trouble conceptualizing the return type
            
            //I think the consensus is that when doing normal arithmetic (ie +, -, /, =...)
            //It is expected that a copy is returned. So given the below ints...
            //      int c{a + b};
            //What is happening is that a + b as an expression returns a new int made from the internals
            //of a and b, 'tempC', which is used to initialize c here.
            //Its just that optimization by the compiler typically makes tempC and c one in the same object.
            //With the statement += however, the return type is a reference? I am not sure why...
            //perhaps to chain += statements?
            //      a += b += d;
            //In doing the above a is the target of both += b and +=d if executed from left to right.
            //Knowing this behavior... I have no idea what this gets me in terms of practical application.
    };

    inline std::ostream& operator<< (std::ostream& os, const Point& point){
        os << "Point (" << point.x_ << "," << point.y_ << ")";
        return os;
    }
}

#endif