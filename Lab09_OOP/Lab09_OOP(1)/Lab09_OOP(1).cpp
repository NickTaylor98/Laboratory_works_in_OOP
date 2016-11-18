// Lab09_OOP(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Container.h"
#include "Container2.h"
int main()
{
	setlocale(LC_ALL, "");
	unique_ptr<Container>cont(new Container{Candy(12,1,13),Candy(23,2,12), Candy(34,3,345)});
	shared_ptr<Container_Second>cont2(new Container_Second { {1, Candy	(12,2,2343)},
														{2, Candy	(45,546,3243)},
														{23, Candy	(22,234,234)} 
													  });

	(*cont2).Print();
	system("pause");
	return EXIT_SUCCESS;
}

