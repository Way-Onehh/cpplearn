#pragma once
namespace mydemo
{
    /*
    allocator是STL默认分配器模板专门用于内存分配和对象构造确保在面对异常时能够安全地处理内存。
    成员
    T* allocate<T> (size_t _Count)  内存中分配一块足够大的未初始化内存区域
    void deallocate<T> (T* Ptr, size_t _Count) 负责将之前通过allocate分配的内存释放回系统
    对于对象
    void construct<T> (T* Ptr, _Types&&... ) 直接在指定的内存位置调用对象的构造函数   _Types&&...被转发的参数
                                              eg：  void* address =  指定的内存地址 ;
                                                    T* obj = new (address) T(构造函数参数 );
    void destroy<T> (T* Ptr) 已经构造了的对象上调用其析构函数，以销毁该对象      
    */
   //这是一个观察类
   
    namespace MY_allocator
    {
   
    void allocator_M()
    {
        //一个分配器
        allocator<track> Allocator;
        //分配2个track对象的空间
        track *adderss= Allocator.allocate(2);
        //分别构造
        Allocator.construct(adderss,0);
        Allocator.construct(adderss+1,1);
        //分别析构
        Allocator.destroy(adderss);
        Allocator.destroy(adderss+1);
        //返回2个track对象的空间
        Allocator.deallocate(adderss,2);
    }
    }
} // namespace name
