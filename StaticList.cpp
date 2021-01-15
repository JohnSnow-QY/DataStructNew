//
// Created by DELL on 2020/11/1.
//

const int maxSize = 100;        //��̬�����С
template<class T>
class SLinkNode {
    T data;                     //�������
    int link;                   //�������ָ��
};

template<class T>
class StaticList {
private:
    SLinkNode<T> elem[maxSize];
    int avil;                   //��ǰ�ɷ���ռ��׵�ַ
public:
    void InitList();
    int Length();               //���㾲̬����ĳ���
    int Search(T x);            //�ھ�̬�����в��Ҿ��и���ֵ�Ľ��
    int Locate(int i);          //�ھ�̬�����в��ҵ�i�����
    bool Append(T x);           //�ھ�̬����ı�β׷��һ���½��
    bool Insert(int i, T x);     //�ھ�̬�����i����������½��
    bool Remove(int i);         //�ھ�̬�������ͷŵ�i�����
    bool IsEmpty();             //�жϱ�շ�
};
template<class T>
void StaticList<T> ::InitList() {
    //������ռ��ʼ��
    elem[0].link = -1;
    avil = 1;                   //��ǰ�ɷ���ռ��1��ʼ������ͷ���Ŀ�����
    for (int i = 1; i < maxSize - 1; i++) {
        elem[i].link = i + 1;             //�����������ӱ�
    }
    elem[maxSize - 1].link = -1;          //������β
}
template<class T>
int StaticList<T>::Length() {
    //���㾲̬����ĳ��ȣ�������β
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
    //�жϱ�շ�
    if (elem[0].link == -1) {
        return true;
    }
    return false;
}

template<class T>
int StaticList<T>::Search(T x) {
    //�ھ�̬�����в��Ҿ��и���ֵ�Ľ��
    int p = elem[0].link;               //ָ��pָ�������һ�����
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
        return -1;                          //����������
    }
    if (i == 0) {
        return 0;
    }
    int j = 1, p;
    p = elem[0].link;
    while (p != -1 && j < i) {               //ѭ�����ҵ�i�����
        p = elem[p].link;
        j++;
    }
    return p;
}

template<class T>
bool StaticList<T> ::Append(T x) {
    //�ھ�̬����ı�β׷��һ���½��
    if (avil == -1) {                         //������׷��ʧ��
        return false;
    }
    int q = avil;                           //������
    avil = elem[avil].link;
    elem[q].data = x;
    elem[q].link = -1;
    int p = 0;                              //���ұ�β
    while (elem[p].link != -1) {
        p = elem[p].link;
    }
    elem[p].link = q;                       //׷�� q���Ϊ�½�β
    return true;
}

template <class T>
bool StaticList<T>::Insert(int i, T x) {
    //�ھ�̬�����i������������½��
    int p = Locate(i);
    if (p == -1) {
        return false;
    }
    int q = avil;                            //������
    avil = elem[avil].link;                  //ˢ�µ�ǰ�ɷ�������׵�ַ
    elem[q].data = x;
    elem[q].link = elem[p].link;             //����
    elem[p].link = q;
    return true;
}
template<class T>
bool StaticList<T> ::Remove(int i) {
    //�Ӿ�̬�������ͷŵ� i�����
    int p = Locate(i - 1);
    if (p == -1) {                            //�Ҳ������
        return false;
    }
    int q = elem[p].link;                   //��i�Ž��
    elem[p].link = elem[q].link;
    elem[q].link = avil;                    //�ͷţ����õ���������
    avil = q;
    return true;
}

