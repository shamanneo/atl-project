# ATLProject

Default Document-View Architecture desktop application with ATL.

    class CView : public CWindowImpl<CView>
    {
        public :
            CView() ; 
            virtual ~CView() ; 
        public :
            DECLARE_WND_CLASS(_T("View")) 
            
            BEGIN_MSG_MAP(CView)
                MESSAGE_HANDLER(WM_PAINT, OnPaint)
            END_MSG_MAP()
        public :
            LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        public :
            virtual void Draw(HDC hDC) ;
    } ;

When you add the some View class, you should implement Draw method.


