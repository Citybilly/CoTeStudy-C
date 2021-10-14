#include <iostream>
#include <string>

using namespace std;

class Employee
{
private :
    int m_ID;
    string m_Name;    
public:
    Employee(int id, const string &name): m_ID(id), m_Name(name)
    {
        cout << "Employee " << m_Name << " created.\n" << endl;
    }

    Employee(const string& name) : Employee(0,name)
    {
        
    }

};

int main()
{
    int ID = 1;
    string Name = "Woo Hyun";
    string Name2 = "Book";
    Employee employee(Name);
    Employee employee2(ID,Name2);
    return 0;
}