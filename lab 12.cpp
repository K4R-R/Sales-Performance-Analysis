#include<bits/stdc++.h>
using namespace std;
#define e 0.00001
#define ld long double
#define ll long long

ld func(ld x){
    return 2*x+3*x*x+5*x*x*x;
}

ld rect(ld a,ld b,ld n,ld h){
    ld q=0;
    for(ll i=1;i<n+1;i++){
        q+=func(a+((2*i-1)*h)/2);
    }
    q=q*h;

    return q;
}

ld trap(ld a,ld b,ld n,ld h){
    ld q=0;
    for(ll i=1;i<n+1;i++){
        q+=(func(a+i*h)+func(a+(i-1)*h));
    }
    q=q/2;
    q*=h;

    return q;
}

ld simp(ld a,ld b,ld n,ld h){
    ld q,s0,se=0,so=0;
    s0=func(a)+func(b);
    for(ll i=0;i<n+1;i++){
        if(i%2==0){
            se+=func(a+i*h);
        }else{
            so+=func(a+i*h);
        }
    }
    q=(h*(2*se+4*so-s0))/3;

    return q;
}

ld mci(ld a,ld b,ld n,ld h){
    ld q=0,y;
    for(ll i=0;i<n+1;i++){
        q+=func(a+i*h);
    }
    q=q*h;

    return q;

}

int main(){
    ld a,b,n,h,i1,i2,i3,i4;
    cin>>a>>b>>n;
    h=(b-a)/n;
    //cout<<h<<endl;
    i1=rect(a,b,n,h);
    i2=trap(a,b,n,h);
    i3=simp(a,b,n,h);
    i4=mci(a,b,n,h);
    cout<<i1<<endl;
    cout<<i2<<endl;
    cout<<i3<<endl;
    cout<<i4<<endl;

    return 0;
}