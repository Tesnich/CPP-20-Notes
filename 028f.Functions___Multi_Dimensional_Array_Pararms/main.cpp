#include <iostream>

double SumArray(const double array[][3], size_t size); //With a multi dimensional array the inner most size is required!
//  all dimensions except the outer must be filled AND ENFORCED ie ...
//  double Sum3DArray(const double array[][3][5], size_t size)

int main(){
    //multi dimensional array function parameters
    const double array[][3] {
        {1,2,3},
        {1,2,3},
        {1,2,3}
    };

    //This method will only take in arrays that have the same type, aka in this case "const double [n][3]", outer size doesn't matter
    std::cout << "The sum of the multi dimensional array is : " << SumArray(array, std::size(array)) << std::endl;

    return 0;
}

double SumArray(const double array[][3], size_t size) // Multi dimensional array inner sizes 
{                                                     // ARE ENFORCED !!!!!! 
    double sum{0};                                    // Failure to follow will not allow you to compile!
    for(size_t i{0}; i < size; ++i)
    {
        for(size_t n{0}; n < 3; ++n)
        {
            sum += array[i][n]; //array index access notation
            //sum += *(*(array+i)+n); //pointer rithmetic notation (yeah I preffer array notation haha)
        }
    }
    return sum;
}