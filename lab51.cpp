#include <iostream>
#include <string>
#define NumberOfMarks 5
#define NumberOfStudents 5
using namespace std;
class Student
{
    private:
        string name;
        int marks[NumberOfMarks]= {0};
        friend void AddMark(int mark);

    public:
        void AddMark(int mark){
            for (int i=0; i<NumberOfMarks; i++){
                if (marks[i]==0){
                    marks[i]=mark;
                    break;
                }
            }
        }

        void OutputMarks(){
            for (int i=0; i<NumberOfMarks; i++){
                cout << " " << marks[i];
            }
        }

        float GetAverageMark(){
            float sumOfMarks=0;
            int count=0;
            for (int i=0; i<NumberOfMarks; i++){
                if (marks[i]){
                    sumOfMarks+=marks[i];
                    count++;
                }
            }
            return sumOfMarks/count; 
        }

        string GetName()
        {
            return this->name;
        } 

        Student(string name)
        {
            this->name=name;  
        }
    
};

class Group  {
    private:
        Student *arrStudent[NumberOfStudents]={0};

        void swap(Student **xp, Student **yp) 
        { 
            Student *temp = *xp; 
            *xp = *yp; *yp = temp; 
        } 

        void bubbleSort(Student *arr[], int n) 
        { 
            int i, j; 
            for (i = 0; i < n-1; i++)
                for (j = 0; j < n-i-1; j++) 
                    if (arr[j]->GetAverageMark() < arr[j+1]->GetAverageMark()) 
                        swap(&arr[j], &arr[j+1]); 
        } 

        void PrintStudentsInt(Student *arr[])
        {
            cout << "=====" << endl;
            for (int i = 0; i < NumberOfStudents; i++)
                if (arr[i] != NULL) {
                    cout << arr[i]->GetName() << " | avarage: " << arr[i]->GetAverageMark() << " | marks: ";
                    arr[i]->OutputMarks();
                    cout << endl;
                }
            cout << "=====" << endl;
        }

    public: 
        void AddStudent(Student* student){
            for (int i = 0; i < NumberOfStudents; i++)
                if (arrStudent[i] == NULL) {
                    arrStudent[i] = student;
                    break;
                }
        }

        Student *GetStudent(string name)
        {
            for (int i = 0; i < NumberOfStudents; i++)
                if (arrStudent[i] != NULL) 
                    if (arrStudent[i]->GetName() == name)
                        return arrStudent[i];
            return NULL;
        }

        void PrintRate()
        {
            Student *tmpArr[NumberOfStudents] = {0};
            int count = 0;
            for (int i = 0; i < NumberOfStudents; i++) {
                if (arrStudent[i]) {
                    tmpArr[count++] = arrStudent[i];
                }
            }
            bubbleSort(tmpArr, count);
            PrintStudentsInt(tmpArr);
        }
    
        bool DelStudent(string name)
        {
            for (int i = 0; i < NumberOfStudents; i++)
                if (arrStudent[i] != NULL) {
                    if (arrStudent[i]->GetName() == name) {
                        delete arrStudent[i];
                        arrStudent[i] = NULL;
                        return true;
                        }
                }
            return false;
        }

        void PrintStudents() {
            PrintStudentsInt(this->arrStudent);
        }
    
        ~Group()
        {
            for (int i = 0; i < NumberOfStudents; i++)
                if (arrStudent[i] != NULL)
                    delete arrStudent[i];
        }
};


int main (){
    string name;
    Group IOT;

    IOT.AddStudent(new Student("GGG"));
    IOT.AddStudent(new Student("HHH"));
    IOT.AddStudent(new Student("YYY"));

    IOT.GetStudent("GGG")->AddMark(5);
    IOT.GetStudent("GGG")->AddMark(2);
    IOT.GetStudent("GGG")->AddMark(7);
    
    IOT.GetStudent("HHH")->AddMark(3);
    IOT.GetStudent("HHH")->AddMark(5);
    IOT.GetStudent("HHH")->AddMark(5);

    IOT.GetStudent("YYY")->AddMark(2);
    IOT.GetStudent("YYY")->AddMark(2);
    IOT.GetStudent("YYY")->AddMark(2);

    IOT.PrintStudents();
    IOT.DelStudent("GGG");
    IOT.PrintStudents();
    IOT.PrintRate();
};
