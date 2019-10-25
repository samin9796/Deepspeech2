#include<bits/stdc++.h>
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
#include<fstream>
#include<dirent.h>
using namespace std;
ofstream outputFile("part4A.csv");
int cnt = 0;
string globalPath = "/data/ahnaf/speech_dataset/our_dataset/part4/A";
void listFile(string curDir)
{
    int curCNt = 0;
    DIR *pDIR;
    struct dirent *entry;
    string path = "/media/samin/Data2/part 4 modified/A/text/" + curDir;
    string wavpath = "/media/samin/Data2/part 4 modified/A/wav/" + curDir;
    string modified_txt_path = globalPath + "/text4/";
    string modified_wav_path = globalPath + "/wav4/";
    char str[100];
    char namestr[100];
    vector<string> vt;
    for(int i = 0; i < path.length(); i++)
    {
        str[i] = wavpath[i];
    }
    if( pDIR=opendir(str) )
    {
        while(entry = readdir(pDIR))
        {
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 )
                vt.push_back(entry->d_name);
        }
        closedir(pDIR);
    }
    for(string st : vt)
    {
        string tmp = st;
        int sz = tmp.size();
        if(sz < 20) continue;
        string textpath = "";
        if(st[sz-7]!='-') textpath += st[sz - 7];
        textpath += st[sz - 6];
        textpath += st[sz - 5];
        textpath += ".txt";
        char change[] = "txt";
        tmp[sz - 1] = change[0];
        tmp[sz  - 2] = change[1];
        tmp[sz  - 3] = change[2];
        tmp = textpath;
        if(1)
        {
            outputFile << modified_wav_path + curDir + '/' + st << "," << modified_txt_path  + curDir + "/p4_" + curDir + '_' + tmp << endl;
        }
        cnt++;
        curCNt++;
    }

}

string convertStr(int number)
{
    stack<char> STACK;
    while(number)
    {
        char ch = '0' + (number % 10);
        STACK.push(ch);
        number /= 10;
    }
    string str = "";
    while(!STACK.empty())
    {
        str += STACK.top();
        STACK.pop();
    }
    return str;
}

int main()
{
    //listFile("0");
    for(int i = 1; i <= 200; i++)
    {
        string str = 'A' + convertStr(i);
        listFile(str);
        //modifyLabelText(str);
    }
    cout << cnt << endl;
}
