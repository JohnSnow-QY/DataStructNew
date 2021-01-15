#pragma once
//
// Created by DELL on 2020/11/1.
//

#ifndef LinkedStack_h
#define LinkedStack_h
//3.1.3 链式栈
//        链式栈时线性表的链接存储表示。采用链式栈来表示一个栈，便于结点的插入与删除。在程序中同时使用多个栈的情况下，用链接表示不仅能够提高效率，还可以达到
//        共享存储空间的目的。
//链式栈的栈顶在链表的表头。因此，新结点的插入和删除都在链表的表头，即栈顶进行。使用第二章的单链表结点类定义

//程序3.6 链式栈的类定义



#include "stack.h"
template<class T>
class LinkedStack :public Stack<T> {
public:
    LinkedStack() :top(nullptr);               //构造函数，置空栈
    ~LinkedStack();                            //析构函数
      
    
    void Push(const T& x);                      //进栈
    bool Pop(T& x);                           //出栈
    bool getTop(T& x)const;                     //读取栈顶元素
    bool IsEmpty()const;
       
    
    int getSize()const ;                        //求栈的元素个数
    void makeEmpty();                            //清空栈的内容
    bool IsFull()const;
    friend std::ostream& operator<<(ostream& os, SeqStack<T>& s);
private:
    LinkNode<T>* top;                                 //栈顶指针，即栈顶指针

};

#endif 
