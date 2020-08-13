#ifndef C_MAIN_VIEW_H
#define C_MAIN_VIEW_H

#include <iostream>
#include <map>
#include <string>
#include "CStudent.h"
#include "CStudentMg.h"

class CMainView
{
public:
	CMainView();
	~CMainView();

	/* 欢迎 */
	void welcome();

	/* 显示菜单 */
	void showMenu();

	/* view 显示所有学生 */
	void showAllStuAtView(const std::map<int, CStudent>& stu_m1);

	/* view层 添加一个学生 */
	void addStuAtView(std::map<int, CStudent>& stu_m1);

	/* view 查找一个学生 */
	void findStuAtView(const std::map<int, CStudent>& m1);

	/* view层删除一个学生 */
	void deleteByIdAtView(std::map<int, CStudent>& v1);

	/* view层 更新一个学生 */
	void updateByIdAtView(std::map<int, CStudent>& m1);

	/* view层 把map保存进文件 */
	void saveToFileAtView(const std::map<int, CStudent>& m1, std::string pathName);

	/* view层 把文件中的东西导入 map */
	void readFromFileAtView(std::map<int, CStudent>& m, std::string pathName);

private:

};

#endif