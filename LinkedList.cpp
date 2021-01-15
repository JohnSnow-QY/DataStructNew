//
// Created by QIYU on 2020/10/12.
//




#include <iostream>
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
    List<T>& operator=(List<T>& list);//�ع���������ֵ

private:
    LinkNode<T>* first;//����ͷָ��
};

//List ��ĳ�Ա������ʵ��
template<class T>
List<T>::List(List<T>& list) {
    //���ƹ��캯��
    T value;
    LinkNode<T>* srcptr = list.getHead();//�����Ʊ�ĸ���ͷ����ַ
    LinkNode<T>* destptr = first = new LinkNode<T>;
    while (srcptr->link != nullptr) {
        value = srcptr->link->data;
        destptr->link = new LinkNode<T>(value);
        destptr = destptr->link;
        srcptr = srcptr->link;
    }
    destptr->link = nullptr;
}

template<class T>
void List<T>::makeEmpty() {
    //��������Ϊ�ձ�
    LinkNode<T>* q;
    while (first->link != nullptr) {//������Ϊ��ʱ��ɾ���������н��
        q = first->link;
        first->link = q->link;//���汻ɾ��㣬������ժ�¸ýڵ�
        delete (q);//ɾ����ֻ����һ����ͷ���

    }
}

template<class T>

int List<T>::Length() const {
    //�����ͷ���ĵ�����ĳ���
    LinkNode<T>* p = first->link;
    int count = 0;
    while (p != nullptr) {
        p = p->link;
        count++;
    }
    return count;
}

template<class T>
LinkNode<T>* List<T>::Search(T x) {
    //�ڱ�����������x�Ľ�㣬�����ɹ�ʱ�������ظýڵ��ַ�����򷵻�NULLֵ
    LinkNode<T>* current = first->link;
    while (current != nullptr) {//ѭ���Һ� x�Ľ��
        if (current->data == x) {
            break;
        }
        else {
            current = current->link;
        }
    }
    return current;//Ϊ nullptr ��δ�ҵ�
}

//20201013  ������
template<class T>
LinkNode<T>* List<T>::Locate(int i) {
    //�ų�ֵ̫������
    //��λ���������ر��е�i��Ԫ�صĵ�ַ����i<0��i�������н��������򷵻�nullptr
    if (i < 0) {
        return nullptr;
    }
    LinkNode<T>* current = first;
    int k = 0;
    while (current != nullptr && k < i) {
        current = current->link;
        k++;
    }
    return current;//���ص�i������ַ��������nullptr,��ʾiֵ̫��


}

template<class T>
T* List<T>::getData(int i) {
    //ȡ�������е�i��Ԫ�ص�ֵ�����ص�ַ
    if (i <= 0) {
        return nullptr;//iֵ̫С
    }
    LinkNode<T>* current = Locate(i);
    if (current == nullptr) {
        return nullptr;//iֵ̫��
    }
    else {
        return &current->data;
    }

}

template<class T>
void List<T>::setData(int i, T& x) {
    //�������е�i��Ԫ�ظ�ֵx
    if (i <= 0) {
        return;//iֵ̫С
    }
    LinkNode<T>* current = Locate(i);
    if (current == nullptr) {
        return;//iֵ̫��
    }
    else {
        current->data = x;
    }
}
//20201013 ����
template <class T>
bool List<T> ::Insert(int i, T& x) {
    //����Ԫ�� x������������i�����֮��
    LinkNode<T>* current = Locate(i);
    if (current == nullptr) {
        return false; // iֵ̫�󣬲��벻�ɹ�
    }
    LinkNode<T>* newNode = new LinkNode<T>(x);
    if (newNode == nullptr) { //������ʾ�����ʼ��λfalse���Ժ�ɺ���
        std::cerr << "�洢�������" << std::endl;
        exit(1);
    }
    newNode->link = current->link;//������current֮��
    current->link = newNode;
}

//20201013 ����
template <class T>
bool List<T> ::Remove(int i, T& x) {
    //�������еĵ�i��Ԫ��ɾȥ��ͨ�������Ͳ���x���ظ�Ԫ�ص�ֵ
    LinkNode<T>* current = Locate(i - 1);
    if (current == nullptr || current->link == nullptr) {
        return false;//ɾ�����ɹ�
    }
    LinkNode<T>* del = current->link;//��������������ɾ��������ժ��
    current->link = del->link;
    x = del->data;
    delete(del);

}
template <class T>
void List<T> ::output() {//�����ò���
    //���������������������������������ݰ��߼�˳�����

        //��������������
    LinkNode<T>* current = first->link;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->link;
    }
}
//this ָ��Ĳ���˵��
/*
 * ������һ����Ա�����ǣ���һ��ָ������������õĶ��ֵ�ָ����Ϊһ�ò������Զ��ش����������
 * ���ָ�����this
 */
template <class T>
List<T>& List<T> ::operator=(List<T>& list) {
    //���غ�������ֵ��������ʽ��A = B,����A�ǵ��ô˲�����List����
    //B����������е������Ͳ���L��ϵ�ʵ��
    T value;
    LinkNode<T>* srcptr = list.getHead();//�����Ʊ�ĸ���ͷ����ַ
    LinkNode<T>* destptr = first = new LinkNode<T>;
    while (srcptr->link != nullptr) {//�����㸴��
        value = srcptr->link->data;
        destptr->link = new LinkNode<T>(value);
        srcptr = srcptr->link;
        destptr = destptr->link;
    }
    destptr->link = nullptr;
    return *this;
}

