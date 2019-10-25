#include<bits/stdc++.h>
#include <sstream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void separate(string fileNo)
{
    string path = "/media/samin/Data2/part 4 modified/A/text/";
    std::ifstream input(path + "A" + fileNo +"/label.txt");



    int i = 1;
    for( std::string line; getline( input, line ); )
    {
    if(line.length()==0) break;
    int num = i;
    std::string s = std::to_string(num);
    string str;
    if(i>9) str = "p4_A"+ fileNo + "_" + s + ".txt";
    else str = "p4_A"+ fileNo + "_" + "0" + s + ".txt";

    ofstream outfile;
    outfile.open(path + "A" + fileNo + "/" + str);

    outfile << line << endl;

    outfile.close();

    i++;


    }
}

int main()
{
    for(int i=11;i<=159;i++){
      separate(to_string(i));
    }
    return 0;

}

