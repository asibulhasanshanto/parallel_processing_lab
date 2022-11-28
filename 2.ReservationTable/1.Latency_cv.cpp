#include<iostream>
#include<stdio.h>
using namespace std;

int reservation_table[10][10];

int main(){
    int i,j,k,l,m,n;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // reading from file and storing in reservation table
    cin>>m>>n;
    int store[n+1] = {0};

    for(i = 1;i<=m;i++){
        for(j = 1;j<=n;j++){
            cin>>reservation_table[i][j];
        }
    }


    // calculate forbidden and permissible latency
    for(i = 1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(reservation_table[i][j]==1 && j!=1){
                for(k=j;k>=1;k--){
                    int difference;
                    difference = reservation_table[i][j]-reservation_table[i][k];
                    if(difference == 0){
                        store[j-k] = 1;
                    }
                } 
            }
        }
    }

    // print forbidden latencies
    int max_forbidden_latency = 0;
    cout<<"Forbiden latencies: ";
    for(i=1;i<=n;i++){
        if(store[i]==1){
            cout<<i<<" ";
            max_forbidden_latency = i;
        }
    }
    cout<<endl;

    cout<<"Permissible latencies: ";
    for(i = 1;i<=n;i++){
        if(store[i] == 0){
            cout<<i<<" ";
        }
    }
    cout<<endl;

    cout<<"collision vector: ";
    for(i = max_forbidden_latency;i>=1;i--){
        cout<<store[i]<<" ";
    }
    cout<<endl;

    // collision points
    int latency = 2;

    cout<<"collision points for latency "<< latency<<"(m,n) :  "<<endl;
    for(i = 1;i<=m;i++){
        for(j = 1;j<=n;j++){
            if(reservation_table[i][j]==1 && reservation_table[i][j+latency]==1){
                cout<<"("<<i<<","<<j<<")"<<endl;
            }
        }
    }

    // // print reservation table
    // for(i = 1;i<=m;i++){
    //     for(j = 1;j<=n;j++){
    //         cout<<reservation_table[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}