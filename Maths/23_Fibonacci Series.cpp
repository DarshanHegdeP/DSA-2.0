#include <bits/stdc++.h>
using namespace std;

int recursion_fib(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else{
        return recursion_fib(n-1)+recursion_fib(n-2);
    }
}

int iterative_fib(int n){
      if(n==0) return 0;
    else if(n==1) return 1;
    int a=0;
    int b=1;
    int c=1;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(){
    cout<<recursion_fib(5)<<endl;
    cout<<iterative_fib(5)<<endl;
}