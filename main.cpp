#include<iostream>
#include<string>
using namespace std;
const int MAX = 1000;
#include<fstream>

//医生个人信息结构体
struct Doctor
{
	//姓名
	string d_Name;
	//性别 1男2女
	int d_Sex;
	//年龄
	int d_Age;
	//医院
	string d_Hospital;
	//科室
	string d_Office;
	//电话
	string d_Phone;
};

//医院管理系统结构体
struct Management
{
	//系统中当前保存的医生数组
	struct Doctor doctorarray[MAX] ;

	//系统中当前记录的医生人数
	int d_Size;
};

//1.添加医生信息
void addDoctor(Management *manage)
{
	//判断系统中人数是否已经满了，如果满了就不添加了
	if(manage->d_Size==MAX)
	{
	    cout<<"系统中医生信息已满，无法添加！"<<endl;
		return;
	}
	else
	{//添加联系人

	//姓名
	string name;
	cout<<"请输入姓名： "<<endl;
	cin>>name;
	manage->doctorarray[manage->d_Size].d_Name=name;

	//性别
	cout<<"请输入性别： "<<endl;
	cout<<"1--男 2--女"<<endl;
	int sex=0;
	while(true)
	{//如果输入的是1或2则退出循环，输入错误值继续循环输入
        cin>>sex;
	    if(sex==1||sex==2)
	    {
		    manage->doctorarray[manage->d_Size].d_Sex=sex;
			break;
	    }
	    cout<<"输入有误，请重新输入"<<endl;
     }

	//年龄
	cout<<"请输入年龄： "<<endl;
	int age=0;
	while(true)
	 {//如果输入的是正确年龄则退出循环，输入错误值则提示继续循环输入
		 cin>>age;
	     if(age<120 && age>10)
	     {
		     manage->doctorarray[manage->d_Size].d_Age=age;
			 break;
	     }
		 cout<<"输入有误，请重新输入"<<endl;
	 }

	//医院
	cout<<"请输入所属医院： "<<endl;
    string hospital;
	cin>>hospital;
	manage->doctorarray[manage->d_Size].d_Hospital=hospital;

	//科室
	cout<<"请输入所属科室： "<<endl;
	string office;
	cin>>office;
	manage->doctorarray[manage->d_Size].d_Office=office;

	//电话
	cout<<"请输入联系电话： "<<endl;
	string phone;
	cin>>phone;
	manage->doctorarray[manage->d_Size].d_Phone=phone;
	
	//更新系统中当前记录的医生人数
	manage->d_Size++;
	cout<<"一名医生信息添加成功！"<<endl;

	system("pause");//请按任意键继续
	system("cls");//清屏操作
	}
}

//2.显示医生信息
void showDoctor(Management *manage)
{
 //先判断医生人数是否为0，如果为0,提示为空；如果不为0，显示医生信息
	if (manage->d_Size==0)
	{
		cout<<"当前记录为空"<<endl;
	}
	else
	{
		for(int i=0;i < (manage->d_Size);i++)
		{
			cout<<"姓名："<<manage->doctorarray[i].d_Name;
			cout<<"\t性别："<<(manage->doctorarray[i].d_Sex==1?"男":"女");
			cout<<"\t年龄："<<manage->doctorarray[i].d_Age;
			cout<<"\t医院："<<manage->doctorarray[i].d_Hospital;
			cout<<"\t科室："<<manage->doctorarray[i].d_Office;
			cout<<"\t电话："<<manage->doctorarray[i].d_Phone<<endl<<endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//3.删除医生信息
//1）首先要检测这个医生是否存在，如果存在，返回这个医生在数组中的具体位置，不存在返回-1
int exit(Management *manage,string name)//参数1：管理系统，参数2：检测的人名
{
	for(int i=0;i< manage->d_Size; i++)
	{//如果找到用户输入的姓名了
		if(manage->doctorarray[i].d_Name==name)
		{
		    return i;//找到了，返回这个医生在数组中的具体位置
		}
	}
	return -1;//如果遍历一遍都没有找到，返回-1
}
//2）删除输入的医生
void deleteDoctor(Management *manage)
{
	cout<<"请输入要删除的医生"<<endl;
	string name1;
	cin>>name1;
	int retur=exit(manage,name1);
	if(retur==-1)//如果遍历一遍都没有找到，返回-1
	{
	    cout<<"系统中没有这个人！"<<endl;
	}
	else
	{//查找到这个人，进行删除操作：将被删除医生后面的数据向前移动，并让系统的总人数-1
	    cout<<"找到此人"<<endl;
		for(int i=0;i < manage->d_Size;i++)
		{//数据前移:把后面那个数据赋值给当前的数据
			manage->doctorarray[i]=manage->doctorarray[i+1];
		}
		manage->d_Size--;//系统的总人数-1
	    cout<<"删除成功"<<endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//4.查询医生信息
void findDoctor(Management *manage)
{
	cout<<"请输入要查找的医生："<<endl;
	string name2;
	cin>>name2;
	//先判断这个人是否存在
	int retur=exit(manage,name2);
	if(retur==-1)
	{
	    cout<<"系统中没有这个人！"<<endl;
	}
	else
	{//查找到这个人，输出信息
	    cout<<"姓名："<<manage->doctorarray[retur].d_Name;
		cout<<"\t性别："<<(manage->doctorarray[retur].d_Sex==1?"男":"女");
		cout<<"\t年龄："<<manage->doctorarray[retur].d_Age;
		cout<<"\t医院："<<manage->doctorarray[retur].d_Hospital;
		cout<<"\t科室："<<manage->doctorarray[retur].d_Office;
		cout<<"\t电话："<<manage->doctorarray[retur].d_Phone<<endl<<endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//5.编辑医生信息
void editDoctor(Management *manage)
{
	cout<<"请输入需要修改信息的医生："<<endl;
	string name3;
	cin>>name3;
	//先判断这个人是否存在
	int retur=exit(manage,name3);
	if(retur==-1)
	{
	    cout<<"系统中没有这个人！"<<endl;
	}
	else
	{//修改这个人的信息
		//姓名
		string name4;
	    cout<<"请输入姓名："<<endl;
		cin>>name4;
		manage->doctorarray[retur].d_Name=name4;
		//性别
		int sex=0;
     	cout<<"请输入性别： "<<endl;
	    cout<<"1--男 2--女"<<endl;
	    while(true)
	    {//如果输入的是1，2则退出循环，输入错误值继续循环输入
            cin>>sex;
	        if(sex==1||sex==2)
	        {
		        manage->doctorarray[manage->d_Size].d_Sex=sex;
		    	break;
	        }
	        cout<<"输入有误，请重新输入"<<endl;
         }
	    //年龄
	    cout<<"请输入年龄： "<<endl;
	    int age=0;
	    while(true)
	    {//如果输入的是则退出循环，输入错误值则提示继续循环输入
		     cin>>age;
	         if(age<120 && age>10)
	         {
		         manage->doctorarray[manage->d_Size].d_Age=age;
			     break;
	         }
		     cout<<"输入有误，请重新输入"<<endl;
	    }
    	//医院
	    cout<<"请输入所属医院： "<<endl;
        string hospital;
	    cin>>hospital;
	    manage->doctorarray[manage->d_Size].d_Hospital=hospital;
	    //科室
	    cout<<"请输入所属科室： "<<endl;
	    string office;
	    cin>>office;
	    manage->doctorarray[manage->d_Size].d_Office=office;
	    //电话
	    cout<<"请输入联系电话： "<<endl;
	    string phone;
	    cin>>phone;
    	manage->doctorarray[manage->d_Size].d_Phone=phone;

    	cout<<"修改成功！"<<endl;
	}
    system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//系统菜单界面
void show()
{
	cout<<"**************************"<<endl;
	cout<<"***** 1.添加医生信息 *****"<<endl;
	cout<<"***** 2.显示医生信息 *****"<<endl;
	cout<<"***** 3.删除医生信息 *****"<<endl;
	cout<<"***** 4.查询医生信息 *****"<<endl;
	cout<<"***** 5.编辑医生信息 *****"<<endl;
	cout<<"***** 6.退出管理系统 *****"<<endl;
	cout<<"**************************"<<endl;
}

//初始化医院信息系统（读文件）
Management load()
{
	ifstream ifile("./record.txt", ios::in);
	if (!ifile)
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	else 
	{
		Management manage = {};
		char raw_data[50];
		while (ifile.getline(raw_data, 50))//读取文件
		{
			char* ptr = NULL;
			char* buf = raw_data;
			ptr = strtok_s(raw_data, "\t", &buf);
			string name = ptr;
			manage.doctorarray[manage.d_Size].d_Name = name;

			ptr = strtok_s(NULL, "\t", &buf);
			int sex = ptr[0] - 48;
			manage.doctorarray[manage.d_Size].d_Sex = sex;

			ptr = strtok_s(NULL, "\t", &buf);
			int age = 0;
			for (int i = 0;ptr[i] != NULL;i++)
				age = 10 * age + ptr[i] - 48;
			manage.doctorarray[manage.d_Size].d_Age = age;

			ptr = strtok_s(NULL, "\t", &buf);
			string hos = ptr;
			manage.doctorarray[manage.d_Size].d_Hospital = hos;

			ptr = strtok_s(NULL, "\t", &buf);
			string off = ptr;
			manage.doctorarray[manage.d_Size].d_Office = off;

			ptr = strtok_s(NULL, "\t", &buf);
			string phone = ptr;
			manage.doctorarray[manage.d_Size].d_Phone = phone;
			manage.d_Size++;
		}

		ifile.close();

		return manage;
	}
	cout << "失败！" << endl;
	return Management();
}

void save(Management *manage)
{
    ofstream ofs;
	ofs.open("./record.txt",ios::out);//用输出的方式打开文件（写文件）

	//将每个医生的数据写入文件中
    for(int i=0;i < (manage->d_Size);i++)
	{
		ofs << manage->doctorarray[i].d_Name << '\t'
			<< manage->doctorarray[i].d_Sex << '\t'
			<< manage->doctorarray[i].d_Age << '\t'
			<< manage->doctorarray[i].d_Hospital << '\t'
			<< manage->doctorarray[i].d_Office << '\t'
			<< manage->doctorarray[i].d_Phone << endl;	
	}
	ofs.close();//关闭文件
}

int main()
{
	//创建管理系统结构体变量
	Management manage;
	//初始化系统中当前人员个数
	 manage.d_Size=0;
	 manage = load();//读文件
	int select=0;//创建用户选择输入的变量

	while(select!=6)
	{
	    show();//菜单界面调用

	    cin>>select;
	    switch(select)
	    {
	    case 1://1.添加医生信息
			addDoctor(&manage);//传地址可以修改实参
		    break;
	    case 2://2.显示医生信息 
			showDoctor(&manage);
		    break;
	    case 3://3.删除医生信息
			deleteDoctor(&manage);
	    	break;
	    case 4://4.查询医生信息
			findDoctor(&manage);
		    break;
	    case 5://5.编辑医生信息
			editDoctor(&manage);
	        break;
	    case 6://6.退出管理系统
		    cout<<"*****  欢迎再次使用  *****"<<endl;
			save(&manage);//写文件

		    system("pause");
		    return 0;
		    break;
	    default:
		    break;
	    }
	}
	system("pause");
	return 0;
}