#include <bits/stdc++.h> 
using namespace std;

struct item {
    int weight;
    int value;
};

int knapSack(item items[],int capacity,int n){
    if(n&&capacity){
        if(capacity>=items[n-1].weight){
            return max(items[n-1].value+knapSack(items,capacity-items[n-1].weight,n-1),knapSack(items,capacity,n-1));
        }
        else return knapSack(items,capacity,n-1);
    }
    return 0;
}

int main(){
    int n;
    cout<<"Enter the number of items ";
    cin>>n;
    item items[n];
    for(int i = 0; i<n; i++) {
        cin>>items[i].weight;
        cin>>items[i].value;
    }
    cout<<"Enter capacity ";
    int capacity;
    cin>>capacity;
    cout<<knapSack(items,capacity,n);
    return 0;
}
