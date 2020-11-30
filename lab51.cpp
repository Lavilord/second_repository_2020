#include <iostream>
#include <string>
#define N 5
#define M 5
using namespace std;
class Student
{
private:
    string name;
    int marks[N]= {0};
    friend void AddMark(int mark);

public:


    void AddMark(int mark){
        for (int i=0; i<N; i++){
            if (marks[i]==0){
                marks[i]=mark;
                break;
            }
        }
    }
    void OutputMarks(){
        for (int i=0; i<N; i++){
            cout << " " << marks[i];
        }
    }
    float GetAverageMark(){
        float s=0;
        int count=0;
        for (int i=0; i<N; i++){
            if (marks[i]){
                s+=marks[i];
                count++;
            }
        }
        return s/count; 
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
void func (int *a,int *b){
    a++;
    b++;
    

}

class Group  {
private:
    Student *arrStudent[M]={0};

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
        for (int i = 0; i < M; i++)
            if (arr[i] != NULL) {
                cout << arr[i]->GetName() << " | avarage: " << arr[i]->GetAverageMark() << " | marks: ";
                arr[i]->OutputMarks();
                cout << endl;
            }
        cout << "=====" << endl;
    }

public: 
    void AddStudent(Student* student){
        for (int i = 0; i < M; i++)
            if (arrStudent[i] == NULL) {
                arrStudent[i] = student;
                break;
            }
    }

    Student *GetStudent(string name)
    {
        for (int i = 0; i < M; i++)
            if (arrStudent[i] != NULL) 
                if (arrStudent[i]->GetName() == name)
                    return arrStudent[i];
        return NULL;
    }
    void PrintRate()
    {
        Student *tmpArr[M] = {0};
        int count = 0;
        for (int i = 0; i < M; i++) {
            if (arrStudent[i]) {
                tmpArr[count++] = arrStudent[i];
            }
        }

        bubbleSort(tmpArr, count);
        PrintStudentsInt(tmpArr);

    }
    
    bool DelStudent(string name)
    {
        for (int i = 0; i < M; i++)
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
        for (int i = 0; i < M; i++)
            if (arrStudent[i] != NULL)
                delete arrStudent[i];
    }

};


int main (){
    int a,b;
    cin >> a >> b;
    func(&a,&b);
    cout << a <<b;
    string name;
    Group IOT1;
    IOT1.AddStudent(new Student("GGG"));
    IOT1.AddStudent(new Student("HHH"));
    IOT1.AddStudent(new Student("YYY"));

    IOT1.GetStudent("GGG")->AddMark(5);
    IOT1.GetStudent("GGG")->AddMark(2);
    IOT1.GetStudent("GGG")->AddMark(7);
    
    IOT1.GetStudent("HHH")->AddMark(3);
    IOT1.GetStudent("HHH")->AddMark(5);
    IOT1.GetStudent("HHH")->AddMark(5);

    IOT1.GetStudent("YYY")->AddMark(2);
    IOT1.GetStudent("YYY")->AddMark(2);
    IOT1.GetStudent("YYY")->AddMark(2);
    IOT1.PrintStudents();
    IOT1.DelStudent("GGG");
    IOT1.PrintStudents();
    IOT1.PrintRate();
    
    
}


