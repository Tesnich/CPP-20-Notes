#ifndef INT_HOLDER_H
#define INT_HOLDER_H
#include <initializer_list>
#include <memory>

class IntHolder
{
    private:
        std::unique_ptr<int[]> ptrValues_{};
        unsigned int count{};
    public:
        IntHolder() = delete;
        IntHolder(std::initializer_list<int> list)
            : ptrValues_{new int[list.size()]{}} {
            //with unique pointers you must reset them before assigning new values, otherwise initialize them properly
            //ptrValues_.reset(new int[list.size()]{});
                for(auto i{list.begin()}; i < list.end(); ++i){
                    ptrValues_[count++] = *(i);
                }
                --count;
            }
        ~IntHolder() = default;

        int At(unsigned int i){
            if (i > count)
                //easy creation and throw of a standard exception object
                throw std::out_of_range(std::string{"YOU TRIED TO FETCH ("} += std::to_string(i) +=") WHICH IS OUT OF RANGLE LOSER!");
            return ptrValues_[i];
        }
};

#endif