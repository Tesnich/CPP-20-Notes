#include "Square.h"
#include <cmath>
#include <iostream>
#include <iomanip>

//Note, when doing constructor declaration you may only call the next constructor. You CANNOT combine with mem var initialization.
//  The only place that variables should be initialized is at the last stop in the chain!!!

Square::Square(double side_param)
    : Square(side_param, "White", 3) //this constructor calls the one below with side param as well as default values "white" and 3
    {
        //Square(side_param, "White", 3);
        //  The above approach can't be manually written into the body of a constructor! This is not the same!
        //  Really what you are doing here is creating a square object for the scope of this call! It will not
        //  survive the end of this block nor set any of the parameters on the current Square object!

        //To chain constructors YOU MUST USE LIST INITIALIZATION
        std::cout << " >> First Constructor Called << " << std::endl;
    }
Square::Square(double side_param, std::string_view color_param, int shading_param)
    : Square(side_param, color_param, shading_param, 12) // this constructor passes all arguments above plus position default
                                                            // to the constructor below
    {
        std::cout << " >> Second Constructor Called << " << std::endl;
    }
Square::Square(double side_param, std::string_view color_param, int shading_param, int position_param)
    : side_(side_param), color_(color_param), shading_(shading_param), position_(position_param)
    {
        std::cout << " >> Third Constructor Called << " << std::endl;
    }
    //The above constructor is the end of the chain and uses the standard list initializer format to instantiate the member vars for the Square object

Square::~Square() {}

double Square::Surface() const {
    return pow(side_, 2);
}

void Square::PrintInfo() const {
    std::cout << std::setw(TABLE_SPACING_) << "Side : " << std::setw(TABLE_SPACING_) << side_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Area : " << std::setw(TABLE_SPACING_) << Surface() << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Color : " << std::setw(TABLE_SPACING_) << color_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Shading : " << std::setw(TABLE_SPACING_) << shading_ << std::endl;
    std::cout << std::setw(TABLE_SPACING_) << "Position : " << std::setw(TABLE_SPACING_) << position_ << std::endl <<std::endl;
}