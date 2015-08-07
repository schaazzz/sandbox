#include <iostream>
#include <string>
#include <signal.h>
#include "process.hpp"

using namespace std;

int main(void) {
    int qID = -1;
    string msg;

    Process *tx_proc = new Process("tx_proc");
    signal(SIGINT, &(Process::intHandler));

    qID = tx_proc->createMsgQueue();
    cout << "Queue ID:" << qID << endl;

    for(;;) {
        cout << "Enter text to send [Ctrl-C to exit]: ";
        cin >> msg;
        tx_proc->sendMsg(msg);
    }
}
