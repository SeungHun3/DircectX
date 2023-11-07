#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69); // 있어야 x를 누를때 프로그램이 종료된다
	case WM_KEYDOWN:
		if (wParam == 'F') // F 키를 눌렀을때
		{
			SetWindowText(hWnd, L"Key F Down");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F') // F 키를 뗏을때
		{
			SetWindowText(hWnd, L"Key F Up");
		}
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//콜백 함수는 이벤트가 발생할 때 시스템이 호출하는 함수이며, 시스템에서 필요한 시점에 호출됩니다. 
// 즉, 이 함수는 시스템에서 이벤트가 발생할 때마다 호출되며 우리가 직접 호출하는 것이 아닙니다.
//만약 WndProc(); 와 같이 괄호를 붙여서 호출한다면, 우리가 명시적으로 이 함수를 호출하는 것이 됩니다.
// 하지만 콜백 함수는 시스템이 필요할 때 자동으로 호출되어야 합니다.그렇기 때문에 단순히 함수의 이름을 지정해주면 됩니다.
// 이렇게 함수의 이름을 전달하면 컴파일러는 필요한 시점에 해당 함수를 자동으로 호출합니다.

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	const auto pClassName = L"hw3dbutts";
	// 윈도우 창 등록하기
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc; //DefWindowProc; // x를 누를때 프로그램이 종료될지, 최소화를 누를때 최소화 될지 등 기본 설정
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	// 윈도우 생성
	HWND hWnd = CreateWindowExW(
		0, pClassName, L"SeunghunDx"
		, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU
		, 200, 200, 640, 480
		, nullptr, nullptr, hInstance, nullptr
	);

	// 화면 보이기
	ShowWindow(hWnd, SW_SHOW);

	//메세지 
	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0)) // 필터하지 않은 메세지를 가져와서
	{
		//해석하고
		TranslateMessage(&msg);
		//발송
		DispatchMessage(&msg);

		//==> 윈도우가 지속적으로 입력, 마우스 등의 이벤트를 받게 해야 화면을 컨트롤 할 수가 있음
	}


	return 0;
}