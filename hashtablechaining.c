#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//#if 0
#define MAX_NAME	256
#define TABLE_SIZE	10

typedef struct _person {
	char name[MAX_NAME];
	int age;
	struct _person* next;
} person;

person* hash_table[TABLE_SIZE];

unsigned int hash(char* name) {
	int length = (int)strnlen(name, MAX_NAME);
	unsigned int hash_value = 0;
	for (int i = 0; i < length; i++) {
		hash_value += name[i];
		hash_value = hash_value * name[i];
	}

	return hash_value % TABLE_SIZE;
}

void init_hash_table() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		hash_table[i] = NULL;
	}
}

bool hash_table_insert(person* p) {
	if (p == NULL) return false;
	int index = hash(p->name);
	p->next = hash_table[index];
	hash_table[index] = p;	
	return true;
}

person* hash_table_lookup(char* name) {
	int index = hash(name);
	person* curr = hash_table[index];
	while (curr != NULL && strncmp(name, curr->name, MAX_NAME) == 0) {
		curr = curr->next;
	}
	return curr;
}

person* hash_table_delete(char* name) {
	int index = hash(name);
	person* curr = hash_table[index];
	/* no person *prev  necessary
	   if (curr == NULL)
	   return NULL;
	   if (strncmp(name, curr->name, MAX_NAME) == 0) {
	   hash_table[index] = curr->next;
	   return curr;
	   }
	   while (curr->next != NULL) {
	   if (strncmp(name, curr->next->name, MAX_NAME) == 0) {
	   person* tmp = curr->next;
	   curr->next = curr->next->next;
	   return tmp;
	   }
	   curr = curr->next;
	   }
	   return NULL;
	   */
	person* prev = NULL;
	while (curr != NULL && strncmp(name, curr->name, MAX_NAME) != 0) {
		prev = curr;
		curr = curr->next;
	}
	if (curr == NULL) return NULL;
	if (prev == NULL) {
		curr = hash_table[index];
		hash_table[index] = curr->next;
	}
	else {
		prev->next = curr->next;
	}
	return curr;
}

void print_table() {
	printf("Begin hash_table\n");
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i] == NULL) {
			printf("\t%i\t---\n", i);
		}
		else {
			person* curr = hash_table[i];
			printf("\t%i\t ", i);
			while (curr) {
				printf("%s - ", curr->name);
				curr = curr->next;
			}
			printf("\n");
		}
	}
	printf("End hash_table\n");
}

int main() {
	init_hash_table();

	print_table();
	person jacob = { .name = "Jacob", .age = 256 };
	person anh = { .name = "Anh", .age = 36 };
	person an = { .name = "An", .age = 37 };
	person edward = { .name = "Edward", .age = 7 };
	person tim = { .name = "Timothy", .age = 4 };
	person truong = { .name = "Truong", .age = 67 };
	person oanh = { .name = "Oanh", .age = 65 };
	person kelsey = { .name = "Kelsey", .age = 32 };
	person daniel = { .name = "Daniel", .age = 39 };
	person jenny = { .name = "Jenny", .age = 26 };
	person chris = { .name = "Chris", .age = 50 };
	hash_table_insert(&jacob);
	hash_table_insert(&anh);
	hash_table_insert(&an);
	hash_table_insert(&edward);
	print_table();
	person* tmp = hash_table_lookup("Anh");
	if (tmp == NULL) {
		printf("Not found!\n");
	}
	else {
		printf("Found %s\n", tmp->name);
	}
	tmp = hash_table_lookup("George");
	if (tmp == NULL) {
		printf("Not found!\n");
	}
	else {
		printf("Found %s\n", tmp->name);
	}
	tmp = hash_table_delete("Anh");
	tmp = hash_table_lookup("Anh");
	if (tmp == NULL) {
		printf("Not found!\n");
	}
	else {
		printf("Found %s\n", tmp->name);
	}

	hash_table_insert(&anh);
	hash_table_insert(&tim);
	hash_table_insert(&truong);
	hash_table_insert(&oanh);
	hash_table_insert(&kelsey);
	hash_table_insert(&daniel);
	hash_table_insert(&jenny);
	hash_table_insert(&chris);
	print_table();

	tmp = hash_table_lookup("Oanh");
	if (tmp == NULL) {
		printf("Not found!\n");
	}
	else {
		printf("Found %s\n", tmp->name);
	}

}
//#endif
