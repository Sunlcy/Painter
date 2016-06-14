#pragma once
#include "Element.h"
#include <vector>

class CCurve :
	public CElement
{
public:
	virtual ~CCurve();
	virtual void Draw(CDC *pDC) override;  //覆盖父类的Draw函数

	//构造函数
	CCurve(const CPoint& first, const CPoint& second, COLORREF color);

	void AddSegment(const CPoint& point);		//添加曲线的一段
protected:
	std::vector<CPoint> m_Points;	//存储曲线的点
	CCurve();
};

