typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);

void liberaHash(Hash *ha);

unsigned long long valorString(char *str);

int insereHash(Hash* ha, char* word);

void buscaHash(Hash* ha, char* word);

void removeHash(Hash* ha, char* word);
