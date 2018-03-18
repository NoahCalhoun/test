#pragma once

#include "Define.h"

class CGraphicDevice
{
public:
	explicit CGraphicDevice();
	virtual ~CGraphicDevice();

private:
	static shared_ptr<CGraphicDevice> m_pInstance;
public:
	static shared_ptr<CGraphicDevice> GetInstance();

//Field
private:
	ID3D11Device* m_pd3dDevice;						//���ҽ� ����
	IDXGISwapChain* m_pDXGISwapChain;				//���÷��� ����
	ID3D11DeviceContext* m_pd3dDeviceContext;		//���������� ����
	ID3D11RenderTargetView* m_pd3dRenderTargetView;	//���� Ÿ�� ��

	int m_iClientWindowWidth;
	int m_iClientWindowHeight;

//Function
public:
	HRESULT InitGraphicDevice();
	void UpdateDevice();

	void RenewDeviceSize(int _width, int _height);

	void ReleaseDevice();
};