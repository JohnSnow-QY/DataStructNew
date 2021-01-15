#ifndef DBLIST_H
#define DBLIST_H
//双向链表（doubly linked list) 每个结点都两个链指针，不论是指向前驱方向还是向后继方向搜索，其时间开销都只有O(1)
//双向链表有一个附加头结点，由链表的头指针first指示，它的data域或者不放数据，或者存放一个特殊要求的数据，它的lLink 指向双向链表的尾结点（最后一个结点），它的rLink指向双向链表的首元结点（第一个结点）。链表的首元结点的左链指针lLink和尾结点的右链指针rLink都指向附加头结点。
//2、带附件头结点的双向循环链表的类定义
//
//        作为双向链表类的私有数据成员，在双向循环链表的类声明中封装了指向链表附加头结点的头指针first，同时采用链表结点类
//        程序2.24 双向循环链表的类定义
template<class T>
class DbNode {		//链表结点类定义
    T data;		//结点数据
    DbNode<T>* lLink, * rLink;	//前驱（左链），后继（右链）
    DbNode(DbNode<T>* left = nullptr, DbNode<T>* right = nullptr) :data(value), lLink(left), rLink(right) {}			//构造函数


};
template<class T>
class DbList :public LinearList<T> {			//链表类定义
public:
    DbList(T uniqueVal);		//构造函数，建立附加头结点
    ~DbList();					//
    int Length()const;			// 计算双链表的长度
    bool IsEmpty() {
        return first->rLink = first;

    }
    DbNode<T>* getHead()const {		//去附件头结点地址
        return first;
    }
    void setHead(DbNode<T>* ptr) {//设置附加头结点地址
        first = ptr;
    }

    DbNode<T>* Locate(int i, int d);	//在链表中定位序号为i(i>=0)的结点，d=0按前驱方向，d!=0 按后继方向

    DbNode<T>* Search(const T& x);		//在链表中延后继方向寻找等于给定值x的结点

    bool Insert(int i, const T& x, int d);		//在i结点后插入一个包含值x的新结点，d=0按前驱方向，d!= 0 按后继方向
    bool Remove(int i, T& x, int d);				//删除第i个结点，返回其值，d=0按前驱方向，d= 0 按后继方向


private:
    DbNode<T>* first;


}; 
#endif  DBLLIST_H
#pragma once
