#include <iostream>

int main(int argc, char **argv){

    //Lambda Functions ie... a mechanism to set up anonymous functions (functions without names)

    //  Lambda function signature
    //                              [capture list] (parameters) -> return type {
                                                //function body
    //                              };

    auto func = [](){    //writing a lambda function and assigning it to a variable
        std::cout << "Lambda Function Execution Through Variable!" << std::endl;
    };
    
    func(); // calling the lambda function in the variable

    [](){    //writing a lambda function and directly calling it
        std::cout << "Lambda Function Direct Execution!" << std::endl;
    }(); //() at the end execute the call

    auto funcDouble = [](double a, double b){ //lambda function with input arguments specified 
        std::cout << "Lambda a + b : " << (a + b) << std::endl;
    }; //could execute without assignment if this line was '}(12.1,5.7);'

    funcDouble(12.1,5.7); //running lambda with input arguments

    //lambda function expression
    auto result = [](int a, int b){ // by directly executing a lambda function that returns a value, 
        return (a+b);               // the returned value is assigned to the output (ie. result gets an int here instead of function)
    }(10,5);

    std::cout << "Result value : " << result << std::endl;

    //forcing return type with arrow -> symbol (no auto deduction from returned value)

    auto funcReturnType = [](int a, int b)->double {
        return (a+b); //because we have specified the return type to double the int result here is implicitly converted
    };

    std::cout << "lambda functReturnType result : " << funcReturnType(1,2) << std::endl;

    //lambda functions can be executed in any statement line just like any other function call
    std::cout << "Lambda executed in std::cout line : " << [](int a, int b) {
        return (a+b);
    }(2,7) << std::endl;


    //Capture lists....
    ///////////////////
    double a{10}, b{20};

    //capture by value

    //with normal functions, you are limited to accessing variables within function scope (ie new variables or those passed in as input arguments)
    auto func3 = [a,b](){ // with lambda, however, you can actually mark variables outside of scope to allow the lambda to access them!
        std::cout << "a + b : " << a + b << std::endl; 
        //downside though! In capture by value you cannot edit a copy like you can if the vars were passed by input argument
        //VVVVVV ILEGAL!!!!
        //++a;
    };

    func3(); //now the lambda function can work off of external stimuli without having to pass input arguments

    //                            -------------
    //TO NOTE: THE ABOVE IS STILL PASS BY VALUE, not pass by reference by default
    //                            -------------

    //capture by reference

    auto func4 = [&a](){ //&a here captures by reference so the a in main scope can be editied
        a+= 5;
    };

    std::cout << "Current value of a : " << a << std::endl;
    std::cout << "Using Lambda Capture by Reference " << std::endl;
    func4();
    std::cout << "Current value of a : " << a << std::endl;

    //capturing EVERYTHING living outside the context of the lambda function

    auto func5 = [=](){ //capture by value all context
        std::cout << "Using [=] lambda can see everything! Here is a : " << a << std::endl;
        //remember, in capture by value you do not have the ability to alter a copy
        //VVVVV ILLEGAL
        //++a;
    };

    func5();

    auto func6 = [&](){ //capture by reference
        std::cout << "Using [&] lambda can see AND EDIT everything! I am adding 10 to a!" << std::endl;
        a+= 10;
    };

    std::cout <<"The value of a is : " << a << std::endl;
    func6();
    std::cout <<"The value of a is : " << a << std::endl;


    return 0;
}