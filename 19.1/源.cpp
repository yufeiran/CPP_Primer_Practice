#include<iostream>
#include<cstdlib>

using namespace std;

void* operator new(size_t size) {
	if (void* mem = malloc(size))
		return mem;
	else
		throw bad_alloc();
}

void operator delete(void* mem) {
	free(mem);
}