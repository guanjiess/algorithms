#include <stdio.h>

int main(){
    int school[100] = {0};
    int n;
    int ID, score;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
    	scanf("%d%d", &ID, &score);
	school[ID] += score;
    }
    int max_ID = 1;
    int max_score = -1;
    for(int i = 1; i <= n; i++){
    	if(school[i] > max_score){
	    max_score = school[i];
	    max_ID = i;
	}
    }
    printf("%d  %d\n", max_ID, max_score);
    return 0;
}
