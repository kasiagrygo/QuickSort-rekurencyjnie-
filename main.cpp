#include <bits/stdc++.h>

using namespace std;

ifstream in;
ofstream out;

vector<int> v;

void Dane(){
in.open("In0201.txt");

int n, a;
in>>n;

for(int i=0;i<n;i++){
    in>>a;
    v.push_back(a);
}

in.close();
}


int Partition(int s, int k){
int p=v[s], l=0;

for(int i=s+1;i<=k;i++){
    if(v[i]<=p)
        l++;
}

//nadanie 1 elementowi wlasciwej pozycji
int ip=s+l;
swap(v[ip], v[s]);

//sortowanie lewej i prawej czesci pierwszego elementu
int i=s, j=k;

while(i<ip&&j>ip){
    while(v[i]<=p)
        i++;
    while(v[j]>p)
        j--;
    if (i<ip&&j>ip)
        swap(v[i++], v[j--]);
}
return ip;
}

void QuickSort(int s, int k)
{
    if (s>=k)
        return;

    int p=Partition(s, k);

    QuickSort(s, p-1);
    QuickSort(p+1, k);
}

int main()
{
    out.open("Out0201.txt");
    Dane();
    QuickSort(0, v.size()-1);

    for(int i=0;i<v.size();i++)
        out<<v[i]<<" ";

    out.close();

    return 0;
}
