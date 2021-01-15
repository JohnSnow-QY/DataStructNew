//
// Created by DELL on 2020/11/1.
//


//3.1.2 顺序栈
//        栈的抽象数据类型有两种典型的存储表示：基于数组的存储表示和基于链表的存储表示。
//基于数组的存储表示实现的栈成为顺序栈，基于链表的存储表示实现的栈称为链式栈。
//顺序栈可以采用顺序表作为其存储表示，为此可以在顺序栈的声明中用顺序表定义它的存储空间。
//程序3.2  顺序栈的类定义
#include <assert.h>
#include<iostream>
#include "stack.h"
using namespace std;
const int statckIncreament = 20;        //栈溢出是拓展空间的增量
template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);              //建立一个空栈
    ~SeqStack() {                        //析构函数
        delete[] elements;
    }

    void Push(const T& x);              //如果IsEmpty(),则不执行退栈，返回false;否则退掉位于栈顶的元素，返回true;

    bool getTop(T& x)const;                //如果 IsEmpty(),则返回false,否则返回true,并通过引用型参数x得到栈顶元素的值
    bool IsEmpty()const {               //如果栈中元素
        return(top == -1) ? true : false;
    }
    bool IsFull()const {                //如果栈中元素格式等于maxSzie,则返回true,否则返回false
        return (top == maxSize - 1) ? true : false;
    }
    int makeEmpty() {                    //清空栈的内容
        top = -1;
    }
    bool Pop(T& x);
    int getSize()const {                //返回栈中元素的栈数组
        return top + 1;
    }
    friend ostream& operator<<(ostream& os, SeqStack<T>& s) {}
    //输出栈中元素的重载操作<<
private:
    T* elements;                    //存放栈中元素的栈数组
    int top;                        //栈顶指针
    int maxSize;                    //
    void overflowProcess();         //栈的溢出处理


};
//        栈的构造函数用于在建立栈的对象时为栈的数据成员附初值，函数中动态建立的栈数组的最大尺寸为maxSize，由函数参数
//        sz给出，并令 top = -1,置栈为空。在这个函数实现中，使用了一种断言（Assert)机制，这是C++提供的一种功能，若断言语句assert参数
//        表中给定的条件满足，则继续执行后续的语句；否则出错处理，终止程序的执行。
//程序3.3 顺序栈的构造函数
template<class T>
SeqStack<T>::SeqStack(int sz) {
    //建立一个最大尺寸为sz的空栈，若分配不成功则错误处理
    elements = new T[sz];              //创建栈的数组空间
    assert(elements != nullptr);             //断言：动态存储分配成功与否

}
//top指示的是最后加入的元素的存储位置。在实现进栈操作时，应先判断是否已满。栈的最后运行存放位置为maxSize-1,如果栈顶指针top == maxSize-1,则
//        说明栈中所有位置均已使用，栈已满。这时若再有元素进栈，将发生溢出，程序转入溢出处理。
//如果top < maxSize-1,则先让栈顶指针进1，指到当前可加入新元素的位置，再按栈顶指针所指位置将新元素插入。这个新插入的元素将成为新的栈顶元素。
//另一个极端情况出现在栈底：如果在退栈是发现是空栈，即 top == -1,则退栈操作将执行栈空处理。栈空处理一般不是出错处理，而是使用这个栈的算法结束是需要执行的处理。
//若当前 top >= 0,则可将栈顶指针减1，等于栈顶退回到次栈顶位置。
//程序3.4 栈的构造函数的实现
template<class T>
void SeqStack<T>::overflowProcess() {
    //私有函数：扩充栈的存储空间
    T* newArray = new T[maxSize + stackIncreament];
    for (int i = 0; i <= top; i++) {
        newArray[i] = elements[i]
    }
    maxSize = maxSize + stackIncreament;
    delete[]elements;
    elements = newArray;
}
template<class T>
void SeqStack<T> ::Push(const T& x) {
    //公共函数：若栈不满，则将元素插入到该栈的栈顶，否则溢出处理
    if (IsFull() == true) {
        overflowProcess();                  //栈满则溢出处理
    }
    elements[++top] = x;                   //栈顶指针先加1，再进栈
}
template<class T>
bool SeqStack<T> ::Pop(T& x) {
    //公共函数：若栈不空则函数返回该栈栈顶元素的值，然后栈顶指针退1
    if (IsEmpty() == true) { return false };        //判断栈空否，若栈空则函数返回
    x = elements[top--];                        //栈顶指针退1
    return true;                                //退栈成功
}

template<class T>
bool SeqStack<T>::getTop(T& x)const {
    //公共函数：若栈不空则函数返回该栈栈顶元素的地址
    if (IsEmpty() == true) {
        return false;                           //判栈空否，若栈空则函数返回
    }
    x = elements[top];                          //返回栈顶元素的值
    return true;
}
template<class T>
ostream& operator<< (ostream& os, SeqStack<T>& s) {
    //输出栈中元素的重载函数 <<
    os << "top = " << s.top << endl;                 //输出栈顶位置
    for (int i = 0; i <= s.top; i++) {
        os << i << ":" << s.elements[i] << endl;
    }
    return os;
}
//如果给几个栈分配同样大小的空间，可能在实际运行中，有的栈膨胀的很快，很快就产生了溢出，而其它的栈可能此时还有许多空闲的空间。这时，
//就必须调整整栈的空间，防止栈的溢出。(双栈仅仅作为顺序栈到链式栈的一个过渡，不做实现要求）
//例如，程序同时需要两个栈时，我们可以定义一个足够的栈空间。该空间的两端分别设为两个栈的栈底，用b[0](= -1) 和b[1](=maxSize)指示。
//让两个栈的栈顶t[0]和t[1]都向中间伸展，直到两个栈的栈顶相遇，才认为发生了溢出。
//在双栈的情形下，各栈的初始化语句为t[0] = b[0] = -1,t[1] = b[1] = maxSize。栈满的条件为t[0] + 1 = t[1]。
//而栈空的条件为t[0] = b[0] 或 t[1] = b[1],此时栈顶指针退到栈底。
//
//程序3.5 双栈的插入和删除操作的实现
//        n(n>2) 个栈的情形有所不同，采用多个栈共享栈空间的顺序存储表示方式，处理十分复杂，在插入是元素的移动量很大，时间代价较高。特别是当整个存储空间
//        即将充满时，这个问题更严重。解决的方法就是采用链接方式作为栈的存储表示。

