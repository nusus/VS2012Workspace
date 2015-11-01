#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

struct A
{
	char a[10];
	int  b;
	short c[3];
};

int problem2(){
	int n, t, c;
	scanf("%d%d%d",&n,&t,&c);
	unsigned int* arr = (unsigned int*)malloc(sizeof(unsigned int) * n);
	for(int i=0 ; i<n; ++i){
		scanf("%d",&arr[i]);
	}
	long long sum =0 ;
	int ret = 0;
	for(int start = 0, end = c; end<=n; ++start, ++end){
		for (int j=start ; j< end ;++j)
		{
			sum +=arr[j];
		}
		if(sum <= t) {
			ret += 1;		
		}
		sum = 0;
	}
	printf("%d ", ret);
	return 0;
}

int problem3(){
	int station_count = 0;
	scanf("%d", &station_count);
	if(station_count <=0 ) return 1;
	int* a = (int*)malloc(sizeof(int) * station_count);
	int* b = (int*)malloc(sizeof(int) * station_count);
	for (int i= 0; i< station_count; ++i)
	{
		scanf("%d%d", &b[i], &a[i]);
	}
	int max_passenger = 0;
	int current_passenger = 0; 
	for(int i=0; i< station_count; ++i){
		current_passenger += (a[i] - b[i]);
		if(current_passenger > max_passenger){
			max_passenger = current_passenger;
		}
	}
	printf("%d", max_passenger);
	return 0;
}

int problem1(){
	int m =3 , n=3;
	//scanf("%d%d",&m,&n);
	/*int** arr = (int**)malloc(sizeof(int*) * m);
	for (int i =0 ;i< m; ++i)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i =0 ; i<m ;++i)
	{
		for (int j=0; j<n; ++j)
		{
			scanf("%d", &arr[i][j]);
			printf("%d\n",arr[i][j]);
		}
	}*/
	int arr[3][3] = {1,1,1,1,0,1,1,1,1};
	std::vector<std::vector<int> > dp(m, std::vector<int>(n,0));
	dp[0][0] = 1;
	for(int row = 0; row < m; ++row){
		for(int col = 0; col<n ; ++col){
			if(row ==0 && col==0) continue;
			if(row ==0 && col>0){
				dp[row][col] = dp[row][col-1]*arr[row][col-1];
			}else
			{
				if( row ==0 ) continue;
				if(col==0 && row>0){
					dp[row][col] = dp[row-1][col] * arr[row][col-1];
				}else
				{
					dp[row][col] = dp[row-1][col] * arr[row-1][col] +dp[row-1][col-1] * arr[row-1][col-1] + dp[row][col-1]*arr[row][col-1];
				}
			}

		}
	}
	for (int i=0 ;i <m ;++i)
	{
		for(int j=0 ; j<n;++j){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("%d",dp[m-1][n-1]);
	system("pause");
	return 0;

}

int Problem4(){
	int light_count =0 ;
	int street_length = 0;
	scanf("%d %d", &light_count, &street_length);
	int* arr = (int*)malloc(sizeof(int) * light_count);
	for(int i=0 ; i<light_count ; ++i){
		scanf("%d",&arr[i]);
		//printf("%d", arr[i]);
	}
	int max =0;
	int min_index = arr[0];
	int max_index = arr[0];
	for(int i=1 ; i<light_count ;++i){
		int distance = arr[i] - arr[i-1];
		if(distance > max){
			max = distance;
		}
		if(-distance > max){
			max = -distance;
		}

		if(arr[i] < min_index){
			min_index = arr[i];
		}
		if(arr[i] > max_index){
			max_index = arr[i];
		}
	}
	max = max > min_index? max:min_index;
	max = max> (street_length - max_index)?max:(street_length - max_index);
	printf("%f",max/2);
	//system("pause");
	return 0;
}

int Problem5(){
	int m =0 ;
	int n =0;
	scanf("%d", &m);
	int* a = (int*)malloc(sizeof(int) * m);
	for(int i=0; i<m ;++i){
		scanf("%d", &a[i]);
	}
	int* b = (int*)malloc(sizeof(int) * n);
	for(int i=0 ;i<n;++i){
		scanf("%d", &b[i]);
	}
	std::sort(a,a+m);
	std::sort(b,b+n);
	int ret = b[n-1] ;
	for(int i=0 ; i<m;++i){
		int b_count = n-( std::lower_bound(b,b+n,*(a + i)) - b);
		if( (m-i)>b_count ){
			ret = *(a+i);
			break;
		}
	}
	printf("%d" , ret);
	return 0;

}

int main(){
	printf("A size:%d", sizeof(struct A));
	getchar();
	return 0;
}
