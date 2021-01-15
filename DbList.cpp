//
// Created by DELL on 2020/11/1.
//


//双向链表（doubly linked list) 每个结点都两个链指针，不论是指向前驱方向还是向后继方向搜索，其时间开销都只有O(1)
//双向链表有一个附加头结点，由链表的头指针first指示，它的data域或者不放数据，或者存放一个特殊要求的数据，它的lLink 指向双向链表的尾结点（最后一个结点），它的rLink指向双向链表的首元结点（第一个结点）。链表的首元结点的左链指针lLink和尾结点的右链指针rLink都指向附加头结点。
//2、带附件头结点的双向循环链表的类定义
//
//        作为双向链表类的私有数据成员，在双向循环链表的类声明中封装了指向链表附加头结点的头指针first，同时采用链表结点类
//        程序2.24 双向循环链表的类定义
template<class T>
class DbNode {		//链表结点类定义
    T data;		//结点数据
    DbNode<T>* lLink, * rLink;	//前驱（左链），后继（右链）
    DbNode(DbNode<T>* left = nullptr, DbNode<T>* right = nullptr) :data(value), lLink(left), rLink(right) {}			//构造函数


};
template<class T>
class DbList :public LinearList<T> {			//链表类定义
public:
    DbList(T uniqueVal);		//构造函数，建立附加头结点
    ~DbList();					//
    int Length()const;			// 计算双链表的长度
    bool IsEmpty() {
        return first->rLink = first;

    }
    DbNode<T>* getHead()const {		//去附件头结点地址
        return first;
    }
    void setHead(DbNode<T>* ptr) {//设置附加头结点地址
        first = ptr;
    }

    DbNode<T>* Locate(int i, int d);	//在链表中定位序号为i(i>=0)的结点，d=0按前驱方向，d!=0 按后继方向

    DbNode<T>* Search(const T& x);		//在链表中延后继方向寻找等于给定值x的结点

    bool Insert(int i, const T& x, int d);		//在i结点后插入一个包含值x的新结点，d=0按前驱方向，d!= 0 按后继方向
    bool Remove(int i, T& x, int d);				//删除第i个结点，返回其值，d=0按前驱方向，d= 0 按后继方向


private:
    DbNode<T>* first;


};

template<class T>
DbList<T> ::DbList(T uniqueVal) {
    //构造函数，建立双向循环链表的附加头结点，它包含一个用于某些特定情况的值
    first = new DblList<T>(uniqueVal);
    if (first == nullptr) {
        std::cout << "存储分配出错";
        exit(1);
    }
    first->rLink = first->lLink = first;

}
template<class T>
int DbList<T> ::Length()const {
    //计算带附加头结点的双向循环链表的长度，通过函数返回
    DblList<T>* current = first->rLink;
    int count = 0;
    while (count != first) {
        count++;
        current = current->rLink;
    }
    return count;
}
//3、双向循环链表的搜索、插入和删除算法
//        如果链中所有结点都监测完，但未找到数据域的值与给定值相等的结点，此时检测指针current延循环链表转了一圈又回到头结点，函数返回NULL，表示搜索失败
//        程序2.25 搜索运算Search的实现
template<class T>
DbNode<T>* DbList<T>::Search(const T& x) {
    //在带附件头结点的双向循环链表中寻找值等于x的结点，若找到，则函数返回该结点地址，否则返回NULL
    DbNode<T>* current = first->rLink;
    while (current != first && x != current->data) {
        current = current->rLink;
    }
    if (current != first) {
        return current;			//搜索成功
    }
    return nullptr;				//搜索失败
}
//双向循环链表的定位运算Locate要区分是哪个方向上的第i个结点。为此，在函数参数表中要增加一个形参d用以明确指明搜索方向。没一个方向运算都是类似的
//程序2.26 定位运算 Locate的实现
template<class T>
DbNode<T>* DbList<T>::Locate(int i, int d) {
    //在带附加头结点的双向循环链表中按d所指的方向寻找第i个结点的地址。如d=0,在前驱方向寻找第i个结点，若d != 0,在后继方向上寻找第i个结点
    if (first->rLink == first || i == 0) {
        return first;
    }
    DblNode<T>* current;
    if (d == 0) {
        current = first->lLink;		//搜索方向
    }
    if (d == 0) {
        current = first->lLink;		//搜索方向
    }
    else {
        current = first->rLink;
    }
    for (int j = 1; j < i; j++) {		//逐个结点检测
        if (current == first) {	//链太短退出搜索
            break;
        }
        else if (d == 0) {
            current = current->lLink;
        }
        else {
            current = current->rLink;
        }
    }
    if (current != first) { return current; }
    return nullptr；
}

//双向循环链表Insert算法是根据给定值x建立一个新结点，并按照d所指方向插入到双向循环链表第i个结点之后。d = 0,在前驱方向查找第i个结点；d!=0 ,在后继方向查找第i个结点
//        分为两种情况：在空表情形，新结点成为链表的第一个结点。如果链表非空，必须寻找到d方向的第i个结点，再进行插入。在插入是，需要在两个环形链中插入，一个是前驱指针lLink链，一个是后继指针链，为此至少需要修改4个指针。
//程序2.27 插入算法的实现
template<class T>
bool DbList<T> ::Insert(int i, const T& x, int d) {
    //建立一个包含有值 x的新结点，并将其按 d指定的方向插入到第i个结点之后
    DblNode<T>* current = Locate(i, d);		//查找第i个结点
    if (current == nullptr) return false;	//i不合理，插入失败
    DblNode<T>* newNode = new DblNode<T>(x);
    if (d == 0) { 		//从前驱方向插入
        newNode->lLink = current->lLink;
        newNode->rLink = current;
        current->lLink->rLink = newNode;
        current->lLink = newNode
    }
    else {				//从后继方向插入
        newNode->rLink = current->rLink;
        newNode->lLink = current;
        current->rLink->lLink = newNode;
        current->rLink = newNode;

    }
    return true;

}
//双向循环链表的Remove运算是按照d所指方向删除第 i个结点，删除过程分三步：第一步先寻找d所指方向的第i个结点。d=0,在前驱方向查找第i个结点；d!=0,在后继方向查找第i个结点。第二步把第i个结点从链中分离出来，为了从两个链上摘下被删结点，必须修改前驱结点的后继指针和后继结点的前驱指针。第三步再把被删结点释放。
//程序：2.28 删除运算的实现
template<class T>
bool DbList<T>::Remove(int i, T& x, int d) {
    //在带附加头结点的双向循环链表中按照 d 所指方向删除第i个结点
    DbNode<T>* current = Locate(i, d);		//查找第i个结点
    if (current == nullptr) {
        return false;						//i不合理，删除失败
    }
    current->rLink->lLink = current->lList;			//从lLink链中摘下
    current0 > lLink->rLink = current->rList:			//从rLink链中摘下
    x = current->data;
    delete current;
    return true;
}

