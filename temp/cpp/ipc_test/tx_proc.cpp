#include <iostream>
#include <string>
#include <signal.h>
#include "base_proc.hpp"

using namespace std;

int main(void) {
    int q_id = -1;
    string msg;

    BaseProc *tx_proc = new BaseProc("tx_proc");
    signal(SIGINT, &(BaseProc::IntHandler));

    q_id = tx_proc->CreateMsgQueue();
    cout << "Queue ID:" << q_id << endl;

    for(;;) {
        cout << "Enter text to send [Ctrl-C to exit]: ";
        cin >> msg;
        tx_proc->SendMsg(msg);
    }
}
