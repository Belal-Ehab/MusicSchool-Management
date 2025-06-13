#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

class MusicSchool {

private:
	string StudentName;
	int StudentAge;
	string StudentID;
	string StudentEmail;
	int StudentYear;
	float StudentFees;
	int StudentNumOfCourses;

	vector <float> StudentTiming;
	vector <float> StudentDuration;
	vector <string> StudentCourses;



public:
	MusicSchool() {

		StudentName = " ";
		StudentAge = 0;
		StudentID = " ";
		StudentEmail = " ";
		StudentYear = 0;
		StudentFees = 0;
		StudentNumOfCourses = 0;

	}
	MusicSchool(string SN, int SA, string SID, string SEM, int SY, int SNOC) {

		StudentName = SN;
		StudentAge = SA;
		StudentID = SID;
		StudentEmail = SEM;
		StudentYear = SY;
		StudentFees = 0;
		StudentNumOfCourses = SNOC;

	}
	void SetStudentName(string sn) {
		StudentName = sn;
	}
	void SetStudentAge(int sa) {
		StudentAge = sa;
	}
	void SetStudentID(string sid, int numofstudents, vector<MusicSchool>&V) {

		for (int i = 0; i < numofstudents ; i++) {

			if (V[i].GetStudentID() == sid) {

				cout << "The ID has already been used, please enter another one: ";
				cin >> sid;
				while (sid == V[i].GetStudentID()) {
					cout << "The ID has already been used, please enter another one: ";
					cin >> sid;
				}
			}
		}
		StudentID = sid; //sid is the the students ID but it is needed to be tested whether this ID exists or not.
	}
	void SetStudentEmail(string sem) {
		StudentEmail = sem;
	}
	void SetStudentYear(int sy) {
		StudentYear = sy;
	}
	void SetStudentNumOfCourses(int snoc) {
		StudentNumOfCourses = snoc;
	}
	string GetStudentName() {
		return StudentName;
	}
	int GetStudentAge() {
		return StudentAge;
	}
	string GetStudentID() {
		return StudentID;
	}
	string GetStudentEmail() {
		return StudentEmail;
	}
	int GetStudentYear() {
		return StudentYear;
	}
	int GetStudentNumOfCourses() {
		return StudentNumOfCourses;
	}
	int GetStudentFees() {
		return StudentFees;
	}
	void AddCourses(string coursename, float timing, float duration) {

		StudentDuration.push_back(duration);
		StudentTiming.push_back(timing);
		StudentCourses.push_back(coursename);

	}
	void DeleteCourses(string coursename) {

		for (int i = 0; i < StudentCourses.size(); i++) {

			if (coursename == StudentCourses[i]) {
				
				StudentCourses[i] = StudentCourses[StudentCourses.size() - 1];
				StudentCourses.resize(StudentCourses.size() - 1);
				StudentTiming[i] = StudentTiming[StudentTiming.size() - 1];
				StudentTiming.resize(StudentTiming.size() - 1);
				StudentDuration[i] = StudentDuration[StudentDuration.size() - 1];
				StudentDuration.resize(StudentDuration.size() - 1);	
			
			}
		}

	}
	MusicSchool AddStudent(int numofstudents, vector<MusicSchool>&V) {

		MusicSchool NewStudent;
		string coursename, tempstudentid;
		float timing, duration;

		cout << "Please enter the student's name: ";
		cin >> NewStudent.StudentName;

		cout << "Please enter the student's age: ";
		try {
			cin >> NewStudent.StudentAge;
			if (cin.fail()) {
				throw "Invalid data type entered";
			}
		}
		catch (const char* e) {
			cout << e;
		}

		cout << "Please enter the student's ID: ";
		cin >> tempstudentid;
		NewStudent.SetStudentID(tempstudentid, numofstudents, V);

		cout << "Please enter the student's year: ";
		try {
			cin >> NewStudent.StudentYear;
			if (cin.fail()) {
				throw "Invalid data type entered";
			}
		}
		catch (const char* e) {
			cout << e;
		}

		cout << "Please enter the student's Email: ";
		cin>> NewStudent.StudentEmail;

		cout << "Please enter the amout of money already paid: ";
		try {
			cin >> NewStudent.StudentFees;
			if (cin.fail()) {
				throw "Invalid data type entered";
			}
		}
		catch (const char* e) {
			cout << e;
		}

		cout << "Please enter the student's number of courses: ";
		try {
			cin >> NewStudent.StudentNumOfCourses;
			if (cin.fail()) {
				throw "Invalid data type entered";
			}
		}
		catch (const char* e) {
			cout << e;
		}

		for (int i = 0; i < NewStudent.StudentNumOfCourses; i++) {
			cout << "Please enter the course's name: ";
			cin >> coursename;
			cout << "Please enter the timing of the course: ";
			try {
				cin >> timing;
				if (cin.fail()) {
					throw "Invalid data type entered";
				}
			}
			catch (const char* e) {
				cout << e;
			}
			cout << "Please enter the course's duration: ";
			try {
				cin >> duration;
				if (cin.fail()) {
					throw "Invalid data type entered";
				}
			}
			catch (const char* e) {
				cout << e;
			}
			NewStudent.AddCourses(coursename, timing, duration);
		}

		return NewStudent;
	}
	void DisplayInfo() {
		cout << "Student's name is " << StudentName << endl;
		cout << "Student's ID is " << StudentID << endl;
		cout << "Student's Age is " << StudentAge << endl;
		cout << "Student's Email is " << StudentEmail << endl;
		cout << "Student's Year is " << StudentYear << endl;
		cout << "Student's Number of courses is " << StudentCourses.size() << endl;
		for (int i = 0; i < StudentCourses.size(); i++) {
			cout << "The name of course number " << i + 1 << " is " << StudentCourses[i] << endl;
			cout << "The timing of course number " << i + 1 << " is " << StudentTiming[i] << endl;
			cout << "The duration of course number " << i + 1 << " is " << StudentDuration[i] << endl;
		}
	}
	void GenerateReceipt() {
		float total = StudentCourses.size() * 5000;
		cout << "The overall cost of the semester: " << total << endl;
		cout << "The student already paid: " << StudentFees << endl;
		if (total == StudentFees) {
			cout << "The balance is settled" << endl;
		}
		else if (total < StudentFees) {
			cout << "The Music School owes " << StudentFees - total << endl;
		}
		else {
			cout << "The student owes " << total - StudentFees << endl;
		}
	}
};

int main() {

	vector <MusicSchool> V(1);
	int Command;
	// new string, new float, and new int variables are used to store temporary values of the data type mentioned
	string new_string, editID = " ";
	int	editIndex, new_int, case1command = 0;
	float new_float, new_float1;
	do {
		cout << "What would you like to do from the following: " << endl;
		cout << "Enter 1 to edit\nEnter 2 to add new student\nEnter 3 to display\nEnter 4 to generate reciept\nEnter 5 to exit" << endl;
		cin >> Command;
		switch (Command)
		{
		case 1:
			cout << "Enter the ID of the student: ";
			cin >> editID;
			for (int i = 0; i < V.size(); i++) {

				if (editID == V[i].GetStudentID()) {
					editIndex = i;
					break;
				}

			}
			while (case1command != 7) {
				cout << "What would you like to edit\nEnter 1 to edit name\nEnter 2 to edit age\nEnter 3 to edit ID\nEnter 4 to edit Email\nEnter 5 to edit year\nEnter 6 to edit enrolled classes\nEnter 7 to exit: " << endl;
				int case1command;
				try {
					cin >> case1command;
					if (cin.fail()) {
						throw "Invalid data type entered";
					}
				}
				catch (const char* e) {
					cout << e;
				}
				switch (case1command)
				{
				case 1:
					cout << "Enter new name: ";
					cin >> new_string;
					V[editIndex].SetStudentName(new_string);
					break;
				case 2:
					cout << "Enter new age: ";
					try {
						cin >> new_int;
						if (cin.fail()) {
							throw "Invalid data type entered";
						}
					}
					catch (const char* e) {
						cout << e;
					}
					V[editIndex].SetStudentAge(new_int);
					break;
				case 3:
					cout << "Enter new ID: ";
					cin >> new_string;
					V[editIndex].SetStudentID(new_string, V.size(), V);
					break;
				case 4:
					cout << "Enter new Email: ";
					cin >> new_string;
					V[editIndex].SetStudentEmail(new_string);
					break;
				case 5:
					cout << "Enter new Year: ";
					try {
						cin >> new_int;
						if (cin.fail()) {
							throw "Invalid data type entered";
						}
					}
					catch (const char* e) {
						cout << e;
					}
					V[editIndex].SetStudentYear(new_int);
					break;
				case 6:
					cout << "Enter 1 to add new course\nEnter 2 to delete an existing course\n";
					try {
						cin >> new_int;
						if (cin.fail()) {
							throw "Invalid data type entered";
						}
					}
					catch (const char* e) {
						cout << e;
					}
					if (new_int == 1) {
						cout << "Enter the name of the new course: ";
						cin >> new_string;
						cout << "Enter the timing of the class: ";
						try {
							cin >> new_float;
							if (cin.fail()) {
								throw "Invalid data type entered";
							}
						}
						catch (const char* e) {
							cout << e;
						}
						cout << "Enter the duration of the class: ";
						try {
							cin >> new_float1;
							if (cin.fail()) {
								throw "Invalid data type entered";
							}
						}
						catch (const char* e) {
							cout << e;
						}
						V[editIndex].AddCourses(new_string, new_float, new_float1);
					}
					else if (new_int == 2) {
						cout << "Enter the name of the course you wish to be deleted: ";
						cin >> new_string;
						V[editIndex].DeleteCourses(new_string);
					}
					break;
				default:
					break;
				}
				break;
			}
			break;
		case 2:
			V.push_back(V[0].AddStudent(V.size(),V));

			break;
		case 3:
			cout << "Enter the ID of the student: ";
			cin >> editID;
			for (int i = 0; i < V.size(); i++) {
				if (editID == V[i].GetStudentID()) {
					V[i].DisplayInfo();
				}
			}
			break;
		case 4:
			cout << "Enter the ID of the student: ";
			cin >> editID;
			for (int i = 0; i < V.size(); i++) {
				if (editID == V[i].GetStudentID()) {
					V[i].GenerateReceipt();
				}
			}
			break;
		default:
			break;
		}

	} while (Command != 5 && Command >= 1 && Command <= 4);

}