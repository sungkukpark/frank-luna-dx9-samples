#include <windows.h>
#include "d3dUtility.h"

IDirect3DDevice9* Device = 0;	// instantiating a global variable for the device

// Initialization
bool Setup()
{
	return true;
}

// Cleanup
void Cleanup()
{
}

bool Display(float timeDelta)
{
	if (Device)
	{
		Device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
			0x00000000, 1.0f, 0);

		Device->Present(0, 0, 0, 0); // present backbuffer
	}

	return true;
}

LRESULT CALLBACK d3d::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			DestroyWindow(hwnd);
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// The entry point for any Windows program
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	if (!d3d::InitD3D(hInstance,
		800, 600, true, D3DDEVTYPE_HAL, &Device))
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}

	if (!Setup())
	{
		::MessageBox(0, "InitD3D() - FAILED", 0, 0);
		return 0;
	}

	d3d::EnterMsgLoop(Display);

	Cleanup();

	// return 0 to Windows
	return 0;
}