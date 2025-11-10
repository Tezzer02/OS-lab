#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Listing current directory (ls):\n");
    system("ls -l");
    printf("\nShowing current directory (pwd):\n");
    system("pwd");
    printf("\nPrinting current date (date):\n");
    system("date");
    return 0;
}
