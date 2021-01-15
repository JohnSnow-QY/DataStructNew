#include<iostream>
using namespace std;
template<class T>
class LinkedStack :public Stack<T> {
public:
    LinkedStack() :top(nullptr) {}                //���캯�����ÿ�ջ
    ~LinkedStack() {                             //��������
        makeEmpty();
    }
    void Push(const T& x);                      //��ջ
    bool Pop(T& x);                           //��ջ
    bool getTop(T& x)const;                     //��ȡջ��Ԫ��
    bool IsEmpty()const {
        return (top == nullptr) ? true : false;
    }
    int getSize()const ;                        //��ջ��Ԫ�ظ���
    void makeEmpty();                            //���ջ������
    bool IsFull()const;
    friend ostream& operator<<(ostream& os, SeqStack<T>& s);
private:
    LinkNode<T>* top;                                 //ջ��ָ�룬��ջ��ָ��

};
template<class T>
bool LinkedStack<T>::IsEmpty() const {
    if (top == nullptr) {
        return true;
    }
    return false;
}
template< class T>
void LinkedStack<T>::makeEmpty() {                      //���ɾȥ��ʽջ�е�Ԫ��ֱ��ջ��ָ��Ϊ��
    LinkNode<T>* p;
    while (top != nullptr) {
        p = top;
        top = top->link;
        delete p;                                 //���ɾ��
    }
}
template<class T>
void LinkedStack<T>::Push(const T& x) {
    //��Ԫ��x���뵽��ʽջ��ջ������ջͷ
    top = new LinkNode<T>(x, top);                //�����µĺ�x���
    assert(top != nullptr);                      //�����½��ʧ���˳�
}
template<class T>
bool LinkedStack<T>::Pop(T& x) {
    if (IsEmpty() == true) {                      //��ջ������ջ������
        return false;
    }
    LinkNode<T>* p = top;
    top = top->link;                            //ջ��ָ���Ƶ��µ�ջ��λ��
    x = p->data;                                //�ͷŽ�㣬�����˳�Ԫ�ص�ֵ
    delete p;
}
template<class T>
bool LinkedStack<T>::IsFull()const {
    return false;
}

template<class T>
bool LinkedStack<T>::getTop(T& x) const {
    //����ջ��Ԫ�ص�ֵ
    if (IsEmpty() == true) {
        return false;
    }
    x = top->data;
    return true;
}

template<class T>
int LinkedStack<T>::getSize()const {
    LinkNode<T>* p = top;
    int count = 0;
    while (p != nullptr) {
        p = p->link;
        count++;
    }
    return count;
}

template<class T>
ostream& operator<<(ostream& os, LinkedStack<T>& s) {
    //���ջ��Ԫ�ص����ز���<<
    os << "ջ��Ԫ�ظ���" << s.getSize() << endl;
    LinkNode<T>* p = top;
    while (p != nullptr) {
        os << ++i << ":" << p->data << endl;
    }
    return os;
}
//���ʹ��n����ʽջ����ͷ�����������·�ʽ�Ķ���
//        LinkNode<T> *s = new LinkNode<T>[n];
//�ڶ����ʽջ�������£�link����ҪһЩ���ӵĿռ䣬������۲����ܴ�