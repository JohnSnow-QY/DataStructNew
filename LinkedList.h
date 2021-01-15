#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <d2d1helper.h>

//�˴�ʹ�ø�����ķ���
//class List;
template<class T>
class LinkNode {// �ڵ��ඨ��
//    friend class List;

private:
    T data; //����Ԫ����
    LinkNode<T>* link; //��ָ����
    LinkNode(LinkNode<T>* ptr = nullptr) {
        link = ptr;
    }

    LinkNode(const T& item, LinkNode<T>* ptr = nullptr) {//��ʼ�����ݺ�ָ���Ա
        data = item;
        link = ptr;
    }
};

template<class T>
class List {    //List �ඨ��
public:
    //����������

    List() {
        first = new LinkNode<T>;
    }

    List(const T& x) {
        first = new LinkNode<T>(x);
    }

    List(List<T>& list); //���ƹ��캯��
    ~List() { makeEmpty(); }//��������
    void makeEmpty(); //��������λ�ձ�
    int Length() const;

    LinkNode<T>* getHead() const { return first; }

    void setHead(LinkNode<T>* p) { first = p; }

    LinkNode<T>* Search(T x);//����������x��Ԫ��
    LinkNode<T>* Locate(int i);//ȡ����i��Ԫ�ص�ֵ
    T* getData(int i);

    void setData(int i, T& x);

    bool Insert(int i, T& x);

    bool Remove(int i, T& x);

    bool IsEmpty() const {
        return first->link == nullptr ? true : false;
    }


    //   bool IsFull()const {return false};//�ж��Ƿ���
    void Sort();//����
    void input();//����
    void output();//���
    List<T>& std::operator=(List<T>& list);//�ع���������ֵ

private:
    LinkNode<T>* first;//����ͷָ��
};

#endif //LINKEDLIST_H
#pragma once
