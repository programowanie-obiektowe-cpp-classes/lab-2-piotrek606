#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : p_(new Resource()) {}

    ~ResourceManager()
    {
        delete p_;
        p_ = nullptr;
    }

    ResourceManager(const ResourceManager& other) : p_(new Resource(*other.p_)) {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            Resource* nowy = new Resource(*other.p_);
            delete p_;
            p_ = nowy;
        }
        return *this;
    }

    double get() {
        return (*p_).get(); 
    }

private:
    Resource* p_;
};
