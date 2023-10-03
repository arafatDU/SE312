#include<bits/stdc++.h>
using namespace std;

string RE, w, s1, s2;
bool isAccepted(string s)
{

}

string pump(string L, int k)
{
    

}

void get_num_from_re()
{
    int i;
    for(i = 0; i < RE.size();++i){
        if(RE[i] == '0' and RE[i+1] == '^'){
            i++;
            break;       
        }
    }
    
    while(RE[++i] != '^'){
        s1+=RE[i];
    }

    if(s1[s1.size()-1] == '1') s1.resize(s1.size()-1);
    while(RE[++i]!='\0'){
        s2+=RE[i];
    }
    
    cout << "s1: " << s1 << endl << "s2: " << s2 << endl;  
    s1.erase(s1.size() - 1);
    s2.erase(s2.size() - 1);
    if(s1.size() == 0) s1 = "1";
}

int main()
{
    freopen("input.txt", "r", stdin);
    int k = 0, r1, r2;
    
    cin >> RE;
    int i;
    cout << "Regular Expression: " << RE << endl;

    //substring from regular expression
    get_num_from_re();

    cout << "s1: " << s1 << endl << "s2: " << s2 << endl; 

    r1 = stoi(s1);
    r2 = stoi(s2);

    cout << "r1: " << r1 << endl << "r2: " << r2 << endl; 




    return 0;
}