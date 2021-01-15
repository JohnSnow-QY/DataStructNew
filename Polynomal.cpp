//
// Created by lixy on 2020/11/1.
//


#include<iostream>
using namespace std;
class Term {			//����ʽ���Ķ���
    
public:
    float coef;		//ϵ��
    int exp;		//ָ��
    Term* link;
    Term(float c, int e, Term* next = nullptr) {
        coef = c;
        exp = e;
        link = next;
    }
    Term* InsertAfter(float c, int e);
    friend ostream& operator<<(ostream&, const Term&);
};
class Polynomal {			//����ʽ��Ķ���
public:
    Polynomal() {
        first = new Term(0, -1);
    }
    Polynomal(Polynomal& R);		//���ƹ��캯��
    int maxOrder();					//����������
    Term* getHead()const {
        return first;				//ȡ�ö���ʽ������ı�ͷָ��
    }
private:
    Term* first;
    friend ostream& operator << (ostream&, const Polynomal&);
    friend ostream& operator >> (istream&, Polynomal&);
    friend Polynomal operator + (Polynomal&, Polynomal&);
    friend Polynomal operator * (Polynomal&, Polynomal&);

};

Term* Term::InsertAfter(float c, int e) {
    //�ڵ�ǰ��this ָ��ָʾ��������ô˺������󣩺������һ������
    link = new Term(c, e, link);			//����һ���½�㣬�Զ�����
    return link;						//���뵽this ������
}
ostream& operator << (ostream& out, const Term& x) {
    //Term ����Ԫ���������һ���� x�����ݵ������out ��
    if (x.coef == 0) {			//��ϵ�������
        return out;
    }
    out << x.coef;			//���ϵ��
    switch(x.exp) {

        case 1: out << "X";
            break;
        case 2: out << "X+" << x.exp;
            break;
    }
    return out;
}

Polynomal::Polynomal(Polynomal& R) {
    //���ƹ��캯���������ж���ʽ����R��ʼ����ǰ����ʽ����R
    first = new Term(0, -1);
    Term* destptr = first, * srcptr = R.getHead()->link;
    while (srcptr != nullptr) {
        //destptr->InsertAfter(srcptr->coef ,srcptr->exp);
        //��destpth��ָ��������½�㣬����destptrָ��ָ������½�㣬--������20201021
        Term* term = new Term(srcptr->coef, srcptr->exp);
        destptr->link = term;
        srcptr = srcptr->link;
        destptr = destptr->link;
    }
}
int Polynomal::maxOrder() {
    //������������������ʽ����������ʱ�����һ����ָָ�������
    Term* current = first;
    while (current->link != nullptr) {		//�ձ����Σ�currentͣ����first������currentͣ���ڱ�β���
        current = current->link;

    }
    return current->exp;
}

