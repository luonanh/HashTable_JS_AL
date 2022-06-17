#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#if 0
#define MAX_NAME	256
#define TABLE_SIZE	10
#define DELETED_NODE	(person *)(0xFFFFFFFFFFFFFFFFUL)

typedef struct {
	char name[MAX_NAME];
	int age;
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

	for (int i = 0; i < TABLE_SIZE; i++) {
		int try = (index + i) % TABLE_SIZE;
		if (hash_table[try] == NULL ||
				hash_table[try] == DELETED_NODE) {
			hash_table[try] = p;
			return true;
		}
	}
	return false;
}

person* hash_table_lookup(char* name) {
	int index = hash(name);
	for (int i = 0; i < TABLE_SIZE; i++) {
		int try = (index + i) % TABLE_SIZE;
		if (hash_table[try] == NULL) return NULL;
		if (hash_table[try] == DELETED_NODE) continue;
		if (strncmp(name, hash_table[try]->name, MAX_NAME) == 0) {
			return hash_table[try];
		}
	}
	return NULL;
}

person* hash_table_delete(char* name) {
	int index = hash(name);
	for (int i = 0; i < TABLE_SIZE; i++) {
		int try = (index + i) % TABLE_SIZE;
		if (hash_table[try] == NULL) return NULL;
		if (hash_table[try] == DELETED_NODE) continue;
		if (strncmp(name, hash_table[try]->name, MAX_NAME) == 0) {
			person* tmp = hash_table[index];
			hash_table[try] = DELETED_NODE;
			return tmp;
		}
	}
	return NULL;
}

void print_table() {
	printf("Begin hash_table\n");
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hash_table[i] == NULL) {
			printf("\t%i\t---\n", i);
		}
		else if (hash_table[i] == DELETED_NODE) {
			printf("\t%i\t---<deleted>\n", i);
		}
		else {
			printf("\t%i\t%s\n", i, hash_table[i]->name);
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
#endif
