//
// Created by DELL on 2020/11/1.
//

#ifndef CRICLINKNODE_H
#define CRICLINKNODE_H
//ѭ��������ඨ��
template <class T>
class CircLinkNode {
    //����ڵ��ඨ��
    T data;
    CircLinkNode<T>* link;
    CircLinkNode(CirclLinkNode<T> next = NULL) :link(next) {
    }
    CircLinkNode(T d, CircLinkNode<T>* next = NULL) :data(d), link(next) {}

};

template<class T>
class CirList : public LinearList<T> {
    //�����ඨ�� ��ͷ���
public:
    CircList(const T& x);	//
    CircList(CircList<T>& L);		//���ƹ��캯��
    ~CircList();
    int Length()const;		//����ѭ��������
    bool IsEmpty() {
        return first->link == first ? true : false;

    }
    CircListNode<T>* getHead()const;		//���ظ���ͷ����ַ
    void setHead(CirListNode<T>* p);		//���ø���ͷ����ַ
    CircListNode<T>* Search(T x);			//����������x��Ԫ��
    CircListNode<T>* Locate(int i);			//������i��Ԫ�ص�ֵ
    T* getData(int i);						//ȡ����i��Ԫ�ص�ֵ
    void setData(int i, T& x);				//��x�޸ĵ�i��Ԫ�ص�ֵ
    bool Insert(int i, T& x);				//�ڵ�i��Ԫ�غ����x
    bool Remove(int i, T& x);				//ɾ����i��Ԫ�أ�x���ظ�Ԫ�ص�ֵ
private:
    CircListNode<T>* first, * last;			//ͷָ�룬βָ��

};
#endif //CRICLINKNODE_H
#pragma once
