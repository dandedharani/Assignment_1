#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct SymTable{
const char *pcKey;
const char *pvValue;
SymTable *n;
SymTable *oSymTable;
};


// function used to create new SymTable
struct SymTable* SymTable_new(){
    struct SymTable *SymTable_new;
    SymTable_new = (SymTable*) malloc(1 * sizeof(SymTable));
    if(SymTable_new==NULL){
        return NULL;
    }
    else{
        return SymTable_new;
        //used to free SymTable_new
        free(SymTable_new);
    }
}


// SymTable_put function
void SymTable_put(SymTable **oSymTable, const char *pcKey, const char *pvValue){
    SymTable* a;
    a = SymTable_new();
    a->pcKey=pcKey;
    a->pvValue=pvValue;
    a->n=(*oSymTable);
    (*oSymTable)=a;
    std::cout<<a->pcKey<<" "<<a->pvValue<<endl;
}


// function used to get the length of SymTable
int SymTable_getLength (SymTable *oSymTable){
	SymTable *current = oSymTable; 
	int count=0;
    while (current != NULL)
    {
        count++;
        current = current->n;
    }
    return count;	
}


// function used to search whether a key is present or not
int SymTable_contains(SymTable *oSymTable, const char *new_key){
	SymTable *current = oSymTable;
    while (current != NULL)
    {
        if (current->pcKey == new_key)
            return 1;
        current = current->n;
    }
    return 0;
}


int main(){
	SymTable* SymTable_new();
    struct SymTable *oSymTable = NULL;
    SymTable_put(&oSymTable,"b","char");
    SymTable_put(&oSymTable,"c","int");
    SymTable_put(&oSymTable,"d","float");
    int x = SymTable_getLength(oSymTable);
    cout<<"Length of SymTable is "<<x<<endl;
    int y = SymTable_contains(oSymTable,"c");
    cout<<y;
} 
