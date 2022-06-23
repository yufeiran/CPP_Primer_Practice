#pragma once
class Base {
public:
	void pub_mem();
	void memfcn(Base& b) { b = *this; }
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv :public Base {
	int f() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
	//char g() { return priv_mem; }
};

struct Priv_Derv :private Base {
	void memfcn(Base& b) { b = *this; }
	int f1()const { return prot_mem; }
};

struct Prot_Derv :protected Base {
	void memfcn(Base& b) { b = *this; }
	int f1()const { return prot_mem; }
};

struct Derived_from_Public :public Pub_Derv {
	void memfcn(Base& b) { b = *this; }
	int use_base() { return prot_mem; }
};

struct Derived_from_Private :public Priv_Derv {
	//void memfcn(Base& b) { b = *this; }
	//int use_base() { return prot_mem; }
};

struct Derived_from_Protect :public Prot_Derv {
	void memfcn(Base& b) { b = *this; }
	int use_base() { return prot_mem; }
};