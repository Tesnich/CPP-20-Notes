#include <iostream>

double sumArray(double (&array)[10]);
//!!!!! in this case, where we are passing an array by reference the [10] is enforced!

int main(){
    //passing arrays by reference

    //passing the below would be rejected by the compiler!
    double array[] {10.0, 20.0, 30.0, 40.0, 50.0};
    double array2[] {10.0, 20.0, 30.0, 40.0, 50.0, 10.0, 20.0, 30.0, 40.0, 50.0};
    double resultSum {sumArray(array2)}; //only arrays of size [10] will be accepted!
    std::cout << "Sum of the array2 : " << resultSum << std::endl;

    return 0;
}

double sumArray(double (&array)[10]) //size of [10] is strictly enforced!
{
    double sum{0};

    for (auto element : array) //because the array is passed in by reference we have access to the full suite of array tools!
        sum += element;        //we can use a range loop like this, or even call std::size() if we want

    return sum;
}

//  I feel like the benefits here are lacking at the price of restricting usefullness of your function to an array of only one particular size!
//  not worth it in my opinion :(