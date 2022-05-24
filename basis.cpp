
#include <iostream> // std::cin поток ввода cout - поток вывода
//char	char stroka[100]; ('\0' == 0 != '0') библиотека string.h cstring
//char* ptrString = new char[100]
//string	библиотека string
#include <cstring>
using namespace std;

int main()
{
	/*int number1 = 0, number2;
	cout << "number1 = ";
	cin >> number1;
	cout << "number2 = ";
	cin >> number2;
	cout << number1 << " + " << number2
		<< " = " << number1 + number2 << endl;*/




		//int result;   	 
		//__asm {
		//	mov		eax, [number1]
		//	add		eax, [number2]
		//	mov		[result], eax
		//}
		//cout << "result = " << result << endl;


		//const int N = 10;
		//int array[N] = { 1, 2, 3, 4, 5 }; // = {0}; (тогда все 10 элементов будут нулями)

		//for (int i = 0; i < N; i++)
		//{
		//	cout << array[i] << " ";
		//}
		//cout << endl;

		//for (int & item : array) {		//analog foreach c# /*(амперсанд дает менят значение переменной по адресу)*/
		//	item++;
		//	cout << item << " ";
		//}
		//cout << endl;

		//for (int i = 0; i < N; i++)
		//{
		//	cout << &array[i] << " ";	/*(амперсанд дает менят значение переменной по адресу)*/
		//}
		//cout << endl;

		//int* ptr = new int[5]; // *(ptr+3) == ptr[3]
		//
		//for (int i = 0; i < 5; i++)
		//{
		//	cout << ptr + i << " " << *(ptr + i) << " " << ptr[i] << endl;
		//}

		//delete[]ptr;

	char string[100];
	cout << "Input string: ";
	/*cin >> string;
	cout << "result = " << string << endl;
	cin >> string;
	cout << "result = " << string << endl;*/
	cin.getline(string, sizeof(string));
	cout << "result = " << string << endl;

	int length = 0;								//вычисление длины строки
	for (; string[length] != '\0'; length++);
	cout << "length = " << length << endl;
	cout << "length(strlen) = " << strlen(string) << endl;

	int len1 = 0;								//тоже самое на ассемблере
	__asm {
		lea		edi, string						//mov edi,string (если fasm) //аналог
		l1 :
		cmp		byte ptr[edi], 0
			je		_l1
			inc[len1]
			inc		edi
			jmp		l1
			_l1 :

	}
	cout << "length = " << len1 << endl;

	int len2 = 0;
	__asm {
		lea		edi, string
		mov		ecx, 100
		mov		esi, edi
		mov		al, 0
		repne	scasb
		sub		edi, esi
		dec		edi
		mov[len2], edi

	}
	cout << "length = " << len2 << endl;

	char string1[101];
	int lengthWords[50] = {}, cntWords = 0;
	__asm {
		lea		esi, string
		lea		ebx, string1
		lea		edx, lengthWords
		mov		ecx, [len1]
		cld

		l11 :
			mov		edi, esi
			mov		al, ' '
			repne	scasb
			jecxz	l3
			dec		edi

		l3:
			sub		edi, esi
			mov[edx], edi
			add		edx, 4
			inc[cntWords]
			push	ecx
			mov		ecx, edi
			mov		edi, ebx
			rep		movsb
			mov		byte ptr[edi], '\n'
			mov		ebx, edi
			inc		ebx
			inc		esi
			pop		ecx
			jecxz	l2
			jmp		l11

			l2 :
			mov		[ebx], '\0'
	}
	for (int i = 0; i < cntWords; i++)
	{
		cout << lengthWords[i] << " ";
	}
	cout << endl;
	cout << string1;

	system("pause");
	return 0;
}
