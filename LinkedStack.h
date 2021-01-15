#pragma once
//
// Created by DELL on 2020/11/1.
//

#ifndef LinkedStack_h
#define LinkedStack_h
//3.1.3 ��ʽջ
//        ��ʽջʱ���Ա�����Ӵ洢��ʾ��������ʽջ����ʾһ��ջ�����ڽ��Ĳ�����ɾ�����ڳ�����ͬʱʹ�ö��ջ������£������ӱ�ʾ�����ܹ����Ч�ʣ������Դﵽ
//        ����洢�ռ��Ŀ�ġ�
//��ʽջ��ջ��������ı�ͷ����ˣ��½��Ĳ����ɾ����������ı�ͷ����ջ�����С�ʹ�õڶ��µĵ��������ඨ��

//����3.6 ��ʽջ���ඨ��



#include "stack.h"
template<class T>
class LinkedStack :public Stack<T> {
public:
    LinkedStack() :top(nullptr);               //���캯�����ÿ�ջ
    ~LinkedStack();                            //��������
      
    
    void Push(const T& x);                      //��ջ
    bool Pop(T& x);                           //��ջ
    bool getTop(T& x)const;                     //��ȡջ��Ԫ��
    bool IsEmpty()const;
       
    
    int getSize()const ;                        //��ջ��Ԫ�ظ���
    void makeEmpty();                            //���ջ������
    bool IsFull()const;
    friend std::ostream& operator<<(ostream& os, SeqStack<T>& s);
private:
    LinkNode<T>* top;                                 //ջ��ָ�룬��ջ��ָ��

};

#endif 
