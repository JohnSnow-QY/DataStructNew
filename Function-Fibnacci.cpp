#include<iostream>
#include"LinkedStack.h"
using namespace std;
//����3.18 ��ջ�������쳲��������ķǵݹ��㷨 ʱ�临�Ӷ�O(n)
struct Node {			//ջ�����ඨ��
	long n;				//�����߹���n
	int tag;			//�������ҵݹ�ı�־
};
long Fibnacci(long n) {
	
	LinkedStack<Node> S;
	Node  w;
	long sum = 0;

	do {
		while (n > 1) {
			w.n = n;
			w.tag = 1;
			S.Push(w);
			n--;
		}
		sum = sum + n;
		while (S.IsEmpty() == false) {		//��������ջ�ڵ�Ԫ�أ���������ֱ������ģ�ת�������ѭ�������������ּӵ�sum��
			S.Pop(w);
			if (w.tag == 1) {
				w.tag = 2;
				S.Push(w);
				n = w.n - 2;
				break;
			}
		}
	
	
	} while (S.IsEmpty() == false);
	return sum;
	
}

//ʵ���ϣ����쳲���������Fib(n)�Ĺ�����һ�ֵ���ݹ�Ĺ��̣�����ֱ�ӿ����ü򵥵ĵ���������
//���㷨��ʱ�临�Ӷ�Ϊo(n)���ȵݹ�Ч�ʸߵöࣨ�ݹ� o(2��n���ݣ�
//����3.19 ����쳲��������ķǵݹ��㷨
long FibIter(long n) {
	if (n <= 1) {
		return n;					//Fib(0) �� Fib(1)�����
	}
	long twoback = 0, oneback = 1, Current;				//n>=2 �����
	for (int i = 2; i <= n; i++) {
		Current = twoback + oneback;				//����Fib(i) = Fib(i-2) + Fib(i-1)
		twoback = oneback;							//����Fib(i-1)�����˵�Filb(i-2)
		oneback = Current;							//����Fib(i) ,���˵�Fib(i-1)
	}
	return Current;
}
/*
����ݹ��������쳲������������������⣬��β�ݹ����ǵ���ݹ�����������ĵݹ�������ֻ��һ��
�����Ƿ��ڹ��̵���󡣵��ݹ���÷���ʱ�����ص���һ��ݹ���õĵ���һ��䣬���λ�������ǳ���
��ĩβ����ˣ��������õݹ鹤��ջ���淵�ص�ַ�����ҳ��˷���ֵ������ֵ�⣬�����Ĳ����;ֲ�����ֵ����֪��Ҫ
��˿��Բ���ջ��ֱ���õ�����ʽд���ǵݹ���̣���߳����ִ��Ч��
*/

/*
* һ��ӵݹ���̸�Ϊ�ǵݹ���̵ķ������ȸ��ݵݹ��㷨������������ͼ��Ȼ������ѭ���ṹ 122ҳ
*/