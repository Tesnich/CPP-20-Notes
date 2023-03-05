#ifndef DESTRUCTOR_WATCH_H
#define DESTRUCTOR_WATCH_H

class DestructorWatch{
    private :
        static unsigned int count;
        unsigned int identifier_{};
    public :
        DestructorWatch();
        ~DestructorWatch();
};

#endif