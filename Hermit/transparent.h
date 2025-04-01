#pragma once
#include<Windows.h>
#include<easyx.h>

inline void TransparentImage(IMAGE* dest, int x, int y, IMAGE* src, COLORREF transColor) //Í¸Ã÷Í¼Æ¬Êä³ö
{
	HDC hdcDest = GetImageHDC(dest); 
	HDC hdcSrc = GetImageHDC(src);  

	TransparentBlt(hdcDest, x, y, src->getwidth(), src->getheight(),hdcSrc, 0, 0, src->getwidth(), src->getheight(), transColor);
}