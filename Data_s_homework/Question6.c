/*Write the function that prints the record with the longest name in the list.*/
#include <stdio.h>
#include <string.h>

// A structure to represent a record
typedef struct Record {
    char name[50];
    int age;
} Record;

// Function to find the longest name in the list
void findLongestName(Record records[], int n) {
    int max_length = 0;
    int max_index = -1; // Başlangıçta hiçbir indeksin atanmadığını belirtmek için -1 kullanıyoruz.

    for (int i = 0; i < n; i++) {
        int length = strlen(records[i].name);
        if (length > max_length) {
            max_length = length;
            max_index = i;
        }
    }

    if (max_index != -1) { // Eğer hiç isim bulunamazsa çıktıyı vermeyelim.
        printf("The longest name in the list: %s\n", records[max_index].name);
        printf("Length: %d\n", max_length);
    } else {
        printf("No names in the list.\n");
    }
}

int main() {
    Record records[] = {
        {"Abdurrahmangazi", 25},
        {"Musab", 23},
        {"İlayda", 31}
    };

    int n = sizeof(records) / sizeof(records[0]);

    findLongestName(records, n);

    return 0;
}