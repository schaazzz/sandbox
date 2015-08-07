#include <iostream>
#include <string>
#include <signal.h>
#include "proc_base.hpp"
#include "proc_ipc_queues.hpp"

using namespace std;

int main(void) {
    int q_id = -1;
    string msg;

    ProcBase *tx_proc = new ProcIPCQueues("tx_proc");
    signal(SIGINT, &(ProcBase::IntHandler));

    q_id = dynamic_cast<ProcIPCQueues*>(tx_proc)->CreateMsgQueue();
    cout << "Queue ID:" << q_id << endl;

    for(;;) {
        cout << "Enter text to send [Ctrl-C to exit]: ";
        cin >> msg;
        tx_proc->SendMsg(msg);
    }
}
