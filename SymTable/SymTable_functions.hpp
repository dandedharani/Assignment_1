#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include "SymTable.hpp"

using namespace std;

// function used to create new SymTable
struct SymTable* SymTable_new()
{
	struct SymTable *SymTable_new;
	SymTable_new = (SymTable*) malloc(1 * sizeof(SymTable));
	if(SymTable_new==NULL)
	{
    	return NULL;
    }
    else
	{
    	return SymTable_new;
    }
}


void SymTable_free(){
	struct SymTable *SymTable_new;
	SymTable_new = (SymTable*) malloc(1 * sizeof(SymTable));
    free(SymTable_new);
}

// SymTable_put function
void SymTable_put (SymTable **oSymTable, const char *pcKey, const char *pvValue)
{
    SymTable* a;
	SymTable* last = (*oSymTable);
    a = SymTable_new();
    a->pcKey = pcKey;
    a->pvValue = pvValue;
    a->n = NULL;
    if ((*oSymTable) == NULL)
	{ 
        (*oSymTable) = a; 
        return; 
    } 
    while (last->n != NULL)
	{
        last = last->n; 
    }
    last->n = a; 
    return; 
}


// function used to get the length of SymTable
int SymTable_getLength (SymTable *oSymTable)
{
	SymTable *current = oSymTable; 
	int count = 0;
    while (current != NULL)
    {
    	count++;
        current = current->n;
    }
    return count;	
}


// function used to search whether a key is present or not
int SymTable_contains (SymTable *oSymTable, const char *new_key)
{
	SymTable *current = oSymTable;
    while (current != NULL)
    {
    	if (current->pcKey == new_key)
        	return 1;
    	current = current->n;
    }
	return 0;
}


// function used to return the value of the given key
void SymTable_get (SymTable *oSymTable, const char *new_key)
{
	SymTable *current = oSymTable;
	while (current != NULL)
	{
    	if (current->pcKey == new_key)
		{
        	cout<<"The value of given key is "<<current->pvValue<<endl;
		}
		current = current->n;	
	}
}


// function used to replace the value of the given key
void SymTable_replace (SymTable *oSymTable, const char *new_key, const char *new_value)
{
	SymTable *current = oSymTable;
	while (current != NULL)
    {
        if (current->pcKey == new_key)
		{
        	current->pvValue = new_value;
            cout<<"The replaced value of the given key is "<<current->pvValue<<endl;
            break;
		}
        else
		{
        	current = current->n;
		}
    }	
}

// function which is used to remove a given key
void SymTable_remove (SymTable **oSymTable, const char *new_key)
{
	if((*oSymTable) == NULL)
	{
      return;
    }
	SymTable *current = (*oSymTable);
	SymTable *prev = NULL;
	if(current != NULL && current->pcKey == new_key)
	{
		(*oSymTable) = current->n;
		delete current;
		return;
    }
	else
	{
		while(current != NULL && current->pcKey != new_key)
		{
			prev = current;
			current = current->n;
	    }
		if(current == NULL)
		{
			return;
		}
		prev->n = current->n;
		delete current;
   	}
}


// function used to print (key,value) pairs of SymTable
void print_SymTable (SymTable *oSymTable)
{
    while (oSymTable != NULL)
	{
        cout<<oSymTable->pcKey<<" "<<oSymTable->pvValue<<endl;
        oSymTable = oSymTable->n;
    }
}













