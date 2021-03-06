/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef _PROXYAI_PROXYAI_H
#define _PROXYAI_PROXYAI_H

// generated by the C++ Wrapper scripts
#include "OOAICallback.h"
#include "ExternalAI/Interface/SSkirmishAICallback.h"

#define PROXYAI_BUF_SIZE 4096

namespace proxyai {

    class ProxyAI {

    private:
        int SendEvent(int topic, const void* data);
        int ParseCommand(std::string json_string);
        int ParseCommands();
        int ReceiveCommands();
	springai::OOAICallback* callback;
        const struct SSkirmishAICallback* innerCallback;
	int skirmishAIId;
        int sock;
        int current_pos;
        char buf[PROXYAI_BUF_SIZE];
    public:
	ProxyAI(springai::OOAICallback* callback, const struct SSkirmishAICallback* innerCallback);
	~ProxyAI();

	int HandleEvent(int topic, const void* data);
    };

}
#endif
