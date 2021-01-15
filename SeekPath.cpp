#include <iostream>
using namespace std;
class offsets{		//位置在直角坐标下的偏移
public :
	int a;
	int b;			//a,b是x,y方向的偏移
	char* dir;		//dir 是方向


};
int SeekPath(int x, int y,int m,int p, offsets* move,int ** Maze,int** mark) {
	//从迷宫某一位置[i][j]开始，寻找通向出口[m][p]的一条路径。如果找到，则函数返回1.
	//否则函数返回0。试探的出发点为[1][1]。
	int i, g, h;			//g,h记录位置信息，dir纪录方向
	char* dir;				// dir 记录方向
	

	if (x == m && y == p)return 1;			//已到达出口，函数返回1，递归出口

	for (i = 0; i < 8; i++) {		//依次按每一个方向寻找通向出口的路径
		g = x + move[i].a;
		h = y + move[i].b;
		dir = move[i].dir;			//找下一个位置和方向(g,h,dir)
		if (Maze[g][h] == 0 && mark[g][h] == 0) {		//下一个位置可通，试探该方向

			mark[g][h] = 1;			//标记为已访问过
			if (SeekPath(g, h, m, p, move, Maze, mark)) {	

				cout << "(" << g << "," << h << ")," << "Direction" << dir << ",";
				return 1;
			}

		}
		//回溯，换一个方向再试探通向出口的路径

	}
	if (x == 1 && y == 1) {
		cout << "no path in Maze" << endl;
	}

}
/*
* 模拟main函数
* #include <iostream>
* const int  m = 12,p = 15; //迷宫和行数,列数
* void main(){
	int i,j ;		
	int Maze[m+2][p+2];			//迷宫定义
	int mark[m+2][p+2];			//访问标记数组
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
	mark[1][1] =1;			//从入口[1][1]开始
	if(SeekPath(g, h, m, p, move, Maze, mark)){
		cout<<"(" <<1<<","<<1<<"),"<<"Direction"<<"E"<<endl;
	}
	
}
*/