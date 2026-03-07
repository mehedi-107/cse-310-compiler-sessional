#pragma once
#include<bits/stdc++.h>
#include "2105052_hash_func.hpp"
using namespace std;
#define dbg(x) cout<<#x<<" = "<<x<<endl;

typedef unsigned int uint;

inline string* process_str(string str){
    int cnt = 0,k=0;
    string st;
    while(k<str.size()){
        if(str[k]==' '){
            if(st.size()!=0){
            st.clear();cnt++;
            }
        }
        else st+=str[k];
        k++;
    }

    if(st.size()!=0) cnt++;
    string* token = new string[cnt+1];
    st.clear(); k=0; cnt=0;
    while(k<str.size()){
        if(str[k]==' '){
            if(st.size()!=0) {
                token[cnt++]=st;
                // dbg(token[cnt-1]);
                st.clear();
            }
        }
        else st+=str[k];
        k++;
    }
    if(st.size()!=0) token[cnt++]=st;
    token[cnt] = "";
    return token;
}


class Parameter{
    private:
        string name;
        string type;
    public:
        Parameter(string name,string type){
            this->name = name;
            this->type = type;
        } 

        string getName(){
            return this->name;
        }
        string getType(){
            return this->type;
        }
        void setName(string name){
            this->name = name;
        }
        void setType(string type){
            this->type = type;
        }

};


class SymbolInfo{
    private :
        string name;
        string type;
        Parameter** param_arr;
        int param_count;
    public:
        SymbolInfo* next;
        int i,j,scope_id;
        int stack_offset;
        SymbolInfo (string name,string type){
            this->name = name;
            i = j = 0;
            this->stack_offset = 0;
            string* arr = process_str(type);
            this->type = arr[0];
            int cnt = 0;
            for(int m = 0;arr[m]!="";m++){
                cnt++;
            }
            int index = 0;
            if(arr[0]=="FUNCTION"){
                param_count = cnt-1; 
                param_arr = new Parameter*[param_count]();
                for(int k=1;k<cnt;k++){
                    // dbg(arr[k]);
                    this->param_arr[index++] = new Parameter("",arr[k]);
                }
            }
            else if(arr[0]=="STRUCT" or arr[0]=="UNION"){
                param_count = (cnt-1)/2;
                param_arr = new Parameter*[param_count]();
                for(int k = 1; k<cnt;k+=2){
                    this->param_arr[index++] = new Parameter(arr[k+1],arr[k]);
                    // dbg(this->param_arr[index-1]->getName());
                }
            }
            else{
                this->param_arr = nullptr;
            }
            this->next = nullptr;
            delete[] arr;
        } 

        void setOffset(int offset){
            this->stack_offset = offset;
        }
        int getOffset(){
            return this->stack_offset;
        }

        string getName(){
            return this->name;
        }
        string getType(){
            return this->type;
        }
        Parameter* getParam(int index){
            return this->param_arr[index];
        }

        Parameter** getParamList(){
            return this->param_arr;
        }

        int getParamCount(){
            return this->param_count;
        }

        void setScopeId(int scope_id){
            this->scope_id = scope_id;
        }

        int getScopeId(){
            return this->scope_id;
        }

        bool isFunction(){
            return this->type=="FUNCTION";
        }
        string getReturnType(){
            if(this->type!="FUNCTION") return "";
            return this->param_arr[0]->getType();
        }

        vector<string> getFuncParamType(){
            if(this->isFunction()==false) return vector<string>();
            vector<string> param_types;
            for(int i = 1; i<this->param_count; i++){
                param_types.push_back(this->param_arr[i]->getType());
            }
            return param_types;

        }   

        void setName(string name){

            this->name = name;
        }
        void setType(string type){
            // cout<<"Setting type "<<type<<" for "<<this->name<<endl;
            // cout<<"Setting type "<<type<<"for "<<this->name<<endl;
            this->type = type;
        }
        

        ~SymbolInfo(){
            if(this->param_arr!=nullptr){
                for(int i =0; i<this->param_count; i++){
                    delete this->param_arr[i];
                }
                delete[] this->param_arr;
                
            }
            // cout<<"\tSymbolInfo "<<this->name<<" removed"<<endl;
        }
};

class ScopeTable{
    private:
        int table_id;
        ScopeTable* parent_scope;
        int num_bucket;
        SymbolInfo** hashTable;
        uint (*hash_func)(string,uint);
        string name;
        
    public:
        int collision_cnt;
        int child_cnt;
        ScopeTable(int num_bucket,int table_id,uint (*hash_func)(string,uint),string name, ScopeTable* parent_scope = nullptr) {
            this->num_bucket   = num_bucket;
            this->parent_scope = parent_scope;
            this->table_id     = table_id;
            this->hash_func = hash_func;
            this->name = name;
            hashTable = new SymbolInfo*[num_bucket]();
            for(int i =0; i<num_bucket; i++){
                hashTable[i] = nullptr;
            }
            collision_cnt = 0;
            this->child_cnt = 1;
        }

        bool insert(SymbolInfo* symbol){
            // cout<<"inserting into scopetable"<<endl;
            uint hash_index = this->hash_func(symbol->getName(), this->num_bucket);
            hash_index = hash_index % this->num_bucket;
            SymbolInfo* curr_ptr = this->hashTable[hash_index];
            // dbg(hash_index);
            if(curr_ptr==nullptr){
                this->hashTable[hash_index] = symbol;
                symbol->i = hash_index;
                symbol->j = 0;
                symbol->scope_id = this->table_id;
                // collision_cnt++;
                return true;
            }
            int cnt=0;
            while(curr_ptr->next!=nullptr){
                if(curr_ptr->getName()==symbol->getName()){
                    delete symbol; 
                    return false;
                }
                curr_ptr = curr_ptr->next;
                cnt++;
            }
            if(curr_ptr->getName()==symbol->getName()){
                delete symbol;
                return false;
            }
            curr_ptr->next = symbol;
            symbol->i = hash_index;
            symbol->j = cnt+1;
            symbol->scope_id = this->table_id;
            collision_cnt++;
            return true;
        }

        SymbolInfo* look_up(string symbol){
            uint hash_index = hash_func(symbol,this->num_bucket);
            hash_index = hash_index % this->num_bucket;
            SymbolInfo* curr_ptr = this->hashTable[hash_index];
            // dbg(hash_index);
            while(curr_ptr != nullptr){
                if(curr_ptr->getName()==symbol) {
                    return curr_ptr;
                }
                curr_ptr = curr_ptr->next;
            }
            return nullptr;
        }

        bool Delete(string symbol){
            uint hash_index = hash_func(symbol,this->num_bucket);
            hash_index = hash_index % this->num_bucket;
            SymbolInfo* curr_ptr = this->hashTable[hash_index];
            SymbolInfo* prev_ptr = nullptr;
            while(curr_ptr!=nullptr){
                if(curr_ptr->getName()==symbol){
                    if(prev_ptr==nullptr){
                        this->hashTable[hash_index] = curr_ptr->next;
                    }
                    else{
                        prev_ptr->next = curr_ptr->next;
                    }
                    delete curr_ptr;
                    return true;
                }
                prev_ptr = curr_ptr;
                curr_ptr = curr_ptr->next;
            }
            return false;
        }

        int getTableId(){
            return this->table_id;
        }
        ScopeTable* getParentScope(){
            return this->parent_scope;
        }

        void printHashTable(){
            for(int i =0; i<this->num_bucket; i++){
                SymbolInfo* curr_ptr = this->hashTable[i];
                cout<<i+1<<"--> ";
                while(curr_ptr!=nullptr){
                    cout<<"<"<<curr_ptr->getName()<<","<<curr_ptr->getType()<<"> ";
                    curr_ptr = curr_ptr->next;
                }
                cout<<endl;
            }
        }
        
        void print(int indent=0){
            string spaces(indent,'\t');
            cout<<spaces<<"ScopeTable # "<<name<<endl;
            for(int i =0; i<this->num_bucket; i++){
                SymbolInfo* curr_ptr = this->hashTable[i];
                cout<<spaces<<i+1<<"--> ";
                while(curr_ptr!=nullptr){
                    cout<<"<"<<curr_ptr->getName()<<","<<curr_ptr->getType();
                    if(curr_ptr->getType()=="STRUCT" or curr_ptr->getType()=="UNION"){
                        // dbg(curr_ptr->getType());
                        Parameter** param_list = curr_ptr->getParamList();
                        cout<<",{";
                        int n = curr_ptr->getParamCount();
                        for(int i =0; i<n; i++){
                            cout<<"("<<param_list[i]->getType()<<","<<param_list[i]->getName()<<")";
                            if(i!=n-1) cout<<",";
                        }
                        cout<<"}";
                    }
                    else if(curr_ptr->getType()=="FUNCTION"){
                        Parameter** param_list = curr_ptr->getParamList();
                        int n = curr_ptr->getParamCount();
                        cout<<","<<param_list[0]->getType()<<"<==(";
                        for(int i =1; i<n; i++){
                            cout<<param_list[i]->getType();
                            if(i!=n-1) cout<<",";
                        }
                        cout<<")";
                    }
                    curr_ptr = curr_ptr->next;
                    cout<<"> ";
                }
                cout<<endl;
            }
        }

        void print_for_lex(){
            cout<<"ScopeTable # "<< this->name<<endl;
            for(int i =0; i<this->num_bucket; i++){
                SymbolInfo* curr_ptr = this->hashTable[i];
                if(curr_ptr == nullptr) continue;
                cout<<i<<" --> ";
                while(curr_ptr!=nullptr){
                    if(curr_ptr->getName()!="")
                        cout<<"< "<<curr_ptr->getName()<<" : "<<curr_ptr->getType()<<" >";
                    else
                        cout<<"< "<<curr_ptr->getType()<<" >";
                    curr_ptr = curr_ptr->next;
                }
                cout<<endl;
            }
        }


        void print_in_file(ofstream& file){
            file<<"ScopeTable # "<<this->name<<endl;
            for(int i =0; i<this->num_bucket; i++){
                SymbolInfo* curr_ptr = this->hashTable[i];
                if(curr_ptr == nullptr) continue;
                file<<i<<" --> ";
                while(curr_ptr!=nullptr){
                    file<<"< "<<curr_ptr->getName()<<" : ID >";
                    curr_ptr = curr_ptr->next;
                }
                file<<endl;
            }
        }

        

        string getName(){
            return this->name;
        }

        int get_child_cnt_n_incre(){
            child_cnt++;
            return child_cnt-1;
        }

        ~ScopeTable(){
            for(int i =0; i<this->num_bucket; i++){
                SymbolInfo* curr_ptr = this->hashTable[i];
                while(curr_ptr!=nullptr){
                    SymbolInfo* temp = curr_ptr;
                    curr_ptr = curr_ptr->next;
                    string name = temp->getName();
                    delete temp;
                    // cout<< "deleted "<<name<<endl;
                }
            }
            // cout<<"\tScopeTable# "<<this->table_id<<" removed"<<endl;
            delete[] hashTable;
        }
};


class SymbolTable{
    private:
        int num_bucket;
        int table_id;
        uint (*hash_func)(string,uint);
        ScopeTable* curr_scope;
        int collision_cnt;
    public:
        SymbolTable(int num_bucket,uint (*hash_func)(string,uint) = SDBMHash){
            this->hash_func = hash_func;
            this->num_bucket = num_bucket;
            this->table_id = 1;
            string str = to_string(table_id);
            curr_scope = new ScopeTable(num_bucket,table_id++,hash_func, str);
            collision_cnt = 0;
        }

        void enter_scope(){
            string name = curr_scope->getName() + "." + to_string(curr_scope->get_child_cnt_n_incre());
            ScopeTable* new_scope = new ScopeTable(num_bucket,table_id++,hash_func,name,curr_scope);
            curr_scope = new_scope;
        }

        void exit_scope(){
            if(curr_scope->getParentScope()==nullptr){
                // cout<<"No scope to exit"<<endl;
                return;
            }
            ScopeTable* temp = curr_scope;
            collision_cnt+= temp->collision_cnt;
            curr_scope = curr_scope->getParentScope();
            delete temp;
        }

        bool insert(SymbolInfo* symbol){
            // cout<<"inserting"<<endl;
            return curr_scope->insert(symbol);
            // cout<<"inserted"<<endl;
        }

        bool Delete(string symbol){
            return curr_scope->Delete(symbol);

        }

        ScopeTable* getCurrentScope(){
            return curr_scope;
        }

        SymbolInfo* look_up(string symbol){
            return curr_scope->look_up(symbol);
        }

        SymbolInfo* look_up_in_all_scope(string symbol){
            ScopeTable* temp = curr_scope;
            while(temp!=nullptr){
                SymbolInfo* res = temp->look_up(symbol);
                if(res!=nullptr) return res;
                temp = temp->getParentScope();
            }
            return nullptr;
        }


        void print_current_scope(){
            curr_scope->print(1);
        }

        void print_current_scope_lex(){
            curr_scope->print_for_lex();
        }
        

        void print_all_scope(){
            ScopeTable* temp = curr_scope;
            int cnt = 1;    
            while(temp!=nullptr){
                temp->print(cnt++);
                temp = temp->getParentScope();
            }
        }

        void print_all_scope_lex(){
            ScopeTable* temp = curr_scope;  
            while(temp!=nullptr){
                temp->print_for_lex();
                temp = temp->getParentScope();
            }
        }

        void print_all_scope_in_file(ofstream& file){
            ScopeTable* temp = curr_scope;
            while(temp!=nullptr){
                temp->print_in_file(file);
                temp = temp->getParentScope();
            }
        }

        double getMeanRatio(){
            int cnt = collision_cnt;
            ScopeTable* temp = curr_scope;
            while(temp!=nullptr){
                cnt+=temp->collision_cnt;
                temp = temp->getParentScope();
            }
            double mean = cnt/(double)num_bucket;
            // dbg(mean);
            return mean/double(table_id-1);
        }
        
        ~SymbolTable(){
            while(curr_scope!=nullptr){
                ScopeTable* temp = curr_scope;
                int name = curr_scope->getTableId();
                curr_scope = curr_scope->getParentScope();
                delete temp;
                // cout<<"\tScopeTable# "<<name<<" removed"<<endl;
            }
        }
};


