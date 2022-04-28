# 作业（下周四晚上6点前交齐）：
# 控制台版文章管理系统：
# 	1、用户管理系统
# 	2、文章的管理和控制
# 	3、宠物管理【扩展功能】

# 	|-- 密码加密
# 	|-- 时间API
# 	|-- 实现数据的持久化
# 	将我们学习过的知识都使用上
# 	继续完善控制台案例！！！
#注意：第一次使用需先在工作目录中创建 users.txt 文件 并写如 {}
import hashlib
import json
import os
import sys
import time


class SysManger():

    def __init__(self) -> None:
        content = json.load(open("users.txt","r"))
        self.__users = content
        print(content)
        self.now_user = ""
        self.library = {}
        self.File_name = ""
        
        
    def Inof_Meau(self):
        print('------------------------------')
        print('|*********1.用户注册**********|')
        print('|*********2.用户登录**********|')
        print('|*********3.退出系统**********|')
        print('------------------------------')
         
    def sign_in(self):
        userName = input("请输入用户名：")
        Passwd = input("请输入用户密码：")
        ack_Passwd = input("请再次确定密码：")
        while ack_Passwd != Passwd:
            print("两次密码不一致，请重新输入！")
            userName = input("请输入用户名：")
            Passwd = input("请输入用户密码：")
            ack_Passwd = input("请再次确定密码：")
        new_Passwd = hashlib.md5(ack_Passwd.encode()) #MD5加密
        new_Passwd = new_Passwd.hexdigest() #返回加密结果
        self.__users[userName] = new_Passwd
        json.dump(self.__users,open("users.txt","w"))
        print("Successfully!")
        time.sleep(0.5)
        os.system("cls")
    
    def log_in(self):
        content = json.load(open("users.txt","r"))
        self.__users = content
        userName = input("请输入用户名：")
        Passwd = input("请输入用户密码：")
        a = hashlib.md5(Passwd.encode())
        Passwd = a.hexdigest()
        for key in self.__users:
            if{key:self.__users[key]} == {userName:Passwd}:
                self.now_user = key
                self.File_name =  f"{self.now_user}.txt"
                print("登陆成功！")
                try:
                    lib = json.load(open(f"{self.now_user}.txt","r"))
                    self.library = lib
                except FileNotFoundError:
                    f = open(f"{self.File_name}","w",encoding="utf-8")
                    d = {}
                    json.dump(d,open(self.File_name,"w"))
                    f.close()
                time.sleep(0.5)
                os.system("cls")
                return 1
        print("用户名或密码错误！")
        time.sleep(1)
        os.system("cls")
        return 0
    
    def Is_EmptyFile(self,filename):
        with open(f"{filename}","r",encoding="utf-8") as f:
            f.seek(0) #将文件中的读取指针移动到文件开始位置
            content = f.read()
            if content == "{}" or "":
                return True
            else: return False

    def Exit_Sys(self):
        sys.exit()

class ArticleManager(SysManger):

    def __init__(self) -> None:
        super().__init__()


    def Inof_Meau(self):
        t = time.strftime("%Y年-%m月-%d日 %H时:%M分:%S秒")
        print(f"Hi {self.now_user}\n{t}")
        print('------------------------------')
        print('|*********1.文章目录**********|')
        print('|*********2.增加文章**********|')
        print('|*********3.删除文章**********|')
        print('|*********4.查找文章**********|')
        print('|*******5.返回上级菜单********|')
        print('------------------------------')

    def add_Article(self):
        title = input("请输入文章标题：")
        content = input("请输入文章内容：")
        self.library[title] = content
        json.dump(self.library,open(f"{self.now_user}.txt","w"))
        print("添加成功！")
        time.sleep(0.5)
        os.system("cls")

    def show_Article(self):
        if self.Is_EmptyFile(self.File_name):
            print("当前用户无文章！")
            time.sleep(0.5)
            os.system("cls")
            return
        i = 1
        for key in self.library:
            print(f"ID:{i}   文章：{key}   内容：{self.library.get(key)}")
            i += 1
        os.system("pause")
        os.system("cls")
    
    def delete_Article(self):
        if self.Is_EmptyFile(self.File_name):
            print("当前用户无文章！")
            time.sleep(0.5)
            return
        index = input("您要删除哪篇文章：")
        print(f"{self.library.keys()}\n")
        if index not in self.library.keys():
            print("没有找到此文章！")
            time.sleep(1)
            os.system("cls")
            return
        self.library.pop(index)
        json.dump(self.library,open(self.File_name,"w"))
        print("删除成功！")
        time.sleep(0.5)
        os.system("cls")

    def Find_Aricle(self):
        if self.Is_EmptyFile(self.File_name):
            print("当前用户无文章！")
            return
        name = input("您要查找的文章名：")
        if name not in self.library.keys():
            print("Sry,没有找到该文章!")
        else:
            print(self.library.get(name))
        os.system("pause")
        os.system("cls")
         

if __name__ == '__main__':
    M1 = SysManger()
    A1 = ArticleManager()
    while True:
        M1.Inof_Meau()
        select = int(input("请输入选项："))
        if select == 1:
            M1.sign_in()
        elif select == 2:
            x = A1.log_in()
            while x:  #判断是否进入二级界面
                A1.Inof_Meau()
                choice = int(input("请输入选项："))
                if choice == 1:
                    A1.show_Article()
                elif choice == 2:
                    A1.add_Article()
                elif choice == 3:
                    A1.delete_Article()
                elif choice == 4:
                    A1.Find_Aricle()
                elif choice == 5:
                    break
                else:
                    print("输入错误！")
        elif select == 3:
            M1.Exit_Sys()
        else:
            print("输入错误！")
