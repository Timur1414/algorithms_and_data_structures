#include <string>
#include <iostream>
using namespace std;

const string part1[]={"Рам", "Джо", "Ва", "Ло", "Пу"};
const string part2[]={"зам", "ждо", "тя", "чен", "тин"};
const string part3[]={"я", "ой", "джа", "тут", "ду"};

class Student{
private:
    int iq;
    string name;
public:
    Student(){
        iq =50+rand()%151;
        name=part1[rand()%5]+part2[rand()%5]+part3[rand()%5];
    }
    void show(){
        cout << name << " : " << iq << endl;
    }
};


struct hang{
    Student* data;
    hang* next;
};


class Group{
private:
    hang *first, * cur;
public:
    Group(){
        first = NULL;
    }
    ~Group(){
        genocid();
    }
    void add(){
        cur = new hang;
        cur->data=new Student();

        cur->next = first;
        first = cur;
    }
    void add(int n){
        for(int i=0;i<n;i++) add();
    }
    void del(){
        if(first){
            cur = first;
            first = first->next;

            delete cur->data;
            delete cur;
        }
    }
    void del(int n){
        for(int i=0;i<n;i++) del();
    }
    void show(){
        cur = first;
        while(cur){
            cur->data->show();
            cur=cur->next;
        }
    }
    void genocid(){
        while (first) del();
    }
};

int main(){
    setlocale(LC_ALL, "");
    Group A;
    int n,choose;
    do
    {
        cout << "\n=========================================";
        cout << "\n 1-add 2-add(n) 3-del 4-del(n) 5-show 6-genocid \n";
        cin >> choose;
        system("clear");
        switch (choose)
        {
            case 1:A.add(); A.show(); break;
            case 2:cin >> n;A.add(n); A.show(); break;
            case 3:A.del(); A.show(); break;
            case 4:cin >> n;A.del(n); A.show(); break;
            case 5:A.show(); break;
            case 6:A.genocid(); break;
        }
    } while (choose!=0);
    return 0;   
}