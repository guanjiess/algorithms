#include <stdio.h>
int main(){
    int num[200] = {0};
    int n;
    while(scanf("%d", &n) != EOF){
    	for(int i = 0; i < n; i++){
	    scanf("%d", &num[i]);
	}
	int x;
	int k;
	scanf("%d", &x);

	for( k = 0; k < n; k++){
	    if(num[k] == x){
		printf("%d", k);
	    	break;	
	    }
	}
	if(k == n){
	    printf("-1\n");
	}
    }
    return 0;
}
