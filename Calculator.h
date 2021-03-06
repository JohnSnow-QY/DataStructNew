#pragma once
//
// Created by DELL on 2020/11/3.
//
//3.1.5 栈的应用之二——表达式的计算
//C++规定一个表达式中相邻的两个操作符的计算次序为：优先级高的先计算：
//如果优先级相同，则自左向右计算;当使用括号时，从最内层的括号开始计算。
//对于编译程序来说，一般不适用中缀表示处理表达式。解决方法是用后缀表示（较常用）和浅醉表示。
//和前缀表示，因为后缀表示计算表达式的值只用一个栈，二前缀表示和中缀表示同时需要两个栈，所以编译程序一般使用后缀
//表示求解表达式的值
/*
 *用中缀表示求解表达式的值需要利用两个栈是西安，一个暂存操作数，一个暂存操作符。
 * 我们利用"stack.h"中定于的模板Stack,建立两个不同数据类型的Stack对象
 *
 * */
 /*利用后缀表示求表达式的值，后缀表示也叫做RPN或逆波兰记号
  * 参加运算的操作数总在操作符前面
  * 利用后缀表示求解表达式的值时，从左向右顺序地扫描表达式，并使用一个栈暂存扫描到的操作数
  * 或计算结果。
  * 在后缀表达式计算顺序中已经隐含了加括号的优先次序
  * 以下只涉及双目操作符，不考虑单目操作符
  * %通过后缀表示计算表达式值的过程为：顺序扫描表达式的每一项，然后根据它的类型做如下相应操作。
  *  1、如果该项是操作数，则将其压入栈中;如果该项是操作符<op>，则连续从栈中退出两个操作数Y和X,
  *  形成运算指令X<op>Y,并将结果重新压入栈中。当表达式的所有项都扫描完后，栈顶存放的是就是最后的结果
  * */
#ifndef Calculator_h
#define Calculator_h
  //程序3.8 Calculator类的定义
#include<math.h>
#include  "Linkedstack.h"


class Calculator {
    //模拟一个简单的计算器，此计算器从键盘读入的后缀表达式求值
public:
    Calculator();

    void Run();            //执行表达式计算
    void Clear();

private:
    LinkedStack<double> s;        //栈对象定义
    void AddOperand(double value);      //进操作数栈
    bool Get2Operands(double& left, double& right);      //从栈中退出连个操作数
    void DoOperator(char op);           //形成运算指令，进行计算

};

#endif