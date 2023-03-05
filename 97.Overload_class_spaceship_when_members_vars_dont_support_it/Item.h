#ifndef ITEM_H
#define ITEM_H

class Integer{
    private :
        int value_{};
    public :
        Integer() = default;
        Integer(int value)
            :value_{value} {}

        int Value() { return value_; }
        void Value(int value) { value_ = value; }

        //operator overloads
        
        bool operator<(const Integer& integerB){
            return value_ < integerB.value_;
        }

        bool operator==(const Integer& integerB){
            return value_ == integerB.value_;
        }
};

class Item{
    private :
        int a_{}, b_{}, c_{};
        Integer d_{}; //integer here is the custom class above. It holds an int which supports <=> strong_ordering
                   //but we havent overloaded <=> for the class so it can't be used
    public :
        Item() = default;
        Item(int a, int b, int c)
            :a_{a}, b_{b}, c_{c} {}

        //instead of auto, return type can be specified by name ie... 'std::strong_ordering, weak_, & partial_'
        //auto operator<=> (const Item& itemB) const = default;
        std::partial_ordering operator<=> (const Item& itemB) const = default;

        //How does <=> implement its functionality by default?
        // my guess is a default overload of <=> for the Item class would be implemented as something like...
        //
        //  auto operator<=> (const Item& itemB) const {
        //      if ((a_ <=> itemB.a_) != 0){
        //          return a_ <=> itemB.a_;
        //      } else if ((b_ <=> itemB.b_) != 0){
        //          return b_ <=> itemB.b_;
        //      } else if ((c_ <=> itemB.c_) != 0){
        //          return c_ <=> itemB.c_;
        //      }....

        //   Looked it up, and I was close. Its akin to the below suedo code...

        //      for (auto memberVar_ : memberVars_){
        //          if (auto cmp = static_cast<R>(memberVar_ <=> itemB.memberVar); cmp != 0)
        //              return cmp;
        //          return static_cast<R>(strong_ordering::equal);
        //      }
        //
        //  where R is the return type. Anyways...
        //
        //The question in this case is how does default work with the d_ here, which is a
        //class that currently has no overload for <=>
        //
        //  'd_ <=> itemB.d_' wont compile!!!
        //

        //The compiler will atempt to derive a <=> from d_'s class' already implemented overloads,
        //but if it is unable, then our default <=> overload will fail compilation and we will have to implement
        //a custom version
};

#endif