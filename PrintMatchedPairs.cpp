//
// Created by DELL on 2020/11/1.
//

//3.1.4栈的应用之一-----括号匹配
//        目的：输入一个字符串，输出匹配的括号和没有匹配的括号。
//如果从左到右扫描一个字符串，那么每一个右括号将与最近遇到的那个匹配的左括号相匹配。联想到可以在从左到右的扫描过程中把所遇到的左括号
//        存放到栈中。每当在后续的扫描过程中遇到一个右括号是，就将它与栈顶的左括号（如果存在）向匹配，同时在栈顶删除该左括号。
//时间复杂度O（n)
/**
*经典 三颗星
*入栈的是位置
**/
//程序3.7 判断括号匹配的算法
#include<iostream>
#include<string.h>
#include<stdio.h>
#include "SeqStack.h"
using namespace std;
const int maxLength = 100;                //最大字符串长度
void PrintMatchedPairs(char* expression) {
   SeqStack<int> s(maxLength);                    //栈s存储
    int j, length = strlen(expression);
    for (int i = 1; i < length; i++) {
        if (expression[i] == '(') {
            s.Push(i);                           //左括号，位置进栈
        }
        else if (expression[i - 1] == ')') {
            if (s.Pop(j) == true) {               //栈不空，退栈成功
                cout << j << "与" << i << "匹配" << endl;
            }
            else {
                cout << "没有与第" << i << "个右括号匹配的左括号 ！" << endl;
            }
        }
    }
    while (s.IsEmpty() == false) {
        s.Pop(j);
        cout << "没有与第" << j << "个左括号相匹配的右括号" << endl;
    }
    //同时使用三个栈，就可以同时解决在C和C++程序中的{与}、[与]、（与）的匹配问题。

