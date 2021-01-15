#ifndef DBLIST_H
#define DBLIST_H
//˫������doubly linked list) ÿ����㶼������ָ�룬������ָ��ǰ�����������̷�����������ʱ�俪����ֻ��O(1)
//˫��������һ������ͷ��㣬�������ͷָ��firstָʾ������data����߲������ݣ����ߴ��һ������Ҫ������ݣ�����lLink ָ��˫�������β��㣨���һ����㣩������rLinkָ��˫���������Ԫ��㣨��һ����㣩���������Ԫ��������ָ��lLink��β��������ָ��rLink��ָ�򸽼�ͷ��㡣
//2��������ͷ����˫��ѭ��������ඨ��
//
//        ��Ϊ˫���������˽�����ݳ�Ա����˫��ѭ��������������з�װ��ָ��������ͷ����ͷָ��first��ͬʱ������������
//        ����2.24 ˫��ѭ��������ඨ��
template<class T>
class DbNode {		//�������ඨ��
    T data;		//�������
    DbNode<T>* lLink, * rLink;	//ǰ��������������̣�������
    DbNode(DbNode<T>* left = nullptr, DbNode<T>* right = nullptr) :data(value), lLink(left), rLink(right) {}			//���캯��


};
template<class T>
class DbList :public LinearList<T> {			//�����ඨ��
public:
    DbList(T uniqueVal);		//���캯������������ͷ���
    ~DbList();					//
    int Length()const;			// ����˫����ĳ���
    bool IsEmpty() {
        return first->rLink = first;

    }
    DbNode<T>* getHead()const {		//ȥ����ͷ����ַ
        return first;
    }
    void setHead(DbNode<T>* ptr) {//���ø���ͷ����ַ
        first = ptr;
    }

    DbNode<T>* Locate(int i, int d);	//�������ж�λ���Ϊi(i>=0)�Ľ�㣬d=0��ǰ������d!=0 ����̷���

    DbNode<T>* Search(const T& x);		//���������Ӻ�̷���Ѱ�ҵ��ڸ���ֵx�Ľ��

    bool Insert(int i, const T& x, int d);		//��i�������һ������ֵx���½�㣬d=0��ǰ������d!= 0 ����̷���
    bool Remove(int i, T& x, int d);				//ɾ����i����㣬������ֵ��d=0��ǰ������d= 0 ����̷���


private:
    DbNode<T>* first;


}; 
#endif  DBLLIST_H
#pragma once
