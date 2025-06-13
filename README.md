Music School Management System
A C++ console application developed as a university project to manage student records for a music school. The program allows adding, editing, and displaying student information, managing enrolled courses, and generating payment receipts.
Features

Add new students with details like name, age, ID, email, year, and number of courses.
Edit student information (name, age, ID, email, year, or courses).
Add or delete courses for a student, including course name, timing, and duration.
Display student details, including enrolled courses.
Generate a receipt showing total semester cost, paid amount, and balance.
Input validation to handle duplicate IDs and invalid data types.

Technologies

Language: C++ (Standard Library)
Data Structures: Vectors for storing student and course information
Concepts: Object-Oriented Programming (classes, objects), exception handling, input/output

Setup

Clone the Repository:
git clone https://github.com/Belal-Ehab/MusicSchool-Management.git


Navigate to the Project:
cd MusicSchool-Management


Compile the Code:

Use a C++ compiler (e.g., g++):
g++ src/MusicSchool.cpp -o MusicSchool




Run the Program:

On Windows: MusicSchool.exe
On Linux/macOS: ./MusicSchool



Usage

Run the program and choose from the menu:
Edit a student’s details (by ID).
Add a new student.
Display a student’s information.
Generate a receipt for a student.
Exit.


Follow prompts to input student details or manage courses.

Example
What would you like to do from the following:
Enter 1 to edit
Enter 2 to add new student
Enter 3 to display
Enter 4 to generate receipt
Enter 5 to exit

Notes

The program assumes each course costs 5000 units for receipt calculations.
Error handling is implemented for invalid inputs (e.g., non-numeric values).
The project demonstrates fundamental C++ concepts like classes, vectors, and user input handling.

Future Improvements

Add file I/O to save student data persistently.
Implement a graphical user interface (e.g., using Qt).
Add validation for course timings to prevent scheduling conflicts.

