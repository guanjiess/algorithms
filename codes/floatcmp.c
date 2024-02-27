#include <stdio.h>
#include <math.h>
const double pi = acos(-1.0);
const double eps = 1e-8;
#define Equ(a,b) (fabs((a)-(b))<(eps))
#define More(a,b) (((a)-(b))>(eps))
#define MoreEqu(a,b) (((a)-(b))>(-eps))
#define Less(a,b) (((a)-(b))<(-eps))
#define LessEqu(a,b) (((a)-(b))<(eps))


int main(){
    double db = 1.23;
    if(Equ(db, 1.23)){
	printf("true\n");
    } else {
	printf("false\n");
    }

    double db1 = 4 * asin(sqrt(2.0) / 2);
    double db2 = 3 * asin(sqrt(3.0) / 3);
    if(db1 == db2){
	printf("true\n");
    } else {
	printf("false\n");
    }
    return 0;
}
