#ifndef DELETED_COPY_CONSTRUCTOR_H
#define DELETED_COPY_CONSTRUCTOR_H

class DeletedCopyConstructor
{
    public:
        DeletedCopyConstructor() = default;
        ~DeletedCopyConstructor() = default;

        DeletedCopyConstructor( const DeletedCopyConstructor& deletedCopyConstructor) = delete;
};


#endif