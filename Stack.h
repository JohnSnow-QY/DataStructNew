#pragma once
//
// Created by lixy on 2020/11/1.
//

#ifndef STRACK_H
#define STRACK_H
const int maxSize = 50;

template<class T>
class Stack {
public:
    Stack() {};          //���캯��
    virtual void Push(const T& x) = 0;          //���캯��
    virtual bool Pop(T& x) = 0;                 //��Ԫ�ؽ�ջ
    virtual bool getTop(T& x)const = 0;         //��ȡջ��Ԫ�أ���x����
    virtual bool IsEmpty()const = 0;            //�ж�ջ�շ�
    virtual bool IsFull()const = 0;             //�ж�ջ����
    virtual int getSize()const = 0;             //����ջ��Ԫ�ظ���
};
#endif 
