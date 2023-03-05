#include <cassert>
#include "Scores.h"
#include <iostream>

namespace BookKeeping {

    void Scores::PrintAllScores(){
        for(unsigned int i{0}; i < nStudents_; ++i)
            std::cout << scores_[i] << " ";
        std::cout << std::endl;
    }

    double& Scores::operator[](unsigned int i){
        //std::cout<< ">> non const operator[] call" <<std::endl;
        assert(i < 20);
        return scores_[i];
    }
    const double& Scores::operator[](unsigned int i) const{
        //std::cout<< ">> const operator[] call" <<std::endl;
        assert(i < 20);
        return scores_[i];
    }

    //I tried to remove the above overloads in lue of a template
    //written in the header file that covers both cases, but had absolutely no luck

    //free standing, non-member overload for the stream insertion operation operator, friend of Scores
    std::ostream& operator<< (std::ostream& os, const Scores& scores){
        os << "Scores [ ";
        for(unsigned int i{0}; i < scores.nStudents_; ++i)
            os << scores[i] << " ";
        os <<"]";
        return os;
    }

    //So here is my thought process on this one. The stream insertion operation operator <<, is
    //not used on a LHS argument of a Scores object in the context of output streams.
    //Meaning, that really when you use << in respect to an output stream like std::cout <<,
    //you have two arguments. The first being the cout stream(being acted on) and the second being the object
    //you are providing.

    //I think here, the real subject of the '<<' op is the cout stream. As in, if we had access to
    //that class we would be writing this as a member function of cout because << is used in respect to it.

    //If we simply overloaded << on the Scores class itself, so it was a member function, what we would
    //really be writing would be a function executed whenever someone took a Scores instance and did
    //      scoresA << someOtherObject;
    //If I remember, that is the syntax for bitshift on a bunch of the standard types. Which,
    //obviously, is not what we are trying to do. 

    //The way we have written it above, we are specifying an overload of the << operator only for
    //events in which an output stream (std::cout) is used with the argument of an object of
    //the scores class. I think that makes sense.

    //Writing it as a member function also would not allow us any access to an output stream as a LHA.
    //We could specify std::ostream as the input parameter for the member func, but it would be called like...
    //      scoresA << std::cout; 
    //Which, obviously, is backwards as hell.

    //Oh, and just so I have this in writing somewhere... The return type of the overload written
    //above is a reference to the input 'output stream' so they can be chained. This is how all 
    //standard types have it implemented. We could easily make it void, but that would not allow
    //for further arguments to the stream, like the typical punctuation of '<< std::endl'!

    //input stream variant, think for use with cin
    std::istream& operator>> (std::istream& is, Scores& scores){
        std::cout << " >> Entered 'operator>>' << " << std::endl;
        unsigned int count{0};
        while(true){
            if (count >= scores.nStudents_ || !(is >> scores[count])) //bug here, if the >> fails it is populated with 0, would need to save it and put it back if failed
                break;                                                //make it a different conditional in that case
            ++count;
        }
        return is;
    }

    //so what I am trying to do above is a little tricky, the lecture had a finite number of 
    //aguments to fill ( the x and y on a point class). What I wanted to do was write it such that
    //any number of input arguments I provided would be used to replace them in the object.

    //The problem lies in the fact that 'is' is not a finite stream. Meaning any time I call 'is >>scores[count]'
    //I am basically asking the terminal for a response if one isn't already recorded. A better approach
    //to this would have been a getline, where I only grab what the user gives me and parse it for
    //values. 

    //I can break this conditional by providing anything other than input that can fit into a double,
    //so at least this works as long as the user knows to do that? This fills it with a zero though,
    //and I don't really want to fix it rn.

    //Important take away from playing with the above though! top level call 'cin >> class' is not what
    //triggers request for user input into terminal. That is done at the standard type level, when
    //we attempt to slap some values into something like a double. Probably lower than that because
    //they are just pre-defined classes...
}