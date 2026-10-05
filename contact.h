#pragma once
#include <stddef.h>

#define NAME_MAX  50
#define PHONE_MAX 26
#define EMAIL_MAX 60

typedef struct {
    int  id;
    char name[NAME_MAX];
    char phone[PHONE_MAX];
    char email[EMAIL_MAX];
} Contact;

typedef struct {
    Contact* items;      // 数据指针
    size_t   count;      // 当前数量
    size_t   capacity;   // 总容量     ← 补上
    int      next_id;    // 下一个 id
} ContactList;           // 只留 4 个成员

ContactList* clist_create(void);
void         clist_destroy(ContactList* list);
int          clist_add(ContactList* list, const char* name,
                       const char* phone, const char* email);
int          clist_remove(ContactList* list, int id);
int          clist_update(ContactList* list, int id,
                          const char* name, const char* phone, const char* email);
Contact*     clist_find_by_id(ContactList* list, int id);
Contact*     clist_find_by_name(ContactList* list, const char* name);
void         clist_print_all(const ContactList* list);