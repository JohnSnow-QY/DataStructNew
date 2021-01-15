
//
// Created by DELL on 2020/11/1.
//

#ifndef STATICLIST_H
#define STATICLIST_H
//静态链表
//        如果为数组中每个元素附加一个链接指针，就形成静态链表结构。它不允许我们改变这些元素的逻辑顺序。由于它是利用数组定义的，在整个运算过程中存储空间的大小
//        不会变化，因此称为静态链表。
//静态链表的没一个结点又两个数据成员构成：data域存储数据，link域存放链接指针，所有结点形成一个结点数组，也可以带有附加头结点。
//A[0].link 可以找到它的下一个结点位置，当找到某一个结点A[k].link = -1,则链表终止。（由于A[0]有效，所以空指针NULL用 -1表示）
//程序2.32 静态链表定义
const int maxSize = 100;        //静态链表大小
template<class T>
class SLinkNode {
    T data;                     //结点数据
    int link;                   //结点链接指针
};

template<class T>
class StaticList {
private:
    SLinkNode<T> elem[maxSize];
    int avil;                   //当前可分配空间首地址
public:
    void InitList();
    int Length();               //计算静态链表的长度
    int Search(T x);            //在静态链表中查找具有给定值的结点
    int Locate(int i);          //在静态链表中查找第i个结点
    bool Append(T x);           //在静态链表的表尾追加一个新结点
    bool Insert(int i, T x);     //在静态链表第i个结点后插入新结点
    bool Remove(int i);         //在静态链表中释放第i个结点
    bool IsEmpty();             //判断表空否？
};
#endif STATICLIST_H
#pragma once
