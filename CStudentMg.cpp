#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include "CStudent.h"
#include "CStudentMg.h"

using namespace std;

CStudentMg::CStudentMg()
{
}

CStudentMg::~CStudentMg()
{
}

// 增
CStudent CStudentMg::addAStu(map<int, CStudent>& m1, CStudent& stu) {

	// 先假设id可以重复了
	m1.insert(make_pair(stu.getId(), stu));
	return stu;
}

// 删
bool CStudentMg::deleteStuById(map<int, CStudent>& m1, const int& id) {

	bool b = false;

	map<int, CStudent> ::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		m1.erase(iter);
		b = true; // 删除成功
	}

	return b;
}

// 改
CStudent CStudentMg::updateStu(map<int, CStudent>& m1, const CStudent& cStu) {

	// 迭代器是一个smart point！
	// 是可以通过迭代器去访问到 m1里的东西，并且做出修改的！
	// 除非迭代器是const迭代器

	CStudent stu;
	int id = cStu.getId();

	map<int, CStudent> ::iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		// 修改
		iter->second = cStu;
		stu = cStu; // 把修改后的对象，赋值，再返回上层
	}

	return stu;
}

// 查 by id
CStudent CStudentMg::findById(const map <int, CStudent>& m1, const int& id) const {

	CStudent stu;

	map<int, CStudent> ::const_iterator iter;
	iter = m1.find(id);
	if (iter != m1.end())
	{
		stu = iter->second;
	}

	return stu;
}

// showAll
void CStudentMg::showAll(const map<int, CStudent>& m1) const {

	for (auto p : m1)
	{
		cout << p.second << endl;
	}

}

// save to file
bool CStudentMg::saveToFile(const map <int, CStudent>& m1, const string& pathName) const {

	bool b = true;

	//fstream ofs(pathName,ios::out+ios::binary); // 为什么不是以binary保存？
	fstream ofs(pathName, ios::out);
	if (ofs) {
		stringstream ss;

		cout << "open file" << endl;

		CStudent stu;
		for (auto p = m1.begin(); p != m1.end(); p++)
		{
			stu = p->second;
			ss << stu << endl;
		}

		ofs << ss.str(); // 注意，输出一定是 ss.str();

		ofs.close();
	}
	else
	{
		cout << "fail to open file" << endl;
		b = false;
	}

	return b;
}


// read from file
bool CStudentMg::readFromFile(std::map<int, CStudent>& m1, std::string path) {
	bool b = true;

	m1.clear(); // 清掉原来的

	fstream ifs(path, ios::in);
	if (ifs) {
		cout << "open file" << endl;
		string s;
		stringstream ss;
		while (getline(ifs, s)) // 怎么一行行地读取？
		{
			CStudent cStu;
			ss << s;
			// cout<<ss.str();
			ss >> cStu;
			ss.clear();

			m1.insert(make_pair(cStu.getId(), cStu));

		}

		ifs.close();

	}
	else {
		cout << "fail to open file" << endl;
		b = false;
	}

	return b;
}