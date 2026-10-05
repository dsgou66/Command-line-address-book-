#include <stdlib.h>
#include "contact.h"
#include <string.h>
#include <stdio.h>
ContactList* clist_create(void){
    ContactList* list = malloc(sizeof(ContactList));
    if (list == NULL){
        return NULL;
    }
    list -> items = malloc(sizeof(Contact)*4);
    if (list -> items == NULL){
        free(list);
        return NULL;
    }
    list -> count = 0;
    list -> capacity = 4;
    list -> next_id = 1;
    return list;
    }
    void clist_destroy(ContactList* list){
        if (list == NULL){
            return;
        }
        free(list -> items);
        free(list);
    }
    
    int clist_add(ContactList* list, const char* name, const char* phone, const char* email){
        if (list == NULL){
            return -1;
        }
        if (list -> count>=list -> capacity){
            size_t cap_new = list -> capacity * 2;
            Contact* items_new = realloc(list -> items, sizeof(Contact) * cap_new);
        
        if (items_new == NULL){
            return -1;
        }
        list -> items = items_new;
        list -> capacity = cap_new;
        }
        Contact* c = &list -> items[list -> count];
        c -> id = list -> next_id;
        
        strncpy (c -> name, name, NAME_MAX -1);
        c -> name[NAME_MAX -1] = '\0';
        strncpy (c -> phone, phone, PHONE_MAX -1);
        c -> phone[PHONE_MAX -1] = '\0';
        
        strncpy (c -> email, email, EMAIL_MAX -1);
        c -> email[EMAIL_MAX -1] = '\0';
        
        list -> count++;
        list -> next_id++;
        return 0;
    }
    Contact* clist_find_by_id(ContactList* list, int id){
        if (list ==NULL) return NULL;
        
        for (size_t i = 0; i < list ->count; i++) {
             if (list -> items[i].id == id){
                return &list -> items[i];
             }
}
return NULL;
    }
    Contact* clist_find_by_name(ContactList* list, const char* name){
        if (list ==NULL) return NULL;
        
        for(size_t o = 0; o< list -> count; o++){
            if (strcmp(list -> items[o].name, name) == 0){
                return &list->items[o];
            }
        }
        return NULL;
    }
    int clist_remove(ContactList* list, int id){
        if (list ==NULL) return -1;
        for (size_t i = 0; i< list -> count; i++){
            if (list ->items[i].id == id){
                for (size_t j = i; j <list -> count - 1; j++){
                    list -> items[j]=list -> items[j + 1];
                }
                list -> count--;
                return 0;
            }
        }
        return -1;
    }
    
    int clist_update(ContactList* list, int id, const char* name, const char* phone, const char* email){
        if (list ==NULL) return -1;
        
        Contact* c = clist_find_by_id(list, id);
        if (c == NULL) return -1;
        
        strncpy(c -> name, name, NAME_MAX -1);
        c -> name[NAME_MAX -1 ] = '\0';
        
        strncpy(c -> phone, phone, PHONE_MAX -1);
        c-> phone[PHONE_MAX -1] = '\0';
        
        strncpy(c -> email, email, EMAIL_MAX -1);
        c -> email[EMAIL_MAX -1] = '\0';
        
        return 0;
    }
    
    void clist_print_all(const ContactList* list){
        if(list == NULL) return;
        
        printf("ID\t姓名\t电话\t邮箱\n");
        
        for (size_t i = 0; i < list -> count; i++){
     const Contact* c = &list -> items[i];
            printf("%d\t%s\t%s\t%s\n", c->id,c->name,c->phone,c->email);
        }
    }
    