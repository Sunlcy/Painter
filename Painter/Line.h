#pragma once
#include "Element.h"
class CLine :
	public CElement
{
public:
	virtual ~CLine();
	virtual void Draw(CDC *pDC) override;	//覆盖父类的Draw()函数
	//构造函数
	CLine(const CPoint& start, const CPoint& end, COLORREF color);

protected:
	CPoint m_EndPoint;		//线的末尾点

protected:
	CLine();
};

