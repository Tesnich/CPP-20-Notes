#ifndef BASE_H
#define BASE_H

class Base
{
    private:
        inline static int privateStaticInt_{1};
    protected:
        inline static int protectedStaticInt_{2};
    public:
        //illegal! Static members cannot be virtual!
        //virtual inline static int publicStaticInt_{3};
        inline static int publicStaticInt_{3};
        Base() = default;
};


#endif