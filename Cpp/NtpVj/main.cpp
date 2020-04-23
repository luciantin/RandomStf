#include <iostream>
#include <list>
using namespace std;

bool compare_function( string& s1 , string& s2 ){
    return ( s1.length() < s2.length() );
}
int main(){

list<int> l={1,2,3,4,5};
    
    l.push_back(6);
    l.push_back(7);
    /* sad je lista: 1,2,3,4,5,6,7 */
    for (list<int>::iterator i=l.begin(); i!=l.end(); ++i){
		  cout<<*i<<" ";
	  }
    cout<<endl;

    l.push_front(8);
    l.push_front(9);
    /* sad je lista: 9,8,1,2,3,4,5,6,7 */
 for (list<int>::iterator i=l.begin(); i!=l.end(); ++i){
		  cout<<*i<<" ";
	  }
    cout<<endl;

    list<int> list1 = {2,4,5,6,1,3};
    list<string> list2 = {"h", "hhh", "hh"};
    list1.sort();
    /* list1 je sad 1 2 3 4 5 6 */
    for (list<int>::iterator i=list1.begin(); i!=list1.end(); ++i){
		  cout<<*i<<" ";
	  }
    cout<<endl;

    list2.sort(compare_function);
    /* list2 je sad h hh hhh */ 
    for (list<string>::iterator i=list2.begin(); i!=list2.end(); ++i){
		  cout<<*i<<" ";
	  }
    cout<<endl;

    
}

