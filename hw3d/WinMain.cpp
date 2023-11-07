#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69); // �־�� x�� ������ ���α׷��� ����ȴ�
	case WM_KEYDOWN:
		if (wParam == 'F') // F Ű�� ��������
		{
			SetWindowText(hWnd, L"Key F Down");
		}
		break;
	case WM_KEYUP:
		if (wParam == 'F') // F Ű�� ������
		{
			SetWindowText(hWnd, L"Key F Up");
		}
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//�ݹ� �Լ��� �̺�Ʈ�� �߻��� �� �ý����� ȣ���ϴ� �Լ��̸�, �ý��ۿ��� �ʿ��� ������ ȣ��˴ϴ�. 
// ��, �� �Լ��� �ý��ۿ��� �̺�Ʈ�� �߻��� ������ ȣ��Ǹ� �츮�� ���� ȣ���ϴ� ���� �ƴմϴ�.
//���� WndProc(); �� ���� ��ȣ�� �ٿ��� ȣ���Ѵٸ�, �츮�� ��������� �� �Լ��� ȣ���ϴ� ���� �˴ϴ�.
// ������ �ݹ� �Լ��� �ý����� �ʿ��� �� �ڵ����� ȣ��Ǿ�� �մϴ�.�׷��� ������ �ܼ��� �Լ��� �̸��� �������ָ� �˴ϴ�.
// �̷��� �Լ��� �̸��� �����ϸ� �����Ϸ��� �ʿ��� ������ �ش� �Լ��� �ڵ����� ȣ���մϴ�.

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	const auto pClassName = L"hw3dbutts";
	// ������ â ����ϱ�
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc; //DefWindowProc; // x�� ������ ���α׷��� �������, �ּ�ȭ�� ������ �ּ�ȭ ���� �� �⺻ ����
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

	// ������ ����
	HWND hWnd = CreateWindowExW(
		0, pClassName, L"SeunghunDx"
		, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU
		, 200, 200, 640, 480
		, nullptr, nullptr, hInstance, nullptr
	);

	// ȭ�� ���̱�
	ShowWindow(hWnd, SW_SHOW);

	//�޼��� 
	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0)) // �������� ���� �޼����� �����ͼ�
	{
		//�ؼ��ϰ�
		TranslateMessage(&msg);
		//�߼�
		DispatchMessage(&msg);

		//==> �����찡 ���������� �Է�, ���콺 ���� �̺�Ʈ�� �ް� �ؾ� ȭ���� ��Ʈ�� �� ���� ����
	}


	return 0;
}