#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct gang{
    string head;
    int member_num;
};

// return mapping value of current stirng, and store int2str relation.
int string2num(string s, map<string, int> &str2int, map<int, string> &int2str, int &p)
{
    if (str2int.find(s) !=  str2int.end()){
        return str2int[s];
    } else {
        str2int[s] = p;
        int2str[p] = s;
        return p ++;
    }
}

// print graph, for debugging.
void p_graph(int** G, int n)
{
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 每个团伙都可以视作一个双向连通图，从任意一个团伙成员开始，都可以完成对整个团伙的遍历
// 遍历后需要得到的主要特征是：头目、成员数、总通话时长（权值）
// 所以，DFS遍历的过程需要不断更新头目、成员数量、团伙的总权值
void DFS(int current, int &head, int &gang_num, int &total_value, bool* visited, int* weight, int** G, int size)
{
    visited[current] =  true;
    gang_num ++;
    if(weight[current] > weight[head]){
        head = current;
    }
    for (int i = 0; i < size; i++) {
        if(G[current][i] != 0){
            total_value += G[current][i];
            G[current][i] = 0;
            G[i][current] = 0;
            if(!visited[i]){
                DFS(i, head, gang_num, total_value, visited, weight, G, size);
            }
        } 
    }
}

string test_caller[8] = {"AAA","BBB","AAA","DDD","EEE","FFF","GGG","HHH"};
string test_calle[8] = {"BBB","AAA","CCC","EEE","DDD","GGG","HHH","FFF"};
int test_time[8] = {10,20,40,5,70,30,20,10};

int main()
{
    // first line input.
    int call_numbers , threshold ;
    scanf("%d%d", &call_numbers, &threshold);
    
    // following lines of input value, use map structure to keep call infor.
    string caller, calle;
    int time;
    
    int *weight = new int[call_numbers];
    map<string, int> str2int;
    map<int, string> int2str;
    int **G = new int*[call_numbers];
    for (int i = 0; i < call_numbers; i++) {
        G[i] = new int[call_numbers];
    }
    //p_graph(G, call_numbers);
    
    int s_num = 0;
    for (int i = 0; i < call_numbers; i++) {
        cin >> caller >> calle >> time;
        //caller = test_caller[i], calle = test_calle[i], time = test_time[i];
        // use input to construct the adjacency matrix.
        // printf("%s %s %d\n", caller.c_str(), calle.c_str(), time);
        // mapping each caller's name to an integer index.
        // compute the weight of each node and edge. 
        int m = string2num(caller, str2int, int2str, s_num);
        int n = string2num(calle, str2int, int2str, s_num);
        //printf("%d\n", s_num);
        weight[m] += time;
        weight[n] += time;
        G[m][n] += time;
        G[n][m] += time;
        //p_graph(G, call_numbers);
    }
    p_graph(G, call_numbers);

    // find gangs according to adj matrix.
    const int maxn = 1000;
    map<string, int> gang;
    int gang_num = 0;
    int total_value = 0;
    int head ;
    bool visited[maxn] = {false};

    // 把每一个通话节点都视为头目进行DFS遍历
    for (int i = 0; i < call_numbers; i++) {
        if(!visited[i]){
            int member_num = 0, head = i, total_value = 0;
            DFS(i, head, member_num, total_value, visited, weight ,G, call_numbers);
            if (total_value > threshold && member_num > 2) {
                gang_num ++;
                gang[int2str[head]] = member_num;                
            }
        }
    }

    // output gang information.
    printf("%d\n", gang_num);
    map<string, int>::iterator it;
    for (it = gang.begin(); it != gang.end(); it ++) {
        cout << it->first << ' ' << it->second << endl;
    }


    //for (int i = 0; i < s_num; i++) {
    //    cout << int2str[i] << ' ';
    //}
    //cout << endl; 
    //for (int i = 0; i < s_num; i++) {
    //    cout << str2int[int2str[i]] << ' ';
    //}
    //cout << endl;


    delete [] weight;
    for (int i = 0; i < call_numbers; i++) {
        delete [] G[i];
    }
    delete [] G;

    return 0;
}