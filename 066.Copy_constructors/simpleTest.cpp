// #include <iostream>

// void Point(const double& p){
//     std::cout << "Point(const double& p)" << std::endl;
// }

// void Point(double& p){
//     std::cout << "Point(double& p)" << std::endl;
// }

// int main(int argc, char **args){

//     const double test {12.0};

//     Point(test);

//     double test2 {12.0};

//     Point(test2);

// }

//I thought that const double& was too close to double& to distinquish overloads, am wrong
//non const can be ugraded to const ref, but const cannot be upgraded to non const ref
//Keep in mind.