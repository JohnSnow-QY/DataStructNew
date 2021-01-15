#include<iostream>
#include"LinkedStack.h"
using namespace std;
//程序3.18 用栈帮助求解斐波那契数的非递归算法 时间复杂度O(n)
struct Node {			//栈结点的类定义
	long n;				//记忆走过的n
	int tag;			//区分左、右递归的标志
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
		while (S.IsEmpty() == false) {		//按个计算栈内的元素，遇到不能直接算出的，转到上面的循环，最后分两部分加到sum中
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

//实际上，求解斐波那契数列Fib(n)的过程是一种单向递归的过程：可以直接考虑用简单的迭代来计算
//其算法的时间复杂度为o(n)。比递归效率高得多（递归 o(2的n次幂）
//程序3.19 计算斐波那契数的非递归算法
long FibIter(long n) {
	if (n <= 1) {
		return n;					//Fib(0) 或 Fib(1)的情况
	}
	long twoback = 0, oneback = 1, Current;				//n>=2 的情况
	for (int i = 2; i <= n; i++) {
		Current = twoback + oneback;				//计算Fib(i) = Fib(i-2) + Fib(i-1)
		twoback = oneback;							//保存Fib(i-1)，下趟的Filb(i-2)
		oneback = Current;							//保存Fib(i) ,下趟的Fib(i-1)
	}
	return Current;
}
/*
单向递归就是如求斐波那契数列这样的问题，而尾递归则是单向递归的特例。它的递归调用语句只有一个
而且是放在过程的最后。当递归调用返回时，返回到上一层递归调用的的下一语句，这个位置正好是程序
的末尾。因此，不比利用递归工作栈保存返回地址，而且除了返回值和引用值外，其他的参数和局部变量值都不知需要
因此可以不用栈，直接用迭代形式写出非递归过程，提高程序的执行效率
*/

/*
* 一般从递归过程改为非递归过程的方法是先根据递归算法画出程序流程图，然后建立起循环结构 122页
*/