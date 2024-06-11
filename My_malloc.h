#pragma once
#include<malloc.h>
namespace mydemo
{
//一级分配器 malloc calloc reallor  分配失败放回NULL  （free释放）
namespace MY_malloc
{
//void*  malloc(size_t _Size) 尝试分配_Size大小的内存 失败放回NULL(小概率)
void malloc_M()
{ 
    size_t count =10;
    int *p= (int *) malloc(sizeof(int)*count);
    for (size_t i = 0; i < count; i++)
    {
       *(p+i)=i;
       cout<<*(p+i);
    } 
    free(p);
    return;
}
//void*  calloc(size_t _Counts,size_t _Size) 尝试分配_Counts个_Size大小的内存并初始化为0 失败放回NULL(小概率)
void calloc_M()
{ 
    size_t count =10;
    int *p= (int *) calloc(count,sizeof(int));
    for (size_t i = 0; i < count; i++)
    {
       *(p+i)=i;
       cout<<*(p+i);
    } 
    free(p);
    return;
}
//void*  realloc(void * _Block,size_t _Size) 尝试在_Block处重新分配_Size大小的内存 失败放回NULL(小概率)
void realloc_M()
{ 
    //先calloc10个int边赋值0到9边
    size_t count =10;
    int *p= (int *) calloc(count,sizeof(int));
    for (size_t i = 0; i < count; i++)
    {
       *(p+i)=i;
       cout<<*(p+i)<<" ";
    } 
     cout<<"\n";
    //再realloc10个int赋值10到19
    size_t recount =10;
    p=(int *) realloc(p,sizeof(int)*(recount+count));
    for (size_t i = count; i < recount+count; i++)
    {
       *(p+i)=i;
       cout<<*(p+i)<<" ";
    } 
    cout<<"\n";
    //最后检查一遍
    for (size_t i = 0; i < recount+count; i++)
    {
       cout<<*(p+i)<<" ";
    } 
    cout<<"\n";
    free(p);
    return;
}
}
}

