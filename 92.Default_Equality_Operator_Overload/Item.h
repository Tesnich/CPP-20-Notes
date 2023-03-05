#ifndef ITEM_H
#define ITEM_H

class Item {
    private:
        int a_{1}, b_{2}, c_{3};
    public:
        Item() = default;
        Item(int i)
            :Item(i,i,i) {}
        Item(int a, int b, int c)
            :a_{a}, b_{b}, c_{c} {}

        //equality, default : member wise comparison for equality (top level values, not deep comparison)
        bool operator==(const Item& itemB) const = default;
        //BONUS : Implementing a == overload in a C++ 20 will generate the != overload for you

        //Note, I was under the impression that there was some shallow comparison by default, but that
        //doesn't appear to be the case. If I remove the above line I cannot compare itemA and itemB in
        //main
};

#endif