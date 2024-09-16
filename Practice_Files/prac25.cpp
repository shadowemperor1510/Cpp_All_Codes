#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string s1="ag and od";
    string s2;
    ofstream out("file1.txt");
    out<<s1;

    ifstream in("file2.txt");
    getline(in,s2);
    cout<<s2;

    string s3;
    cin>>s3;
    ofstream out2("file3.txt");
    out2<<s3;

    ifstream in2("file3.txt");
    string s4;
    getline(in2, s4);
    cout<<s4;

    out2.close();
    in2.close();
    return 0;
}