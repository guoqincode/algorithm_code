#include<bits/stdc++.h>
using namespace std;
typedef struct {
	int x,y;
} point;
int n,m,ini_i,ini_j;
int dx[8]= {2,-2,2,-2,1,1,-1,-1};
int dy[8]= {1,1,-1,-1,2,-2,2,-2};
int test(int newx,int newy) {
	if((newx>=0)&&(newx<n)&&(newy>=0)&&(newy<m)) return 1;
	else return 0;
}
int main() {
	cin>>n>>m>>ini_i>>ini_j;
	//cout<<test(1,1)<<endl;
	vector< vector<int> >dis(n,vector< int >(m,-1));
	vector< vector<int> >get(n,vector< int >(m,-1));
	point start;
	start.x=ini_i-1;
	start.y=ini_j-1;
	dis[start.x][start.y]=0;
	get[start.x][start.y]=1;
	queue< point >q;
	q.push(start);
	int step=1;
	while (!q.empty()) {
		int nn=q.size();
		//cout<<nn<<endl;
		while(nn--) {
			point temp=q.front();
			q.pop();
			//cout<<temp.x<<" "<<temp.y<<endl;
			for(int i=0; i<8; i++) {
				int newx=temp.x+dx[i];
				int newy=temp.y+dy[i];
				if(test(newx,newy)&&get[newx][newy]==-1) {
					//cout<<newx<<" "<<newy<<"!"<<endl;
					get[newx][newy]=1;
					dis[newx][newy]=step;
					point curtemp;
					curtemp.x=newx;
					curtemp.y=newy;
					q.push(curtemp);
				}//else{
				//	cout<<newx<<" "<<newy<<"?"<<endl;
				//}
			}
		}
		step++;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			printf("%-5d",dis[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
