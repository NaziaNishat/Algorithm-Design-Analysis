#include<bits/stdc++.h>
using namespace std;

void patternMatch(string txt,string pat)
{
    int flag = 0;
    int lenT = txt.length();
    int lenP = pat.length();

    for(int i=0;i<=lenT-lenP;i++)
    {
        for(int j=0;j<lenP;j++)
        {
            if(txt[i+j] == pat[j])
                flag++;
            else flag = 0;
        }

        if(flag == lenP)
            printf("Pattern found at %dth position\n",i+1);

    }
}


int main()
{
    string txt = "dbcabcfabc";
    string pat = "abc";

    patternMatch(txt,pat);

}
