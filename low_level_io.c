#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

typedef struct {
    int id;
    char name[50+1];
    float value;
} myStruct;

int main() {

    myStruct data[10];
    int rec_size = sizeof(myStruct);

    for(int i=0;i<10;i++)
    {
        data[i].id = i;
        memset(data[i].name, 0, 50+1);
        sprintf(data[i].name, "Data row %d",i);
        data[i].value = 3.141592 * i;
    }

    // stdin=0, stdout=1, stderr=2

    int fd = open("data.bin", O_RDWR | O_CREAT, 0666);
    if(fd == -1)
    {
        perror("Error opening file");
        exit(1);
    }

    for(int i=0;i<10;i++)
    {
        int len = write(fd, &data[i], rec_size);
        if(len != rec_size) {
            perror("Error writing to the file");
            close(fd);
            exit(1);
        }
    }

    //REPOSITION FILE POINT TO bof
    lseek(fd, 0 , SEEK_SET);

    for (int i=0;i<10; i += 2) {

        printf("Let's search for the record %d at position %d\n",i, tell(fd));

        int offset = (i * rec_size);

        int position = lseek(fd, offset, SEEK_SET);
        if (position == -1) {
                perror("Error seeking insize of file");
                close(fd);
                exit(1);
        }

        myStruct tempRecord;

        int bytes_read = read(fd, &tempRecord, rec_size);
        if(bytes_read != rec_size) {
            perror("Error reading from file");
            close(fd);
            exit(1);
        }

        printf("Record %d:\n",i);
        printf("   ID: %d\n", tempRecord.id);
        printf("   Name: %s\n", tempRecord.name);
        printf("   Value: %.6f\n", tempRecord.value);

    }

    close(fd);
    return(0);

}
