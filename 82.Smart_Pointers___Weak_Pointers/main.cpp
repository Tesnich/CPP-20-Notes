#include <iostream>
#include <memory>
#include "Person.h"
#include "PersonImproved.h"

int main(int argc, char **argv){

    //Weak Pointers

    //weak pointers do not do memory management on the objects they point to
    //if a weak pointer dies when out of scope, its associated object continues to live

    //weak pointers also do not allow for dereference of the address they hold
    //-> and * are disabled, meaning it is only good for holding the location of an object on the heap
    //has no member function get() like other smart pointers

    std::shared_ptr<int> sharedPtrIntA {std::make_shared<int>(99)};
    std::weak_ptr<int> weakPtrIntA {sharedPtrIntA};

    //Illegal opperations
    //std::cout << *weakPtrIntA << std::endl;
    //std::cout << weakPtrIntA.get() << std::endl;

    //The only way to use a weak_ptr is to convert it to a shared_ptr using the lock() member function

    std::shared_ptr<int> sharedPtrIntB {weakPtrIntA.lock()};
    std::cout << "sharedPtrIntB.use_count() created from {weakPtrIntA.lock()} : " << sharedPtrIntB.use_count() << std::endl;
    //the shared pointer created from the locked weak_ptr is associated with the shared_ptr our weak_ptr was created from
    //2 shared pointers pointing to the same int on heap

    std::shared_ptr<int> sharedPtrIntC {weakPtrIntA};
    std::cout << "sharedPtrIntC.use_count() created from just {weakPtrIntA} : " << sharedPtrIntC.use_count() << std::endl;
    //huh.... so it looks like not using lock works just fine? What is the difference in these initializations I wonder?


    //What is the point of a weak pointer? Look at person.h quickly, then come back

    std::shared_ptr<Person> personA{std::make_shared<Person>("Emily")}, personB{std::make_shared<Person>("Sam")};
    personA->SetFriend(personB);
    personB->SetFriend(personA);
    personA->ReadFriend();
    personB->ReadFriend();

    //  examining the person class and the above code, you will find that we have two person objects
    //  that exist on the heap created with shared_ptrs

    //  In addition to the shared_ptrs we have in main pointing to these Person objects we also have
    //  set their shared_ptr<Person> class members to point at one another.

    //  The problem occurs when we go to clean up these object when we go out of scope

    //  First, lets think about what happens if personA is the first one to "die". Since it is a shared_ptr
    //  it will first check to see if it is the only one of its kind pointing to the Person object named Emily.
    //  Since the Person object named Sam has shared_ptr with PersonA, the shared_ptr named PersonA will leave scope
    //  but the Person object it pointed to will live on.

    //  Second to reach the end of scope in this situation is the shared_ptr personB. Just like personA,
    //  personB will see that the Person object named Emily still has a shared_ptr pointed at Sam. Thus,
    //  personB dissapears but the Person object it is associated with stays behind...

    //  WHOOPS! We are now at the end of the scope for this method and there are two Person objects
    //  living on the heap that we have no pointers to! Sure, they point to one another, but we can't
    //  access those, and the objects will never die. 

    //  THIS IS CLEARLY EVIDENT by the absence of the destructor cout lines in the terminal for 'Emily' and 'Sam'.

    //  A Classic Memory leak! Take note that these situations are possible with even with smart_pointers!!!
    //  When writing with pointers of any kind you must take care to think through how objects will be
    //  destroyed.

    

    //So, the solution? WEAK POINTERS!
    //In a sense weak_pointers are like a normal pointers. They have no barring on whether or not an
    //object is going to be deleted. The difference is that when converted back into a shared ptr
    //using the lock method, that the shared_ptr initalized with them will associate with the
    //the original source for the weak_ptr! This means they will be linked!

    //The above can't be said about a normal pointer to the Person class. As seen in my experimentation
    //in the previous lecture folders, simplying supplying the address of an object, where an existing
    //shared_ptr points, to a new shared_ptr, DOES NOT LINK THEM. The counts on both would be 1, and
    //whenever one dies it will lead to the other trying to delete a spot in memory that was alread
    //deleted.

    //The aspect of weak pointers where they can't be de-referenced is so that programmers don't
    //get into the habbit of using a placeholder to access an object and lose track of its
    //ownership/design their classes poorly.

    //Check out PersonImproved.h ...

    std::shared_ptr<PersonImproved> personC{std::make_shared<PersonImproved>("Zach")}, personD{std::make_shared<PersonImproved>("Charles")};
    personC->SetFriend(personD);
    personD->SetFriend(personC);
    personC->ReadFriend();
    personD->ReadFriend();
    
    //Looking at the terminal it is now clearly evident both Person objects, Zach and Charles, were deleted.

    return 0;
}