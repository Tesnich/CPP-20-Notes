#ifndef NUMBER_H
#define NUMBER_H

class Number{
    private :
        int intVal_{};
    public :
        Number() = delete;
        Number(int intVal)
            :intVal_{intVal} {}

        //custom conversion overloads

        //format is as follows
        //operator double() const;
        explicit operator double() const;
    //  ^        ^        ^        ^
    //  |        |        |        ` Labeled const so that the double conversion can be retrieved from both const and non const Number instances
    //  |        |        |
    //  |        |        The type to convert to follows 'operator' and includes a pair of parenthesis
    //  |        |
    //  |        Like all other overloads, the function is declared with the operator keyword
    //  |
    //  No return type for these overloads, starting statement with 'explicit' keyword means
    //  that the user has to explicitly call for this conversion. It will not occur automatically
    //  in the wild without user intent.

    //Note though that writing these conversion opens the door to some ambiguity. Sat we have another
    //class, NumberPro. Imagine in NumberPro we write a constructor that takes in a Number object. That
    //said, what would be to happen if we also wrote a conversion overload in the original Number to
    //create a NumberPro? Which would be called, the constructor for Pro or the conversion for number?

    //These situations need to be taken into account when designing custom conversions.
};

#endif