#ifndef C_STUDENT_MG_H
#define C_STUDENT_MG_H
#include "CStudent.h"
#include <map>
#include <string>

class CStudentMg
{
public:
	CStudentMg();
	~CStudentMg();

	// Ôö
	CStudent addAStu(std::map<int, CStudent>& m1, CStudent& stu);

	// É¾
	bool deleteStuById(std::map<int, CStudent>& m1, const int& id);

	// ¸Ä
	CStudent updateStu(std::map<int, CStudent>& m1, const CStudent& stu);

	// ²é by id
	CStudent findById(const std::map<int, CStudent>& m1, const int& id) const;


	// showAll
	void showAll(const std::map<int, CStudent>& m1) const;

	// save to file
	bool saveToFile(const std::map <int, CStudent>& m1, const std::string& pathName) const;

	// read from file
	bool readFromFile(std::map<int, CStudent>& m1, std::string path);


private:

};


#endif