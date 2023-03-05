#include <iostream>


int main(int argc, char **argv){

    //Zooming in on partial ordering

    //similar to how we manually returned std::weak_ordering::equivalent we can return std::partial_ordering::unordered

    //The case given here is imagining that points can only be compared to one another if they are within
    //the same 100^2 unit block

    //Essentially, if the condition fails that they are not in the same region the lecturer returns 
    //unordered in <=> overload. It basically boils down to custom conditions determining whether or not
    //their values are in a comparable range. For standard doubles that can be 12.2 and NaN, for
    //user written classes things could get more complicated to warrent this special implementation.

    //ie... Imagine that there are multiple dimensions of a cartesian coordinate system. If one point
    //exists on plane A, and another exists on plane B, while they both may have valid x_ and y_ values
    //comparing their distances wouldn't make sense because they don't exist in the same space. Hence,
    //you'd write a check to see if they are not on the same plane and return ::unordered if so.

    //I am sure there are real world reasons to set up such comparisons, but since it is so similar
    //to the previous notes I took on weak_ordering and I dont like the lecture example, I'm
    //not going to bother writing a class to explore it rn.

    return 0;
}