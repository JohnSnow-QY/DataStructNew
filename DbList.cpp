//
// Created by DELL on 2020/11/1.
//


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

template<class T>
DbList<T> ::DbList(T uniqueVal) {
    //���캯��������˫��ѭ������ĸ���ͷ��㣬������һ������ĳЩ�ض������ֵ
    first = new DblList<T>(uniqueVal);
    if (first == nullptr) {
        std::cout << "�洢�������";
        exit(1);
    }
    first->rLink = first->lLink = first;

}
template<class T>
int DbList<T> ::Length()const {
    //���������ͷ����˫��ѭ������ĳ��ȣ�ͨ����������
    DblList<T>* current = first->rLink;
    int count = 0;
    while (count != first) {
        count++;
        current = current->rLink;
    }
    return count;
}
//3��˫��ѭ������������������ɾ���㷨
//        ����������н�㶼����꣬��δ�ҵ��������ֵ�����ֵ��ȵĽ�㣬��ʱ���ָ��current��ѭ������ת��һȦ�ֻص�ͷ��㣬��������NULL����ʾ����ʧ��
//        ����2.25 ��������Search��ʵ��
template<class T>
DbNode<T>* DbList<T>::Search(const T& x) {
    //�ڴ�����ͷ����˫��ѭ��������Ѱ��ֵ����x�Ľ�㣬���ҵ����������ظý���ַ�����򷵻�NULL
    DbNode<T>* current = first->rLink;
    while (current != first && x != current->data) {
        current = current->rLink;
    }
    if (current != first) {
        return current;			//�����ɹ�
    }
    return nullptr;				//����ʧ��
}
//˫��ѭ������Ķ�λ����LocateҪ�������ĸ������ϵĵ�i����㡣Ϊ�ˣ��ں�����������Ҫ����һ���β�d������ȷָ����������ûһ���������㶼�����Ƶ�
//����2.26 ��λ���� Locate��ʵ��
template<class T>
DbNode<T>* DbList<T>::Locate(int i, int d) {
    //�ڴ�����ͷ����˫��ѭ�������а�d��ָ�ķ���Ѱ�ҵ�i�����ĵ�ַ����d=0,��ǰ������Ѱ�ҵ�i����㣬��d != 0,�ں�̷�����Ѱ�ҵ�i�����
    if (first->rLink == first || i == 0) {
        return first;
    }
    DblNode<T>* current;
    if (d == 0) {
        current = first->lLink;		//��������
    }
    if (d == 0) {
        current = first->lLink;		//��������
    }
    else {
        current = first->rLink;
    }
    for (int j = 1; j < i; j++) {		//��������
        if (current == first) {	//��̫���˳�����
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
    return nullptr��
}

//˫��ѭ������Insert�㷨�Ǹ��ݸ���ֵx����һ���½�㣬������d��ָ������뵽˫��ѭ�������i�����֮��d = 0,��ǰ��������ҵ�i����㣻d!=0 ,�ں�̷�����ҵ�i�����
//        ��Ϊ����������ڿձ����Σ��½���Ϊ����ĵ�һ����㡣�������ǿգ�����Ѱ�ҵ�d����ĵ�i����㣬�ٽ��в��롣�ڲ����ǣ���Ҫ�������������в��룬һ����ǰ��ָ��lLink����һ���Ǻ��ָ������Ϊ��������Ҫ�޸�4��ָ�롣
//����2.27 �����㷨��ʵ��
template<class T>
bool DbList<T> ::Insert(int i, const T& x, int d) {
    //����һ��������ֵ x���½�㣬�����䰴 dָ���ķ�����뵽��i�����֮��
    DblNode<T>* current = Locate(i, d);		//���ҵ�i�����
    if (current == nullptr) return false;	//i����������ʧ��
    DblNode<T>* newNode = new DblNode<T>(x);
    if (d == 0) { 		//��ǰ���������
        newNode->lLink = current->lLink;
        newNode->rLink = current;
        current->lLink->rLink = newNode;
        current->lLink = newNode
    }
    else {				//�Ӻ�̷������
        newNode->rLink = current->rLink;
        newNode->lLink = current;
        current->rLink->lLink = newNode;
        current->rLink = newNode;

    }
    return true;

}
//˫��ѭ�������Remove�����ǰ���d��ָ����ɾ���� i����㣬ɾ�����̷���������һ����Ѱ��d��ָ����ĵ�i����㡣d=0,��ǰ��������ҵ�i����㣻d!=0,�ں�̷�����ҵ�i����㡣�ڶ����ѵ�i���������з��������Ϊ�˴���������ժ�±�ɾ��㣬�����޸�ǰ�����ĺ��ָ��ͺ�̽���ǰ��ָ�롣�������ٰѱ�ɾ����ͷš�
//����2.28 ɾ�������ʵ��
template<class T>
bool DbList<T>::Remove(int i, T& x, int d) {
    //�ڴ�����ͷ����˫��ѭ�������а��� d ��ָ����ɾ����i�����
    DbNode<T>* current = Locate(i, d);		//���ҵ�i�����
    if (current == nullptr) {
        return false;						//i������ɾ��ʧ��
    }
    current->rLink->lLink = current->lList;			//��lLink����ժ��
    current0 > lLink->rLink = current->rList:			//��rLink����ժ��
    x = current->data;
    delete current;
    return true;
}

