#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// abstract data type String
typedef struct String
{
    char *str;
    int length;
} String;

// new String
String *newString(char *str)
{
    String *string = (String *)malloc(sizeof(String));
    string->str = str;
    string->length = strlen(str);
    return string;
}

// print String
void printString(String *string)
{
    printf("%s %d \n", string->str, string->length);
}

// length of String
int lengthString(String *string) -> int
{
    return string->length;
}

// compare two String
int compareString(String *string1, String *string2) 
{
    return strcmp(string1->str, string2->str);
}

// concatenate two String
String *concatenateString(String *string1, String *string2)
{
    char *str = (char *)malloc(sizeof(char) * (string1->length + string2->length + 1));
    strcpy(str, string1->str);
    strcat(str, string2->str);
    return newString(str);
}

// reverse String
String *reverseString(String *string)
{
    char *str = (char *)malloc(sizeof(char) * (string->length + 1));
    strcpy(str, string->str);
    for (int i = 0; i < string->length / 2; i++)
    {
        char temp = str[i];
        str[i] = str[string->length - i - 1];
        str[string->length - i - 1] = temp;
    }
    return newString(str);
}

// remove String
void removeString(String *string)
{
    free(string->str);
    free(string);
}

#define MAX 10 // Maximum string size 

// randon string generator
char *randomString()
{
    char *str = (char *)malloc(sizeof(char) * MAX);
    for (int i = 0; i < MAX - 1; i++)
    {
        str[i] = 'a' + rand() % 26;
    }
    str[MAX - 1] = '\0';
    return str;
}



int main()
{
    String *string1 = newString("Hello");
    String *string2 = newString("World");
    String *string3 = newString("Hello");

    // how to print String memory address? 
    printf("%p %p %p \n\n", string1, string2, string3);

    printString(string1);
    printf("%d ", lengthString(string1)); 
    printf("%d ", compareString(string1, string2));
    printf("%d ", compareString(string1, string3));

    String *string4 = concatenateString(string1, string2);
    printString(string4);

    String *string5 = reverseString(string4);
    printString(string5);
    
    // random string generator

    String *string6 = newString(randomString());
    printString(string6);

    
    removeString(string1);
    removeString(string2);
    removeString(string3);
    removeString(string4);
    removeString(string5);
    // what did you do to my memory?
    return 0;
}