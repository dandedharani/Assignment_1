#include "SymTable_functions.hpp"

int main()
{
	SymTable* SymTable_new();
    struct SymTable *oSymTable = NULL;
    SymTable_put (&oSymTable,"b","char");
    SymTable_put (&oSymTable,"c","int");
    SymTable_put (&oSymTable,"d","float");
    int x = SymTable_getLength (oSymTable);
    cout<<"Length of SymTable is "<<x<<endl;
    int y = SymTable_contains (oSymTable,"c");
    cout<<y<<endl;
	SymTable_get (oSymTable,"b");
	SymTable_replace (oSymTable,"d","double");
	print_SymTable (oSymTable);
	SymTable_remove (oSymTable,"c");
	cout<<"SymTable after removing the given binding"<<endl;
	print_SymTable (oSymTable);
	return 0;
}
