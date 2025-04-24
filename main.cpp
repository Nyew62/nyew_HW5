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
 bool searchDeque(deque<Profile>& pq, Profile&)

int main() {

}

