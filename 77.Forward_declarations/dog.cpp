#include "dog.h"

Dog::Dog()
    :Dog{"DEFAULT_WHITE"} {}

Dog::Dog(std::string_view color)
    :color_{color} {}