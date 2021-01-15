//
// Created by QIYU on 2020/10/12.
//




#include <iostream>
//此次使用复合类的方法
//class List;
template<class T>
class LinkNode {// 节点类定义
//    friend class List;

private:
    T data; //数据元素域
    LinkNode<T>* link; //链指针域
    LinkNode(LinkNode<T>* ptr = nullptr) {
        link = ptr;
    }

    LinkNode(const T& item, LinkNode<T>* ptr = nullptr) {//初始化数据和指针成员
        data = item;
        link = ptr;
    }
};

template<class T>
class List {    //List 类定义
public:
    //链表公共操作

    List() {
        first = new LinkNode<T>;
    }

    List(const T& x) {
        first = new LinkNode<T>(x);
    }

    List(List<T>& list); //复制构造函数
    ~List() { makeEmpty(); }//析构函数
    void makeEmpty(); //将链表置位空表
    int Length() const;

    LinkNode<T>* getHead() const { return first; }

    void setHead(LinkNode<T>* p) { first = p; }

    LinkNode<T>* Search(T x);//搜索含数据x的元素
    LinkNode<T>* Locate(int i);//取出第i个元素的值
    T* getData(int i);

    void setData(int i, T& x);

    bool Insert(int i, T& x);

    bool Remove(int i, T& x);

    bool IsEmpty() const {
        return first->link == nullptr ? true : false;
    }


    //   bool IsFull()const {return false};//判断是否满
    void Sort();//排序
    void input();//输入
    void output();//输出
    List<T>& operator=(List<T>& list);//重构函数，赋值

private:
    LinkNode<T>* first;//链表头指针
};

//List 类的成员函数的实现
template<class T>
List<T>::List(List<T>& list) {
    //复制构造函数
    T value;
    LinkNode<T>* srcptr = list.getHead();//被复制表的附加头结点地址
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
    //将链表致为空表
    LinkNode<T>* q;
    while (first->link != nullptr) {//当链不为空时，删除链中所有结点
        q = first->link;
        first->link = q->link;//保存被删结点，从链上摘下该节点
        delete (q);//删除，只保留一个表头结点

    }
}

template<class T>

int List<T>::Length() const {
    //计算带头结点的单链表的长度
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
    //在表中搜索数据x的结点，搜索成功时函数返回该节点地址；否则返回NULL值
    LinkNode<T>* current = first->link;
    while (current != nullptr) {//循链找含 x的结点
        if (current->data == x) {
            break;
        }
        else {
            current = current->link;
        }
    }
    return current;//为 nullptr 则未找到
}

//20201013  三颗星
template<class T>
LinkNode<T>* List<T>::Locate(int i) {
    //排除值太大的情况
    //定位函数，返回表中第i个元素的地址。若i<0或i超出表中结点个数，则返回nullptr
    if (i < 0) {
        return nullptr;
    }
    LinkNode<T>* current = first;
    int k = 0;
    while (current != nullptr && k < i) {
        current = current->link;
        k++;
    }
    return current;//返回第i个结点地址，若返回nullptr,表示i值太大


}

template<class T>
T* List<T>::getData(int i) {
    //取出链表中第i个元素的值，返回地址
    if (i <= 0) {
        return nullptr;//i值太小
    }
    LinkNode<T>* current = Locate(i);
    if (current == nullptr) {
        return nullptr;//i值太大
    }
    else {
        return &current->data;
    }

}

template<class T>
void List<T>::setData(int i, T& x) {
    //给链表中第i个元素赋值x
    if (i <= 0) {
        return;//i值太小
    }
    LinkNode<T>* current = Locate(i);
    if (current == nullptr) {
        return;//i值太大
    }
    else {
        current->data = x;
    }
}
//20201013 三星
template <class T>
bool List<T> ::Insert(int i, T& x) {
    //将新元素 x插入在链表中i个结点之后
    LinkNode<T>* current = Locate(i);
    if (current == nullptr) {
        return false; // i值太大，插入不成功
    }
    LinkNode<T>* newNode = new LinkNode<T>(x);
    if (newNode == nullptr) { //代码显示该情况始终位false，以后可忽略
        std::cerr << "存储分配错误" << std::endl;
        exit(1);
    }
    newNode->link = current->link;//链接在current之后
    current->link = newNode;
}

//20201013 三星
template <class T>
bool List<T> ::Remove(int i, T& x) {
    //将链表中的第i个元素删去，通过引用型参数x返回该元素的值
    LinkNode<T>* current = Locate(i - 1);
    if (current == nullptr || current->link == nullptr) {
        return false;//删除不成功
    }
    LinkNode<T>* del = current->link;//重新拉链，将别删结点从链中摘下
    current->link = del->link;
    x = del->data;
    delete(del);

}
template <class T>
void List<T> ::output() {//基本用不上
    //单链表的输出函数：将单链表中所有数据按逻辑顺序输出

        //单链表的输出函数
    LinkNode<T>* current = first->link;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->link;
    }
}
//this 指针的补充说明
/*
 * 当调用一个成员函数是，有一个指向请求这个调用的兑现的指针作为一该参数将自动地传给这个函数
 * 这个指针叫做this
 */
template <class T>
List<T>& List<T> ::operator=(List<T>& list) {
    //重载函数，赋值操作，形式如A = B,其中A是调用此操作的List对象
    //B是与参数表中的引用型参数L结合的实参
    T value;
    LinkNode<T>* srcptr = list.getHead();//被复制表的附加头结点地址
    LinkNode<T>* destptr = first = new LinkNode<T>;
    while (srcptr->link != nullptr) {//逐个结点复制
        value = srcptr->link->data;
        destptr->link = new LinkNode<T>(value);
        srcptr = srcptr->link;
        destptr = destptr->link;
    }
    destptr->link = nullptr;
    return *this;
}

