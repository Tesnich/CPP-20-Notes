#ifndef POINT_H
#define POINT_H
#include <memory>
#include <iostream>

namespace Geometry {
    class Point {
        friend std::ostream& operator<<(std::ostream& os, const Point& point);
        private :
            std::unique_ptr<double> x_{}, y_{};
        public :
            Point()
                :Point(0.0,0.0) {}
            Point(double x, double y)
                :x_{std::make_unique<double>(x)}, y_{std::make_unique<double>(y)} {}

            //  with an assignment overload the object you are left with should be a reference to the
            //  original context of the object that is being assigned. Subsequent += on top of the result
            //  of an = operation should effect the object itself, not a copy. ie...
            //  
            //        objectB = objectA += objectC;
            //  
            //  after the firest expression resolves += objectC will be used on the original objectB
            //  so objectB will be equal to whatever A and B together were.
            //  if a reference to the first object is not returned then += objectC would be used on
            //  a copy and the work done there would be dumped into the void.

            Point& operator=(const Point& pointB){
                //    //  these are smart pointers, but in this case we need to take care of deleting 
                //    //  what they hold. They only automatically free their heap memory when they die.
                //    //  Because we are assigning new addresses we need to clear that memory as to not
                //    //  cause a memory leak.
                //    x_.reset();
                //    y_.reset(); //reminder : member function reset clears heap memory and sets unique_ptr to nullptr
                //
                //    x_ = std::make_unique<double>(*pointB.x_);
                //    y_ = std::make_unique<double>(*pointB.y_);
                //    return *this;

                //  SOOOOOOO, I must have been drinking the silly juice above. 
                //  If I was writing a constructor I'd need to allocate memory, and that is where my mind jumped.
                //  The above would work, but there is really no need to reset() the memory. 
                //  We simply need to assign new values to the doubles our unique pointers point to.

                *x_ = *pointB.x_;
                *y_ = *pointB.y_;

                return *this;

                //  IMPORTANT NOTE!!! If any memory is cleared in an assignment overload (like my commented stuff above)
                //                    YOU MUST CHECK THAT this IS NOT THE SAME OBJECT AS THE INPUT PARAMETER
                //                    If they are, you need to skipp all mem clearing and just return *this. Otherwise
                //                    you will clear memory, then use that cleared memory to initialize heap memory.
                //                    Obviously not good!

            }
    };

    inline std::ostream& operator<<(std::ostream& os, const Point& point){
        os << "(" <<point.x_ << " " << *point.x_ << "," <<point.y_ << " " << *point.y_ << ")";
        return os;
    }
}

#endif