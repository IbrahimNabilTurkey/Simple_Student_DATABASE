#ifndef simple_DB_H
#define simple_DB_H


#define NULL 0

typedef struct simpleDB
{
    int Student_ID;
    int Student_YEAR;
    int Courses_IDs[3];
    int Courses_Grades[3];
    struct simpleDB*  ptr_next_node;
}DB;

bool SDB_IsFull(void);

char SDB_GetUsedSize(void);

bool SDB_AddEntry(void);

void SDB_DeleteEntry(void);

bool SDB_ReadEntry(void);

void SDB_GetIdList(void);

bool SDB_IsIdExist(void);

int _menu_ (void);




















#endif /* simple_DB_H */