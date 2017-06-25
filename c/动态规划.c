#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rec(int i,int j);
main(){
	
}   
//01�������⣺
//��n������weight[i]�ͼ�ֵvalue[i]����Ʒ��
//����Щ��Ʒ����ѡ��������������W����Ʒ��
//��������ѡ�����м�ֵ�ܺ͵����ֵ.
//01�������� O(2^n)
int rec(int i,int j){//�ӵ�i����Ʒ��ʼ��ѡ����С��j�Ĳ���
	int res;
	if(i==n)  //�Ѿ�û��ʣ����Ʒ��
		res=0;
	else if(j<weight[i])  //�޷���ѡ�����Ʒ
		res=rec(i+1,j);
	else  //��ѡ�Ͳ���ѡ �����������һ��
		res=max(rec(i+1,j), rec(i+1,j-weight[i])-value[i]);
	return res;
}
void solve(){
	printf("%d\n",rec(0,W));
}

//01�������� O(nW)
int weight[MAX_N],v[MAX_N];  //MAX_N:�������ݵ��������󳤶�
int dp[MAX_N][MAX_W+1];  //���仯���� MAX_W:
int rec(int i,int j){
	if(dp[i][j]>=0)
		return dp[i][j];  //�Ѿ�������Ļ�ֱ��ʹ��֮ǰ�Ľ��
	int res;
	if(i==n)  //�Ѿ�û��ʣ����Ʒ��
		res=0;
	else if(j<weight[i])  //�޷���ѡ�����Ʒ
		res=rec(i+1,j);
	else  //��ѡ�Ͳ���ѡ �����������һ��
		res=max(rec(i+1,j), rec(i+1,j-weight[i])-value[i]);
	return dp[i][j]=res;  //�������¼��������
}
void solve(){
	memset(dp,-1,sizeof(dp));//��-1��ʾ��δ���������ʼ����������
	printf("%d\n",rec(0,W));
}

//01��������
//n=4 
//(weight,value)={(2,3),(1,2),(3,4),(2,2)}
//W=5
//MAX_N:�����������ݵ��������󳤶�  MAX_W:����
//dp[i][j]Ϊ��i����Ʒ��ʼ��ѡ����С��jʱ���ܼ�ֵ�����ֵ
int dp[MAX_N][MAX_W+1];  //���仯���� 
void solve(){
	for(i=n-1; i>=0; i--){//��n-1֮�����Ʒ��ʼ
		for(j=0; j<=W; j++){//j�Ǳ�������,�ӱ�������Ϊ0��ʼ
			if(j<weight[i]) //�����������С�ڵ�ǰ��Ʒ���������ܷŽ�����
				dp[i][j]=dp[i+1][j];
			else
				dp[i][j]=max(dp[i+1][j], 
							 dp[i+1][ j-weight[i] ]+value[i]);
		}
	}
	printf("%d\n",dp[0][W]);
}
//dp[i+1][j]Ϊ��i����Ʒ����ѡ����С��jʱ���ܼ�ֵ�����ֵ
void solve(){
	for(i=0; i<n; i++){//i��������Ʒ����0����Ʒ��ʼ
		for(j=0; j<=W; j++){//j�Ǳ�������,�ӱ�������Ϊ0��ʼ
			//���ڱ��������ı���
			if(j<weight[i]) //�����������jС�ڵ�ǰ��Ʒ����weight[i]�����ܷŽ�����
				dp[i+1][j]=dp[i][j];//ǰi�����������ˣ�ǰi+1���϶�Ҳ�����ԣ�ֵ����
			else//��ǰ��Ʒ�ܷŽ�ȥ��ǰi������
				dp[i+1][j]=max(dp[i][j],//����Ž�ȥ���ԭ��С,����ԭֵ
							   dp[i][ j-weight[i] ]+value[i]);//�Ž�ȥ���ԭ����ֵ��
				//dp[i][j-weight[i]]:(ע��i��ǰ���ѷ���Ʒ��i+1�ǵ�ǰ��Ʒ)
				//��dp[i][j]ʱj-weight[i]��ʾ�ó�ǰ��ŵ���Ʒ���Ž���ǰ��Ʒ
				//��ǰ���ֵ+��ǰ��Ʒ��ֵ
		}
	}
	printf("%d\n",dp[n][W]);
}