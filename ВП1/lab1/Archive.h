#include "Book.h"
class Archive {
 int n;
 Book *books;
 public:
 Archive(int a);
 ~Archive();
 void Create_Archive();
 void Print_Archive();
 void special_author();
 void special_izd();
 void after_year();
 void Print_table();
};