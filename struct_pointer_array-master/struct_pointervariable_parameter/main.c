#include <stdio.h>
#define N 3         //学生人数是3

struct Student      //建立结构体类型dstruct Student
{
    int num;
    char name[20];
    float score[3];
    float aver;     //平均成绩
};
int main()
{
    void input(struct Student stu[]);       //函数声明，这里必须是stu[],只有这样才是一个数组类型，
    // 如果写成stu,就不是数组类型了  这的stu是struct Student类型的***变量***
    struct Student max(struct Student stu[]); //函数声明

    //*****************
    // 在这犯了一个错误--->struct Student max(struct Student stu)少写了[]，这样再这声明的max函数的类型就不对了
    // 我们想要定义一个结构体数组，如果不加[]就不是数组了呀
    //*************************

    void print(struct Student stu);         //函数声明，这的stu是struct Student类型的***变量***就是个结构体
    // 而不是struct Student 类型的数组
    struct Student stu[N], * p = stu;         //定义结构体数组和指针
    // 等价于  p = stu;
    //等价于 struct Student stu[N], *p;
    // p = stu;   stu是数组名，也是一个指针，所以p=stu
    input(p);                               //调用input函数
    print(max(p));                         //先调用max函数，再调用printf函数
    return 0;
}

void input(struct Student stu[])//要输出的是一个结构体，所以行参
{
    int i;
    printf("请输入各学生的信息：学号、姓名、三门课的成绩： \n");
    for(i=0;i<N;i++)                    //简单的for循环输入学生的信息
    {
        scanf("%d %s %f %f %f",&stu[i].num,&stu[i].name,
                &stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;//直接将平均值输出
    }

}

struct Student max(struct Student stui[])
{
    int i,m=0;
    for(i=0;i<N;i++)
        if(stui[i].aver>stui[m].aver)
            m=i;
    return stui[m];              //return 0; error!这个函数是结构体类型的，只能返回结构体类型的值
}

void print(struct Student stud)     //定义print函数  这的stu是struct Student类型的***变量***就是个结构体
{
    printf("\n成绩最高的学生是： \n");
    printf("学号： %d\n姓名： %s\n三门课成绩：%5.1f,%5.1f,%5.1f\n 平均成绩：%6.2f\n",
            stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
}


/*
 * 在主函数中定义了结构体struct Student 类型的数组 stu和指向struct Student类型数据的指针变量p，使p指向stu数组的首元素
 *
 * input函数，指针变量p作为实参   形参是struct Student stu[], 也就是stu[],是结构体数组，传递的是结构体元素的地址
 *
 * print函数  实参是max(p)，先调用max函数
 *
 * max函数  指针变量p将主函数中的stu数组的首元素的地址传给形参数组stu，使形参数组stu与主函数中的stu数组具有相同的地址
 * 再max函数中对stu数组的操作就是对主函数中的stu数组的操作，
 *
 * 注意stu[m]是一个结构体数组的 **元素**，max函数类型为struct Student类型
 *
 * max(p)的值，是结构体的元素，作为实参调用print函数。
 *
 * 这的stu是struct Student类型的***变量***就是个结构体，在调用是进行虚实结合，吧stu[m]的值传递给行参，
 * 这时传递的不是地址而是结构体变量中的信息。
 *
 * input ：  实参是 指针变量p,   形参是结构体数组，传递的是结构体元素的地址  函数无返回值
 *
 * max ：  实参是 指针变量p,   形参是结构体数组，传递的是结构体元素的地址    函数返回值是结构体类型数据
 *
 *
 * print：  实参是 结构体变量（结构体数组元素）,    形参是结构体变量，传递的是结构体变量中的个成员的值，函数无返回值
 *
 *
 * */