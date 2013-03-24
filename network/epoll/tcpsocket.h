/*
* ZSUMMER License
* -----------
* 
* ZSUMMER is licensed under the terms of the MIT license reproduced below.
* This means that ZSUMMER is free software and can be used for both academic
* and commercial purposes at absolutely no cost.
* 
* 
* ===============================================================================
* 
* Copyright (C) 2012 YaweiZhang <yawei_zhang@foxmail.com>.
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
* 
* ===============================================================================
* 
* (end of COPYRIGHT)
*/

#ifndef _ZSUMMER_TCPSOCKET_H_
#define _ZSUMMER_TCPSOCKET_H_



#include "public.h"
#include "epoll.h"

namespace zsummer
{


	class CTcpSocket : public ITcpSocket
	{
	public:
		CTcpSocket();
		virtual ~CTcpSocket();
		virtual bool BindIOServer(IIOServer * ios);
		virtual bool SetCallback(ITcpSocketCallback * cb);
		virtual bool GetPeerInfo(unsigned int * addr, unsigned short *port);


		virtual bool DoConnect(const char *ip, unsigned short port);
		virtual bool DoSend(char * buf, unsigned int len);
		virtual bool DoRecv(char * buf, unsigned int len);
		virtual bool Close();

		void OnPostClose();

		virtual bool OnEPOLLMessage(int type, int flag);


	public:
		IIOServer * m_ios;
		ITcpSocketCallback * m_cb;
		sockaddr_in	m_addr;
		tagRegister m_handle;

		bool		m_bNeedDestroy;

		unsigned int m_iRecvNeedLen;
		unsigned int m_iRecvCurLen;
		char	*	 m_pRecvBuf;

		unsigned int m_iSendNeedLen;
		unsigned int m_iSendCurLen;
		char *		 m_pSendBuf;
	};

}






















#endif











