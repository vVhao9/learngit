#include<iostream>
#define MAX 1000

void showMenu()
{
    std::cout << "****************************" << std::endl;
    std::cout << "***  1.Add a person      ***" << std::endl;
    std::cout << "***  2.Display person    ***" << std::endl;
    std::cout << "***  3.Delete a contact  ***" << std::endl;
    std::cout << "***  4.find              ***" << std::endl;
    std::cout << "***  5.Modify a Contact  ***" << std::endl;
    std::cout << "***  6.Empty contacts    ***" << std::endl;
    std::cout << "***  0.Quit Addressbook  ***" << std::endl;
    std::cout << "****************************" << std::endl;
}
struct person
{
    std::string m_Name;
    int m_Sex;
    int m_Age;
    std::string m_Phone;
    std::string m_Addr;
};
struct Addrseebook
{
    person PersonArray[MAX];
    int m_Size;
};
void addperson(Addrseebook * abs)
{
    if (abs->m_Size == MAX)  
    {
        std::cout << "Addressbook is full." << std::endl;
        return ;
    }
    else
    {
        //添加联系人
        //姓名
        std::string name;
        std::cout << "Enter name" << std::endl;
        std::cin >> name;
        abs->PersonArray[abs->m_Size].m_Name = name;
        //性别
        std::cout << "Enter sex" << std::endl;
        std::cout << "1 --- man" << std::endl;
        std::cout << "2 --- woman" << std::endl;
        int sex;
        while (true)
        {
            std::cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->PersonArray[abs->m_Size].m_Sex = sex;
                break;
            }
            std::cout << "Enter error,please re-enter" << std::endl;
        }
        //年龄
        int age;
        std::cout << "Enter age" << std::endl;
        while (true)
        {  
            std::cin >> age;
            if (age < 120)
            {
                abs->PersonArray[abs->m_Size].m_Age = age;
                break;
            }
            std::cout << "Enter error,please re-enter" << std::endl;        
        }
        //电话
        std::cout << "Please enter phone" << std::endl;
        std::string phone;
        std::cin >> phone;
        abs->PersonArray[abs->m_Size].m_Phone = phone;
        //住址
        std::cout << "please enter address" << std::endl;
        std::string  address;
        std::cin >> address;
        abs->PersonArray[abs->m_Size].m_Addr = address;
        //更新通讯录人数
        abs->m_Size++;
        std::cout << "Successfully Added!" << std::endl;
        system("pause");
        system("cls");
    }
}
void showPerson(Addrseebook * abs) //显示联系人
{
    if (abs->m_Size == 0)
    {
        std::cout << "No persons." << std::endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            std::cout << "name: " << abs->PersonArray[i].m_Name << "\t";
            std::cout << "sex: " << (abs->PersonArray[i].m_Sex == 1 ? "man" : "woman") << "\t";
            std::cout << "age: " << abs->PersonArray[i].m_Age << "\t";
            std::cout << "phone: " << abs->PersonArray[i].m_Phone << "\t";
            std::cout << "address: " << abs->PersonArray[i].m_Addr << "\t" << std::endl;
        }
        
    }
    system("pause");
    system("cls");
}
//检测联系人是否存在，如果存在，返回联系人所在数组中的位置，不存在返回-1
//参数1 通讯录 ， 参数2 对比姓名
int isExist(Addrseebook * abs, std::string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->PersonArray[i].m_Name == name)
        {
            return i;
        }
    
    }
    return -1;
}
void deletePerson(Addrseebook * abs)
{   

    std::cout << "The name of the person you want to delete" << std::endl;
    std::string name;
    std::cin >> name;
    int ret = isExist(abs,name);
    if (ret != -1) //ret == -1 未找到 ，ret ！=- 1 找到了
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            abs->PersonArray[i] = abs->PersonArray[i+1]; //数据前移
        }
        abs->m_Size--;
        std::cout << "Successfully delete!" << std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        std::cout << "not find" << std::endl;
        system("pause");
        system("cls");
    }
}
void findPerson(Addrseebook * abs)
{
    std::cout << "the name of the person you want to find" << std::endl;
    std::string  name;
    std::cin >> name;
    if (isExist(abs,name) == -1)
    {
        std::cout << "not find" << std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        std::cout << "name: " << abs->PersonArray[isExist(abs,name)].m_Name << "\t";
        std::cout << "age: " << abs->PersonArray[isExist(abs,name)].m_Age << "\t";
        std::cout << "sex: " << (abs->PersonArray[isExist(abs,name)].m_Sex == 1 ? "man" : "woman") << "\t";
        std::cout << "phone: " << abs->PersonArray[isExist(abs,name)].m_Phone << "\t";
        std::cout << "address: " << abs->PersonArray[isExist(abs,name)].m_Addr << "\t" << std::endl;
        system("pause");
        system("cls");
    }
}
void modifyPerson(Addrseebook * abs)
{
    std::cout << "the name of the person you wang to modify" << std::endl;
    std::string name;
    std::cin >> name;
    int ret = isExist(abs,name);
    if (ret == -1)  
    {
        std::cout << "not find" << std::endl;
        system("pause");
        system("cls");
    }
    else
    {
        //姓名
        std::string modifyName;
        std::cout << "Enter name" << std::endl;
        std::cin >> modifyName;
        abs->PersonArray[ret].m_Name = modifyName;
        //性别
        int sex;
        std::cout << "Enter sex" << std::endl;
        std::cout << "1 --- man" << std::endl;
        std::cout << "2 --- woman" << std::endl;
        while (true)
        {  
            std::cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->PersonArray[ret].m_Sex = sex;
                break;
            }
            std::cout << "Enter error,please re-enter" << std::endl;
        }
        //年龄
        int age;
        std::cout << "Enter age" << std::endl;
        while (true)
        {
            std::cin >> age;
            if (age > 120)  
            {
                std::cout << "Enter error,please re-enter" << std::endl;
            }
            else
            {
                abs->PersonArray[ret].m_Age = age;
                break;
            }
        }
        //电话
        std::string phone;
        std::cout << "Enter phone" << std::endl;
        std::cin >> phone;
        abs->PersonArray[ret].m_Phone = phone;
        //地址
        std::cout << "Enter address" << std::endl;
        std::string address;
        std::cin >> address; 
        abs->PersonArray[ret].m_Addr = address;
        
        std::cout << "modify sucefully !" << std::endl;
        system("pause");
        system("cls"); 
    }
}
void cleanPerson(Addrseebook * abs)
{
    abs->m_Size = 0;
    std::cout << "cleaned." << std::endl;
    system("pause");
    system("cls");
}
int main(){
    
    Addrseebook abs;
    abs.m_Size = 0;

    showMenu();

    int select = 0;

    while (true)
    {
        std::cin >> select;
        
        switch (select)
        {
        case 1:
            addperson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
        deletePerson(&abs);
        // {
        // std::cout << "The name of the person you want to delete" << std::endl;
        // std::string name;
        // std::cin >> name;
        // if ( isExist(&abs,name) == -1 )  //如果isExist函数的返回值为-1则no，否则输出ok即找到此人
        // {
        //     std::cout << "no!" << std::endl;
        // }
        // else
        // {
        //     std::cout << "ok!" << std::endl;
        // }
        // }
            break;
        case 4:
        findPerson(&abs);
            break;
        case 5:
        modifyPerson(&abs);
            break;
        case 6:
        cleanPerson(&abs);
            break;
        case 0:
            std::cout << "welecome next time." << std::endl;
            system("pause");
            return 0;
            break;    
        default:
            break;
        }
        showMenu();
    }
    
    system("pause");
    return 0;
}
