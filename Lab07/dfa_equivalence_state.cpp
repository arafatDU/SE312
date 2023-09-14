#include<bits/stdc++.h>
using namespace std;

#define STATES 8
#define SYMBOLS 2

string initialState, finalstate;
string dfa_transition[STATES][SYMBOLS+1];
string TF[STATES][STATES];

void readInput()
{
    cin>>initialState>>finalstate;
    for(int i=0; i<STATES; i++)
    {
        for(int j=0; j<SYMBOLS + 1; j++)
        {
            cin>>dfa_transition[i][j];
        }
    }
}



bool isEquivalence(string s1, string s2)
{
    int index1, index2;
    if(s1 == finalstate || s2 == finalstate) return false;

    for(int i=0; i<STATES; i++)
        if(dfa_transition[i][0] == s1) index1 = i;

    for(int j=0; j<STATES; j++)
        if(dfa_transition[j][0] == s2) index2 = j;

    //cout<<endl<<"For index "<<index1<<" and "<<index2<<endl;

    if(dfa_transition[index1][1] == finalstate && dfa_transition[index2][1] != finalstate) return false;
    else if(dfa_transition[index1][1] != finalstate && dfa_transition[index2][1] == finalstate) return false;
    
    else if(dfa_transition[index1][2] == finalstate && dfa_transition[index2][2] != finalstate) return false;
    else if(dfa_transition[index1][2] != finalstate && dfa_transition[index2][2] == finalstate) return false;

    else{
        
    }

    return true;

}


int main()
{
    freopen("input.txt", "r", stdin);
    readInput();


    // Print given transition table
    cout<<finalstate<<endl;
    cout<<"  0 1"<<endl;
    for(int i=0; i<STATES; i++)
    {
        for(int j=0; j<SYMBOLS + 1; j++)
        {
            cout<<dfa_transition[i][j]<<" ";
        }
        cout<<endl;
    }


    // Initialize all to 'X'
    for(int i=1; i<STATES; i++)
    {
        for(int j=0; j<i; j++)
        {
            TF[i][j] = "X";
        }
    }


    // Checking the equivalence state
    // case 01: 
    string s1, s2;
    for(int i=1; i<STATES; i++)
    {
        s1 = dfa_transition[i][0];
        for(int j=0; j<i; j++)
        {
            s2 = dfa_transition[j][0];
            cout<<"("<<s1<< " "<< s2<<") ";
            if(isEquivalence(s1, s2)) TF[i][j] = "=";
        }
    }



    cout<<endl<<endl;
    // Print Table Fillin TF
    for(int i=1; i<STATES; i++)
    {
        cout<< dfa_transition[i][0]<< " ";
        for(int j=0; j<i; j++)
        {
            cout<<TF[i][j]<< " ";
        }
        cout<<endl;
    }



    return 0;
}