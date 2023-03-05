#ifndef SCORES_H
#define SCORES_H

#include <string>
#include <string_view>
#include <memory>

namespace BookKeeping {
    class Scores {
        private :
            std::string courseName_{};
            unsigned int nStudents_{};
            std::shared_ptr<double[]> scores_;
        public :
            Scores() = delete;
            Scores(std::string_view courseName,unsigned int nStudents)
                : courseName_{courseName}, nStudents_{nStudents}, scores_{new double[nStudents]{}} {}
            ~Scores() = default;

            void PrintAllScores();

            double& operator[](unsigned int i);
            const double& operator[](unsigned int i) const;

            //so the above overloads of the operator[] have the same processing in their body,
            //the only real difference is that one is called from const objects and also returns
            //a const version of the double ref return type

            //Is there a clever way that these could be combined into a template that satisfies
            //both calls from const and non const objects of the Scores class?

            //lets try the below

            //DOES NOT WORK
            // template<typename T>
            // T& operator[](unsigned int i){
            //     return scores_[i];
            // }

            //this works for non-const call, but NOT the const version :/
            // auto& operator[](unsigned int i){
            //     return scores_[i];
            // }

            //I think what I am missing is some way to tell the compiler that this function has
            //a const version in addition to the non-const

            //You know, that bit after the parms but before the body where you put 'const'

            //providing friend access to non-class member operator overloads
            friend std::ostream& operator<< (std::ostream& os, const Scores& scores);
            friend std::istream& operator>> (std::istream& is, Scores& scores);
    };

    //free standing, non-member overload for the stream insertion operation operator, marked as friend above
    std::ostream& operator<< (std::ostream& os, const Scores& scores);
    //same thing but for the input stream 
    std::istream& operator>> (std::istream& is, Scores& scores);
}

#endif