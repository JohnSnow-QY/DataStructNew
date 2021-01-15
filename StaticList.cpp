//
// Created by DELL on 2020/11/1.
//

const int maxSize = 100;        //静态链表大小
template<class T>
class SLinkNode {
    T data;                     //结点数据
    int link;                   //结点链接指针
};

template<class T>
class StaticList {
private:
    SLinkNode<T> elem[maxSize];
    int avil;                   //当前可分配空间首地址
public:
    void InitList();
    int Length();               //计算静态链表的长度
    int Search(T x);            //在静态链表中查找具有给定值的结点
    int Locate(int i);          //在静态链表中查找第i个结点
    bool Append(T x);           //在静态链表的表尾追加一个新结点
    bool Insert(int i, T x);     //在静态链表第i个结点后插入新结点
    bool Remove(int i);         //在静态链表中释放第i个结点
    bool IsEmpty();             //判断表空否？
};
template<class T>
void StaticList<T> ::InitList() {
    //将链表空间初始化
    elem[0].link = -1;
    avil = 1;                   //当前可分配空间从1开始建立表头结点的空链表
    for (int i = 1; i < maxSize - 1; i++) {
        elem[i].link = i + 1;             //构建空闲链接表
    }
    elem[maxSize - 1].link = -1;          //链表收尾
}
template<class T>
int StaticList<T>::Length() {
    //计算静态链表的长度，查找链尾
    int p = elem[0].link;
    int count = 0;
    while (p != -1) {
        p = elem[p].link;
        count++;
    }
    return count;
}

template<class T>
bool StaticList<T>::IsEmpty() {
    //判断表空否？
    if (elem[0].link == -1) {
        return true;
    }
    return false;
}

template<class T>
int StaticList<T>::Search(T x) {
    //在静态链表中查找具有给定值的结点
    int p = elem[0].link;               //指针p指向链表第一个结点
    while (p != -1) {
        if (elem[p].data == x) {
            break;
        }
        p = elem[p].link;
    }
    return p;
}

template<class T>
int StaticList<T>::Locate(int i) {
    if (i < 0) {
        return -1;                          //参数不合理
    }
    if (i == 0) {
        return 0;
    }
    int j = 1, p;
    p = elem[0].link;
    while (p != -1 && j < i) {               //循链查找第i个结点
        p = elem[p].link;
        j++;
    }
    return p;
}

template<class T>
bool StaticList<T> ::Append(T x) {
    //在静态链表的表尾追加一个新结点
    if (avil == -1) {                         //已满，追加失败
        return false;
    }
    int q = avil;                           //分配结点
    avil = elem[avil].link;
    elem[q].data = x;
    elem[q].link = -1;
    int p = 0;                              //查找表尾
    while (elem[p].link != -1) {
        p = elem[p].link;
    }
    elem[p].link = q;                       //追加 q结点为新结尾
    return true;
}

template <class T>
bool StaticList<T>::Insert(int i, T x) {
    //在静态链表第i个结点后面插入新结点
    int p = Locate(i);
    if (p == -1) {
        return false;
    }
    int q = avil;                            //分配结点
    avil = elem[avil].link;                  //刷新当前可分配结点的首地址
    elem[q].data = x;
    elem[q].link = elem[p].link;             //链入
    elem[p].link = q;
    return true;
}
template<class T>
bool StaticList<T> ::Remove(int i) {
    //从静态链表中释放第 i个结点
    int p = Locate(i - 1);
    if (p == -1) {                            //找不到结点
        return false;
    }
    int q = elem[p].link;                   //第i号结点
    elem[p].link = elem[q].link;
    elem[q].link = avil;                    //释放，重置到待分配结点
    avil = q;
    return true;
}

