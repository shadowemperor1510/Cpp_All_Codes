#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,j,k=0;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        k=0;
        cin>>s;
        if(s.at(0)==')' || s.at(s.length()-1)=='(')
        {
            cout<<"No\n";
            continue;
        }
        for(j=0;j<s.length();j++)
        {
            if(s[j]=='('){k++;}
            if(s[j]==')'){k--;}
            if(k<0){
                cout<<"No\n";
            }
            
        }
        if(k==0)
            {
                cout<<"Yes\n";
            }
        if(k!=0){
            cout<<"No\n";
        }
    }
        
    return 1;
}



 int n,p,o;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      scanf("%d",&p);
      m->data=p;
      m->next=head;
      head=m;
      temp=head;
      while(temp!= NULL)
        {
          if(temp->data >= temp->next->data)
          {
            head=temp->next;
            //head->data=temp->next->data;
            temp->next=temp;
            //temp->next->data=temp->data;
          }
          else
          {
            temp=NULL;
          }
        }
    }
  
      scanf("%d",&o);
      temp=head;
      while(temp!=NULL)
        {
          if(o==temp->data && temp==head)
          {
            printf("%d",-1);
            temp=NULL;
          }
          else if(o==temp->data)
          {
            copy=temp;
            break;
          }
        }
  if(temp!=NULL)
  {
          u->next=copy;
        copy->prev=u;
    printf("%d",u->data);
  }