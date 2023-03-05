#include <iostream>


int main(int argc, char **argv){

    //Inheriting base constructors

    //Base constructors are not inherited by default. To inherit a constructor
    //you add 'using Base::Base;' to the Derived class. 

    //Doing this will add ALL Base class constructors to your Derived class. 
    //If the Derived class is called with conditions that match these constructors,
    //the Derived class will be created but might not have its members initialized,
    //but the Base object baked into the Derived class will have its contructor called.

    //This isn't ideal as usually the plan is to add functionality to an already existing class
    //when one inherits from it.

    //Additionally, doing this can make it difficult for people to read your code at a glance,
    //mistaking whose constructor is being called. You also run the risk of potentially missing
    //the initalization of important derived members if they aren't in-class initialized (ie. 'int var_{}' vs 'int var_;').

    //Still, you are more than welcome to try if it fits in a unique situation.

    return 0;
}