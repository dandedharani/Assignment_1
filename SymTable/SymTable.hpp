struct SymTable
{
	const char *pcKey;
	const char *pvValue;
	SymTable *n;
	SymTable *oSymTable;
};

struct SymTable* SymTable_new();
void SymTable_put (SymTable **oSymTable, const char *pcKey, const char *pvValue);
int SymTable_getLength (SymTable *oSymTable);
int SymTable_contains (SymTable *oSymTable, const char *new_key);
void SymTable_get (SymTable *oSymTable, const char *new_key);
void SymTable_replace (SymTable *oSymTable, const char *new_key, const char *new_value);
void SymTable_remove (SymTable *oSymTable, const char *new_key);
void print_SymTable (SymTable *oSymTable);
