#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
// time
#include <time.h>

// creat new file write random data to file
void creat_file(char *file_name)
{
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        printf("creat file error !\n");
        exit(1);
    }
    fclose(fp);
};

// write to file data
void data_write(char *file_name, char *data)
{
    FILE *fp = fopen(file_name, "a");
    if (fp == NULL)
    {
        printf("open file error !\n");
        exit(1);
    }
    fwrite(data, strlen(data), 1, fp);
    fclose(fp);
};

// creat Json Objet data for File
typedef struct json
{
    char *name;
    char *age;
    char *sex;
    char *address;
    char *phone;
    char *email;
    char *job;
    char *hobby;
    char *school;
    char *major;
    char *grade;
    char *company;
    char *position;
    char *salary;
    char *remark;
    char *other;
    char *car;
    char *house;
    char *marriage;
    char *children;
    char *birthday;
    char *id;
    char *idcard;
    char *nation;
    char *native;
    char *blood;
    char *height;
    char *weight;
    char *degree;
    char *politics;
    char *religion;
    char *language;
    char *interest;
    char *skill;
    char *experience;
    char *award;
} json;

// creat an array and save json object to file
char *random_str()
{
    // randomw string
    char *str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(str);
    char *random_str = (char *)malloc(10);
    for (int i = 0; i < 10; i++)
    {
        random_str[i] = str[rand() % len];
    }
    // free(random_str);
    return random_str;
}

// random Number
char *random_number()
{
    // randomw string
    char *str = "0123456789";
    int len = strlen(str);
    char *random_str = (char *)malloc(10);
    for (int i = 0; i < 10; i++)
    {
        random_str[i] = str[rand() % len];
    }
    return random_str;
}

// return json object with random data
json *random_json()
{
    json *json_obj = (json *)malloc(sizeof(json));
    json_obj->name = random_str();
    json_obj->age = random_number();
    json_obj->address = random_str();
    json_obj->phone = random_number();
    json_obj->email = random_str();
    json_obj->job = random_str();
    json_obj->hobby = random_str();
    json_obj->school = random_str();
    json_obj->major = random_str();
    json_obj->grade = random_number();
    json_obj->company = random_str();
    json_obj->position = random_str();
    json_obj->salary = random_number();
    json_obj->remark = random_str();
    json_obj->other = random_str();
    json_obj->car = random_str();
    json_obj->house = random_str();
    json_obj->marriage = random_str();
    json_obj->children = random_str();
    json_obj->birthday = random_number();
    json_obj->id = random_number();
    json_obj->idcard = random_number();
    json_obj->nation = random_str();
    json_obj->native = random_str();
    json_obj->blood = random_str();
    json_obj->height = random_number();
    json_obj->weight = random_number();
    json_obj->degree = random_str();
    json_obj->politics = random_str();
    json_obj->religion = random_str();
    json_obj->language = random_str();
    json_obj->interest = random_str();
    json_obj->skill = random_str();
    json_obj->experience = random_str();
    json_obj->award = random_str();
    return json_obj;
    // type of funtion will be json *
};

// generate 100 json object and save to file
void generate_json()
{
    //  100  Object to Json
    // array of json object  100
    char *big_Array = (char *)malloc(1000);
    // write as a array
    sprintf(big_Array, "let random = [");
    for (int i = 0; i < 500; i++)
    {
        json *json_obj = random_json();        // get json object
        char *json_str = (char *)malloc(1000); // creat a string to save json object
        // write to file for int we use %d
        sprintf(json_str, "{ name: \"%s\", age: \"%s\", address: \"%s\", phone: \"%s\", email: \"%s\", job: \"%s\", hobby: \"%s\", school: \"%s\", major: \"%s\", grade: \"%s\", company: \"%s\", position: \"%s\", salary: \"%s\", remark: \"%s\", other: \"%s\", car: \"%s\", house: \"%s\", marriage: \"%s\", children: \"%s\", birthday: \"%s\", id: \"%s\", idcard: \"%s\", nation: \"%s\", native: \"%s\", blood: \"%s\", height: \"%s\", weight: \"%s\", degree: \"%s\", politics: \"%s\", religion: \"%s\", language: \"%s\", interest: \"%s\", skill: \"%s\", experience: \"%s\", award: \"%s\" }", json_obj->name, json_obj->age, json_obj->address, json_obj->phone, json_obj->email, json_obj->job, json_obj->hobby, json_obj->school, json_obj->major, json_obj->grade, json_obj->company, json_obj->position, json_obj->salary, json_obj->remark, json_obj->other, json_obj->car, json_obj->house, json_obj->marriage, json_obj->children, json_obj->birthday, json_obj->id, json_obj->idcard, json_obj->nation, json_obj->native, json_obj->blood, json_obj->height, json_obj->weight, json_obj->degree, json_obj->politics, json_obj->religion, json_obj->language, json_obj->interest, json_obj->skill, json_obj->experience, json_obj->award);
        // add to array
        strcat(big_Array, json_str);
        // free(json_str);
        // add comma to
        strcat(big_Array, ",\r \r"); // add comma
    }
    strcat(big_Array, "];");
    // write to file
    data_write("json.js", big_Array);
    free(big_Array);
}

// time to calculate the time of the program
// take a function as a parameter
void time_calculate(void (*fun)())
{
    clock_t start, end;
    start = clock();
    fun();
    end = clock();
    // printf("time: %f", (double)(end - start), "ms");
    printf("time: %f ms", (double)(end - start) / CLOCKS_PER_SEC * 1000);
}

int main()
{
    time_calculate(generate_json);
    printf("\ndone\n"); // 14ms and 3.14mb space used

    return 0;
}