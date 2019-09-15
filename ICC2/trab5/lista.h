struct data {
  int day;
  int month;

};

struct hora {
  int hour;
  int min;

};

typedef struct _tab {
  char title[30];
  char url[1024];
  struct data date;
  struct hora time;
  int number;

} Tab;

typedef struct _node Node;

typedef struct {
  Node *beg;
  Node *end;
  int num_elems;

} List;

void create(List *L);

int insert(List *L, Tab info);

void show(List *L);

void move(List *L, char* search, int pos);

void radix_sort(List *L);

void leave(List *L);
