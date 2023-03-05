#ifndef SQUARE_H
#define SQUARE_H

class Square {
    private :
        double length_{1};

    public  :
    Square() = default;
    Square(double length);
    
    double ComputeSurfaceArea();
};

class ExplicitSquare {
    private :
        double length_{1};

    public  :
    ExplicitSquare() = default;
    //     This keyword in the header file prevents implicit conversion to class using the constructor
    //     |
    //     V
    explicit ExplicitSquare(double length);
    
    double ComputeSurfaceArea();
};

#endif