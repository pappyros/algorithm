// ShapeDraw.cpp : Defines the entry point for the application.
//
#include <windowsx.h>
#include <string>
#include "ShapeDraw.h"
#include "resource.h"
#include "ShapeManager.h"
#include "NewShapeFactory.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
ShapeManager g_ShapeManager;
std::string g_ShapeType = "Rectangle";  // �ʱ� Shape�� �簢�� �׸��� ���


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SHAPEDRAW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SHAPEDRAW));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SHAPEDRAW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SHAPEDRAW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

void checkMenuItem(HWND hWnd, int shape) 
{
	int shapeID[] = { ID_SHAPE_RECTANGLE, ID_SHAPE_CIRCLE, ID_SHAPE_PARALLELOGRAM, ID_SHAPE_TRAPEZOID };

	for (int i = 0; i < sizeof(shapeID) / sizeof(int); i++) {
		if (shapeID[i] == shape)
			CheckMenuItem(GetMenu(hWnd), shapeID[i], MF_BYCOMMAND | MF_CHECKED);
		else
			CheckMenuItem(GetMenu(hWnd), shapeID[i], MF_BYCOMMAND | MF_UNCHECKED);
	}
}

void repaintWindow(HWND hWnd)
{
	InvalidateRect(hWnd, NULL, TRUE);  // ȭ�� �ٽ� �׸���
	UpdateWindow(hWnd);
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static bool leftButtonDown = false;
	static bool dragging = false;
	static int lastX = 0, lastY = 0;
	static WinShape* selectedShape = NULL;
	
	switch (message)
    {
	case WM_RBUTTONDOWN:  // ������ ���콺 ��ư�� Ŭ���Ǹ�
	{
		int xPos = GET_X_LPARAM(lParam);
		int yPos = GET_Y_LPARAM(lParam);
		shared_ptr<WinShape> s (NewShapeFactory::create(g_ShapeType, xPos, yPos));
		g_ShapeManager.add(s);

		
		

		repaintWindow(hWnd);
		break;
	}

	case WM_LBUTTONDOWN:
	{
		leftButtonDown = true;
		int xPos = GET_X_LPARAM(lParam);
		int yPos = GET_Y_LPARAM(lParam);
		selectedShape = g_ShapeManager.findShape(xPos, yPos);
		if (selectedShape) {
			dragging = true;
			lastX = xPos;
			lastY = yPos;
		}
		break;
	}

	case WM_LBUTTONUP:
		leftButtonDown = false;
		dragging = false;
		selectedShape = NULL;
		break;

	case WM_MOUSEMOVE:
	{
		int xPos = GET_X_LPARAM(lParam);
		int yPos = GET_Y_LPARAM(lParam);
		if (selectedShape) {
			shapelib::Shape* s = dynamic_cast<shapelib::Shape*> (selectedShape);
			if (s) {
				s->move(xPos - lastX, yPos - lastY);
				repaintWindow(hWnd);
				lastX = xPos;
				lastY = yPos;
			}
		}
		break;
	}

	case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;

			case ID_SHAPE_RECTANGLE:
				g_ShapeType = "Rectangle";
				checkMenuItem(hWnd, ID_SHAPE_RECTANGLE);
				break;

			case ID_SHAPE_CIRCLE:
				g_ShapeType = "Circle";
				checkMenuItem(hWnd, ID_SHAPE_CIRCLE);
				break;

			case ID_SHAPE_PARALLELOGRAM:
				g_ShapeType = "Parallelogram";
				checkMenuItem(hWnd, ID_SHAPE_PARALLELOGRAM);
				break;

			case ID_SHAPE_TRAPEZOID:
				g_ShapeType = "Trapezoid";
				checkMenuItem(hWnd, ID_SHAPE_TRAPEZOID);
				break;

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:    // ȭ�� �׸��� �κ�
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
			g_ShapeManager.draw(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
