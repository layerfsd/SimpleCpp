//server cpp 
#include "ModuleIfS.h" 

//cpp file, user can not modify this file 
#include "ModuleIfS.h" 
#include "RpcMessage.h" 
#include "Variant.h" 
#include "Session.h" 
#include "RpcDispatcher.h" 

int CDeviceInfo::Write(CBuffer* pBuffer)
{
	int nRet=0;
	int nWriteLen=0;
	nRet = pBuffer->Write(m_strName);
	if(nRet < 0)
	    return -1;
	nWriteLen += nRet;
	nRet = pBuffer->Write(m_nId);
	if(nRet < 0)
	    return -1;
	nWriteLen += nRet;
	return nRet;
}
int CDeviceInfo::Read(CBuffer* pBuffer)
{
	int nRet=0;
	int nReadLen = 0;
	nRet = pBuffer->Read(m_strName);
	if(nRet < 0)
	    return -1;
	nReadLen += nRet;
	nRet = pBuffer->Read(m_nId);
	if(nRet < 0)
	    return -1;
	nReadLen += nRet;
	return nRet;
}
CModuleIFS::CModuleIFS()
{
	m_strName = "CModuleIFS";
	m_strServiceName = "CModuleIFC";
	RegisterFunction(string("Login"), (ServiceFunctionHandle)&CModuleIFS::OnLogin);
	RegisterFunction(string("SendData"), (ServiceFunctionHandle)&CModuleIFS::OnSendData);
	RegisterFunction(string("GetDeviceInfo"), (ServiceFunctionHandle)&CModuleIFS::OnGetDeviceInfo);
	RegisterFunction(string("GetDevices"), (ServiceFunctionHandle)&CModuleIFS::OnGetDevices);
	RegisterFunction(string("CreateStream"), (ServiceFunctionHandle)&CModuleIFS::OnCreateStream);
}
CModuleIFS::~CModuleIFS()
{
	
}
int CModuleIFS::OnLogin ( string& strUser , string& strPWD , OUT_P int& nReturn ) 
{
	 int nRet=0;

	 return nRet;
}
int CModuleIFS::OnLogin(CFunctionParams* pFunctionParam)
{
	CBuffer*	pBuffer = pFunctionParam->GetBuffer();
	int nRet(0);
	pBuffer->Read(nRet);
	
	string  strUser; 
	pBuffer->Read(strUser);
	string  strPWD; 
	pBuffer->Read(strPWD);
	int  nReturn; 
	pBuffer->Read(nReturn);
	
	//call OnXXX function
	nRet= OnLogin(	strUser , 
		strPWD , 
		nReturn 
	);
	pBuffer->Clear();
	//返回值
	pBuffer->Write(nRet);
	pBuffer->Write(nReturn);

	return 0;
}
int CModuleIFS::OnSendData ( buffer& bufferData ) 
{
	 int nRet=0;

	 return nRet;
}
int CModuleIFS::OnSendData(CFunctionParams* pFunctionParam)
{
	CBuffer*	pBuffer = pFunctionParam->GetBuffer();
	int nRet(0);
	pBuffer->Read(nRet);
	
	buffer  bufferData; 
	pBuffer->Read(bufferData);
	
	//call OnXXX function
	nRet= OnSendData(	bufferData 
	);
	pBuffer->Clear();
	//返回值
	pBuffer->Write(nRet);

	return 0;
}
int CModuleIFS::OnGetDeviceInfo ( string& strName , CDeviceInfo& pDeviceInfo ) 
{
	 int nRet=0;

	 return nRet;
}
int CModuleIFS::OnGetDeviceInfo(CFunctionParams* pFunctionParam)
{
	CBuffer*	pBuffer = pFunctionParam->GetBuffer();
	int nRet(0);
	pBuffer->Read(nRet);
	
	string  strName; 
	pBuffer->Read(strName);
	CDeviceInfo  pDeviceInfo; 
	pBuffer->Read(pDeviceInfo);
	
	//call OnXXX function
	nRet= OnGetDeviceInfo(	strName , 
		pDeviceInfo 
	);
	pBuffer->Clear();
	//返回值
	pBuffer->Write(nRet);

	return 0;
}
int CModuleIFS::OnGetDevices ( string& strName , OUT_P vector<CDeviceInfo*>& lstDevices ) 
{
	 int nRet=0;

	 return nRet;
}
int CModuleIFS::OnGetDevices(CFunctionParams* pFunctionParam)
{
	CBuffer*	pBuffer = pFunctionParam->GetBuffer();
	int nRet(0);
	pBuffer->Read(nRet);
	
	string  strName; 
	pBuffer->Read(strName);
	vector < CDeviceInfo * >  lstDevices; 
	pBuffer->Read(lstDevices);
	
	//call OnXXX function
	nRet= OnGetDevices(	strName , 
		lstDevices 
	);
	pBuffer->Clear();
	//返回值
	pBuffer->Write(nRet);
	pBuffer->Write(lstDevices);
	pBuffer->Write(lstDevices);
	pBuffer->Free(lstDevices);

	return 0;
}
int CModuleIFS::OnCreateStream ( OUT_P int64& i64From , OUT_P int64& i64To ) 
{
	 int nRet=0;

	 return nRet;
}
int CModuleIFS::OnCreateStream(CFunctionParams* pFunctionParam)
{
	CBuffer*	pBuffer = pFunctionParam->GetBuffer();
	int nRet(0);
	pBuffer->Read(nRet);
	
	int64  i64From; 
	pBuffer->Read(i64From);
	int64  i64To; 
	pBuffer->Read(i64To);
	
	//call OnXXX function
	nRet= OnCreateStream(	i64From , 
		i64To 
	);
	pBuffer->Clear();
	//返回值
	pBuffer->Write(nRet);
	pBuffer->Write(i64From);
	pBuffer->Write(i64To);

	return 0;
}
