#include <iostream>
#include "BoxContainer.h"

void ReadBoxContainer(const BoxContainer& boxContainer){
    std::cout << "---- Reading Box Container ------------------\n";
    std::cout << "boxContainer.capactiy() : " << boxContainer.capacity() << "\n";
    std::cout << "boxContainer.size() : " << boxContainer.size() << "\n";
    std::cout << "boxContainer : " << boxContainer << "\n";
}

int main(int argc, char **argv){

    //BoxContainer class : Practicing What We Know

    //BoxContainer is a container class that provides the features :
    //  - add_item
    //  - remove_item
    //  - remove_all

    //We can add BoxContainers up with :
    //  - +=
    //  - +

    //Additional support includes :
    //  - stream insert BoxContainers with operator <<
    //  - copy constructor BoxContainers
    //  - copy assign BoxContainers

    BoxContainer boxContainer(5);
    ReadBoxContainer(boxContainer);

    boxContainer.AddItem(0);
    boxContainer.AddItem(11);
    boxContainer.AddItem(22);
    boxContainer.AddItem(11);

    ReadBoxContainer(boxContainer);

    try{
        std::cout<< "boxContainer.At(4) : " << boxContainer.At(4) << "\n";
    }catch(const std::exception& ex){
        std::cout << "Exception Caught : " << ex.what() << "\n";
    }

    boxContainer.AddItem(44);

    try
    {
        boxContainer.AddItem(55);
    }
    catch(const std::exception& ex)
    {
        std::cout << "Exception Caught : " << ex.what() << "\n";
    }
    
    ReadBoxContainer(boxContainer);

    boxContainer.RemoveItem(11);
    std::cout << ">> boxContainer.RemoveItem(11) <<\n";

    ReadBoxContainer(boxContainer);

    std::cout << ">>copy of boxContainer<<\n";
    BoxContainer boxContainer2{boxContainer};
    ReadBoxContainer(boxContainer2);

    std::cout << ">>new boxContainer3 with 2 values<<\n";
    BoxContainer boxContainer3{};
    boxContainer3.AddItem(88);
    boxContainer3.AddItem(99);
    ReadBoxContainer(boxContainer3);
    std::cout << ">>boxContainer2 += boxContainer3<<\n";
    boxContainer2 += boxContainer3;
    ReadBoxContainer(boxContainer2);
    std::cout << ">>boxContainer + boxContainer3<<\n";
    ReadBoxContainer(boxContainer + boxContainer3);
    std::cout << "Reading boxContainer & boxContainer3 to look for changes...\n";
    ReadBoxContainer(boxContainer);
    ReadBoxContainer(boxContainer3);
    std::cout << "Box Containters for comparison...";
    BoxContainer boxContainerA{};
    boxContainerA.AddItem(5);
    boxContainerA.AddItem(5);
    boxContainerA.AddItem(5);
    BoxContainer boxContainerB{};
    boxContainerB.AddItem(5);
    boxContainerB.AddItem(5);
    boxContainerB.AddItem(5);
    //something isnt quiet working here, I can see from cout that I am returning both equal and equivalent
    //maybe I have to read it in a different way?
    std::cout<< "{"<<boxContainerA<<"} == {"<<boxContainerB<<"} : " << ((boxContainerA <=> boxContainerB) == std::strong_ordering::equivalent) << "\n";
    //NOTE:: Reading online, they are the same in the context of strong_types. The difference only applys when stepping
    //down to weak or partial ordering types which do not implement equal, just equivalence. Anyways, its in the
    //weeds. I implemented it fine.

    return 0;
}