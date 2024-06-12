#pragma once
#include<iostream>
#include <vector>
using namespace std;

namespace mydemo
{
     class track
    {
    public:
        size_t _id;
        track(size_t id):_id(id) {cout<<"track("<<id<<")"<<" adderss:"<<this<<"\n";} 
        explicit track(track &tra):_id(tra._id) {cout<<"复制track("<<tra._id<<")"<<" adderss:"<<this<<"\n";} 
        virtual ~track() {cout<<"~track("<<_id<<")"<<" adderss:"<<this<<"\n";} 
    };
} // namespace mydemo
#include"My_malloc.h"
#include"My_allocator.h"
#include"My_new.h"
#include"My_memory.h"