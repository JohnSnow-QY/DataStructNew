
#ifndef SEQSTACK_H
#define SEQSTACK_H
//3.1.2 ˳��ջ
//        ջ�ĳ����������������ֵ��͵Ĵ洢��ʾ����������Ĵ洢��ʾ�ͻ�������Ĵ洢��ʾ��
//��������Ĵ洢��ʾʵ�ֵ�ջ��Ϊ˳��ջ����������Ĵ洢��ʾʵ�ֵ�ջ��Ϊ��ʽջ��
//˳��ջ���Բ���˳�����Ϊ��洢��ʾ��Ϊ�˿�����˳��ջ����������˳��������Ĵ洢�ռ䡣
//����3.2  ˳��ջ���ඨ��
#include <assert.h>

#include "stack.h"
const int statckIncreament = 20;        //ջ�������չ�ռ������
template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);              //����һ����ջ
    ~SeqStack() {                        //��������
       
    }

    void Push(const T& x);              //���IsEmpty(),��ִ����ջ������false;�����˵�λ��ջ����Ԫ�أ�����true;

    bool getTop(T& x)const ;                //��� IsEmpty(),�򷵻�false,���򷵻�true,��ͨ�������Ͳ���x�õ�ջ��Ԫ�ص�ֵ
    bool IsEmpty()const;            //���ջ��Ԫ��
    
    bool IsFull()const;               //���ջ��Ԫ�ظ�ʽ����maxSzie,�򷵻�true,���򷵻�false
        
    
    int makeEmpty();                  //���ջ������
       
    
    bool Pop(T& x);
    int getSize()const;              //����ջ��Ԫ�ص�ջ����
      
    
    friend std::ostream& operator<<(std::ostream& os, SeqStack<T>& s) {}
    //���ջ��Ԫ�ص����ز���<<
private:
    T* elements;                    //���ջ��Ԫ�ص�ջ����
    int top;                        //ջ��ָ��
    int maxSize;                    //
    void overflowProcess();         //ջ���������


};
#endif SEQSTACK_H
#pragma once