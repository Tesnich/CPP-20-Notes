#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include <string_view>

class Square
{
    private :
        double side_;
        std::string color_;
        int shading_;
        double position_;
        unsigned int TABLE_SPACING_{15};

    public :
        //The below constructors are chained in their definitions, nothing new to see in this file.
        //  Although, nothing would stop you from moving list initializers here and combining both decl and definition I guess...
        explicit Square(double side_param);
        Square(double side_param, std::string_view color_param, int shading_param);
        Square(double side_param, std::string_view color_param, int shading_param, int position_param);
        ~Square();

        double Surface() const;
        void PrintInfo() const;
};

#endif