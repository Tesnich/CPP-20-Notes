#ifndef POINT_H
#define POINT_H

namespace Geometry{
    class Point {
        private :
            double x_{}, y_{};
            static const unsigned int PRINT_SPACING_{7};
            static bool constructorVisibility_;
        public :
            Point();
            Point(double x, double y);

            //general format of opperator overloading is 

            //  return type | "operator" | [operator character for overload] | parameters

            Point operator+ (const Point& pointB)const;
            //  ^
            //  |
            //  ----------------------------------
            //                                   |
            //the above line indicates that the Point class is having its '+' overloaded.
            //By starting this line with "Point" we are doing two things. Declaring that the +
            //for Point has special processing, and indicating that we are returning a new
            //object of that type. I don't believe there is a way to seperate those function in the
            //context of operator overloading. (ie. cant overload + to return an int for none int class)
            //For that you'd have to implement your own function.

            //We are not restricted to using an input parameter of the same type as the return type
            Point operator+ (double offset)const;
            //This is an additional operator overload to accept a double instead of another point...
            //What determines whether this or the above operator+ gets called is what the right hand
            //argument of Point +, is called. 
            //  Add a double and this one is called.
            //  Add another point, and the other is. 
            //This is simply how overloading works. Just think of '+' as a function and it makes sense.

            //subscript operator overloading, declared here and defined in .cpp
            double operator[] (unsigned int i) const;

            //non const subscript operator overload, returning reference to double
            double& operator[] (unsigned int i);

            void X(double x);
            double X() const;

            void Y(double y);
            double Y() const;

            void PrintData();

            static double CalculateDistance(Point* pointA, Point* pointB);

            static void ConstructorVisibility(bool setting);

            //non member function declared as friend for mem var access
            friend Point operator- (const Point& pointA, const Point& pointB);
            //things get complicated upon trying to add something not in the same
            //namespace as a friend function for a class
            //  The below doesnt want to compile any way I try it
            //friend Geometry::Point operator* (const Geometry::Point& pointA, const Geometry::Point& pointB);

    };

    //below is an opperator- overload, but as a NON CLASS MEMBER function

    //using inline so as to not have to define in .cpp (not required)
    inline Point operator- (const Point& pointA, const Point& pointB){
        //the below is how I would have firest set this up,
        //  return Point(pointA.X() - pointB.X(), pointA.Y() - pointB.Y());
        //however lecture took this approach to make this method a friend and access private
        //member variables directly (is this an advantage?)
        return Point(pointA.x_ - pointB.x_, pointA.y_ - pointB.y_);
    }

}

//failed experimentation with *, outside of Geometry namespace

// inline Geometry::Point operator* (const Geometry::Point& pointA, const Geometry::Point& pointB){
//     return Geometry::Point(pointA.x_ * pointB.x_, pointA.y_ * pointB.y_);
// }

#endif