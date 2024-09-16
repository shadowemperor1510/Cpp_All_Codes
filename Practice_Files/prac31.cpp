#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string, int> ma;
    ma["ag"]=98;
    ma["od"]=97;
    ma["ng"]=69;
    map<string, int> :: iterator it;

    for(it=ma.begin(); it!=ma.end(); it++)
    {
        cout<<(*it).first<<"  "<<(*it).second<<endl;
    }

    ma.insert({{"pc", 96}, {"nd", 97}});

    for(it=ma.begin(); it!=ma.end(); it++)
    {
        cout<<(*it).first<<"  "<<(*it).second<<endl;
    }
    cout<<"size= "<<ma.size()<<endl;
    return 0;
}