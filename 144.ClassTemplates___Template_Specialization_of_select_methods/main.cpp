#include <iostream>
#include "Exercise.h"

int main(int argc, char **argv){

    //Template specialization of select methods in a class template
    //I've done it a couple times now but here is a formal fold on the process.

    //declare the specialization using 'template<>' then use Map<????>:: to define it where ???? is the
    //type you are specializing. Nice :)

    //I didn't like how complicated the lecture example was for this so making use of an online exercise I
    //did.

    Map<int> m1(11,22);
    Map<int> m2(11,22);
    auto result = m1.compare_to(m2);
    std::cout << "result : " << std::boolalpha << result << std::endl;
    m1.print_info();

    //goal is using specialization to compare c_strings using special functionality, exhibited here
    //for my specialization check the Exercise.cpp file
    Map<const char*> m1_b("Daniel","Gakwaya");
    std::string last_name_b {"Daniel"};
    std::string first_name_b{"Gakwaya"};
    Map<const char*> m2_b(last_name_b.c_str(),first_name_b.c_str());
    auto result_b = m1_b.compare_to(m2_b);
    std::cout << "result : " << std::boolalpha << result_b << std::endl;

    //NOTE:
    //Definitions of class templates methods have inline protection by default.
    //This does NOT extend to specializations of methods in a template. Template specializations are real
    //c++ code definitions. If you want to keep them close to the class template method they specialize, 
    //they will need to be inline in header files. Otherwise put them in a .cpp.

    return 0;
}