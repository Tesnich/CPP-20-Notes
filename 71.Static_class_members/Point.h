#ifndef POINT_H
#define POINT_H

#include <vector>

class Point{
    private :
        double x_{};
        double y_{};
        //static member variables can't be initialized in headers
        static unsigned int pointCount_; //   So '{}' or '()' can't be used here
        static double maxX_;             //   This may be because the value is initialized before any object has been created
        static double maxY_;             //   If you added an initializer value here, each instance created would be trying to re-initialize the static memeber
        //Instead static memeber functions MUST be initialized using the format in the .cpp

        //Got the idea of a point object capable of knowing where all other points are on the map
        static std::vector<Point*> allPoints_;

        void CompareAndUpdateMaximums();
        double Distance(Point* B) const;
    public :
        //if the static member variable is declared constant you can initialize it here without .cpp
        static const unsigned int publicStaticTest{12};
        //additionally it looks like you can circumvent having to seperate your declaration and definition of a
        //static member variable through the use of the keyword inline
        inline static double x2_{};
        //^^^^^Works absolutely fine because of... a reason.
        //     What I know about inline so far is that use of the keyword literaly rewrites a function
        //     at the spot it is being called from so the program doesnt have to fetch it from some spot in memory (focus on efficiency)
        //     So.....nope still dont get it. My best guess is that it forces the creation of a var to one spot? Somehow preventing re-definition errors?
        //     In any event, it works.

        //static const variables
        //so say we wanted to use a constant in our classes, normally writing something like the below
        const double PI_ {3.141592}; //only an example, you should use cmath instead for pi
        //result in that constant being created any time you create a class, which is wasteful!
        //instead we could do this...
        //  v- inline can be before or after static, no difference
        inline static const double PI2_{3.141592}; //C++ 17 AND ABOVE!!
        //^^^^PI2_ is only ever initialized ONCE, but still usable by all instances of Point just like PI_
        //    This is an upside for memory if you find yourself creating a ton of points
        //    at the cost of having a single double of memory chewed up if you have no instances of the class running
        //    (because it is static and exists without the class objects)
        //    As long as you have at least one object of the class this is not a drain on resources, and >1 it saves resources

        //BEFORE C++ 17 you could only initialize static const INTs and ENUMS in the header
        //If not an int or enum you have to initialize it in the .cpp like we did above for the non-static x_.

        //WARNING!!!!
        //Initialization order of static member variables is not gauranteed between classes!
        //So where as we are able to initialize a constexpr with another constexpr for compilation...
        //We should AVOID initializing a static member variable with a static member var of another class because
        //  we have no idea if it will be ready to use! It could contain junk data,cause a compilation failure, or prevent the program from running.

        // WOULD BUILD BUT !! AVOID !!
        //inline static const double HALF_MAXIMUM_WEIGHT_{WEIGHTS::MAXIMUM_WEIGHT/2};
        // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

        Point();
        Point(double x, double y);
        ~Point();
        
        double x() const;
        void x(double x);

        double y() const;
        void y(double y);

        void DisplayMetaData() const;
        static void DisplayMetaData(const Point& point);
};

#endif