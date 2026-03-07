#include<bits/stdc++.h>
#include "2105052_symbol_table.hpp"
using namespace std;
#define dbg(x) cout<<#x<<" = "<<x<<endl;

void insertHandler(SymbolTable* st,string str){
    stringstream ss(str);
    string name,type;
    ss>>name;
    getline(ss,type);
    type.erase(0, type.find_first_not_of(' '));
    SymbolInfo * symbol1 = new SymbolInfo(name,type);
    bool temp = st->insert(symbol1);
}


void deleteHandler(SymbolTable* st,string str){
    SymbolInfo* symbol = st->look_up(str);
    if(symbol==nullptr){
        return;
    }
    int i = symbol->i;  
    int j = symbol->j;
    int scope_id = symbol->getScopeId();
    bool temp1 = st->Delete(str);
}

void lookUpHandler(SymbolTable* st,string str){
    SymbolInfo* symbol = st->look_up(str);
}   

void printCurrentScopeHandler(SymbolTable* st){
    // st->print_current_scope();
}
void printAllScopeHandler(SymbolTable* st){
    // st->print_all_scope();
}

void enterScopeHandler(SymbolTable* st){
    st->enter_scope();
    ScopeTable* temp = st->getCurrentScope();
}
void exitScopeHandler(SymbolTable* st){
    ScopeTable* temp = st->getCurrentScope();
    st->exit_scope();
}
int main(int argc, char** argv){ 
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
    #endif

    int num_bucket;
    cin>>num_bucket;
    cin.ignore();
  
    uint (*hash_func)(string,uint) = SDBMHash;
    uint (*hash_func1)(string,uint) = fnvHash;
    uint (*hash_func2)(string,uint) = djb2;


    SymbolTable* st = new SymbolTable(num_bucket,hash_func);
    SymbolTable* st1 = new SymbolTable(num_bucket,hash_func1);
    SymbolTable* st2 = new SymbolTable(num_bucket,hash_func2);
    // cout<<"\tScopeTable# "<<st->getCurrentScope()->getTableId()<<" created"<<endl;
    int command_num = 1;
    while(1){
        string str;
        getline(cin,str);
        stringstream ss(str);
        string command;
        ss>>command;

        if(command =="I"){
            string str ;
            getline(ss,str);
            if(str.empty()){
                continue;
            }
            insertHandler(st,str);
            insertHandler(st1,str);
            insertHandler(st2,str);
        }
            

        else if(command =="L"){
            string name,str;
            ss>>name>>str;
            if(!str.empty() or name.empty()){
                continue;
            }
            lookUpHandler(st,name);
            lookUpHandler(st1,name);
            lookUpHandler(st2,name);

        }
        else if(command =="D"){
            string name,str;
            ss>>name>>str;
            if(!str.empty() or name.empty()){
                continue;
            }
            deleteHandler(st,name); 
            deleteHandler(st1,name);
            deleteHandler(st2,name);
        }
        else if(command =="P"){
            string name;
            ss>>name;
            if(name=="C"){
                printCurrentScopeHandler(st);
                printCurrentScopeHandler(st1);
                printCurrentScopeHandler(st2);
            }
            else if(name=="A"){
                printAllScopeHandler(st);
                printAllScopeHandler(st1);
                printAllScopeHandler(st2);
            }
            else if(name.empty()){
                continue;
            }

        }
        else if(command =="S"){
            enterScopeHandler(st);
            enterScopeHandler(st1);
            enterScopeHandler(st2);
        }
        else if(command =="E"){
            exitScopeHandler(st);
            exitScopeHandler(st1);
            exitScopeHandler(st2);
        }
        else if(command =="Q"){
            break;
        }
    }
    double mean1 = st->getMeanRatio();
    double mean2 = st1->getMeanRatio();
    double mean3 = st2->getMeanRatio();

    cout<<"SDBMHash: "<<mean1<<endl;
    cout<<"FNVHash: "<<mean2<<endl;
    cout<<"djb2: "<<mean3<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"FNV Hash source: https://gist.github.com/hwei/1950649d523afd03285c#file-const_fvn_hash-cpp-L6"<<endl;
    cout<<"djb2 Hash source: https://stackoverflow.com/questions/19892609/djb2-by-dan-bernstein-for-c"<<endl;
    
    delete st;
    delete st1;
    delete st2;
    return 0;
}