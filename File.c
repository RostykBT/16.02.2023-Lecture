#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char surname[20];
    int age;
} person;



void read_file_name(char *filename, char *prompt){
    printf("%s", prompt);
    scanf("%s", filename);
}

int file_exists(FILE *ffa){
    if ((ffa = NULL)){
        return 0;
    }
    return 1;
}

void count_data(FILE *ffa, int *count){
    int i = 0;
    char buffer[100], buffer2[100];
    int j;
    while(fscanf(ffa, "%s %s %d", buffer, buffer2, j) != EOF){
        i++;
        // printf("%s %s %d, ", buffer, buffer2, j); //debug
    }
    *count = i;
    rewind(ffa);
}

//function to read data from file and store it in an array of structs "people"
void read_data(FILE *ffa, person *people, int count){
    int i;
    for (i = 0; i < count; i++){
        fscanf(ffa, "%s %s %d", people[i].name, people[i].surname, &people[i].age);
    }
}
//function to print data from array of structs "people"
void print_data(person *people, int count){
    int i;
    for (i = 0; i < count; i++){
        printf("%s %s %d\n", people[i].name, people[i].surname, people[i].age);
    }
}



int main(void)
{
//array of structs of type person
person people[100];
int count;
char filename[100];
read_file_name(filename, "we enter the full name of the file here ");
FILE *ffa;
ffa = fopen(filename, "r");
if (file_exists(ffa) == 0){
    printf("File does not exist");
    return 1;
}
else{
    printf("File exists");
}
count_data(ffa, &count);
printf("The number of data in the file is %d ", count);
read_data(ffa, people, count);
print_data(people, count);
fclose(ffa);
return 0;
}


