//
// Created by DELL on 2020/11/1.
//

//3.1.4ջ��Ӧ��֮һ-----����ƥ��
//        Ŀ�ģ�����һ���ַ��������ƥ������ź�û��ƥ������š�
//���������ɨ��һ���ַ�������ôÿһ�������Ž�������������Ǹ�ƥ�����������ƥ�䡣���뵽�����ڴ����ҵ�ɨ������а���������������
//        ��ŵ�ջ�С�ÿ���ں�����ɨ�����������һ���������ǣ��ͽ�����ջ���������ţ�������ڣ���ƥ�䣬ͬʱ��ջ��ɾ���������š�
//ʱ�临�Ӷ�O��n)
/**
*���� ������
*��ջ����λ��
**/
//����3.7 �ж�����ƥ����㷨
#include<iostream>
#include<string.h>
#include<stdio.h>
#include "SeqStack.h"
using namespace std;
const int maxLength = 100;                //����ַ�������
void PrintMatchedPairs(char* expression) {
   SeqStack<int> s(maxLength);                    //ջs�洢
    int j, length = strlen(expression);
    for (int i = 1; i < length; i++) {
        if (expression[i] == '(') {
            s.Push(i);                           //�����ţ�λ�ý�ջ
        }
        else if (expression[i - 1] == ')') {
            if (s.Pop(j) == true) {               //ջ���գ���ջ�ɹ�
                cout << j << "��" << i << "ƥ��" << endl;
            }
            else {
                cout << "û�����" << i << "��������ƥ��������� ��" << endl;
            }
        }
    }
    while (s.IsEmpty() == false) {
        s.Pop(j);
        cout << "û�����" << j << "����������ƥ���������" << endl;
    }
    //ͬʱʹ������ջ���Ϳ���ͬʱ�����C��C++�����е�{��}��[��]�����룩��ƥ�����⡣

