#ifndef NESTED_H
#define NESTED_H

#include <iostream>

class Outer{
    private :
        int integerVal_{};
        double doubleVal_{};

    public :
        class Inner{
            private:
                double doubleVal_{};
            public:
                Inner() = default;
                ~Inner();
                Inner(double doubleVal);
                double doubleVal();
        };

        Outer() = default;
        ~Outer();
        Outer(int integerVal, double doubleVal);

        void DoSomething();
};

#endif