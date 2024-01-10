#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <iostream>
using namespace std;

void print_vec(vector<int> vi)
{
    vector<int>::iterator it;
    for (it = vi.begin(); it != vi.end(); it ++) {
        printf("%d ", *(it));
    }
    printf("\n");
}

void test_vector()
{
    printf("----------test vector.\n"); 
    vector<int> vi;
    int size = 6;
    for (int i = 0; i < size; i++) {
        vi.push_back(i);
    }
    
    vector<int>::iterator it = vi.begin();
    printf("print vector with iterator\n");
    print_vec(vi);
    
    printf("print vector with index\n");
    for (int i = 0; i < size; i ++) {
        printf("%d ", vi[i]);
    }
    printf("\n");

    printf("size of vi is: %ld\n", vi.size());

    vi.insert(it+4, 99);
    printf("after an insert, the size of vi is: %ld\n", vi.size());
    print_vec(vi);

    vi.erase(it+3);
    print_vec(vi);
}

void print_set(set<int> s)
{
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it ++) {
        printf("%d ", *(it));
    }
    printf("\n");
}

void test_set()
{
    printf("----------test set.\n"); 
    set<int> s1;
    s1.insert(79); 
    print_set(s1);
    
    s1.insert(32);
    print_set(s1);
    
    s1.insert(98);
    print_set(s1);
    
    s1.insert(213);
    print_set(s1);

    printf("size of s1 is %ld.\n", s1.size());

}

void test_str()
{
    string s = "Thank you for your smile.\n";
    cout << s.substr(0,10) << endl;
    cout << s.substr(2,10) << endl;
    cout << s.substr(3,6) << endl;
    cout << s.substr(8,9) << endl;
}

void print_map(map<int, string> m)
{
    map<int, string>::iterator it;
    for (it = m.begin(); it != m.end(); it ++){
        cout << it->first << "--->"<< it->second << endl;
    }
}
void test_map()
{
    map<int , string> presidents;
    presidents[2016]= "Trump";
    presidents[2008]= "Obama";
    presidents[2000]= "Bush";
    presidents[1992]= "Clinton";
    print_map(presidents);
}


int main()
{
    test_vector();

    test_set();

    test_str();

    test_map();
    return 0;
}