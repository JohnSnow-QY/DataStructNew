#include <iostream>
using namespace std;
class offsets{		//λ����ֱ�������µ�ƫ��
public :
	int a;
	int b;			//a,b��x,y�����ƫ��
	char* dir;		//dir �Ƿ���


};
int SeekPath(int x, int y,int m,int p, offsets* move,int ** Maze,int** mark) {
	//���Թ�ĳһλ��[i][j]��ʼ��Ѱ��ͨ�����[m][p]��һ��·��������ҵ�����������1.
	//����������0����̽�ĳ�����Ϊ[1][1]��
	int i, g, h;			//g,h��¼λ����Ϣ��dir��¼����
	char* dir;				// dir ��¼����
	

	if (x == m && y == p)return 1;			//�ѵ�����ڣ���������1���ݹ����

	for (i = 0; i < 8; i++) {		//���ΰ�ÿһ������Ѱ��ͨ����ڵ�·��
		g = x + move[i].a;
		h = y + move[i].b;
		dir = move[i].dir;			//����һ��λ�úͷ���(g,h,dir)
		if (Maze[g][h] == 0 && mark[g][h] == 0) {		//��һ��λ�ÿ�ͨ����̽�÷���

			mark[g][h] = 1;			//���Ϊ�ѷ��ʹ�
			if (SeekPath(g, h, m, p, move, Maze, mark)) {	

				cout << "(" << g << "," << h << ")," << "Direction" << dir << ",";
				return 1;
			}

		}
		//���ݣ���һ����������̽ͨ����ڵ�·��

	}
	if (x == 1 && y == 1) {
		cout << "no path in Maze" << endl;
	}

}
/*
* ģ��main����
* #include <iostream>
* const int  m = 12,p = 15; //�Թ�������,����
* void main(){
	int i,j ;		
	int Maze[m+2][p+2];			//�Թ�����
	int mark[m+2][p+2];			//���ʱ������
	offsets move[8]= {{-1,0,"N"},{-1,1,"NE"},{0,1,"E"},{1,1,"SE"},{1,0,"S"},{1,-1,"SW"},{0,-1,"W"},{-1,-1,"NW"}};
	for(i = 0,i<m+2;i++){
		for(j = 0; j<p+2; j++){
			cin>>Maze[i][j];
		}
	}
	for(i = 0;i<m+2; i++){
		for(j = 0;j<p+2; j++){
			mark[i][j] = 0;
		}
	}
	mark[1][1] =1;			//�����[1][1]��ʼ
	if(SeekPath(g, h, m, p, move, Maze, mark)){
		cout<<"(" <<1<<","<<1<<"),"<<"Direction"<<"E"<<endl;
	}
	
}
*/