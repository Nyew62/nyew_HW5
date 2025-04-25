/*************************************************************************
** Author : A'Nyla Weathers
** Program : hw5, q1
** Date Created : April 23, 2025
** Date Last Modified : April 24, 2025
** Usage : No command line arguments
**
** Problem:


*************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <deque>
#include "MyList.h"
using namespace std;

struct Profile{
    string fulln;
    string state;

    bool operator==(Profile r){
        return fulln==r.fulln;
    }
    bool operator!=(Profile r){
        return fulln != r.fulln;
    }
};
ostream& operator<<(ostream& out, Profile& user){
    out << user.fulln << "---" << user.state;
    return out;
}
 bool searchDeque(deque<Profile>& pq, Profile&);

int main() {
MyList<Profile> pMyList;
queue<Profile> pqueue;
deque<Profile> pdeque;
Profile temp;
string line;

ifstream file("presidentsWstates.txt");
if (file.is_open()){
    while(getline(file,line)){
        stringstream ss(line);
        getline(ss, temp.fulln,'\t');
        getline(ss, temp.state,'\t');
        pMyList.insertHead(temp);
        pqueue.push(temp);
        pdeque.push_front(temp);
    }


}else{
    cout<<"cant open file"<<endl;
}

cout << "List: "<<endl;



cout << "Queue: "<< endl;
while(!pqueue.empty()){
    cout << pqueue.front()<<endl;
    pqueue.pop();
}


for (deque<Profile>::iterator dIte=pdeque.begin(); dIte!=pdeque.end();dIte++){
    cout<<*dIte<<endl;
}

for (int i=0; i<pdeque.size(); i++){
    cout << pdeque[i]<<endl;

    temp.fulln="John Tyler";
    if(searchDeque(pdeque,temp)){
        cout <<"found: "<<temp<<endl;
    }
    else{
        cout <<"name not found: "<<temp<<endl;
    }
}
return 0;


}

bool searchDeque(deque<Profile> &pq, Profile &president){
    for(Profile &p:pq)
        if(p==president){
            president=p;
            return true;
        }
        return false;

}
