#include<iostream>
#include<map>
using namespace std;
int main()
{
        std::map<char, int> table1;
        std::map<char, int> table2;
        int t;
        cin>>t;
        int i;
        while(t--) {
                string a;
                string b;
                cin>>a;
                cin>>b;
                i = 0;
                while(a[i] != '\0') {
                        table1[a[i]]++;
                        i++;
                }
                i = 0;
                while(b[i] != '\0') {
                        table2[b[i]]++;
                        i++;
                }
                int flag = 0;
                typedef std::map<char,int>::iterator it;
                for (it iterator = table1.begin(); iterator != table1.end(); iterator++) {
			if(iterator->second >1) {
				flag = 1;
				break;
				}
				for (it iterator = table2.begin(); iterator != table2.end(); iterator++) {
			if(iterator->second >1) {
				flag = 1;
				break;
				}
			
                }
                if(flag == 1)
                	cout<<("Yes\n");
                else 
                	cout<<("No\n");
                table1.clear();
                table2.clear();
        }
        return 0;
}

