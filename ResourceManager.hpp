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

    ResourceManager(ResourceManager&& other) noexcept : p_(other.p_) {other.p_ = nullptr;}


    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            delete p_;
            p_       = other.p_;
            other.p_ = nullptr;
        }
        return *this;
    }

    double get() {
        return (*p_).get(); 
    }

private:
    Resource* p_;
};
