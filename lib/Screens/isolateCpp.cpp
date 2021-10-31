#include <bits/stdc++.h>
// #define testPrint  
using namespace std;
bool testing = false;
bool stress = false;
bool recursion = false;
#define templatify template<typename T>
using ll = long long;
using ull = unsigned long long;
using ld = long double;

template<typename T1,typename T2> ostream& operator<<(ostream &os,pair<T1,T2> &p){os<<p.first<<" "<<p.second;return os;}
template<typename T1,typename T2> istream& operator>>(istream &is,pair<T1,T2> &p){is>>p.first>>p.second;return is;}
templatify istream& operator>>(istream &is,vector<T>&vec){for(int i =0;i<vec.size();i++){ cin>>vec[i]; }  return is;}
templatify void print(T var){
    cerr<<var<<" ";
}
templatify void print(vector<T> vec){
for(auto itr = vec.begin();itr!=vec.end();itr++){
    print(*itr);
}
}

templatify void print(T arr[],ll n){
    for(ll i = 0;i<n;i++){
        print(arr[i]);
    }
}

templatify void print(set<T> st){
    for(auto itr = st.begin();itr!=st.end();itr++){
        print(*itr);
    }
}

template<class T1,class T2> void print(map<T1,T2> mp){
    for(auto itr = mp.begin();itr!=mp.end();itr++){
        print("key: "); print(itr->first);
        print("value: ");print(itr->second);
    }

}

templatify class Debugger{
void print(T var){
    cerr<<var<<" ";
}
void print(vector<T> vec){
for(auto itr = vec.begin();itr!=vec.end();itr++){
    print(*itr);
}
}


Debugger operator<<(T var){
 print(var);
 return Debugger();
}

};



#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";print(x);cerr<<endl;
#define debArr(x,y) cerr<<#x<<" ";print(x,y);cerr<<endl;
#else
#define debug(x) 
#define debArr(x,y) 
#endif

template<class T> void arrInput(T arr[], int n)
{
    
    
    for (int i = 0; i < n; i++)
    {
        T el;
        cin >> el;
        arr[i] = el;
    }
}

template<class T1,class T2> void arrInput(pair<T1,T2> arr[],int n){
    for (int i = 0; i < n; i++)
    {
        pair<T1,T2> el;
        cin >> el;
        arr[i] = el;
    }

}

template<class T> void arrInput(vector<T> &arr, int n)
{
    
    
    for (int i = 0; i < n; i++)
    {
        T el;
        cin >> el;
        arr.push_back(el);
    }
}

template<class T> void arrInput(vector<T> &arr)
{
    
    
    for (int i = 0; i < arr.size(); i++)
    {
        T el;
        cin >> el;
        arr[i] = el;
    }
}

// void printMap(map<int, float> infected[], int n, string message = "printing map function")
// {
//     if (testing)
//     {
//         cout << message << " "
//              << "new print" << endl
//              << endl;

//         for (int i = 0; i < n; i++)
//         {
//             cout << endl
//                  << "map " << i << " " << endl;
//             for (auto j = infected[i].begin(); j != infected[i].end(); j++)
//             {
//                 cout << j->first << " " << j->second << endl;
//             }
//         }
//         cout << endl;
//     }
// }

// void printArray(int n, int arr[], bool forcePrint = false, string message = "printing array")
// {
//     if (testing)
//     { 
//         cout<<message<<" ";
//     }
//     if( testing ||forcePrint)
//         for (int j = 0; j < n; j++)
//         {
//             cout << arr[j] << " ";
//         }
    
// }

// void printSet(set<int,greater<int>> arr){
// if(testing)
// {for(auto i = arr.begin();i!=arr.end();i++){
//     cout<<*i<<" ";
// }
// cout<<endl;}
// }

int placeHigh(int arr[],int low,int high){
    int less = low;
    for(low;low<high;low++){
        if (arr[low]<=arr[high])
        {
            swap(arr[less],arr[low]);
            less++;
        }
        
    }
    swap(arr[less],arr[high]);
    return less;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi = placeHigh(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

// void printValue(string value,string message = "value = "){
//  if(testing)
//  cout<<message<<value<<endl;
// }

void inputSet(set<int,greater<int>> *mySet,int n){
    
    for (int i = 0; i < n; i++)
    {   int el;
    cin>>el;
        (*mySet).insert(el);
    }
    
}

templatify long long binarySearch(vector<T> vec,T el){
    long long low = 0,high = vec.size()-1;
    while(low<=high){
        long long mid = low + abs((high-low)/2);
        if(vec[mid]==el){
            return mid;
        }
        if(el<vec[mid]){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int left(int i,int r){
    int l = (2*i) -  r;
    if(l>1){
        for(l;l>=1;l--){
            int result = left(l-1,i);
            if(result){
                return 1+result;
            }
        }
        return 1;
    }else{
        return 1;
    }
}

int right(int i,int l){
    int r = (2*i) -  l;
    if(r>1){
        for(r;r>=1;r--){
            int result = right(r-1,i);
            if(result){
                return 1+result;
            }
        }
        return 1 ;
    }else{
        return 1;
    }
}

void solve()
{
    int n;
    cin >> n;
    cout<<left(n,n)<<endl;
    int num = left(n,n) + right(n,n);
    cout<<num;

}


templatify void resultPrinter(T var){
    cout<<var<<" ";
}
templatify void resultPrinter(vector<T> vec){
    cout<<vec.size()<<endl;
    for(int i =0;i<vec.size();i++){
        resultPrinter(vec[i]);
        // cout<<endl;
    }
}


void resultPrinter(bool var){
    cout<<(var?"Yes":"No");
}


void takeInput(){

}
bool test(){
    return true;
}
signed main(int arg, char **args)
{

    for(long long i = 1;i<arg;i++){
        char ar = *args[i];
        if(ar =='d'){
            testing = true;
        }else{
            if(ar == 's'){
                stress = true;
            }else{
                if(ar == 'r'){
                    recursion = true;
                }
            }
        }
        
    }
    // if (arg > 1)
    //     *args[1] == 'd' ? testing = true : testing = false;
    // if(arg>2){
    //     stress = (*args[2] == 's' );
    // }
    if(recursion){
        takeInput();
        return 0;
    }
    if(stress){
        return test();
    }else{

    
    long long t=1;
    cin >> t;
    while (t-- > 0)
    {
        // resultPrinter(solve());
        solve();
        cout<<endl;
    }
    }
    return 0;
}