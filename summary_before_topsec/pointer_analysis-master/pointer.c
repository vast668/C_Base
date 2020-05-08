#include <stdio.h>


//修改之后的程序
void func(int **p)		//形参p的值是0x7fffffffd640.
{
	static int num = 4;	//静态变量 num 的值为4，地址为0x404024
	*p = &num;			//*p就是一个指针，之前也是i的地址，现在将num的地址重新赋予给它，*p的值改变
	(**p)--;				//**p就是i，上一步的值是4，现在是4-1=3
	printf("%d\n", num);	//num值为3
}

int main()
{
	int i = 5;			
	int *p = &i;		//p 保存i的地址 ：0x7fffffffd64c，p的地址是0x7fffffffd640
	func(&p);			//实参p的地址的值是0x7fffffffd640
	printf("%d\n", *p);

	return 0;
}

/*
		结论，下面的程序，虽然传参也是指针，但只是将指针的值传递过来，值传递，值如果被重新赋予一个新的值
		就不会在指向初始值了，传参过来的指针p的地址变化，导致词指针非彼指针。

		上面的程序：
			传递的是指针的地址，这样无论二级指针p的值怎么变化，但是我一直保存这二级指针p的地址，
			这样，*p是指针，随便指向，但是**p还是原来的i
*/



/*
void func(int *p)		//形参p的值是0x7fffffffd644，它的地址是0x7fffffffd628,它依然保存这变量i的地址
{
	static int num = 4;	//静态变量 num 的值为4，地址为0x404024
	p = &num;			//p的值已变，不再是i的地址了，保存的是num的地址的值0x404024
	(*p)--;				//故在这的（*p）就不再是i了，而是num
	printf("%d\n", num);	//num值为3
}

int main()
{
	int i = 5;			
	int *p = &i;		//p 保存i的地址 ：0x7fffffffd644，p的地址是0x7fffffffd648
	func(p);			//实参p的值是0x7fffffffd644，也就是i的地址
	printf("%d\n", *p);

	return 0;
}*/