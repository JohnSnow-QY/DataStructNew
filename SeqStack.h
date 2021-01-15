
#ifndef SEQSTACK_H
#define SEQSTACK_H
//3.1.2 顺序栈
//        栈的抽象数据类型有两种典型的存储表示：基于数组的存储表示和基于链表的存储表示。
//基于数组的存储表示实现的栈成为顺序栈，基于链表的存储表示实现的栈称为链式栈。
//顺序栈可以采用顺序表作为其存储表示，为此可以在顺序栈的声明中用顺序表定义它的存储空间。
//程序3.2  顺序栈的类定义
#include <assert.h>

#include "stack.h"
const int statckIncreament = 20;        //栈溢出是拓展空间的增量
template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);              //建立一个空栈
    ~SeqStack() {                        //析构函数
       
    }

    void Push(const T& x);              //如果IsEmpty(),则不执行退栈，返回false;否则退掉位于栈顶的元素，返回true;

    bool getTop(T& x)const ;                //如果 IsEmpty(),则返回false,否则返回true,并通过引用型参数x得到栈顶元素的值
    bool IsEmpty()const;            //如果栈中元素
    
    bool IsFull()const;               //如果栈中元素格式等于maxSzie,则返回true,否则返回false
        
    
    int makeEmpty();                  //清空栈的内容
       
    
    bool Pop(T& x);
    int getSize()const;              //返回栈中元素的栈数组
      
    
    friend std::ostream& operator<<(std::ostream& os, SeqStack<T>& s) {}
    //输出栈中元素的重载操作<<
private:
    T* elements;                    //存放栈中元素的栈数组
    int top;                        //栈顶指针
    int maxSize;                    //
    void overflowProcess();         //栈的溢出处理


};
#endif SEQSTACK_H
#pragma once