#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szClassName[] = _T("HelloWin32Window20160626");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst,
                   LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS myProg;
    if (!hPreInst) {
        myProg.style            = CS_HREDRAW | CS_VREDRAW;
        myProg.lpfnWndProc      = WndProc;
        myProg.cbClsExtra       = 0;
        myProg.cbWndExtra       = 0;
        myProg.hInstance        = hInstance;
        myProg.hIcon            = NULL;
        myProg.hCursor          = LoadCursor(NULL, IDC_ARROW);
		myProg.hbrBackground    = (HBRUSH)(COLOR_WINDOW+1);
        myProg.lpszMenuName     = NULL;
        myProg.lpszClassName    = szClassName;
        if (!RegisterClass(&myProg))
            return FALSE;
    }
    hWnd = CreateWindow(szClassName,	// class名
		_T("Hello Window !! こんにちは窓！"),			// タイトル
        WS_OVERLAPPEDWINDOW,		// Style
        CW_USEDEFAULT,				// X
        CW_USEDEFAULT,				// Y
        CW_USEDEFAULT,				// Width
        CW_USEDEFAULT,				// Height
        NULL,						// 親ウィンドウまたはオーナーウィンドウのハンドル
        NULL,						// メニューハンドルまたは子ウィンドウ ID
        hInstance,					// アプリケーションインスタンスのハンドル
        NULL);						// ウィンドウ作成データ
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return(DefWindowProc(hWnd, msg, wParam, lParam));
    }
    return (0L);
}