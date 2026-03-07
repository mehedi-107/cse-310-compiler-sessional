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
    SymbolInfo* symbol = st->look_up(name);
    if(temp){
        cout<<"\tInserted in ScopeTable# "<<symbol->getScopeId()<<" at position "<<symbol->i+1<<", "<<symbol->j+1<<endl;
    }
    else{
        cout<<"\t'"<<name<<"' already exists in the current ScopeTable"<<endl;
    }
}


void deleteHandler(SymbolTable* st,string str){
    SymbolInfo* symbol = st->look_up(str);
    if(symbol==nullptr){
        cout<<"\tNot found in the current ScopeTable"<<endl;
        return;
    }
    int i = symbol->i;  
    int j = symbol->j;
    int scope_id = symbol->getScopeId();
    bool temp1 = st->Delete(str);
    if(temp1){
        cout<<"\tDeleted '"<<str<<"' from ScopeTable# "<<scope_id<<" at position "<<i+1<<", "<<j+1<<endl;
    }
    else{
        cout<<"\tNot found in the current ScopeTable"<<endl;
    }
}

void lookUpHandler(SymbolTable* st,string str){
    SymbolInfo* symbol = st->look_up(str);
    if(symbol!=nullptr){
        cout<<"\t'"<<str<<"' found in ScopeTable# "<<symbol->getScopeId()<<" at position "<<symbol->i+1<<", "<<symbol->j+1<<endl;
    }
    else{
        cout<<"\t'"<<str<<"' not found in any of the ScopeTables"<<endl;
    }
}   

void printCurrentScopeHandler(SymbolTable* st){
    // cout<<"ScopeTable# "<<st->curr_scope->getTableId()<<endl;
    st->print_current_scope();
}
void printAllScopeHandler(SymbolTable* st){
    st->print_all_scope();
}

void enterScopeHandler(SymbolTable* st){
    st->enter_scope();
    ScopeTable* temp = st->getCurrentScope();
    cout<<"\tScopeTable# "<<temp->getTableId()<<" created"<<endl;
}
void exitScopeHandler(SymbolTable* st){
    ScopeTable* temp = st->getCurrentScope();
    cout<<"\tScopeTable# "<<temp->getTableId()<<" removed"<<endl;
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
    // dbg(argv[3]);
    if(argv[3]!=nullptr and strcmp(argv[3], "djb2") == 0){
        hash_func = djb2;
        // cout<<"djb2 working"<<endl;
    }
    else if(argv[3]!=nullptr and strcmp(argv[3], "fnv") == 0){
        hash_func = fnvHash;
        // cout<<"fnv working"<<endl;
    }
    SymbolTable* st = new SymbolTable(num_bucket,hash_func);
    cout<<"\tScopeTable# "<<st->getCurrentScope()->getTableId()<<" created"<<endl;
    int command_num = 1;
    while(1){
        string str;
        getline(cin,str);
        string* arr = process_str(str);
        stringstream ss(str);
        cout<<"Cmd "<<command_num++<<": ";
        for(int i = 0; arr[i]!="";i++){
            cout<<arr[i];
            if(arr[i+1]!="") cout<<" ";
        }
        delete[] arr;
        cout<<endl;
        string command;
        ss>>command;

        if(command =="I"){
            string str ;
            getline(ss,str);
            if(str.empty()){
                cout<<"\tNumber of parameters mismatch for the command"<<endl;
                continue;
            }
            insertHandler(st,str);
        }
            

        else if(command =="L"){
            string name,str;
            ss>>name>>str;
            if(!str.empty() or name.empty()){
                cout<<"\tNumber of parameters mismatch for the command L"<<endl;
                continue;
            }
            lookUpHandler(st,name);
        }
        else if(command =="D"){
            string name,str;
            ss>>name>>str;
            if(!str.empty() or name.empty()){
                cout<<"\tNumber of parameters mismatch for the command D"<<endl;
                continue;
            }
            deleteHandler(st,name); 
        }
        else if(command =="P"){
            string name;
            ss>>name;
            if(name=="C"){
                printCurrentScopeHandler(st);
            }
            else if(name=="A"){
                printAllScopeHandler(st);
            }
            else if(name.empty()){
                cout<<"\tNumber of parameters mismatch for the command P"<<endl;
                continue;
            }

        }
        else if(command =="S"){
            enterScopeHandler(st);
        }
        else if(command =="E"){
            exitScopeHandler(st);
        }
        else if(command =="Q"){
            break;
        }
    }
    ScopeTable* temp = st->getCurrentScope();
    while(temp!=nullptr){
        cout<<"\tScopeTable# "<<temp->getTableId()<<" removed"<<endl;
        temp = temp->getParentScope();
    }

    delete st;
    return 0;
}