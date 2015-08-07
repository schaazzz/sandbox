#include <iostream>
#include <string>
#include <signal.h>
#include "base_proc.hpp"

using namespace std;

int main(void) {
    int q_id = -1;
    string msg;

    BaseProc *rx_proc = new BaseProc("rx_proc");
    signal(SIGINT, &(BaseProc::IntHandler));

    q_id = rx_proc->CreateMsgQueue();
    cout << "Queue ID:" << q_id << endl;

    cout << "Waiting for messages [Ctrl-C to exit]" << endl;
    for(;;) {
        std::string msg = rx_proc->GetMsg();
        cout << "Received message : " << msg << endl;
    }
}
