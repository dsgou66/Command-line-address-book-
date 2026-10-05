#include "contact.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void clear_input(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

static void line(char *bugf, size_t size) {
  if (fgets(bugf, size, stdin)) {
    size_t meet = strlen(bugf);
    if (meet > 0 && bugf[meet - 1] == '\n') {
      bugf[meet - 1] = '\0';
    }
  }
}

int main(void) {
  ContactList *list = clist_create();
  if (list == NULL) {
    printf("列表创建失败");
    return 1;
  }
  while (1) {
    printf("\n=====通讯录=====\n");
    printf("1.显示所有\n");
    printf("2.查找联系人\n");
    printf("3.添加联系人\n");
    printf("4.修改联系人\n");
    printf("5.删除联系人\n");
    printf("0.退出\n");
    int choice;
    if (scanf("%d", &choice) != 1) {
      clear_input();
      printf("输入无效\n");
      continue;
    }
    clear_input();
    char name[NAME_MAX];
    char phone[PHONE_MAX];
    char email[EMAIL_MAX];
    int id;
    switch (choice) {
    case 1:
      clist_print_all(list);
      break;
    case 2:
      int sub;
      printf("\n1.用id查找 2.用名字查找\n");
      clear_input();
      scanf("%d", &sub);
      if (sub == 1) {
        printf("id:");
        scanf("%d", &id);
        Contact *c = clist_find_by_id(list, id);
        if (c) {
          printf("搜到以下结果: %d %s %s %s\n", c->id, c->name, c->phone,
                 c->email);
        } else {
          printf("无结果\n");
        }
        break;
      }
      if (sub == 2) {
        printf("名字:\n");
        line(name, NAME_MAX);
        Contact *c = clist_find_by_name(list, name);
        if (c) {
          printf("搜到以下结果: %d %s %s %s\n", c->id, c->name, c->phone,
                 c->email);
        } else {
          printf("无结果");
        }
        break;
      }
      if (sub != 1 && sub != 2){
          printf("无效选项");
      }
      break;
    case 3:
      printf("请输入添加联系人的信息\n");
      printf("请输入名字\n");
      line(name, NAME_MAX);
      printf("请输入电话\n");
      line(phone, PHONE_MAX);
      printf("请输入邮箱\n");
      line(email, EMAIL_MAX);
      if (clist_add(list, name, phone, email) == 0){
          printf("添加成功\n");
      }else{
          printf("添加失败\n");
      }
      break;
case 4:
    printf("要修改的 id: ");
    scanf("%d", &id);
    clear_input();
    
    printf("新姓名: ");
    line(name, NAME_MAX);
    printf("新电话: ");
    line(phone, PHONE_MAX);
    printf("新邮箱: ");
    line(email, EMAIL_MAX);
    
    if (clist_update(list, id, name, phone, email) == 0) {
        printf("修改成功\n");
    } else {
        printf("修改失败\n");
    }
    break;
          case 5:
              printf("请输入联系人的ID");
              scanf("%d", &id);
              clear_input();
              if(clist_remove(list, id) == 0){
                  printf("删除成功\n");
              }else{
                  printf("删除失败\n");
              }
              break;
              case 0:
                  printf("exit");
                  return 0;
    }
  }
}