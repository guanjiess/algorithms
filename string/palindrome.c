#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool is_palin(char s[]){
    bool ans = true;
    int len = strlen(s);
    for(int i = 0; i < len / 2; i ++){
  	if(s[i] != s[len - 1 - i]){
	    ans = false;
	    break;	    
	}
    }

    if(ans)
	printf("YES\n");
    else
	printf("NO\n");
    return ans;
}

void reverse(char s[]){
    int len = strlen(s);
    int MAX = 80;
    if(s[len-1] == ' '){
	printf("Format error!");
	return;
    }
    if(len > 80){
	printf("Too long.");
	return;
    }

    char ans[MAX][MAX];
    int word_i = 0;
    for(int i = 0; i < len; i ++){
    }
    
}


int main(){

    char s1[] = "test case 1.";
    bool ans = is_palin(s1);

    char s2[] = "test case 2.";
    bool ans2 = is_palin(s2);

    char s3[] = "1234321";
    bool ans3 = is_palin(s3);

    char s4[] = "tit";
    bool ans4 = is_palin(s4);

    char s5[] = "noon";
    bool ans5 = is_palin(s5);
    return 0;
}
