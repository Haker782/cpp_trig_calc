#include<Windows.h>
#include <iostream>
#include <stack>
#include<sstream>
#include"resource.h"








#define left_parenthesis 10
#define COS 11
#define SIN 12
#define TG 13
#define CTG 14
#define right_parenthesis 15
#define STEPEN 16
#define PLUS 17
#define MINUS 18
#define UMNOGIT 19
#define DELITE 20
#define RAVNO 21
#define CLEAR 22
#define PI 23



#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")




static HWND hBtn; static HWND hStatic; static HWND hEdit;
char BUFFER[100]; char ch[100]; int num = 0; LPCSTR answer;
std::wstringstream s;

struct Leksema {
	double value;
	char type;
};

int GetRang(char ch) {
	if (ch == 'c' || ch == 's' || ch == 't' || ch == 'g')return 4;//g == cot , all of other : c = cos and so far
	if (ch == '^')return 3;
	if (ch == '*' || ch == '/') return 2;
	if (ch == '+' || ch == '-') return 1;
	if (ch >= '0' || ch <= '9')  return 0;
}

void math(std::stack <Leksema>& stack_n, std::stack <Leksema>& stack_o, Leksema& item) {
	double a, b, c;
	a = stack_n.top().value;
	stack_n.pop();

	switch (stack_o.top().type) {
	case'g':

		c = cos(a) / sin(a);
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;

	case't':
		c = sin(a) / cos(a);
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;

	case's':
		c = sin(a);
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;

	case'c':
		c = cos(a);
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;

	case'+':
		b = stack_n.top().value;
		stack_n.pop();
		c = a + b;
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;

	case'-':
		b = stack_n.top().value;
		stack_n.pop();
		c = b - a;
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;

	case'*':
		b = stack_n.top().value;
		stack_n.pop();
		c = b * a;
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;

	case'/':
		b = stack_n.top().value;
		stack_n.pop();

		c = b / a;
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;
	
	case'^':
		b = stack_n.top().value;
		stack_n.pop();
		c = pow(b, a);
		item.type = '0';
		item.value = c;
		stack_n.push(item);
		stack_o.pop();
		break;
	}
}





void CreateWigdgets(HWND hwnd) {
	
	hBtn = CreateWindow(
		L"BUTTON", L"1",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>('1'), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"2",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		95, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>('2'), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"3",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		180, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>(3), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"4",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		265, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>(4), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"5",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		350, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>(5), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"6",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		435, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>(6), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"7",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		520, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>(7), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"8",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		605, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>(8), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"9",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		690, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>(9), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"0",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		775, 150, 75, 30,
		hwnd, reinterpret_cast<HMENU>('0'), NULL, NULL

	);

	hBtn = CreateWindow(
		L"BUTTON", L"(",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5, 200, 75, 30,
		hwnd, reinterpret_cast<HMENU>(left_parenthesis), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"cos",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 +75 + 10, 200, 75, 30,
		hwnd, reinterpret_cast<HMENU>(COS), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"sin",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75*2 + 20, 200, 75, 30,
		hwnd, reinterpret_cast<HMENU>(SIN), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"tg",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75 * 3 + 30, 200, 75, 30,
		hwnd, reinterpret_cast<HMENU>(TG), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"ctg",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75 * 4 + 40, 200, 75, 30,
		hwnd, reinterpret_cast<HMENU>(CTG), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L")",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75 * 5 + 50, 200, 75, 30,
		hwnd, reinterpret_cast<HMENU>(right_parenthesis), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"^",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75 * 6 + 60, 200, 75, 30,
		hwnd, reinterpret_cast<HMENU>(STEPEN), NULL, NULL

	);


	hBtn = CreateWindow(
		L"BUTTON", L"+",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75 + 10, 250, 75, 30,
		hwnd, reinterpret_cast<HMENU>(PLUS), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"-",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75*2 + 20, 250, 75, 30,
		hwnd, reinterpret_cast<HMENU>(MINUS), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"*",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75*3 + 30, 250, 75, 30,
		hwnd, reinterpret_cast<HMENU>(UMNOGIT), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"/",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75*4 + 40, 250, 75, 30,
		hwnd, reinterpret_cast<HMENU>(DELITE), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"=",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		 775, 250, 75, 30,
		hwnd, reinterpret_cast<HMENU>(RAVNO), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"CLEAR",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		10, 250, 75, 30,
		hwnd, reinterpret_cast<HMENU>(CLEAR), NULL, NULL

	);
	hBtn = CreateWindow(
		L"BUTTON", L"pi",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		132.5 + 75 * 5 + 50, 250, 75, 30,
		hwnd, reinterpret_cast<HMENU>(PI), NULL, NULL

	);


	hEdit = CreateWindow(
		L"static", L"",
		WS_CHILD | WS_BORDER | WS_VISIBLE | ES_LEFT ,
		30, 100, 800, 25,
		hwnd, NULL, NULL, NULL

	);
	hStatic = CreateWindow(
		L"static",
		L"",
		WS_CHILD | WS_VISIBLE,
		250, 25, 350, 50,
		hwnd, NULL, NULL, NULL
	);

}







LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {
	case WM_CREATE: {
		CreateWigdgets(hwnd);
		break;
	}

	case WM_DESTROY: {
		PostQuitMessage(0);
		break;
	}

	
	case WM_COMMAND: {

		switch (LOWORD(wparam)) {
		case left_parenthesis: {
			BUFFER[num] = '(';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;

		}
		case right_parenthesis: {
			BUFFER[num] = ')';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case PI: {
			BUFFER[num] = 'p';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case '1': {
			BUFFER[num] = '1';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case '2': {
			BUFFER[num] = '2';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case 3: {
			BUFFER[num] = '3';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case 4: {
			BUFFER[num] = '4';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case 5: {
			BUFFER[num] = '5';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case 6: {
			BUFFER[num] = '6';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case 7: {
			BUFFER[num] = '7';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case 8: {
			BUFFER[num] = '8';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case 9: {
			BUFFER[num] = '9';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case '0': {
			BUFFER[num] = '0';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case COS: {
			BUFFER[num] = 'c';
			num += 1;
			BUFFER[num] = 'o';
			num += 1;
			BUFFER[num] = 's';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case SIN: {
			BUFFER[num] = 's';
			num += 1;
			BUFFER[num] = 'i';
			num += 1;
			BUFFER[num] = 'n';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case TG: {
			BUFFER[num] = 't';
			num += 1;
			BUFFER[num] = 'a';
			num += 1;
			BUFFER[num] = 'n';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case CTG: {
			BUFFER[num] = 'c';
			num += 1;
			BUFFER[num] = 'o';
			num += 1;
			BUFFER[num] = 't';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case PLUS: {
			BUFFER[num] = '+';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case MINUS: {
			BUFFER[num] = '-';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case UMNOGIT: {
			BUFFER[num] = '*';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case DELITE: {
			BUFFER[num] = '/';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case STEPEN: {
			BUFFER[num] = '^';
			num += 1;
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case CLEAR: {
			for (int i = 0; i <= 99; i++) {
				BUFFER[i] = NULL; ch[i] = NULL;
			}
			num = 0;
			SetWindowTextA(hStatic, " ");
			SetWindowTextA(hEdit, BUFFER);
			break;
		}
		case RAVNO: {
			BUFFER[num] = '=';
			num += 1;
			//SetWindowTextA(hEdit, BUFFER);


			for (int g = 0; g < 100; g++) {
				ch[g] = BUFFER[g];
			}

			float value;
			bool flag = 1;
			int i = 0;
			std::string a;
			Leksema item;
			LPWSTR answer;
			std::stack <Leksema> stack_n;
			std::stack <Leksema> stack_o;
			while (1) {

				if (ch[i] == '=')break;


				if (ch[i] >= '0' && ch[i] <= '9' || ch[i] == '-' && flag == 1) {
					while (ch[i] != '/' && ch[i] != '=' && ch[i] != '*' && ch[i] != '+' && ch[i] != '-' && ch[i] != ')' && ch[i] != '^') {
						
							a += ch[i]; i++; flag = 0;
					} 
					flag = 0;
					value = atof(a.c_str());
					item.value = value;
					item.type = '0';
					stack_n.push(item);
					
					a = "";
					
					continue;

				}

				if (ch[i] == '+' || ch[i] == '-' && flag == 0 || ch[i] == '*' || ch[i] == '/' || ch[i] == '^') {
					if (stack_o.size() == 0) {
						item.value = 0;
						item.type = ch[i];
						stack_o.push(item);
						i++;
					
						continue;
					}

				}
				if (ch[i] == 'p') {
					item.value = acos(-1);
					item.type = '0';
					stack_n.push(item);
					flag = 0;
					i++;
					continue;
				}
				if (ch[i] == 'c' || ch[i] == 's' || ch[i] == 't') {
					if (ch[i] == 'c' && ch[i + 1] == 'o' && ch[i + 2] == 's') {
						item.value = 0;
						item.type = 'c';
						stack_o.push(item);
						i += 3;
						continue;
					}
					if (ch[i] == 's' && ch[i + 1] == 'i' && ch[i + 2] == 'n') {
						item.value = 0;
						item.type = 's';
						stack_o.push(item);
						i += 3;
						continue;
					}
					if (ch[i] == 't' && ch[i + 1] == 'a' && ch[i + 2] == 'n') {
						item.value = 0;
						item.type = 't';
						stack_o.push(item);
						i += 3;
						continue;
					}
					if (ch[i] == 'c' && ch[i + 1] == 'o' && ch[i + 2] == 't') {
						item.value = 0;
						item.type = 'g';
						stack_o.push(item);
						i += 3;
						continue;
					}

				}
				if (ch[i] == '(') {
					item.value = 0;
					item.type = ch[i];
					stack_o.push(item);
					i++;
					continue;
				}
				if (ch[i] == ')') {
					while (stack_o.top().type != '(') {
						math(stack_n, stack_o, item);

					}
					stack_o.pop();
					i++;
					continue;
				}

				if (stack_o.size() != 0 && GetRang(ch[i]) > GetRang(stack_o.top().type)) {
					item.value = 0;
					item.type = ch[i];
					stack_o.push(item);
					i++;
					continue;

				}
				if (stack_o.size() != 0 && GetRang(ch[i]) <= GetRang(stack_o.top().type)) {
					math(stack_n, stack_o, item);

				}

				

			}
			while (stack_o.size() != 0) {
				math(stack_n, stack_o, item);
			}



			{
				s << L"ANSWER: " << *&(stack_n.top().value);

				std::wstring ws = s.str();
				s = std::wstringstream();
				

				SetWindowTextW(hStatic, ws.c_str());

				ws = ' ';
				i = 0;
			}

			


			break;
		}

		}
	default: {return DefWindowProc(hwnd, msg, wparam, lparam); }

	}
	}
	
}
	
	


WNDCLASSEX NewWindowlass(HINSTANCE hinstance) {
	WNDCLASSEX wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIcon = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hIconSm = LoadIcon(hinstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor = LoadCursor(NULL, IDC_HAND);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hInstance = hinstance;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = WndProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"WinMainClass";
	return wc;

}

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR LpCmdLine, int nCmdShow) {
	HWND hwnd;
	MSG msg;
	WNDCLASSEX WC = NewWindowlass(hinstance);



	RegisterClassEx(&WC);
	

	hwnd = CreateWindow(WC.lpszClassName, L"TRGCAL",  WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 880 , 330, NULL, NULL, hinstance, NULL);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return msg.wParam;
}

