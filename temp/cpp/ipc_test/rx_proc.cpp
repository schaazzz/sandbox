#include <iostream>
#include <string>
#include <signal.h>
#include "process.hpp"

using namespace std;

int main(void) {
    int qID = -1;
    string msg;

    Process *rx_proc = new Process("rx_proc");
    signal(SIGINT, &(Process::intHandler));

    qID = rx_proc->createMsgQueue();
    cout << "Queue ID:" << qID << endl;

    cout << "Waiting for messages [Ctrl-C to exit]" << endl;
    for(;;) {
        std::string msg = rx_proc->getMsg();
        cout << "Received message : " << msg << endl;
    }
}
