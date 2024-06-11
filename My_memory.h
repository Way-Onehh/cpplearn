#pragma once
#include<memory.h>
#include<memory>
namespace mydemo
{

namespace MY_memory
{   
    /*
    void *__cdecl memset(void *_Dst, int _Val, size_t _Size) 将特定内存区域的内容设置为指定的值
    void *__cdecl memcpy(void *_Dst, const void *_Src, size_t _Size) 从源地址空间复制一定数量的字节到目标地址空间复制时非常高效。
                                                                     使用memcpy时需要注意源和目标地址不能重叠，否则会导致未定义行为。
    void *__cdecl memmove(void *_Dst, const void *_Src, size_t _Size) 该函数与memcpy类似，但可以正确处理源和目标内存区域重叠的情况
    int __cdecl memcmp(const void *_Buf1, const void *_Buf2, size_t _Size) 比较两个内存区域的前n个字节是否相等
    */
    //memory.h
    void MY_memory_M()
    {
        int* adderss1=new int[10];
        int* adderss2=new int[10];
        memset(adderss1,1,10);
        memset(adderss2,2,10);
        memcpy(adderss1,adderss2,10);
        memmove(adderss1,adderss2,10);
        int b= memcmp(adderss1,adderss2,10);
        delete[] adderss1;
        delete[] adderss2;
    }
    
    //删除器 调用delete obj delete[] obj 
    void  MY_default_delete_M()
    {
        
        std::default_delete<track> a;
        track* b=new track(1);
        a(b);
    }


    /*
     unique_ptr 一种智能指针，它提供了对动态分配的对象的独占所有权
    //构造器
    unique_ptr() noexcept：默认构造函数，创建一个不拥有任何对象的 unique_ptr
    explicit unique_ptr(Pointer p) noexcept：接受一个指针参数，创建一个拥有该指针所指向对象的 unique_ptr。
    unique_ptr(unique_ptr&& u) noexcept：移动构造函数，从另一个 unique_ptr 对象中接管所有权。
    //观察器
    get() const noexcept：返回智能指针所指向的原始指针。
    operator*() const：返回智能指针所指向的对象的引用。
    operator->() const noexcept：返回一个指向智能指针所指向对象的指针。
    //修改器  :
    release() noexcept：只释放智能指针所指向的对象的所有权不释放内存，并返回原始指针。调用此函数后，智能指针不再拥有该对象。
    reset(Pointer p = pointer()) noexcept：释放当前所拥有的对象（如果存在），并接管一个新的指针所指向的对象。
    reset(nullptr_t) noexcept：释放当前所拥有的对象，并将智能指针设置为空指针。
    unique_ptr& operator=(unique_ptr&& u) noexcept：移动赋值操作符，从另一个 unique_ptr 对象中接管所有权，并释放原有的对象。
    //比较器
    bool operator==(const unique_ptr& u) const noexcept：检查两个 unique_ptr 是否指向相同的对象
    bool operator!=(const unique_ptr& u) const noexcept：检查两个 unique_ptr 是否指向不同的对象。
    //删除器
    get_deleter：这是一个可调用的类型，用于在智能指针的生命周期结束时释放所管理的对象。删除器的实例可
    ~unique_ptr()：当 unique_ptr 离开作用域时，自动释放所指向的对象，并调用删除器。
    */
   
    void MY_unique_ptr_M()
    { 
    //构造器
    unique_ptr<track> unip;
    cout<<"adderss:"<<&unip<<" unique_ptr is empty"<<endl;
    unique_ptr<track> unip1(new track(1));   
    unique_ptr<track> unip2(move(unip1));  
    //观察器
    memset(unip2.get(), 10 ,1);
    cout<<"id:"<<unip2->_id<<endl;
    unip2.get_deleter()(new track(11));
    //修改器
    unip1.reset(unip2.release());
    unip2.swap(unip1);
    unip1=move(unip2);
    //比较器
    unip2.reset(unip1.get()) ;
    if(unip2==unip1)
    {
      //error  unip1.reset(nullptr);
      unip1.release();
    }
    //make_unique<T>构造 不能直接用来分配数组内存，因为它是为单个对象设计的。
    unique_ptr<track> unip3 (make_unique<track>(123));
    unip3= make_unique<track>(1);
    unique_ptr<track[]> unip4((track *) malloc(sizeof(track)*5));

    }

     void MY_shared_ptr_M()
    { 
        
    }
}
}