#include<bits/stdc++.h>
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
#include<fstream>
#include<dirent.h>
using namespace std;


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


void writeAllLines(string filepath, string originalPath)
{
    //cout << filepath << " ... " << originalPath << endl;
    string line;
    ifstream myfile (filepath);
    ofstream outfile;
    outfile.open(originalPath + "/" + "label.txt");
    if (myfile.is_open())
    {
        int cnt = 0;
        string prevstring = "", curstring;
        while (myfile.good() )
        {
            getline (myfile,line);
            int last = 0;
            for(int i = 0; i < line.length(); i++) {
                if(line[i] == '\t') {
                    last = i;
                }
            }
            line.erase(0, last + 1);
            outfile << line << endl;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}

int main()
{

    for(int i = 2; i <= 159; i++)
    {
        string str = convertStr(i);
        writeAllLines("/media/samin/Data2/part 4 modified/A/text/A"+str+"/Label Track.txt", "/media/samin/Data2/part 4 modified/A/text/A"+str);
    }
}
