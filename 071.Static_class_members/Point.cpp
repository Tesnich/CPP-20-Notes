#include "Point.h"
#include <iostream>
#include <cmath>
#include <algorithm>

//static memeber variables can't be initialized in headers, so we need to initialize them with scope operator in .cpp
//static typename not needed on definition
unsigned int Point::pointCount_{}; //values set here will be those used before any objects of class created
double Point::maxX_{};
double Point::maxY_{};
std::vector<Point*> Point::allPoints_{};

void Point::CompareAndUpdateMaximums()
{
    maxX_ = (x_ > maxX_)? x_ : maxX_;
    maxY_ = (y_ > maxY_)? y_ : maxY_;
}

double Point::Distance(Point* B) const
{
    return std::sqrt(std::pow(x_ - B->x(), 2) + std::pow(y_ - B->y(), 2));
}

Point::Point()
{
    std::cout << " >> Point() called <<" << std::endl;
    ++pointCount_; //tracks new point objects by incrementing static pointCount_ whenever this constructor is called
    //curate a list of all points
    allPoints_.push_back(this); //supply list with address of newly created Point object
}
Point::Point(double x, double y)
    : Point() //constructor delegation to above 
{
    x_ = x;
    y_ = y;
    CompareAndUpdateMaximums();
}

Point::~Point()
{
    std::cout << " >> ~Point() called <<" << std::endl;
    --pointCount_; //removes a point whenever the destructor is called
    //so I wrote CompareAndUpdateMaximums() to get max, but without being able to tie back to all instances
    //removing a point that is the maximum will not remove from max vals
    //better names for maxX_ and maxY_ would be maxXSeenSoFarButMayAlsoNotBeRelevantToActivePointObjectsAnymoreBeCareful_ ;P

    //remove current object's address from list of all Point object addresses
    allPoints_.erase(std::find(allPoints_.begin(), allPoints_.end(), this));
}
        
double Point::x()const{
    return x_;
}
void Point::x(double x){
    x_ = x;
    CompareAndUpdateMaximums();
}

double Point::y()const{
    return y_;
}
void Point::y(double y){
    y_ = y;
    CompareAndUpdateMaximums();
}

void Point::DisplayMetaData() const
{
    std::cout << "---------------------------" << std::endl;
    std::cout << "Total Point Instances : " << pointCount_ << std::endl;
    std::cout << "Max X among Point Objects : " << maxX_ << std::endl;
    std::cout << "Max Y among Point Objects : " << maxY_ << std::endl;
    std::cout << "Distance to other Points... " << std::endl;

    for(auto point : allPoints_){
        if (point != this) //dont compare to self
            std::cout << "(" << point->x() <<","<< point->y() << ") : " << Distance(point) << std::endl;
    }

    std::cout << "---------------------------" << std::endl;
}

//static is not needed on definition
void Point::DisplayMetaData(const Point& point){
    point.DisplayMetaData();
    std::cout << "Static member functions can call on static variables without scope opperatior because of they have class scope : " << PI2_ << std::endl << std::endl;
}