
// PainterDoc.h : interface of the CPainterDoc class
//


#pragma once
#include <memory>
#include <list>
#include "ElementType.h"
#include "ElementColor.h"
#include "Element.h"

using PaintIterator = std::list<std::shared_ptr<CElement>>::const_iterator;

class CPainterDoc : public CDocument
{
protected: // create from serialization only
	CPainterDoc();
	DECLARE_DYNCREATE(CPainterDoc)

// Attributes
public:

// Operations
public:
	//Provide a begin iterator for the painting
	PaintIterator begin() const
	{
		return std::begin(m_Paint);
	}
	//Provide a ene iterator for the painting
	PaintIterator end() const
	{
		return std::end(m_Paint);
	}

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CPainterDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	//Add a painting element
	void AddElement(std::shared_ptr<CElement>& pElement)
	{
		m_Paint.push_back(pElement);
	}

	//Delete a painting element
	void DeleteElement(std::shared_ptr<CElement>& pElement)
	{
		m_Paint.remove(pElement);
	}

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnElementLine();
	afx_msg void OnElementRectangle();
	afx_msg void OnElementCircle();
	afx_msg void OnElementCurve();
	afx_msg void OnElementEllipse();
	afx_msg void OnColorBlack();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	ElementType GetElementType() { return m_Element; }
	ElementColor GetElementColor() { return m_Color; }
protected:
	// Current type of  element 
	ElementType m_Element = { ElementType::LINE };
	// Current color of the element
	ElementColor m_Color = { ElementColor::BLACK };
	std::list<std::shared_ptr<CElement>> m_Paint;	//Use list to contain the paintint
public:
	afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElementLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElementRectangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElementCircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElementCurve(CCmdUI *pCmdUI);
	afx_msg void OnUpdateElementEllipse(CCmdUI *pCmdUI);
};
