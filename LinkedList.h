#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <d2d1helper.h>

//此次使用复合类的方法
//class List;
template<class T>
class LinkNode {// 节点类定义
//    friend class List;

private:
    T data; //数据元素域
    LinkNode<T>* link; //链指针域
    LinkNode(LinkNode<T>* ptr = nullptr) {
        link = ptr;
    }

    LinkNode(const T& item, LinkNode<T>* ptr = nullptr) {//初始化数据和指针成员
        data = item;
        link = ptr;
    }
};

template<class T>
class List {    //List 类定义
public:
    //链表公共操作

    List() {
        first = new LinkNode<T>;
    }

    List(const T& x) {
        first = new LinkNode<T>(x);
    }

    List(List<T>& list); //复制构造函数
    ~List() { makeEmpty(); }//析构函数
    void makeEmpty(); //将链表置位空表
    int Length() const;

    LinkNode<T>* getHead() const { return first; }

    void setHead(LinkNode<T>* p) { first = p; }

    LinkNode<T>* Search(T x);//搜索含数据x的元素
    LinkNode<T>* Locate(int i);//取出第i个元素的值
    T* getData(int i);

    void setData(int i, T& x);

    bool Insert(int i, T& x);

    bool Remove(int i, T& x);

    bool IsEmpty() const {
        return first->link == nullptr ? true : false;
    }


    //   bool IsFull()const {return false};//判断是否满
    void Sort();//排序
    void input();//输入
    void output();//输出
    List<T>& std::operator=(List<T>& list);//重构函数，赋值

private:
    LinkNode<T>* first;//链表头指针
};

#endif //LINKEDLIST_H
#pragma once
