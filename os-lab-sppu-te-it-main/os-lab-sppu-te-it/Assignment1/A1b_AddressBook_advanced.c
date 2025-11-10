/*
 Advanced Address Book: uses binary file to store records,
 supports add, display, delete (by name) and search.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
} Contact;

const char *FNAME = "addressbook.bin";

void add_contact() {
    Contact c;
    FILE *fp = fopen(FNAME, "ab");
    if(!fp) { perror("fopen"); return; }
    printf("Name: "); scanf("%49s", c.name);
    printf("Phone: "); scanf("%19s", c.phone);
    fwrite(&c, sizeof(Contact), 1, fp);
    fclose(fp);
    printf("Added.\n");
}

void display_contacts() {
    Contact c;
    FILE *fp = fopen(FNAME, "rb");
    if(!fp) { printf("No contacts yet.\n"); return; }
    printf("\nContacts:\n");
    while(fread(&c, sizeof(Contact), 1, fp)==1) {
        printf("Name: %-20s Phone: %s\n", c.name, c.phone);
    }
    fclose(fp);
}

void delete_contact() {
    char key[50]; printf("Enter name to delete: "); scanf("%49s", key);
    FILE *fp = fopen(FNAME, "rb");
    if(!fp) { printf("No contacts.\n"); return; }
    FILE *tmp = fopen("tmp.bin","wb");
    Contact c; int found=0;
    while(fread(&c,sizeof(Contact),1,fp)==1) {
        if(strcmp(c.name,key)!=0) fwrite(&c,sizeof(Contact),1,tmp);
        else found=1;
    }
    fclose(fp); fclose(tmp);
    if(found) { remove(FNAME); rename("tmp.bin",FNAME); printf("Deleted.\n"); }
    else { remove("tmp.bin"); printf("Not found.\n"); }
}

void search_contact() {
    char key[50]; printf("Enter name to search: "); scanf("%49s", key);
    FILE *fp = fopen(FNAME, "rb");
    if(!fp) { printf("No contacts.\n"); return; }
    Contact c; int found=0;
    while(fread(&c,sizeof(Contact),1,fp)==1) {
        if(strcmp(c.name,key)==0) { printf("Found: %s %s\n", c.name, c.phone); found=1; break; }
    }
    fclose(fp);
    if(!found) printf("Not found.\n");
}

int main() {
    int ch;
    while(1) {
        printf("\n1.Add 2.Display 3.Delete 4.Search 5.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch) {
            case 1: add_contact(); break;
            case 2: display_contacts(); break;
            case 3: delete_contact(); break;
            case 4: search_contact(); break;
            case 5: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
