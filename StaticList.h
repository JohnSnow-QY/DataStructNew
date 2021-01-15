
//
// Created by DELL on 2020/11/1.
//

#ifndef STATICLIST_H
#define STATICLIST_H
//��̬����
//        ���Ϊ������ÿ��Ԫ�ظ���һ������ָ�룬���γɾ�̬����ṹ�������������Ǹı���ЩԪ�ص��߼�˳�����������������鶨��ģ���������������д洢�ռ�Ĵ�С
//        ����仯����˳�Ϊ��̬����
//��̬�����ûһ��������������ݳ�Ա���ɣ�data��洢���ݣ�link��������ָ�룬���н���γ�һ��������飬Ҳ���Դ��и���ͷ��㡣
//A[0].link �����ҵ�������һ�����λ�ã����ҵ�ĳһ�����A[k].link = -1,��������ֹ��������A[0]��Ч�����Կ�ָ��NULL�� -1��ʾ��
//����2.32 ��̬������
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
#endif STATICLIST_H
#pragma once
