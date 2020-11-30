#include <iostream>
#include <string>
using namespace std;
class ship {
    private:
        string name;
        int capacity, number;
    public:
        string l;
        int h=5;  
        void getcapacity(){
            cout << "capacity =";
            cin >> capacity;
            cout<< endl;
        }
        void getname(){
            cout << "name =";
            cin >> name;
            
            cout<< endl;
        }
        void getnumber(){
            cout << "number =";
            cin >> number;
            cout<< endl;
        }  
        void outcapacity(){
            cout << "capacity = "<< capacity<< endl;
        }

        void outname(){
            cout << "name = "<< name<< endl;
        }

        void outnumber(){
            cout << "number = "<< number << endl;
        }
        void outm(){
            cout << "m = "<< m << endl;
        }
        void outr(){
            cout << "r = "<< r << endl;
        }
        void outh(){
            cout << "h =" << h << endl;
        }
        void outl(){
            cout << "l = "<< l << endl;
        }
        ship(int c, int num, string m, string r, string n){
            name= n;
            capacity= c;
            number= num;
            m=m;
            r=r;
        };
        ship(){
            cout << "m =";
            cin >> m;
            cout << "r =";
            cin >> r;
            cout << "l =";
            cin >> l;
        };
        ~ship(){}
    protected:
        string m,r;
};