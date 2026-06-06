
#include <iostream>
using namespace std;
class Solution {
public:
    int counter(int num1,int num2,int& count){
        if(num1==0 || num2==0) return count;
        if(num1>=num2){
            num1=num1-num2;
         
        }
        else {
            num2=num2-num1;
           
        }
        count++;
        return counter(num1,num2,count);
    }

    int countOperatonMeth(int num1, int num2) {
        int count=0;
        return counter(num1,num2,count);
    }


    int countOperations(int num1, int num2) {
        int count=0;
       
        while(num1!=0&&num2!=0){
            if(num1>=num2) num1=num1-num2;
            else num2=num2-num1;
            count++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    int num1 = 2, num2 = 3;
    int ans = sol.countOperations(num1, num2);
    int ans1 = sol.countOperatonMeth(num1, num2);
    cout << "The number of operations required to reduce both numbers to zero is: " << ans << endl;
    cout << "The number of operations required (recursive) is: " << ans1 << endl;
    return 0;
}