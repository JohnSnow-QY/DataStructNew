//
// Created by DELL on 2020/11/1.
//

#ifndef CRICLINKNODE_H
#define CRICLINKNODE_H
//循环链表的类定义
template <class T>
class CircLinkNode {
    //链表节点类定义
    T data;
    CircLinkNode<T>* link;
    CircLinkNode(CirclLinkNode<T> next = NULL) :link(next) {
    }
    CircLinkNode(T d, CircLinkNode<T>* next = NULL) :data(d), link(next) {}

};

template<class T>
class CirList : public LinearList<T> {
    //链表类定义 带头结点
public:
    CircList(const T& x);	//
    CircList(CircList<T>& L);		//复制构造函数
    ~CircList();
    int Length()const;		//计算循环链表长度
    bool IsEmpty() {
        return first->link == first ? true : false;

    }
    CircListNode<T>* getHead()const;		//返回附加头结点地址
    void setHead(CirListNode<T>* p);		//设置复制头结点地址
    CircListNode<T>* Search(T x);			//搜索含数据x的元素
    CircListNode<T>* Locate(int i);			//搜索第i个元素的值
    T* getData(int i);						//取出第i个元素的值
    void setData(int i, T& x);				//用x修改第i个元素的值
    bool Insert(int i, T& x);				//在第i个元素后插入x
    bool Remove(int i, T& x);				//删除第i个元素，x返回该元素的值
private:
    CircListNode<T>* first, * last;			//头指针，尾指针

};
#endif //CRICLINKNODE_H
#pragma once
