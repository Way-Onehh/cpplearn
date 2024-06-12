#pragma once
#include <new>
namespace mydemo
{
    /*
    void *__cdecl operator new(size_t _Size)  
    void *__cdecl operator new(size_t _Size, const std::nothrow_t &) noexcept   不用异常版本
    inline void *__cdecl operator new(size_t _Size, void *_Where) noexcept placement new 并不分配内存
    void *__cdecl operator new[](size_t _Size)
    void __cdecl operator delete(void *_Block, size_t _Size) noexcept
    void __cdecl operator delete[](void *_Block) noexcept

    */
    namespace MY_new
    {
    inline    void new_M()
        {
            //单个对象
            int *a=new int;
            long int adderss= int(a);
            delete a;
            a=nullptr;
            //不有异常版本
            a=new(std::nothrow) int ;
            delete a;
            a=nullptr;
            /*未完成align_val_t 是c++17内容
            std::align_val_t align;
            a=new(align) int;
            delete a;
            a=nullptr;
            */
           //原位构造版本
           /*error (int*)aderss这个内存已经被释放了 new((int*)aderss) int 自己本身不分配空间
            a=new((int*)aderss) int ;
            delete a;
            a=nullptr;
            */
            a=new int;
            adderss= int(a);
            a=new((int*)adderss) int ;
            delete a;
            //追踪原位构造版本
            track* b=new track(1);
            adderss= int(b);
            b=new((track*)adderss) track(2) ;
            delete b;
            //追踪只构造一次原位构造版本
            b=(track *) malloc(sizeof(track));
            adderss= int(b);
            b=new((track*)adderss) track(2) ;
            delete b;

            a=new int[10] ;
            delete[] a;
            a=nullptr;
        }
    } // namespace MY_new
} // namespace mydemo
