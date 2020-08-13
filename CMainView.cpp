#include "CMainView.h"

CMainView::CMainView()
{
}

CMainView::~CMainView()
{
}

/* 欢迎 */
void CMainView::welcome() {
	system("cls");
	std::cout << "welcome to student management system" << std::endl;
}

/* 显示菜单 */
void CMainView::showMenu() {

	std::cout << "\n";
	std::cout << "Steps:" << std::endl;

	std::cout << "1. add student" << std::endl;
	std::cout << "2. modify student" << std::endl;
	std::cout << "3. find student" << std::endl;
	std::cout << "4. delete student" << std::endl;
	std::cout << "5. show all" << std::endl;
	std::cout << "6. output to a file" << std::endl;
	std::cout << "7. import to a file" << std::endl;
	std::cout << "0. exit" << std::endl;
	std::cout << "\n";

	std::cout << "Author：liule" << std::endl;
	std::cout << "2019/01/01" << std::endl;

	std::cout << "\n";
	std::cout << "please select a operation：";
}


/* view 显示所有学生 */
void CMainView::showAllStuAtView(const std::map<int, CStudent>& stu_m1)
{

	system("cls");
	std::cout << "id    |" << "name  |" << "age" << std::endl;
	CStudentMg cStuMg;
	cStuMg.showAll(stu_m1);

	system("pause");
	system("cls");
	welcome();
	showMenu();
}

/* view层 添加一个学生 */
void CMainView::addStuAtView(std::map<int, CStudent>& stu_m1)
{
	CStudentMg cStuMg;

	int id;
	std::string name;
	int age;
	CStudent cStu;

	system("cls");

	std::cout << "add\n";
	std::cout << "id:";
	std::cin >> id;

	std::cout << "name:";
	std::cin >> name;

	std::cout << "age:";
	std::cin >> age;

	cStu.setId(id);
	cStu.setName(name);
	cStu.setAge(age);

	// 保存
	cStuMg.addAStu(stu_m1, cStu);

	system("cls");
	welcome();
	showMenu();
}



/* view 查找一个学生 */
void CMainView::findStuAtView(const std::map<int, CStudent>& m1) {

	system("cls");
	std::cout << "please input the id of your want to search" << std::endl;
	int id;
	std::cin >> id;

	CStudentMg cStuMg;
	CStudent cStu;
	cStu = cStuMg.findById(m1, id);

	if (cStu.getId() != -1)
	{
		std::cout << cStu << std::endl;
	}
	else
	{
		std::cout << "there is no this student" << std::endl;
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();

}

/* view层删除一个学生 */
void CMainView::deleteByIdAtView(std::map<int, CStudent>& v1) {

	system("cls");
	std::cout << "please input the id you want ro delete" << std::endl;
	int id;
	std::cin >> id;

	CStudentMg cStuMg;
	bool b = cStuMg.deleteStuById(v1, id);

	if (b)
	{
		std::cout << "delete success!" << std::endl;
	}
	else {
		std::cout << "there is no this student" << std::endl;
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();

}

/* view层 更新一个学生 */
void CMainView::updateByIdAtView(std::map<int, CStudent>& m1) {

	system("cls");

	std::cout << "please input the id you want to modify" << std::endl;
	int id;
	std::cin >> id;
	std::string name;

	std::cout << "name:";
	std::cin >> name;

	int age;
	std::cout << "age:";
	std::cin >> age;

	CStudent cStu;
	cStu.setId(id);
	cStu.setName(name);
	cStu.setAge(age);

	CStudentMg cStuMg;

	CStudent cStu2 = cStuMg.updateStu(m1, cStu);

	if (cStu2.getId() != -1)
	{
		std::cout << cStu2 << std::endl;
		std::cout << "modify success" << std::endl;
	}
	else
	{
		std::cout << "there is no this student" << std::endl;
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();

}

/* view层 把vec保存进文件 */
void CMainView::saveToFileAtView(const std::map<int, CStudent>& m1, std::string pathName) {

	if (m1.begin() == m1.end()) {
		system("cls");
		std::cout << "there is not information of student, can not save" << std::endl;
	}
	else {
		// 保存
		CStudentMg cStuMg;
		bool b = cStuMg.saveToFile(m1, pathName);
		if (b) {
			system("cls");
			std::cout << "save success" << std::endl;
		}
		else {
			std::cout << "save defeat" << std::endl;
		}
	}

	system("pause");
	system("cls");
	welcome();
	showMenu();

}

/* view层 把文件中的东西导入 vec */
void CMainView::readFromFileAtView(std::map<int, CStudent>& m, std::string pathName) {

	system("cls");

	CStudentMg cStuMg;
	bool b = cStuMg.readFromFile(m, pathName);
	if (b) {
		std::cout << "read success" << std::endl;
	}
	else {
		std::cout << "read defeat" << std::endl;
	}
	system("pause");
	system("cls");
	welcome();
	showMenu();
}