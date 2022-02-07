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
int count=0;//������
int new1=0;//׷������

void SaveFile();
void MainMenu();
void ReadFile();
void DataInput();
void ClearAll();

void SaveFile(int x){
    FILE *fp=fopen("demo.txt","a");
    fwrite(list,sizeof(STUDENT),x,fp);
    // fprintf(fp,"%d %s %d\n",list[count].no,list[count].name,list[count].age);//fwrite�ǽ����ݲ���ת��ֱ���Զ����Ƶ���ʽд���ļ�����fprintf�ǽ�����ת��Ϊ�ַ�����д���ļ�
    rewind(fp); //ָ�뷵�ؿ�ͷ
    fclose(fp);
    return;
}
void MainMenu(){
    printf("******************************************************************************\n");
    printf("\" ���Ź���ϵͳ \"\n1.��������\n2.��ѯ����\n3.ɾ������\n4.ClearAll\n5.Quit System\n"); 
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
        //�������е����鳤��
        printf("�ܳ���Ϊ��%d\n������Ϊ%d\n",length,num);
        printf("-------------------------------------------------------------------------\n");
        rewind(fp);//ָ�뷵�ؿ�ͷ
        fread(list,sizeof(STUDENT),num,fp);
        printf("%-7s %-7s %-7s %-7s\n","���","No","����","����");
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
		return log10(abs(n))+1;//��������λ��
	//����  1234  lgx+1;                   
}
//λ����֤


int DataChecker(int y){
    int x=Bit_Int(y);
    if(x!=5){
        return 0;
    }else{
        return 1;
    }
}
//���ݲ���

void DataInput(){
    new1 = 0;
    printf("����¼������:");
    scanf("%d",&new1);
    printf("��������:��ţ�����������\r\n");
    for(int k=0;k<count+new1;k++){
    scanf("%d %s %d",&list[count+k].no,list[count+k].name,&list[count+k].age);
    // printf("%d %s %d\n",list[count+k].no,list[count+k].name,list[count+k].age);
    if(DataChecker(list[count+k].no)==0){
        printf("�������,������ǰ����\n");
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
        printf("ѡ��:\r\n");
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
        printf("�˳�����\r\n");
        break;
        default:
        printf("��Ч���룬��������\r\n");
        } 
    } while (a != 5);   
    // fflush(stdin);
    system("pause");
}

// malloc �����ڴ�
// memset ��丳ֵ (��ַ����ֵ����С)
// memcpy ����
// free �ͷ�