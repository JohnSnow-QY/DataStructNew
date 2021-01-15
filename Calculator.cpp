#include<iostream>
#include  "Linkedstack.h"

using namespace std;
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
class  Calculator
{
public:
    Calculator();
    ~Calculator();

    void Run();            //执行表达式计算
    void Clear();
private:
    LinkedStack<double> s;        //栈对象定义
    void AddOperand(double value);      //进操作数栈
    bool Get2Operands(double& left, double& right);      //从栈中退出连个操作数
    void DoOperator(char op);           //形成运算指令，进行计算

};

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

//执行函数Run()输入一个后缀表达式，输入流以#结束。
//程序3.9 Calculator 类私有成员函数的实现
void Calculator::DoOperator(char op) {
    //私有函数，取两个操作数，根据操作数op形成运算指令并计算
    double left, right, value;
    int result;
    result = Get2Operands(left, right);      //
    if (result == true) {
        switch (op) {
        case '+':value = left + right;
            s.Push(value);
            break;
        case '-': value = left - right;
            s.Push(value);
            break;
        case '*': value = left * right;
            s.Push(value);
            break;
        case '/':if (right == 0.0) {
            cout << "Divide by 0!" << std::endl;
            Clear();            //若除0，则报错，清栈
        }
                else {
            value = left / right;
            s.Push(value);
        }
                break;
        }
    }
    else {
        Clear();            //去操作数出错，清栈
    }
};
bool  Calculator::Get2Operands(double& left, double& right) {
    //私有函数：从操作数栈张去除两个操作数
    if (s.IsEmpty() == true) {        //检查栈空否？
        std::cout << "缺少有操作数" << endl;
        return false;               //栈空，报错
    }
    s.Pop(right);                   //取出右操作数
    if (s.IsEmpty() == true) {
        std::cout << "缺少左操作数" << std::endl;
        return false;               //栈空，取出左操作数报错
    }
    s.Pop(left);                    //取出左操作数
    return  true;
};
void Calculator::AddOperand(double value) {
    //私有函数：将操作数的值value进栈
    s.Push(value);
};
/*
 * 所有的内部运算都在DoOperator()的控制下，以调用Get2Operands()开始。如果
 * Get2Operands（）返回false ，表示操作失败，没有取到两个操作数，执行清栈处理；
 *否则，DoOperator()执行字符标量op(+,*,-,/)所指定的操作，并将结果进栈
 * 计算器的主要工作是同故宫共有函数Run()执行求解后缀表达式的计算来完成的。在Run()中，有一个
 * 主循环，从输入流读取字符，直到读入字符'#"时结束。如果读入的字符时操作数（’+‘，’-‘，’*‘，’/')所指定的操作，并将结果进栈
 * 则调用函数DoOperator()完成相关的计算。如果读入的字符部署操作符，则Run()把他看作时一个
 * 操作符的第一个字符，将它放回到输入流中，以便能用流操作，将其按一个浮点操作数重新读入。
 *
 */
 //经典计算器的程序 三颗星***
 //程序3.10Calculator的实现
void Calculator::Run() {
    //读字符串并求一个后缀表达式的值。以字符'#'结束
    char ch;
    double  newOperand;
    std::cin >> ch;
    while (ch != '#') {
        switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
            //是操作符，执行计算
            DoOperator(ch);
            break;
        default:cin.putback(ch);           //将字符放回输入流
            std::cin >> newOperand;              //重新读操作数
            AddOperand(newOperand);            //将操作数放入栈中
        }
    }

}
void Calculator::Clear() {//清栈
    double x;
    while (!s.IsEmpty()) {
        s.Pop(x);
    }
}

/***
 * 将各个算法操作符分优先级,isp (in stack priority) 叫做栈内有限数，icp(in coming priority)叫做栈外优先数。左括号的栈外优先数最高，他一来到立即进栈，但当它
 * 进入栈中后，其站内优先数变得极低，以便括号内的其他操作数进栈。其他操作数进入栈中后优先级都升1，这样可体现在中最表达式总相同优先级的操作符自左向右计算的要求，让位于
 * 栈顶的操作符先退栈并输出。操作符优先数相等的情况值出现在括号配对或栈底的 "#" 号与输入流最后的"#" 号配对时，前者将连续退出位于栈顶的操作符，直到遇到'('为止。
 * 然后将"(" 退栈以对消括号，后者将结束算法。
 *
 */
 /***
  * 扫描中缀表达式，将它转换成后缀表达式的算法描述如下
  * 1、操作符栈初始化，将结束符#进栈，然后读入中缀表达式字符流的首字符ch.
  * 2、重复执行一下步骤，直到 ch = '#' ,同时栈顶的操作符也是'#'，停止循环
  *     a) 若ch 是操作数直接输出，读入下一个字符ch
  *     b) 若ch 是操作符，判断ch 的优先级icp和 当前位于栈顶的操作符op 的优先级isp;
  *         . 若 icp(ch) > isp(op) ,令ch 进栈，读入下一个字符ch
  *         . 若 icp(ch) < isp(op), 退栈输出
  *         . 若 icp(ch) == isp(op) ，退栈但不输出，若退出的是 '(' 号，读入下一个字符ch。
  * 3、算法结束，输出序列即为所需的后缀表达式
  *
  */
  //程序3.11 中缀表达式转换为后缀表达式的算法
void postfix() {
    //把中缀表达式 e 转换成后缀表达式并输出，设定e中最后一个符号是"#"，而且 "#" 一开始先放在栈s的栈底
    LinkedStack<char> stack;
    char  ch = '#';
    char chl;
    char op;
    stack.Push(ch);             //栈低放入一个"#"
    cin.get(ch);                //读入一个字符
    while (stack.IsEmpty() == false && ch != '#') {
        //书 100页提供的是不能直接能运行的代码 ，对于ch 操作符的优先级没有写赋值、获取的方法
        //判断是否为操作数的方法也没有先定义 20201126 22：43
    }

}