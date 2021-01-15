//
// Created by lixy on 2020/11/1.
//


#include<iostream>
using namespace std;
class Term {			//多项式结点的定义
    
public:
    float coef;		//系数
    int exp;		//指数
    Term* link;
    Term(float c, int e, Term* next = nullptr) {
        coef = c;
        exp = e;
        link = next;
    }
    Term* InsertAfter(float c, int e);
    friend ostream& operator<<(ostream&, const Term&);
};
class Polynomal {			//多项式类的定义
public:
    Polynomal() {
        first = new Term(0, -1);
    }
    Polynomal(Polynomal& R);		//复制构造函数
    int maxOrder();					//计算最大阶数
    Term* getHead()const {
        return first;				//取得多项式单链表的表头指针
    }
private:
    Term* first;
    friend ostream& operator << (ostream&, const Polynomal&);
    friend ostream& operator >> (istream&, Polynomal&);
    friend Polynomal operator + (Polynomal&, Polynomal&);
    friend Polynomal operator * (Polynomal&, Polynomal&);

};

Term* Term::InsertAfter(float c, int e) {
    //在当前由this 指针指示的项（即调用此函数对象）后面插入一个新项
    link = new Term(c, e, link);			//创建一个新结点，自动链接
    return link;						//插入到this 结点后面
}
ostream& operator << (ostream& out, const Term& x) {
    //Term 的友元函数：输出一个项 x的内容到输出流out 中
    if (x.coef == 0) {			//零系数不输出
        return out;
    }
    out << x.coef;			//输出系数
    switch(x.exp) {

        case 1: out << "X";
            break;
        case 2: out << "X+" << x.exp;
            break;
    }
    return out;
}

Polynomal::Polynomal(Polynomal& R) {
    //复制构造函数：用已有多项式对象R初始化当前多项式对象R
    first = new Term(0, -1);
    Term* destptr = first, * srcptr = R.getHead()->link;
    while (srcptr != nullptr) {
        //destptr->InsertAfter(srcptr->coef ,srcptr->exp);
        //在destpth所指结点后插入新结点，再让destptr指到指到这个新结点，--看不懂20201021
        Term* term = new Term(srcptr->coef, srcptr->exp);
        destptr->link = term;
        srcptr = srcptr->link;
        destptr = destptr->link;
    }
}
int Polynomal::maxOrder() {
    //计算最大阶数，当多项式按升序排列时，最后一项是指指数最大者
    Term* current = first;
    while (current->link != nullptr) {		//空表情形，current停留在first，否则current停留在表尾结点
        current = current->link;

    }
    return current->exp;
}

