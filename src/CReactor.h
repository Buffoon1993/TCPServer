/*
 ================================================================================
 名 称: CReactor.h
 作 者: qinb
 版 本: 1.0.0
 时 间: 2019-4-9
 版 权: 
 描 述:
 
 历史修改:
 ================================================================================
 */

#ifndef CREACTOR_H_
#define CREACTOR_H_

#include <list>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

class CReactor {
public:
	CReactor();
	virtual ~CReactor();

	bool InitServer(const char *pIP, short nPort);
	bool UninitServer();

	bool CloseClient(int nClientfd);

	static void * LoopMain(void *pData);

private:
	//赋值构造和拷贝构造
	CReactor(const CReactor& that);
	CReactor& operator = (const CReactor& that);

	bool CreatorServerListener(const char* pIP, const int nPort);
	static void AcceptThreadProc(CReactor *pReactor);
	static void WorkerThreadProc(CReactor *pReactor);

private:
	int m_nListenFd = 0;
	int m_nEpollFd = 0;
	bool m_bStop = false;


};












#endif /* CREACTOR_H_ */
