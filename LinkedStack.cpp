#include<iostream>
using namespace std;
template<class T>
class LinkedStack :public Stack<T> {
public:
    LinkedStack() :top(nullptr) {}                //构造函数，置空栈
    ~LinkedStack() {                             //析构函数
        makeEmpty();
    }
    void Push(const T& x);                      //进栈
    bool Pop(T& x);                           //出栈
    bool getTop(T& x)const;                     //读取栈顶元素
    bool IsEmpty()const {
        return (top == nullptr) ? true : false;
    }
    int getSize()const ;                        //求栈的元素个数
    void makeEmpty();                            //清空栈的内容
    bool IsFull()const;
    friend ostream& operator<<(ostream& os, SeqStack<T>& s);
private:
    LinkNode<T>* top;                                 //栈顶指针，即栈顶指针

};
template<class T>
bool LinkedStack<T>::IsEmpty() const {
    if (top == nullptr) {
        return true;
    }
    return false;
}
template< class T>
void LinkedStack<T>::makeEmpty() {                      //逐次删去链式栈中的元素直至栈顶指针为空
    LinkNode<T>* p;
    while (top != nullptr) {
        p = top;
        top = top->link;
        delete p;                                 //逐个删除
    }
}
template<class T>
void LinkedStack<T>::Push(const T& x) {
    //将元素x插入到链式栈的栈顶，即栈头
    top = new LinkNode<T>(x, top);                //创建新的含x结点
    assert(top != nullptr);                      //创建新结点失败退出
}
template<class T>
bool LinkedStack<T>::Pop(T& x) {
    if (IsEmpty() == true) {                      //若栈空则不退栈，返回
        return false;
    }
    LinkNode<T>* p = top;
    top = top->link;                            //栈顶指针推到新的栈顶位置
    x = p->data;                                //释放结点，返回退出元素的值
    delete p;
}
template<class T>
bool LinkedStack<T>::IsFull()const {
    return false;
}

template<class T>
bool LinkedStack<T>::getTop(T& x) const {
    //返回栈顶元素的值
    if (IsEmpty() == true) {
        return false;
    }
    x = top->data;
    return true;
}

template<class T>
int LinkedStack<T>::getSize()const {
    LinkNode<T>* p = top;
    int count = 0;
    while (p != nullptr) {
        p = p->link;
        count++;
    }
    return count;
}

template<class T>
ostream& operator<<(ostream& os, LinkedStack<T>& s) {
    //输出栈中元素的重载操作<<
    os << "栈中元素个数" << s.getSize() << endl;
    LinkNode<T>* p = top;
    while (p != nullptr) {
        os << ++i << ":" << p->data << endl;
    }
    return os;
}
//如果使用n个链式栈，其头结点可以用以下方式的定义
//        LinkNode<T> *s = new LinkNode<T>[n];
//在多个链式栈的情形下，link域需要一些附加的空间，但其代价并不很大