//
// Created by DELL on 2020/11/1.
//


//3.1.2 ˳��ջ
//        ջ�ĳ����������������ֵ��͵Ĵ洢��ʾ����������Ĵ洢��ʾ�ͻ�������Ĵ洢��ʾ��
//��������Ĵ洢��ʾʵ�ֵ�ջ��Ϊ˳��ջ����������Ĵ洢��ʾʵ�ֵ�ջ��Ϊ��ʽջ��
//˳��ջ���Բ���˳�����Ϊ��洢��ʾ��Ϊ�˿�����˳��ջ����������˳��������Ĵ洢�ռ䡣
//����3.2  ˳��ջ���ඨ��
#include <assert.h>
#include<iostream>
#include "stack.h"
using namespace std;
const int statckIncreament = 20;        //ջ�������չ�ռ������
template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);              //����һ����ջ
    ~SeqStack() {                        //��������
        delete[] elements;
    }

    void Push(const T& x);              //���IsEmpty(),��ִ����ջ������false;�����˵�λ��ջ����Ԫ�أ�����true;

    bool getTop(T& x)const;                //��� IsEmpty(),�򷵻�false,���򷵻�true,��ͨ�������Ͳ���x�õ�ջ��Ԫ�ص�ֵ
    bool IsEmpty()const {               //���ջ��Ԫ��
        return(top == -1) ? true : false;
    }
    bool IsFull()const {                //���ջ��Ԫ�ظ�ʽ����maxSzie,�򷵻�true,���򷵻�false
        return (top == maxSize - 1) ? true : false;
    }
    int makeEmpty() {                    //���ջ������
        top = -1;
    }
    bool Pop(T& x);
    int getSize()const {                //����ջ��Ԫ�ص�ջ����
        return top + 1;
    }
    friend ostream& operator<<(ostream& os, SeqStack<T>& s) {}
    //���ջ��Ԫ�ص����ز���<<
private:
    T* elements;                    //���ջ��Ԫ�ص�ջ����
    int top;                        //ջ��ָ��
    int maxSize;                    //
    void overflowProcess();         //ջ���������


};
//        ջ�Ĺ��캯�������ڽ���ջ�Ķ���ʱΪջ�����ݳ�Ա����ֵ�������ж�̬������ջ��������ߴ�ΪmaxSize���ɺ�������
//        sz���������� top = -1,��ջΪ�ա����������ʵ���У�ʹ����һ�ֶ��ԣ�Assert)���ƣ�����C++�ṩ��һ�ֹ��ܣ����������assert����
//        ���и������������㣬�����ִ�к�������䣻�����������ֹ�����ִ�С�
//����3.3 ˳��ջ�Ĺ��캯��
template<class T>
SeqStack<T>::SeqStack(int sz) {
    //����һ�����ߴ�Ϊsz�Ŀ�ջ�������䲻�ɹ��������
    elements = new T[sz];              //����ջ������ռ�
    assert(elements != nullptr);             //���ԣ���̬�洢����ɹ����

}
//topָʾ�����������Ԫ�صĴ洢λ�á���ʵ�ֽ�ջ����ʱ��Ӧ���ж��Ƿ�������ջ��������д��λ��ΪmaxSize-1,���ջ��ָ��top == maxSize-1,��
//        ˵��ջ������λ�þ���ʹ�ã�ջ��������ʱ������Ԫ�ؽ�ջ�����������������ת���������
//���top < maxSize-1,������ջ��ָ���1��ָ����ǰ�ɼ�����Ԫ�ص�λ�ã��ٰ�ջ��ָ����ָλ�ý���Ԫ�ز��롣����²����Ԫ�ؽ���Ϊ�µ�ջ��Ԫ�ء�
//��һ���������������ջ�ף��������ջ�Ƿ����ǿ�ջ���� top == -1,����ջ������ִ��ջ�մ���ջ�մ���һ�㲻�ǳ���������ʹ�����ջ���㷨��������Ҫִ�еĴ���
//����ǰ top >= 0,��ɽ�ջ��ָ���1������ջ���˻ص���ջ��λ�á�
//����3.4 ջ�Ĺ��캯����ʵ��
template<class T>
void SeqStack<T>::overflowProcess() {
    //˽�к���������ջ�Ĵ洢�ռ�
    T* newArray = new T[maxSize + stackIncreament];
    for (int i = 0; i <= top; i++) {
        newArray[i] = elements[i]
    }
    maxSize = maxSize + stackIncreament;
    delete[]elements;
    elements = newArray;
}
template<class T>
void SeqStack<T> ::Push(const T& x) {
    //������������ջ��������Ԫ�ز��뵽��ջ��ջ���������������
    if (IsFull() == true) {
        overflowProcess();                  //ջ�����������
    }
    elements[++top] = x;                   //ջ��ָ���ȼ�1���ٽ�ջ
}
template<class T>
bool SeqStack<T> ::Pop(T& x) {
    //������������ջ�����������ظ�ջջ��Ԫ�ص�ֵ��Ȼ��ջ��ָ����1
    if (IsEmpty() == true) { return false };        //�ж�ջ�շ���ջ����������
    x = elements[top--];                        //ջ��ָ����1
    return true;                                //��ջ�ɹ�
}

template<class T>
bool SeqStack<T>::getTop(T& x)const {
    //������������ջ�����������ظ�ջջ��Ԫ�صĵ�ַ
    if (IsEmpty() == true) {
        return false;                           //��ջ�շ���ջ����������
    }
    x = elements[top];                          //����ջ��Ԫ�ص�ֵ
    return true;
}
template<class T>
ostream& operator<< (ostream& os, SeqStack<T>& s) {
    //���ջ��Ԫ�ص����غ��� <<
    os << "top = " << s.top << endl;                 //���ջ��λ��
    for (int i = 0; i <= s.top; i++) {
        os << i << ":" << s.elements[i] << endl;
    }
    return os;
}
//���������ջ����ͬ����С�Ŀռ䣬������ʵ�������У��е�ջ���͵ĺܿ죬�ܿ�Ͳ������������������ջ���ܴ�ʱ���������еĿռ䡣��ʱ��
//�ͱ��������ջ�Ŀռ䣬��ֹջ�������(˫ջ������Ϊ˳��ջ����ʽջ��һ�����ɣ�����ʵ��Ҫ��
//���磬����ͬʱ��Ҫ����ջʱ�����ǿ��Զ���һ���㹻��ջ�ռ䡣�ÿռ�����˷ֱ���Ϊ����ջ��ջ�ף���b[0](= -1) ��b[1](=maxSize)ָʾ��
//������ջ��ջ��t[0]��t[1]�����м���չ��ֱ������ջ��ջ������������Ϊ�����������
//��˫ջ�������£���ջ�ĳ�ʼ�����Ϊt[0] = b[0] = -1,t[1] = b[1] = maxSize��ջ��������Ϊt[0] + 1 = t[1]��
//��ջ�յ�����Ϊt[0] = b[0] �� t[1] = b[1],��ʱջ��ָ���˵�ջ�ס�
//
//����3.5 ˫ջ�Ĳ����ɾ��������ʵ��
//        n(n>2) ��ջ������������ͬ�����ö��ջ����ջ�ռ��˳��洢��ʾ��ʽ������ʮ�ָ��ӣ��ڲ�����Ԫ�ص��ƶ����ܴ�ʱ����۽ϸߡ��ر��ǵ������洢�ռ�
//        ��������ʱ�������������ء�����ķ������ǲ������ӷ�ʽ��Ϊջ�Ĵ洢��ʾ��

