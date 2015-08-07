#include <iostream>
#include <string>
#include <signal.h>
#include "proc_base.hpp"
#include "proc_ipc_queues.hpp"

using namespace std;

int main(void) {
    int q_id = -1;
    string msg;

    ProcBase *rx_proc = new ProcIPCQueues("rx_proc");
    signal(SIGINT, &(ProcBase::IntHandler));

    q_id = dynamic_cast<ProcIPCQueues*>(rx_proc)->CreateMsgQueue();
    cout << "Queue ID:" << q_id << endl;

    cout << "Waiting for messages [Ctrl-C to exit]" << endl;
    for(;;) {
        std::string msg = rx_proc->GetMsg();
        cout << "Received message : " << msg << endl;
    }
}
