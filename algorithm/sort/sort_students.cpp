#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
//test
struct student
{
    char id[15];
    int score;
    int local;
    int local_rank;    
}stu[100];

bool stu_cmp(student a, student b)
{
    if(a.score == b.score) 
        return strcmp(a.id, b.id) < 0;
    else 
        return a.score > b.score;
}
int main()
{
    int locals = 1;
    //scanf("%d", &locals);
    int stu_num = 0;
    printf("there's %d locals.\n", locals);
    int local_student_num[locals];

    for (int local_i = 0; local_i < locals; local_i++)
    {

        local_student_num[local_i] = 3;
        //scanf("%d", &local_student_num[local_i]);
        int local_num_i = local_student_num[local_i];
        printf("local_%d need %d students.\n",local_i, local_num_i);

        for (int i = 0; i < local_num_i; i++)
        {
            scanf("%s %d", stu[stu_num].id, &stu[stu_num].score);
            stu[stu_num].local = local_i;
            stu_num ++;
        }

        sort(stu + stu_num - local_student_num[local_i], stu + stu_num, stu_cmp);
    
        stu[stu_num - local_num_i].local_rank = 1;

        for (int j = stu_num - local_num_i + 1; j < stu_num; j++)
        {
            if(stu[j].score == stu[j-1].score){
                stu[j].local_rank = stu[j-1].local_rank;
            } else{
                stu[j].local_rank = j - (stu_num - local_num_i) + 1;
            }
        }
    }

    printf("total student number is: %d\n", stu_num);
    sort(stu, stu + stu_num, stu_cmp);
    int r = 1;
    for (int i = 0; i < stu_num; i++)
    {
        if(i > 0 && stu[i].score != stu[i-1].score){
            r = i + 1;
        }
        printf("id: %s ", stu[i].id);
        printf("score: %d local: %d local_rank: %d ", stu[i].score, stu[i].local, stu[i].local_rank);
        printf("total rank:%d\n", r);
    }   
    return 0;
    
}
