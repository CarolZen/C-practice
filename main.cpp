#include <stdio.h> 
#include <string.h> 
#include <assert.h>
#include<math.h> 

typedef struct date
{
    int year;
    int month;
    int day;
    char addr[50];
}DATE;
typedef struct student{
    int no;
    char name[20];
    int age;
    // double score;
    // struct date;
}STUDENT;

STUDENT list[200]={0};
int count=0;//总数量
int new1=0;//追加数量

void SaveFile();
void MainMenu();
void ReadFile();
void DataInput();
void ClearAll();

void SaveFile(int x){
    FILE *fp=fopen("demo.txt","a");
    fwrite(list,sizeof(STUDENT),x,fp);
    // fprintf(fp,"%d %s %d\n",list[count].no,list[count].name,list[count].age);//fwrite是将数据不经转换直接以二进制的形式写入文件，而fprintf是将数据转换为字符后再写入文件
    rewind(fp); //指针返回开头
    fclose(fp);
    return;
}
void MainMenu(){
    printf("******************************************************************************\n");
    printf("\" 工号管理系统 \"\n1.输入数据\n2.查询数据\n3.删除数据\n4.ClearAll\n5.Quit System\n"); 
    printf("******************************************************************************\n");
    return;
}

void ReadFile(){
    FILE *fp=fopen("demo.txt","r");
    if(fp==NULL){
        printf("open error");
    }else{
        fseek(fp,0,SEEK_END);
        long length=ftell(fp);
        int num=length/sizeof(STUDENT);
        //计算已有的数组长度
        printf("总长度为：%d\n总数量为%d\n",length,num);
        printf("-------------------------------------------------------------------------\n");
        rewind(fp);//指针返回开头
        fread(list,sizeof(STUDENT),num,fp);
        printf("%-7s %-7s %-7s %-7s\n","序号","No","姓名","年龄");
        for(int i=0;i<num;i++){
        printf("%-7d %-7d %-7s %-7d\n",i,list[i].no,list[i].name,list[i].age);
        }
        printf("-------------------------------------------------------------------------\n");
    }
}

int Bit_Int(int n){
	if(n==0)
		return 1;
	else
		return log10(abs(n))+1;//求整数的位数
	//例如  1234  lgx+1;                   
}
//位数验证


int DataChecker(int y){
    int x=Bit_Int(y);
    if(x!=5){
        return 0;
    }else{
        return 1;
    }
}
//数据测试

void DataInput(){
    new1 = 0;
    printf("输入录入数量:");
    scanf("%d",&new1);
    printf("输入数据:序号，姓名，年龄\r\n");
    for(int k=0;k<count+new1;k++){
    scanf("%d %s %d",&list[count+k].no,list[count+k].name,&list[count+k].age);
    // printf("%d %s %d\n",list[count+k].no,list[count+k].name,list[count+k].age);
    if(DataChecker(list[count+k].no)==0){
        printf("输入错误,保存先前数据\n");
        SaveFile(k);
        break;
    }else{
        SaveFile(new1);
        };
    }
    return;
}
void ClearAll(){
    FILE *fp;
    fp=fopen("demo.txt","w");
    return;
}
int main(void)
{   
    int a;  
    do
    {   
        fflush(stdin);
        MainMenu();
        printf("选择:\r\n");
        scanf("%d",&a); 
        switch (a)
        {
        case 1:
        DataInput();
        break;
        case 2:
        ReadFile();
        break;
        case 4:
        ClearAll();
        case 5:
        printf("退出程序\r\n");
        break;
        default:
        printf("无效输入，重新输入\r\n");
        } 
    } while (a != 5);   
    // fflush(stdin);
    system("pause");
}

// malloc 分配内存
// memset 填充赋值 (地址，赋值，大小)
// memcpy 复制
// free 释放