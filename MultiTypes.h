#pragma once

#include <string>
class Position;

class MultiTypes {
public:
	virtual void* get() const = 0;
};

class INT : public MultiTypes {
public:
	INT(int num = 0) : m_num(num) {};
	INT(const INT& num) : m_num(num.m_num) {};
	~INT() {};
	virtual void* get() const {
		return (void*)&m_num;
	};
private:
	int m_num;
};

class FLOAT : public MultiTypes {
public:
	FLOAT(float num = 0) : m_num(num) {};
	FLOAT(const FLOAT& num) : m_num(num.m_num) {};
	~FLOAT() {};
	virtual void* get() const {
		return (void*)&m_num;
	};
private:
	float m_num;
};

class DOUBLE : public MultiTypes {
public:
	DOUBLE(double num = 0) : m_num(num) {};
	DOUBLE(const DOUBLE& num) : m_num(num.m_num) {};
	~DOUBLE() {};
	virtual void* get() const {
		return (void*)&m_num;
	};
private:
	double m_num;
};


class STRING : public MultiTypes {
public:
	STRING(std::string num = 0) : m_num(num) {};
	STRING(const STRING& num) : m_num(num.m_num) {};
	~STRING() {};
	virtual void* get() const {
		return (void*)&m_num;
	};
private:
	std::string m_num;
};

class CHAR : public MultiTypes {
public:
	CHAR(char num = 0) : m_num(num) {};
	CHAR(const CHAR& num) : m_num(num.m_num) {};
	~CHAR() {};
	virtual void* get() const {
		return (void*)&m_num;
	};
	
private:
	char m_num;
};


